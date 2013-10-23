#include  "dispatcher.h"
#include  "sched.h"

void ctx_switch() {
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
