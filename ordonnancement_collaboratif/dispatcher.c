void switch_to(struct ctx_s* ctx) {
	//Save current context
	__asm("mov %14, sp" : "=r"(current_ctx.adr_instruction)); //LR because we want the following instruction
	__asm("mov %0, sp" : "=r"(current_ctx.adr_stack)); //stack pointer

	//Switch
	current_ctx = ctx;

	//update the mc: assembleur to restaure new context
	__asm("mov sp, %14" : : "r"(current_ctx.adr_instruction));
	__asm("mov sp, %0" : : "r"(current_ctx.adr_stack));
}
