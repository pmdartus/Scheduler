#include <stdint.h>
#include "process.h"
#include "allocateMemory.h"



//-------------------------
//  init_pcb
//	Initialize pcb => from created to ready
//-------------------------
void init_pcb(struct pcb_s* pcb, func_t f, unsigned int stack_size) {

	//Initialisation of the context	
	pcb->pc = f;
	
	//Stack allocation
	uint32_t* new_loc = AllocateMemory(stack_size);
	
	//The stack adress is resturned by AllocateMemory. As the stack is decremented, we add the stack size to the stack start adress.
	pcb->sp = (uint32_t) new_loc + stack_size - 1; //because start at 0

	//Init info for the pcb
	pcb->state = Created;
}
