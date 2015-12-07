#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "execute_arithmetic.h"

typedef double (*arithmetic_func_t)(double x,double y);

double add_impl(double x,double y){
  printf("\n [ %f + %f ] \n",x,y);
  return x+y;
  
}

double sub_impl(double x,double y){
  printf("\n [ %f - %f ] \n",x,y);
  return x-y;
  
}

double mul_impl(double x,double y){
  printf("\n [ %f * %f ] \n",x,y);
  return x*y;
  
}
double div_impl(double x,double y){
  if(y==0)
  {
    printf("Error you cannot divide with zero y!!\n");
    return 0;
    
  }
  printf("\n [ %f / %f ] \n",x,y);
  return x/y;
  
}
double mod_impl(double x,double y){
  unsigned xi=x;	
  unsigned yi=y;
  printf("\n [ %f %% %f ] ",x,y);
  return xi%yi;
  
}


arithmetic_func_t arithmeticFuncs[]={
  add_impl,sub_impl,mul_impl,div_impl,mod_impl
};





void execute_arithmetic (struct instruction* instr){
	
	struct	avm_memcell* lv = avm_translate_operand(instr->result,(struct avm_memcell*)0);
	struct	avm_memcell* rv1= avm_translate_operand(instr->arg1, &ax);
	struct avm_memcell* rv2= avm_translate_operand(instr->arg2, &bx);

// 	assert(lv && ( (&stack[AVM_STACKSIZE]>= lv && &stack[top]<lv )|| lv==&retval ));
	assert(rv1 && rv2);

	if (rv1->type !=number_m || rv2->type !=number_m ){
		avm_error("not a number arithmetic!\n");
		executionFinished=1;
	}
	else{
		arithmetic_func_t op=arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal,rv2->data.numVal);
		printf("= %f\n",lv->data.numVal);
	}
	
}