#include "env.h"

void
init_env()
{
  root_symbol_table = new_member_table(0x0, 64);
}
