#include <stdint.h>

//-------------------------
//  Type definition
//-------------------------

// Used function by process
typedef void (*func_t)(void);

// Context structure definition
typedef struct{
	// Program counter
	uint32_t pc;

	// Stack Pointer
	uint32_t sp;

	//Registers
	uint32_t registers [12];
} ctx_s;

// Context state definition
typedef enum {created, ready, paused, active} ctx_state;

// PCB structure to store process
typedef struct{
	//Context
	ctx_s* ctx;
	
	//Actual state of the process
	ctx_state state = created;

	//Chained list
	pcb_s* next;	
} pcb_s;


//-------------------------
//  Functions
//-------------------------

void init_pcb(func_t f, unsigned int stack_size);
void init_ctx(ctx_s* ctx, func_t f, unsigned int stack_size);
