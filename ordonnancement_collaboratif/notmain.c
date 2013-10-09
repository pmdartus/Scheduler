#include <stdint.h>
#include "process.h"
#include "dispatcher.h"

// To be verified
const STACK_SIZE = 1000;

struct ctx_s ctx_A;
struct ctx_s ctx_B;
struct ctx_s ctx_init;

void
ping()
{
  while (1) {
    switch_to(&ctx_B);
    switch_to(&ctx_B);
  }
}

void
pong()
{
  while (1) {
    switch_to(&ctx_A);
    switch_to(&ctx_A);
    switch_to(&ctx_A);
  }
}

//------------------------------------------------------------------------
int
notmain ( void )
{
  init_ctx(&ctx_A, ping, STACK_SIZE);
  init_ctx(&ctx_B, pong, STACK_SIZE);

  current_ctx = &ctx_init;

  switch_to(&ctx_A);
}
