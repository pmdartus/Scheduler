#include <stdint.h>
#include "dispatcher.h"

const STACK_SIZE = 100000;

ctx_s ctx_A;
ctx_s ctx_B;
ctx_s ctx_init;

void
funcA()
{
 int cptA = 0;

 while ( 1 ) {
   cptA ++;
   switch_to(&ctx_B);
 }
}

void
funcB()
{
 int cptB = 1;

 while ( 1 ) {
   cptB += 2 ;
   switch_to(&ctx_A);
 }
}

//------------------------------------------------------------------------
int
notmain ( void )
{
	init_ctx(&ctx_A, funcA, STACK_SIZE);
	init_ctx(&ctx_B, funcB, STACK_SIZE);

	current_ctx = &ctx_init;
	switch_to(&ctx_A);

	/* Pas atteignable vues nos 2 fonctions */
	return(0);
}
