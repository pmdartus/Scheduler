#include  "dispatcher.h"

void switch_to(ctx_s* ctx) {
	//Save current context
	//%0 will be replaced by the value of the passed variable
	__asm("mov %0, lr" : "=r"(current_ctx->adr_instruction)); //LR because we want the following instruction
	__asm("mov %0, sp" : "=r"(current_ctx->adr_stack)); //stack pointer

	//Switch
	current_ctx = ctx;

	//update the mc: assembleur to restaure new context
	__asm("mov lr, %0" : : "r"(current_ctx->adr_instruction));
	__asm("mov sp, %0" : : "r"(current_ctx->adr_stack));
}
