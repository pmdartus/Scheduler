#ifndef _SCHED_H
#define _SCHED_H

#include "process.h"

//-------------------------
//  Functions
//-------------------------

void create_process(func_t f);
void yield();
void start_current_process();
void start_sched();
void schedule();

extern struct pcb_s* act_pcb;
extern const long STACK_SIZE;

#endif

