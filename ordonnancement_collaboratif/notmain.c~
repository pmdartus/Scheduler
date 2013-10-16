#include <stdint.h>
#include "dispatcher.h"
#include "sched.h"

const long STACK_SIZE = 100000;

void funcA()
{
 int cptA = 0;

 while ( 1 ) {
   cptA ++;
   yield();
 }
}

void funcB()
{
 int cptB = 1;

 while ( 1 ) {
   cptB += 2 ;
   yield();
 }
}

//------------------------------------------------------------------------
int
notmain ( void )
{
	create_process(funcA, []);
	create_process(funcB, []);

	start_sched();

	/* Pas atteignable vues nos 2 fonctions */
	return(0);
}
