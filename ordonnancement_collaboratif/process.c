void init_ctx(struct ctx_s* ctx, func_t f, unsigned int stack_size) {
	//Initialisation of the context	
	ctx.adr_instruction = (uint32_t) f;
	
	//Stack allocation
	uint32* new_loc = AllocateMemory(stack_size);
	
	//The stack adress is resturned by AllocateMemory. As the stack is decremented, we add the stack size to the stack start adress.
	ctx.adr_stack = (uint32_t) new_loc + stack_size - 1; //because start at 0
}
