#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "newquads.h"


 
void execute_jeq(struct instruction* instr);
void execute_jump(struct instruction* instr);
void execute_eq_assign(struct instruction* instr); //perister new
void execute_jlt(struct instruction* instr);




unsigned char number_tobool(struct avm_memcell *m);
unsigned char string_tobool(struct avm_memcell *m);
unsigned char bool_tobool (struct avm_memcell *m);
unsigned char table_tobool (struct avm_memcell *m);
unsigned char userfunc_tobool(struct avm_memcell *m);
unsigned char libfunc_tobool (struct avm_memcell *m);
unsigned char nil_tobbol(struct avm_memcell *m);
unsigned char undef_tobool(struct avm_memcell *m);

unsigned char avm_tobool(struct avm_memcell* m);