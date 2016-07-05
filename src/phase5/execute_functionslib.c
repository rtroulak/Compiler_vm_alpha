#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "execute_functionslib.h"






typedef char* (*tostring_func_t) (struct avm_memcell*);

extern char* number_tostring (struct avm_memcell*);
extern char* string_tostring (struct avm_memcell*);
extern char* bool_tostring (struct avm_memcell*);
extern char* table_tostring (struct avm_memcell*);
extern char* userfunc_tostring (struct avm_memcell*);
extern char* libfunc_tostring (struct avm_memcell*);
extern char* nil_tostring (struct avm_memcell*);
extern char* undef_tostring (struct avm_memcell*);



/*START CALL FUNCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

tostring_func_t tostringFuncs []={
//   number_tostring,
//   string_tostring,
//   bool_tostring,
//   table_tostring,
//   userfunc_tostring,
//   libfunc_tostring,
//   nil_tostring,
//   undef_tostring
};


extern void avm_error(char* msg);
extern char* avm_tostring(struct avm_memcell*);
extern void avm_calllibfunc(char * funcName);
extern void avm_callsaveenviroment(void);
struct avm_memcell* res;

unsigned totalActuals=0;

void execute_call (struct instruction* instr){
  
  
  struct avm_memcell * func=avm_translate_operand(instr->result,&ax);
  assert(func);
  avm_callsaveenviroment();
  
  switch (func->type){
    
    case userfunc_m:{
      pc=func->data.funcVal;
      assert(pc<AVM_ENDING_PC);
     // assert(code[pc].opcode == funcenter_v);
      break;
      
    }
    case string_m: avm_calllibfunc(func->data.strVal);
    case libfunc_m:
      if( strcmp(func->data.libfuncVal,"print") == 0){
	int counteryo=1;
	printf("\n %d YO %d\n",totalActuals,top);
	while( counteryo <= totalActuals ){
	  res = &stack[top+5];
	  printf("%s",res->data.strVal);
	  counteryo--;
	}
	break;
      }
    
    default:{
      
      char *s=avm_tostring(func);
      avm_error("call: cannot bind %s to function!");
      free(s);
      executionFinished=1;
      
      
      
      
    }
    
    
    
    
  }
}

  
void avm_dec_top(void){
  
  if(!top){
    
    avm_error("stack overflow");
    executionFinished=1;
    
    
  }else
    --top;
}
  
  
void avm_push_envalue(unsigned val){
    
    stack[top].type=number_m;
    stack[top].data.numVal=val;
    avm_dec_top();
}
    
void avm_callsaveenviroment(void){
    
    avm_push_envalue(totalActuals);
    avm_push_envalue(pc+1);
    avm_push_envalue(top + totalActuals +2);
    avm_push_envalue(topsp);
    
}
  
  
 extern struct userfunc* avm_getfuncinfo(unsigned address);
 
 void execute_funcenter(struct instruction* instr){
   
   struct avm_memcell* func =avm_translate_operand(instr->result,&ax);
   assert(func);
   assert(pc==func->data.funcVal);
   
   totalActuals=0;
   topsp=top;
   //top=top-funcInfo->localSize;
   
   
}

unsigned avm_get_envvalue(unsigned i){
  
  assert (stack[i].type=number_m);
  unsigned val= (unsigned) stack[i].data.numVal;
  assert(stack[i].data.numVal==((double) val));
  return val;
  
  
}


void execute_funcexit(struct instruction* unused){
  
  unsigned oldTop=top;
  top=avm_get_envvalue(topsp+AVM_SAVEDTOP_OFFSET);
  pc=avm_get_envvalue(topsp+AVM_SAVEDPC_OFFSET);
  topsp=avm_get_envvalue(topsp+AVM_SAVETOPSP_OFFSET);
  
  
  while(oldTop++<= top)
    avm_memcellclear(&stack[oldTop]);
  
}
 
 

    
typedef void(*library_func_t)(void);
library_func_t avm_getlibraryfunc(char * id){
 return NULL; 
  
}




  
  
  

    
  







void avm_calllibfunc(char * id){
  
//   library_func_t f=avm_getlibraryfunc (id);
  
  if(!id){
    avm_error("unsupported lib func '%s(id)' called");
    executionFinished=1;	
  }else{
    /**/
    
    topsp=top;
    totalActuals=0;
    
    //(*f)();	/*call library func*/
    
    if(!executionFinished){/*an error may naturaly occour inside*/
      
      execute_funcexit((struct instruction*)0);/*return sequence*/
      
      
    }
    
  }
  
  
  
  
}

/*END CALL FUNCTIONS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
unsigned avm_totalactuals(void){
  return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

struct avm_memcell* avm_getactual(unsigned i){
  assert(i<avm_totalactuals());
  return &stack[topsp +AVM_STACKENV_SIZE +1+i];
  
}

void libfunc_print(void){
  
  unsigned n=avm_totalactuals();
  unsigned i;
  for(i=0;i<n;++i){
    char *s=avm_tostring(avm_getactual(i));
    puts(s);
    free(s);
    
  }
  
  
}

void avm_registerlibfunc(char *id,library_func_t addr);	

void libfunc_typeof(void){
  unsigned n=avm_totalactuals();
  
  if(n!=1){
    
    avm_error("one argument (not %d(n)) expected in 'typeof' !");
    
  }else{
    
    avm_memcellclear(&retval);
    retval.type=string_m;
//     retval.data.strVal=strdup(avmtypes[avm_getactual(0)->type]);
    
    
  } 
  
}

void libfunc_totalarguments(void){
  unsigned p_topsp=avm_get_envvalue(topsp+AVM_SAVETOPSP_OFFSET);
  avm_memcellclear(&retval);
  
  if(!p_topsp){
    
    avm_error("totall arguments call outside function!");
    retval.type=nil_m;
    
  }else{
    
    retval.type=number_m;
    retval.data.numVal=avm_get_envvalue(p_topsp+ AVM_NUMACTUALS_OFFSET);
    
    
  }
  
  
  
}

char* avm_tostring(struct avm_memcell *m){
  
  assert(m->type>=0 && m->type<=undef_m);
  return (*tostringFuncs[m->type]) (m);
  //return strdup(m->data.strVal);
  
}


void avm_registerlibfunc (char* id, library_func_t addr);

void execute_pusharg ( struct instruction* instr ) {
  struct avm_memcell* arg = avm_translate_operand(instr->arg1, &ax);
  struct avm_memcell* res = &stack[top];
  assert(arg);
  printf("\n%s",instr->result->name);
//   avm_assign( &stack[top], arg);
  res->data.strVal=strdup(arg->data.strVal);
  printf("=%s at %d\n",arg->data.strVal,top);
  printf("Param \"%s\" saved to %d\n",arg->data.strVal,top);
  
  ++totalActuals;
  avm_dec_top();
}