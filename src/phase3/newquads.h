#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define AVM_STACKSIZE 4096
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUNCTIONS (unsigned) nop_v



unsigned char executionFinished ;
unsigned pc ; 
unsigned currLine ;
unsigned codeSize ;

#define AVM_ENDING_PC	codeSize




enum avm_memcell_t{
	number_m	=0,
	string_m	=8,
	bool_m		=2,
	table_m		=3,
	userfunc_m	=4,
	libfunc_m	=5,
	nil_m		=6,
	undef_m		=7
};



struct avm_table;

struct avm_memcell {
   enum avm_memcell_t type;
   union {
      double numVal;
      char* strVal;
      unsigned char boolVal;
      struct avm_table* tableVal;
      unsigned funcVal;
      char* libfuncVal;   
   }data;
};

#define AVM_WIPEOUT(m) memset( & (m), 0, sizeof(m))

struct avm_memcell stack[AVM_STACKSIZE];

struct avm_memcell ax,bx,cx,retval;
unsigned top, topsp;



enum vmopcode{
  ASSIGN,add_v,SUB,
  MUL,DIVI,MOD,
  UMINUS,IF_EQ,IF_NOTEQ,
  IF_LESSEQ,IFGREATEREQ,IF_LESS,
  IF_GREATER,CALL,PARAM,
  RET,GETRETVAL,FUNCSTART,
  FUNCEND,TABLECREATE,
  TABLEGETELEM,TABLESETELEM
  ,ANDI,ORI,NOTI,JUMP ,ASSING ,nop_v ,EQ_ASSIGN
};




enum vmarg_t{  
  global_a,
  local_a,
  formal_a,
  bool_a,
  string_a,
  constnum_a,
  number_a,
  userfunc_a,
  libfunc_a,
  retval_a,
  nil_a
};

struct vmarg { 
  enum vmarg_t type;
  unsigned val;
  char* name;
  char* func_name;
};

struct instruction{
  enum vmopcode opcode;
  struct vmarg* result;
  struct vmarg* arg1;
  struct vmarg* arg2;
  unsigned srcLine;
};

char* vmarg_array[11] ;

char* bool_array[3] ;

void avm_error(char* msg);
void avm_warning(char* msg);

struct avm_memcell* avm_translate_operand( struct vmarg* arg, struct avm_memcell* reg);
unsigned avm_totalactuals(void);
