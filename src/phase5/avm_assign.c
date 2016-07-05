#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "avm_assign.h"



void avm_assign(struct avm_memcell *lv,struct avm_memcell *rv){
//   printf("\nYO\n");
  if(lv==rv){	/*same cells*/
//     printf("MPIKA1\n");
    return;
  }
//   printf("\nYO1 %d %d\n",lv->type,rv->type);
  if(lv->type==table_m && rv->type==table_m && lv->data.strVal==rv->data.strVal){		/*same tables*/
//     printf("MPIKA2\n");
    return;
  }
//   printf("\nYO2\n");
  
  
  if(rv->type==undef_m){		/*warning for undefined r-value*/
//     printf("MPIKA3\n");
    avm_warning("assign from undef content!");
  }
  
  avm_memcellclear(lv);	/*clear old cells contents*/
  
  memcpy(lv,rv,sizeof(struct avm_memcell));	/*in c++ dispatch instead*/
  
  
  
  /*
   * NOW take care of copied values or reference counting
   * */
//   printf("\nYO\n");
//   printf("\n It is %d\n",lv->type);
  if(lv->type==string_m){
    lv->data.strVal=strdup(rv->data.strVal);
    printf("=%s\n",lv->data.strVal);
  }
  
  if(lv->type==global_a){
//     printf("\nYO\n");
      lv=rv;
      printf("=%f\n",lv->data.numVal);
  }
  
  if(lv->type==local_a){
//       printf("\nYO\n");
      lv=rv;
      printf("=%f\n",lv->data.numVal);
  }
  
  if(lv->type==bool_m){
      lv=rv;
      printf("=%s\n",bool_array[lv->data.boolVal]);
  }
  
  
  if(lv->type==table_m){
//     printf("MPIKA6\n");
//     avm_tableincrefcounter(lv->data.strVal);
  }
  
  
  
  
  
}