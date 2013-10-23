#include <stdint.h>

#define NULL ((void*)0)

#include "sched.h"
#include "process.h"
#include "allocateMemory.h"

// Global varible to store all PCBs
pcb_s* act_pcb = NULL;

//-------------------------
//  create_process
//	Initialize pcb => from created to ready
//-------------------------
void create_process(func_t f) {
	// Init phase

	pcb_s* new_pcb = (pcb_s*) AllocateMemory(sizeof(struct pcb_s));
	init_pcb(new_pcb, f, STACK_SIZE);

	// Set act_pcb for the first created process
	if (act_pcb == NULL) 
	{
		act_pcb = new_pcb;
		act_pcb->next = act_pcb;
	}
	else // Insert it into the fifo after the current PCB
	{
		pcb_s* pcb_to_move = act_pcb->next;
		act_pcb->next = new_pcb;
		new_pcb->next = pcb_to_move;
	}
	
	new_pcb->state = Ready;
}


//-------------------------
//  start_current_process
//	lunch process for the first time
//-------------------------
void start_current_process() {
	//Call function of the process
	act_pcb->pc();
	
	//Declare the processus as terminated
	act_pcb->state = Terminated;
	//and switch
	yield();
}


//-------------------------
//  schedule
//	Manage killed process
//	Elect next process to be run
//-------------------------
void schedule() {
	pcb_s* pcb = act_pcb;
	
	while( pcb->next->state == Terminated ) {
		//Update chained list
		act_pcb->next = pcb->next;

		//Desallocate pcb & stack
		FreeAllocatedMemory((uint32_t*) pcb->sp);
		FreeAllocatedMemory((uint32_t*) pcb);
		
		//next
		pcb = act_pcb->next;
	}

	//Elect next process
	act_pcb -> state = Paused ;
	act_pcb = act_pcb->next;
	if (act_pcb -> state != Ready) {
		act_pcb -> state = Active;
	}
}



//-------------------------
//  yield
//	switch automatically the process
//-------------------------
void yield( ) {
	//First, save all registers in stack
	__asm("push {r0-r12, lr}");

	//Save current context
	__asm("mov %0, sp" : "=r"(act_pcb->sp)); //stack pointer
	
	schedule(); // this call changes act_pcb

	//update the mc: assembleur to restaure new context
	__asm("mov sp, %0" : : "r"(act_pcb->sp));

	//If Proc never lunched
	if (act_pcb->state == Ready) {
		//Go to the entry point: the function
		start_current_process();
	}
	else {
		//pull all registers from stack
		__asm("pop {r0-r12, lr}");
	}
}


//-------------------------
//  start_sched
//	manage yield for first call (special case)
//-------------------------
void start_sched( ) {
	//Create a fake process to be able to do the yield
	pcb_s pcb_useless;
	pcb_useless.next = act_pcb;
	act_pcb = &pcb_useless;

	yield();
}
