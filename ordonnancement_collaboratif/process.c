#include <stdint.h>
#include "process.h"
#include "allocateMemory.h"

void init_pcb(pcb_s* pcb, func_t f, unsigned int stack_size) {	
	ctx_s* new_ctx = malloc(sizeof(ctx_s));

	pcb->ctx = new_ctx;
	init_ctx( pcb->ctx, f, stack_size);

	pcb->state = ready;
	pcb->next = null;
}

void init_ctx(ctx_s* ctx, func_t f, unsigned int stack_size) {
	//Initialisation of the context	
	(*ctx).adr_instruction = (uint32_t) f;
	
	//Stack allocation
	uint32_t* new_loc = AllocateMemory(stack_size);
	
	//The stack adress is resturned by AllocateMemory. As the stack is decremented, we add the stack size to the stack start adress.
	(*ctx).adr_stack = (uint32_t) new_loc + stack_size - 1; //because start at 0

	int n;
	for ( n=0 ; n<11 ; n++ )
	{
		(*ctx).registers[n] = 0;
	}
}
