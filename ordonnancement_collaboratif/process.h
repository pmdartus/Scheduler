#ifndef _PROCESS_H
#define _PROCESS_H

#include <stdint.h>

//-------------------------
//  Type definition
//-------------------------

// Used function by process
typedef void (*func_t)(void);

// Context state definition
typedef enum {Created, Ready, Paused, Active} ctx_state;

// PCB structure to store process
typedef struct pcb_s {
	//------- Context ----------
	// Program counter
	func_t pc;

	// Stack Pointer
	uint32_t sp;	

	//------- Infos ----------
	//Actual state of the process
	ctx_state state;

	//Chained list
	struct pcb_s* next;	
} pcb_s;


//-------------------------
//  Functions
//-------------------------

void init_pcb(struct pcb_s* pcb, func_t f, unsigned int stack_size);


#endif

