// Global varible to store all PCBs
struct pcb_s* act_pcb;

//-------------------------
//  create_process
//	Initialize pcb => from created to ready
//-------------------------
void create_process(func_t f, void* args) {
	// Init phase
	pcb_s* new_pcb = AllocateMemory(sizeof(pcb_s));
	init_pcb(new_pcb, f, STACK_SIZE);

	// Set act_pcb for the first created process
	if (act_pcb = null) 
	{
		act_pcb = new_pcb;
		act_pcb->next = act_pcb;
	}
	else // Insert it into the fifo after the current PCB
	{
		pcb_s* pcb_to_move = act_pcb->next;
		act_pcb->next = new_pcb;
		new_pcb->next = pcb_to_move;
	}
}


//-------------------------
//  start_current_process
//	lunch process for the first time
//-------------------------
void start_current_process() {
	//Call function of the process
	act_pcb->pc();
}


//-------------------------
//  yield
//	switch automatically the process, based on ctx_switch
//-------------------------
void yield( ) {
	//Change status of quiting process
	act_pcb->status = Paused;

	ctx_switch();
	
	//Change status of ongoing process
	act_pcb->status = Active;
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
