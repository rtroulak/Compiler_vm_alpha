#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "execute_assign.h"

// extern void avm_warning(char* format);
extern void avm_assign(struct avm_memcell* lv, struct avm_memcell* rv);

void execute_assign(struct instruction* instr){
  struct avm_memcell* lv=avm_translate_operand( instr->result, (struct avm_memcell*) 0 );
  struct avm_memcell* rv=avm_translate_operand( instr->arg1, &ax );
  printf("\n%s",instr->result->name);
//   assert(lv && (&stack[0] <= lv && &stack[top] > lv || lv==&retval) );
  assert(rv);
//     printf("LANOTTIA1\n");
  avm_assign( lv, rv);
//     printf("LANOTTIA2\n");
}