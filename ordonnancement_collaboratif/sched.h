extern pcb_s* act_pcb;

//-------------------------
//  Functions
//-------------------------

void create_process(func_t f);
void yield();
void start_current_process();
void start_sched();
