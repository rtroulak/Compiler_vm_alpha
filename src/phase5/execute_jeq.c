#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "execute_jeq.h"

void execute_jeq(struct instruction* instr)
{
  //assert(instr->result->type==label_a);
  printf("YOLO JEQ\n");
 
   struct avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
   struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);
      unsigned char result=0;
  
       if(rv1->type==undef_m||rv2->type==undef_m)
       {avm_error("'undef' involved in equality!");}
  
  else if(rv1->type==nil_m||rv2->type==nil_m)
  {result=rv1->type==nil_m &&rv2->type==nil_m;}
  
  else if(rv1->type==bool_m||rv2->type==bool_m)
  {result=(avm_tobool(rv1)==avm_tobool(rv2));}
    else if(rv1->type!=rv2->type)
    avm_error("%S==%S IS ILLEGAL");
  
  else 
   {  
      }
  
     if(!executionFinished &&result)
    pc=instr->result->val;
  
} 
 