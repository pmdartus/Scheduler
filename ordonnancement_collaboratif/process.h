#include <stdint.h>

typedef void (*func_t)(void);

typedef struct{
	uint32_t pc;
	uint32_t sp;
	uint32_t registers [12];
} ctx_s;

typedef struct{
	//Context
	ctx_s* ctx;
	
	//Actual state of the process : 0 = created, 1 = ready, 2 = paused, 3 = active
	int state = 0;

	//Chained list mngt
	pcb_s* next;	
} pcb_s;

void init_pcb(func_t f, unsigned int stack_size);
void init_ctx(ctx_s* ctx, func_t f, unsigned int stack_size);
