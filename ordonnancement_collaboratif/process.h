#include <stdint.h>

typedef void (*func_t)(void);

typedef struct{
	//Stack pointer and program counter
	uint32_t pc;
	uint32_t sp;
	
	//Actual state of the process : 0 = created, 1 = ready, 2 = active
	int state = 0;
	
	//Function containing the running code, linked to some arguments that we also need to store
	func_t f;
	void* args;

	//Chained list mngt
	pcb_s* next;	
} pcb_s;

pcb_s* current_ctx;

void init_ctx(ctx_s* ctx, func_t f, unsigned int stack_size);
