
struct ctx_s {
	uint32_t* adr_inst;
	uint32_t* adr_stack;
};

ctx_s current_ctx;

void init_ctx(struct ctx_s* ctx, func_t f, unsigned int stack_size);
