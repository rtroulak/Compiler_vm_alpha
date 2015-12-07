#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "newquads.h"

#define	execute_add execute_arithmetic
#define	execute_sub execute_arithmetic
#define	execute_mul execute_arithmetic
#define	execute_div execute_arithmetic
#define	execute_mod execute_arithmetic

#define EXPAND_SIZEvm 1204
#define CURR_SIZEvm (totalvm*sizeof(struct instruction))
#define NEW_SIZEvm (EXPAND_SIZEvm*sizeof(instructions)+CURR_SIZEvm)



unsigned int totalvm;
unsigned int currQuadvm;

unsigned top,topsp;
int no_instructions;

char * array_new[100];
int i_for_array=0;

double 	 consts_getnumber (unsigned  index);
char*	consts_getstring (unsigned  index);
char*	libfuncs_getused (unsigned  index);



struct instruction *instructions;

void execute_cycle(void);

void avm_memcellclear(struct avm_memcell* m);
void memclear_string (struct avm_memcell* m);
void memclear_table (struct avm_memcell* m);

static void avm_initstack(void);
int read_bin();
struct vmarg *create_vmarg( enum vmarg_t type, unsigned val ,char* name );
void create_instr(enum vmopcode opcode, struct vmarg* result, struct vmarg* arg1, struct vmarg* arg2);
void expandvm(void);
   
char* avm_tostring(struct avm_memcell *m);
void libfunc_typeof(void);