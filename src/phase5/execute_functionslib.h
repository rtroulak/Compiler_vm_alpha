#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "newquads.h"
#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET  3
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVETOPSP_OFFSET 1

void execute_call (struct instruction* instr);
void avm_dec_top(void);
void avm_push_envalue(unsigned val);
void avm_callsaveenviroment(void);
void execute_funcenter(struct instruction* instr);
unsigned avm_get_envvalue(unsigned i);
void execute_funcexit(struct instruction* unused);   
typedef void(*library_func_t)(void);
library_func_t avm_getlibraryfunc(char * id);
void avm_calllibfunc(char * id);
unsigned avm_totalactuals(void);
struct avm_memcell* avm_getactual(unsigned i);
void libfunc_print(void);
void avm_registerlibfunc(char *id,library_func_t addr);	
void libfunc_typeof(void);
void libfunc_totalarguments(void);
char* avm_tostring(struct avm_memcell *m);
void execute_pusharg ( struct instruction* instr ) ;