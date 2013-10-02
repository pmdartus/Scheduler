void init_ctx(struct ctx_s* ctx, func_t f, unsigned int stack_size) {
	//Initialisation of the context	
	ctx.adr_instruction = (uint32_t) f;
	ctx.adr_stack = (uint32_t) stack_size;
	
	//Stack allocation for pong (ping will use notmain stack :)
	AllocateMemory(stack_size);
}
