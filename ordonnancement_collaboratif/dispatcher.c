#include  "dispatcher.h"

void ctx_switch() {
	//First, save all registers in stack
	__asm("push {r0-r12}, lr");

	//Save current context
	__asm("mov %0, sp" : "=r"(act_pcb->adr_stack)); //stack pointer

	//Switch
	act_pcb = next_run;

	//update the mc: assembleur to restaure new context
	__asm("mov sp, %0" : : "r"(act_pcb->adr_stack));

	//pull all registers from stack
	__asm("pop {r0-r12}, lr");
}
