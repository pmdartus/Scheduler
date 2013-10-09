#include <stdint.h>

typedef void (*func_t)(void);

typedef struct{
	uint32_t adr_instruction;
	uint32_t adr_stack;
} ctx_s;

ctx_s* current_ctx;

void init_ctx(ctx_s* ctx, func_t f, unsigned int stack_size);
