# Switch_to explaination

When entering a function, LR contains the following line that we need to get to when switching back to the previous context.

That known, we use it to save the current context instruction into current_ctx (the global current ctx_s structure). We also need to save the stack pointer into this structure.

*N.B.: Assembler call in C++ are read from right to left like an affectation.*

# PCB new system

The PCBs are chained lists that contains context and pointer to the next process.
All the process are then stored globally, whithin the sched.c who ,anage the proc schedule. 
