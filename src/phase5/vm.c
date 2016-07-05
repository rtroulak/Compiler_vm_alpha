#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"


extern void execute_arithmetic (struct instruction* instr);
extern void execute_assign(struct instruction* inst);
extern void execute_jeq(struct instruction* instr);
extern void execute_jump(struct instruction* instr);
extern void execute_eq_assign(struct instruction* instr);
void execute_jeq(struct instruction* instr);
void execute_jump(struct instruction* instr);
void execute_eq_assign(struct instruction* instr); //perister new
void execute_jlt(struct instruction* instr);

void execute_jle(struct instruction* instr); //perister new
void execute_jge(struct instruction* instr);
void execute_jgt(struct instruction* instr);
void execute_jne(struct instruction* instr);
struct instruction* code;


typedef void (*execute_func_t)(struct instruction *);
typedef void (*memclear_func_t)(struct avm_memcell*);

/*insssssssssssssssssss*/


execute_func_t executeFuncs[] = {
   execute_assign,
   execute_add,
   execute_sub,
   execute_mul,
   execute_div,
   execute_mod,
//     execute_uminus,
//     execute_and,
//     execute_or,
//     execute_not,
 
    0, 
    execute_jeq,
   execute_jne,
     
//   
     execute_jle,
     execute_jge,
     execute_jlt,
     execute_jgt,
  
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   execute_jump,0,execute_eq_assign
};






char* avmtypes[8] = {
	"number_m",
	"string_m",
	"bool_m",
	"table_m",
	"userfunc_m",
	"libfunc_m",
	"nil_m","undef_m"
};

char* vmarg_array[11] = {  
  ""
  "global",
  "local",
  "formal",
  "boolean",
  "string",
  "constnum",
  "number",
  "userfunc",
  "libfunc",
  "retval_a",
  "nil"
};

char* bool_array[3] = {
      ""
      "true",
      "false",
      "null"
};


double 	 consts_getnumber (unsigned  index){
    int counter=0;
    struct instruction *quad_elem;
    quad_elem=instructions;
    while( counter < currQuadvm ){
    
	if( quad_elem->arg1 != NULL && quad_elem->arg1->type==number_a && quad_elem->arg1->name != NULL ){
	  if(quad_elem->arg1->val != -1 && strcmp(quad_elem->arg1->name,"#") != 0 ){
	    if( quad_elem->arg1->val == index && quad_elem->arg1->name != NULL ){
	      return atoi(quad_elem->arg1->name);
	    }
	  }
	}
	if( quad_elem->arg2 != NULL && quad_elem->arg2->type==number_a && quad_elem->arg2->name != NULL ){
	  if(quad_elem->arg2->val!=-1 && strcmp(quad_elem->arg2->name,"#") != 0 ){
	    if( quad_elem->arg2->val == index && quad_elem->arg2->name != NULL ){
	      return atoi(quad_elem->arg2->name);
	    }
	  }
	}
	if( quad_elem->result!=NULL && quad_elem->result->type==number_a && quad_elem->result->name != NULL ){
	    if(quad_elem->result->val!=-1 && strcmp(quad_elem->result->name,"#") != 0 ){
	      if( quad_elem->result->val == index &&  quad_elem->result->name != NULL ){
		return atoi(quad_elem->result->name);
	      }
	    }
	}
    
	counter++;
	quad_elem++;
      }
      return -111;
}
char*	consts_getstring (unsigned  index){    int counter=0;
    struct instruction *quad_elem;
    quad_elem=instructions;
    while( counter < currQuadvm ){
    
	if( quad_elem->arg1 != NULL && quad_elem->arg1->type==string_a && quad_elem->arg1->name != NULL ){
	  if(quad_elem->arg1->val != -1 && strcmp(quad_elem->arg1->name,"#") != 0 ){
	    if( quad_elem->arg1->val == index && quad_elem->arg1->name != NULL ){
	      return quad_elem->arg1->name;
	    }
	  }
	}
	if( quad_elem->arg2 != NULL && quad_elem->arg2->type==string_a && quad_elem->arg2->name != NULL ){
	  if(quad_elem->arg2->val!=-1 && strcmp(quad_elem->arg2->name,"#") != 0 ){
	    if( quad_elem->arg2->val == index && quad_elem->arg2->name != NULL ){
	      return quad_elem->arg2->name;
	    }
	  }
	}
	if( quad_elem->result!=NULL && quad_elem->result->type==string_a && quad_elem->result->name != NULL ){
	    if(quad_elem->result->val!=-1 && strcmp(quad_elem->result->name,"#") != 0 ){
	      if( quad_elem->result->val == index &&  quad_elem->result->name != NULL ){
		return quad_elem->result->name;
	      }
	    }
	}
    
	counter++;
	quad_elem++;
      }
  return NULL;
}
char*	libfuncs_getused (unsigned  index){return NULL;}




struct avm_memcell* avm_translate_operand( struct vmarg* arg, struct avm_memcell* reg){
  switch (arg->type){
      /*Variables*/
      case global_a :
// 		printf("\nYOLO\n");
		printf("%s %d\n",arg->name,arg->type);
		
	 	return(&stack[AVM_STACKSIZE-1-arg->val]);
      case local_a :
	 	return(&stack[topsp-arg->val]);
      case formal_a :
// 	 	return(&stack[topsp+AVM_STACKENV_SIZE+avm_totalactuals()-arg->val+1]);
      case retval_a :
	 	return(&retval);
      case number_a :
// 		printf("\nYOLO2\n");
	 	reg->type = number_m;
	 	reg->data.numVal=consts_getnumber(arg->val);
	 	return reg;	 
      case string_a :
	 	reg->type = string_m;
	 	reg->data.strVal=consts_getstring(arg->val);
		printf("cool");
	 	return reg;
      case bool_a :
	 	reg->type = bool_m;
	 	reg->data.boolVal=arg->val;
	 	return reg;
      case nil_a :
	 	reg->type = nil_m;
	 	return reg;
      case userfunc_a :
	 	reg->type = userfunc_m;
	 	reg->data.funcVal = arg->val;
	 	return reg;
      case libfunc_a :
	 	reg->type = libfunc_m;
	 	reg->data.libfuncVal=libfuncs_getused(arg->val);
	 	return reg;
      default :
	 	assert(0);
   }
}



void execute_cycle(void) {
  
   if (executionFinished)
      return;
   else if(pc == AVM_ENDING_PC){
	
         executionFinished = 1;
         return;
   }
   else {
     
      assert(pc < AVM_ENDING_PC);
      
      struct instruction* instr = code + pc;
     
      
      assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUNCTIONS);
        
      if(instr -> srcLine)
         currLine = instr->srcLine;
      unsigned oldPC = pc; 
      (*executeFuncs[instr->opcode]) (instr);
      printf("\n--------------------------\n");
      if( pc == oldPC )
         ++pc;
   }
}


//========================================================================
// CLEAR

memclear_func_t memclearFuncs[]={
  0,/*number*/
  memclear_string,
  0,/*bool*/
  memclear_table,
  0,/*userfunc*/
  0,/*libfunc*/
  0,/*nil*/
  0/*undef*/
};

void avm_memcellclear(struct avm_memcell* m){
  if( m->type != undef_m ){
    memclear_func_t f=memclearFuncs[m->type];
    if (f)
      (*f)(m);
    m->type=undef_m;
  }
}

extern void memclear_string (struct avm_memcell* m){
  assert(m->data.strVal);
  free(m->data.strVal);
}
extern void memclear_table (struct avm_memcell* m){
  assert(m->data.tableVal);
  //avm_tabledecrefcounter(m->data.tableVal);
}

//========================================================================
//CLEAR

static void avm_initstack(void){
  unsigned i;
  for(i=0;i<AVM_STACKSIZE;++i){
    AVM_WIPEOUT(stack[i]);
    stack[i].type = undef_m;
  }
}

void avm_error(char* msg){
  printf("\nerror: %s\n",msg);
}

void avm_warning(char* msg){
  printf("\nwarning: %s\n",msg);
}

int read_bin(){
    FILE* fh;
    int op;
    int arg1_val;
    int arg2_val;
    int res_val;
    int arg1_type;
    int arg2_type;
    int res_type;
    char* arg1_name;
    char* arg2_name;
    char* result_name;
    int srcLine;
    int len;
    int counter=0;
    
    struct vmarg *v_arg1=NULL;
    struct vmarg *v_arg2=NULL;
    struct vmarg *v_result=NULL;
    fh = fopen ("file.bin", "rb");
/*    
    fread (&op, sizeof (int), 1, fh);
    arg1_name=malloc(sizeof(char)*op);
    fread (arg1_name, sizeof (char), op, fh);
    printf ("Value is: %s\n", arg1_name);*/
    
    while(1){
      if (fh != NULL) {
	  fread (&op, sizeof (op), 1, fh);
	  if( op == -3821 ){
	    return 0;
	  }
	  if( op == 26 ){
	    op=0;
	  }
	  
	  //arg1
	  fread (&arg1_type, sizeof (arg1_type), 1, fh);
	  if( arg1_type == -3821 ){
	    return 0;
	  }
	  fread (&arg1_val, sizeof (arg1_val), 1, fh);
	  if( arg1_val == -3821 ){
	    return 0;
	  }
	  fread (&len, sizeof (int), 1, fh);
	  arg1_name=malloc(sizeof(char)*len);
	  fread (arg1_name, sizeof (char), len, fh);
	  
	  //arg2
	  fread (&arg2_type, sizeof (arg2_type), 1, fh);
	  if( arg2_type == -3821 ){
	    return 0;
	  }
	  fread (&arg2_val, sizeof (arg2_val), 1, fh);
	  if( arg2_val == -3821 ){
	    return 0;
	  }
	  fread (&len, sizeof (int), 1, fh);
	  arg2_name=malloc(sizeof(char)*len);
	  fread (arg2_name, sizeof (char), len, fh);

	  //result
	  fread (&res_type, sizeof (res_type), 1, fh);
	  if( res_type == -3821 ){
	    return 0;
	  }
	  fread (&res_val, sizeof (res_val), 1, fh);
	  if( res_val == -3821 ){
	    return 0;
	  }
	  
	  
	  fread (&len, sizeof (int), 1, fh);
	  result_name=malloc(sizeof(char)*len);
	  fread (result_name, sizeof (char), len, fh);
	   fread (&srcLine, sizeof (int), 1, fh);
	  
	  
	  
      }

      /* Check that it worked */
//       printf("\nsrcLine=%d\n",srcLine);
      printf ("Value is: %d %s %d [%s] %s %d [%s] %s %d [%s]\n", op, vmarg_array[arg1_type],arg1_val,arg1_name,vmarg_array[arg2_type],arg2_val,arg2_name,vmarg_array[res_type],res_val,result_name);
      v_arg1=create_vmarg(arg1_type, arg1_val ,arg1_name);
      v_arg2=create_vmarg(arg2_type, arg2_val ,arg2_name);
      v_result=create_vmarg(res_type,res_val ,result_name);
      create_instr(op,v_result, v_arg1,v_arg2);
    }
    
    fclose (fh);
    return 0;
}

struct vmarg *create_vmarg( enum vmarg_t type, unsigned val ,char* name ){
  struct vmarg *new_vmarg=malloc(sizeof(struct vmarg));
  new_vmarg->type=type;
  new_vmarg->val=val;
  new_vmarg->name=strdup(name);//??
  new_vmarg->func_name=NULL;  //??

  return new_vmarg;
}

void create_instr(enum vmopcode opcode, struct vmarg* result, struct vmarg* arg1, struct vmarg* arg2){
  if( currQuadvm == totalvm )
    expandvm();
  struct instruction* new_instruction=instructions+currQuadvm++;
  
  new_instruction->opcode=opcode;
  new_instruction->result=result;
  new_instruction->arg1=arg1;
  new_instruction->arg2=arg2;
  no_instructions++;    
  return;
   
}
  
void expandvm(void){
  assert(totalvm==currQuadvm);
  struct instruction* p=(struct instruction*) malloc(NEW_SIZEvm);
  if(instructions){
    memcpy(p,instructions,CURR_SIZEvm);
    free(instructions);
  }
  instructions=p;
  totalvm +=EXPAND_SIZEvm;
}


int main(int argc,char** argv){
  printf("\nHELLO WORLD!!!\n");
  top=0;
  executionFinished = 0 ;
  pc = 0; 
  currLine = 0;
  codeSize = 1;
  read_bin();
  code=instructions;
  AVM_ENDING_PC=no_instructions;

  no_instructions=0;
  
  
  while( executionFinished == 0 ){
    execute_cycle();
  }
//   int counter=4096;
//   while(counter>4093){
//     printf("-%s-",stack[counter].data.strVal);
//   }
  
  
  printf("\n");
  return 0;
}








