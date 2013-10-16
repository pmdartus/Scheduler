// Global varible to store all PCBs
pcb_s* act_pcb;

//-------------------------
//  create_process
//	Initialize pcb => from created to ready
//-------------------------
void create_process(func_t f, void* args) {
	
}


//-------------------------
//  start_current_process
//	lunch process for the first time
//-------------------------
void start_current_process() {
	//"Positionne contexte courrant" => WTF?

	//Call function of the process
	act_pcb->ctx->pc();
}


//-------------------------
//  yield
//	switch automatically the process, based on ctx_switch
//-------------------------
void yield( ) {
	next_run = act_pcb->next;

	ctx_switch();
}


//-------------------------
//  start_sched
//	manage yield for first call (special case)
//-------------------------
void start_sched( ) {
	//Create a fake process to be able to do the yield
	pcb_s pcb_useless;
	pcb_useless.next = act_pcb;
	act_pcb = &pcb_useless;

	yield();
}
