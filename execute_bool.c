#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "execute_bool.h"

typedef unsigned char (*tobool_func_t)(struct avm_memcell*);




unsigned char number_tobool(struct avm_memcell *m){return m->data.numVal!=0; }
unsigned char string_tobool(struct avm_memcell *m){return m->data.strVal[0]!=0;}
unsigned char bool_tobool (struct avm_memcell *m){return m->data.boolVal;}
unsigned char table_tobool (struct avm_memcell *m){return 1;}
unsigned char userfunc_tobool(struct avm_memcell *m){return 1;}
unsigned char libfunc_tobool (struct avm_memcell *m){return 1;}
unsigned char nil_tobbol(struct avm_memcell *m){return 0;}
unsigned char undef_tobool(struct avm_memcell *m){assert(0);return 0;}

tobool_func_t toboolFuncs[]={
   number_tobool,
   string_tobool,
   bool_tobool,
   table_tobool,
   userfunc_tobool,
   libfunc_tobool,
   nil_tobbol,
   undef_tobool
  
};

unsigned char avm_tobool(struct avm_memcell* m)
{
 assert(m->type>=0 && m->type<undef_m); 
  return(*toboolFuncs[m->type])(m);
}


  
  char *typeStrings[]={
     "number",
     "string",
     "bool",
     "table",
     "userfunc",
     "libfunc",
     "nill",
     "undef"
  };
  
  
void execute_jeq(struct instruction* instr)
{
  
  //assert(instr->result->type==label_a);
//   printf("\nJEQ\n");
 
   struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
   unsigned int result=0;
      unsigned int pc_old=pc;
      
   if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {
    result=rv1->type==nil_m &&rv2->type==nil_m;
  }
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
    printf("(jeq)Check %d with %d\n", rv1->data.boolVal,rv2->data.boolVal);
//     printf("Check %d with %d\n", avm_tobool(rv1),avm_tobool(rv2));
    if(  rv1->data.boolVal == rv2->data.boolVal )
    {
      printf("TRUE\n",rv1->data.boolVal);
      result=1;   
    }
    else
    {
	printf("FALSE\n",rv1->data.boolVal);
	result=0;
    }
    if(result==1)
    { if(res->data.numVal!=-666)
      {
        pc=(unsigned int)res->data.numVal-1;
      }
      else{
	pc=AVM_ENDING_PC;
      }
      
      
     
    }
    
    
  }
  else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
   {
     
      }
   printf("Jumped from %u to %u\n",pc_old,pc);
} 


void execute_jump(struct instruction* instr){
  
  struct avm_memcell* res= avm_translate_operand(instr->result, &ax);

  if(res->data.numVal!=-666)
      {
        pc=(unsigned int)res->data.numVal-1;
      }
       else{
	pc=AVM_ENDING_PC;
      }
  
  printf("Normal Jumped TO %u \n",pc);
  
}
 
 
void execute_eq_assign(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned int result=0;
  
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
    
    if(rv1->data.boolVal + rv2->data.boolVal==1){
      result=1;
    }
    else{
      
      result=0;
    }
  
    res->data.boolVal=result;
    //result=(avm_tobool(rv1)==avm_tobool(rv2));
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf(" (eq assign) Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
       if(rv1->data.numVal==rv2->data.numVal)
      {
	printf("EQUALS\n");
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT EQUALS\n");
	res->data.boolVal=1;
      } 
   } 
}














void execute_jlt(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned char result=0;
//      printf("JLT\n");
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
       avm_error("BOOLEAN  IS ILLEGAL,ONLY NUMBERS");
         executionFinished = 1 ;
    //result=(avm_tobool(rv1)==avm_tobool(rv2));
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf("Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
       if(rv1->data.numVal<rv2->data.numVal)
      {
	printf("IS '<' \n");
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT '<'\n");
	res->data.boolVal=1;
      } 
   }
}




void execute_jgt(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned char result=0;
//      printf("JGT\n");
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
       avm_error("BOOLEAN  IS ILLEGAL,ONLY NUMBERS");
         executionFinished = 1 ;
    //result=(avm_tobool(rv1)==avm_tobool(rv2));
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf("Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
       if(rv1->data.numVal>rv2->data.numVal)
      {
	printf("IS '>'\n");
	printf("%s",instr->result->name);
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT '<'\n");
	res->data.boolVal=1;
      } 
   }
}













void execute_jge(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned char result=0;
//      printf("JGE\n");
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
  //  result=(avm_tobool(rv1)==avm_tobool(rv2));
       avm_error("BOOLEAN  IS ILLEGAL,ONLY NUMBERS");
         executionFinished = 1 ;
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf("Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
            if((rv1->data.numVal>rv2->data.numVal)||(rv1->data.numVal==rv2->data.numVal))
      {
	printf("'>='\n");
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT '>='\n");
	res->data.boolVal=1;
      } 
   }
}





void execute_jle(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned char result=0;
   printf("JLE\n");
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
      avm_error("BOOLEAN  IS ILLEGAL,ONLY NUMBERS");
        executionFinished = 1 ;
    // result=(avm_tobool(rv1)==avm_tobool(rv2));
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf("Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
       if((rv1->data.numVal<rv2->data.numVal)||(rv1->data.numVal==rv2->data.numVal))
      {
	printf("IS '<='\n");
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT '<='\n");
	res->data.boolVal=1;
      } 
   }
}





void execute_jne(struct instruction* instr){
  struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
   struct avm_memcell* res= avm_translate_operand(instr->result, &cx);
      unsigned char result=0;
//    printf("JNE\n");
       if(rv1->type==undef_m||rv2->type==undef_m)
       {
// 	 avm_error("'undef' involved in equality!");
      }
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {
    result=(avm_tobool(rv1)!=avm_tobool(rv2));
    
  }
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else //perister 
    {  printf("Check %f with ",rv1->data.numVal);
      printf("%f\n",rv2->data.numVal);
      
       if( rv1->data.numVal!=rv2->data.numVal)
      {
	printf(" IS '!='\n");
	res->data.boolVal=0;}
     
      else
      {
	printf("NOT '!='\n");
	res->data.boolVal=1;
      } 
   }
}















