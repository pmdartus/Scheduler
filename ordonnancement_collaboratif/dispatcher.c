#include  "dispatcher.h"

void switch_to(ctx_s* ctx) {
	//Save current context
	//%0 will be replaced by the value of the passed variable
	__asm("mov %0, lr" : "=r"(current_ctx->adr_instruction)); //LR because we want the following instruction
	__asm("mov %0, sp" : "=r"(current_ctx->adr_stack)); //stack pointer
	
	//Lastly, save all registers
	//for ( n=0 ; n<11 ; n++ )
	//{
		__asm("mov %0, r0" : "=r"(current_ctx->registers[0]));
		__asm("mov %0, r1" : "=r"(current_ctx->registers[1]));
		__asm("mov %0, r2" : "=r"(current_ctx->registers[2]));
		__asm("mov %0, r3" : "=r"(current_ctx->registers[3]));
		__asm("mov %0, r4" : "=r"(current_ctx->registers[4]));
		__asm("mov %0, r5" : "=r"(current_ctx->registers[5]));
		__asm("mov %0, r6" : "=r"(current_ctx->registers[6]));
		__asm("mov %0, r7" : "=r"(current_ctx->registers[7]));
		__asm("mov %0, r8" : "=r"(current_ctx->registers[8]));
		__asm("mov %0, r9" : "=r"(current_ctx->registers[9]));
		__asm("mov %0, r10" : "=r"(current_ctx->registers[10]));
		__asm("mov %0, r11" : "=r"(current_ctx->registers[11]));
		__asm("mov %0, r12" : "=r"(current_ctx->registers[12]));
	//}

	//Switch
	current_ctx = ctx;

	//update the mc: assembleur to restaure new context
	__asm("mov lr, %0" : : "r"(current_ctx->adr_instruction));
	__asm("mov sp, %0" : : "r"(current_ctx->adr_stack));

	//pull all registers
	//for ( n=0 ; n<11 ; n++ )
	//{
		__asm("mov r0, %0" : : "r"(current_ctx->registers[0]));
		__asm("mov r1, %0" : : "r"(current_ctx->registers[1]));
		__asm("mov r2, %0" : : "r"(current_ctx->registers[2]));
		__asm("mov r3, %0" : : "r"(current_ctx->registers[3]));
		__asm("mov r4, %0" : : "r"(current_ctx->registers[4]));
		__asm("mov r5, %0" : : "r"(current_ctx->registers[5]));
		__asm("mov r6, %0" : : "r"(current_ctx->registers[6]));
		__asm("mov r7, %0" : : "r"(current_ctx->registers[7]));
		__asm("mov r8, %0" : : "r"(current_ctx->registers[8]));
		__asm("mov r9, %0" : : "r"(current_ctx->registers[9]));
		__asm("mov r10, %0" : : "r"(current_ctx->registers[10]));
		__asm("mov r11, %0" : : "r"(current_ctx->registers[11]));
		__asm("mov r12, %0" : : "r"(current_ctx->registers[12]));
	//}
}