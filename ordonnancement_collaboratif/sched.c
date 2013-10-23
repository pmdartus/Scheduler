#include <stdint.h>

#include "sched.h"
#include "process.h"
#include "dispatcher.h"
#include "allocateMemory.h"

// Global varible to store all PCBs
pcb_s* act_pcb;

//-------------------------
//  create_process
//	Initialize pcb => from created to ready
//-------------------------
void create_process(func_t f) {
	// Init phase
	uint32_t* new_pcb_adr = AllocateMemory(sizeof(struct pcb_s));
	pcb_s* new_pcb = (pcb_s*) new_pcb_adr;
	init_pcb(new_pcb, f, STACK_SIZE);

	// Set act_pcb for the first created process
	if (act_pcb == 0) 
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
//-------------------------
void schedule() {
	pcb_s* pcb = act_pcb;
	
	while( pcb->next ) {
		//Desallocate pcb & stack
		
		//Update chained list
		
		//next
		pcb = pcb->next;
	}
}



//-------------------------
//  yield
//	switch automatically the process, based on ctx_switch
//-------------------------
void yield( ) {
	//Change status of quiting process
	act_pcb->state = Paused;

	ctx_switch();
	
	//Change status of ongoing process
	act_pcb->state = Active;
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
