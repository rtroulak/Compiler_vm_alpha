#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "quads.h"


extern int arraysnot;
extern int exprnoname;
extern char bufferforexpr[9],nonameexpr[20],exprdefault[2];
extern int lineofnewfile;
extern int  global_a_counter,
  local_a_counter,
  formal_a_counter,
  bool_a_counter,
  string_a_counter,
  constnum_a_counter,
  number_a_counter,
  userfunc_a_counter,
  libfunc_a_counter,
  nil_a_counter;

  
int flag_global_a=0,
  flag_local_a=0,
  flag_formal_a=0,
  flag_string_a=0,
  flag_constnum_a=0,
  flag_number_a=0,
  flag_userfunc_a=0,
  flag_libfunc_a=0;
  
void print_lines(){
  printf("\n====================================================================================================================\n");
  printf("====================================================================================================================\n");
  return;
}
void print_quad (struct quad *quad_elem){
    int counter=0;
    printf("\n\n\n------------------------------------------QUADS----------------------------------\n\n");
    printf( "Operation			Result		Arg1		Arg2		Label		Line		IntermLine	 NoVars		Offset\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while( counter < currQuad ){
      printf("%-35s",iopcode_array[quad_elem->op]);
      
	if( quad_elem->result != NULL ){
	  if(quad_elem->result->sym!=NULL)
	  printf("%-16s",quad_elem->result->sym->name);
	}
	else
	  printf("%-16s","Unused");
      
      if( quad_elem->arg1 != NULL ){
	if( quad_elem->arg1->sym != NULL )
	  printf("%-18s",quad_elem->arg1->sym->name);
	else if( quad_elem->arg1->strConst != NULL )
	  printf("%-18s",quad_elem->arg1->strConst);
	else if( quad_elem->arg1->boolConst != null )
	  printf("%-18s",bool_array[quad_elem->arg1->boolConst]);
	else
	  printf("%-18f",quad_elem->arg1->numConst);
      }
      else
	printf("%-18s","Unused");
      
      if( quad_elem->arg2 != NULL ){
	if( quad_elem->arg2->sym != NULL )
	  printf("%-18s",quad_elem->arg2->sym->name);
	else if( quad_elem->arg2->strConst != NULL )
	  printf("%-18s",quad_elem->arg2->strConst);
	else if( quad_elem->arg2->boolConst != null )
	  printf("%-18s",bool_array[quad_elem->arg2->boolConst]);
	else
	  printf("%-18f",quad_elem->arg2->numConst);
      }
      else
	printf("%-18s","Unused");
      
     
      
      printf("%-16d",quad_elem->label);
      printf("%-16d",quad_elem->line);
      printf("%-16d",quad_elem->iline);
      if(quad_elem->arg1!=NULL){
	if(quad_elem->arg1->NumberOfLocalVar!=0)
	  printf("%-16d",quad_elem->arg1->NumberOfLocalVar);
	if(quad_elem->arg1->sym!=NULL){
	if(quad_elem->arg1->sym->offset!=0)
	  printf("%-16d",quad_elem->arg1->sym->offset);
	}
     }
     
      if(quad_elem->result!=NULL){
	if(quad_elem->result->NumberOfLocalVar!=0)
	  printf("%-16d",quad_elem->result->NumberOfLocalVar);
	else
	   printf("%-16c",' ');
	if(quad_elem->result->sym!=NULL){
	if(quad_elem->result->sym->offset!=0)
	  printf("%-16d",quad_elem->result->sym->offset);
	else
	   printf("%-16c",' ');
	}
     }
     
      

      printf("\n");

      quad_elem++;
      counter++;
    }
    printf("\n\n");
    
    return;
}

void produce_quad (struct quad *quad_elem){
    int counter=0;
    
      lineofnewfile=1;
      FILE *ifp, *ofp;
      char *mode = "r";
      char outputFilename[] = "IntermediateCode.my";
      
      
     
	      
      
      ifp = fopen(outputFilename, "w"); /*create the new file*/
      /*fputs(name,ifp);*/ /*write the players name to the file*/
    while( counter < currQuad ){
      if( quad_elem == NULL )
	break;
      
      
      fprintf (ifp, "%d: %s ",lineofnewfile,iopcode_array[quad_elem->op]);
      if(quad_elem->label!=0){
	
	fprintf (ifp, "%d ",quad_elem->label);
	
      }
      
      if(quad_elem->arg1!=NULL){
	  if(quad_elem->arg1->sym!=NULL)
	    fprintf (ifp, "%s ",quad_elem->arg1->sym->name);
	  else if( quad_elem->arg1->strConst != NULL )
	    fprintf(ifp,"%s ",quad_elem->arg1->strConst);
	  else if( quad_elem->arg1->boolConst != null )
	    fprintf(ifp,"%s ",bool_array[quad_elem->arg1->boolConst]);
	  else
	    fprintf (ifp, "%f ",quad_elem->arg1->numConst);
      }
      if(quad_elem->arg2!=NULL){
	  if(quad_elem->arg2->sym!=NULL)
	    fprintf (ifp, "%s ",quad_elem->arg2->sym->name);
	  else if( quad_elem->arg2->strConst != NULL )
	    fprintf(ifp,"%s ",quad_elem->arg2->strConst);
	  else if( quad_elem->arg2->boolConst != null )
	    fprintf(ifp,"%s ",bool_array[quad_elem->arg2->boolConst]);
	  else
	    fprintf (ifp, "%f ",quad_elem->arg2->numConst);
      }
      if(quad_elem->result!=NULL){
	  if(quad_elem->result->sym!=NULL)
	    fprintf (ifp, "%s ",quad_elem->result->sym->name);
	  else
	    fprintf (ifp, "%f ",quad_elem->result->numConst);
      }
      fprintf(ifp, "\n");
      lineofnewfile++;
      counter++;
      quad_elem++;
    }
    fclose(ifp); /*close the file*/
}


void produce_finalquad (struct instruction *quad_elem){
    int counter=0;
    
      lineofnewfile=1;
      FILE *ifp;
      char outputFilename[] = "FinalCode.my";
      
      
     
	      
      
      ifp = fopen(outputFilename, "w"); /*create the new file*/
      /*fputs(name,ifp);*/ /*write the players name to the file*/
    while( counter < currQuadvm ){
      if( quad_elem == NULL )
	break;
      
      if(strcmp(vmopcode_array[quad_elem->opcode],"FUNCSTART")==0){
	  fprintf (ifp, "%-3d| %-20s",quad_elem->srcLine,"ENTERFUNC");
	  printf("NAME=%s\n",quad_elem->result->func_name);
	  push(0,"_",quad_elem->result->func_name);
	  
      
      }
        else if(strcmp(vmopcode_array[quad_elem->opcode],"FUNCEND")==0){
	  fprintf (ifp, "%-3d| %-20s",quad_elem->srcLine,"EXITFUNC");
	  returnListLookUp(returnLists,top->function_name,quad_elem->srcLine);
	  printf("Egine pop to=%s me line=%d\n",top->function_name,quad_elem->srcLine);
	  pop();
      
      }
      else if(strcmp(vmopcode_array[quad_elem->opcode],"ASSING")==0){
	
	 fprintf (ifp, "%-3d| %-20s",quad_elem->srcLine,"ASSIGN");

	
	if(top!=NULL){
	  returnListInsert(returnLists,0,top->function_name,quad_elem->result->name);
	}
	
      }else{
	
	fprintf (ifp, "%-3d| %-20s",quad_elem->srcLine,vmopcode_array[quad_elem->opcode]);
      }
      
      
      
      if(quad_elem->arg1!=NULL){
	if(quad_elem->arg1->val!=-1 && quad_elem->arg1->type<15 )
	    fprintf (ifp, "%s:%d 		",vmarg_array[quad_elem->arg1->type],quad_elem->arg1->val);
	else{
	    fprintf (ifp,"			");
	}    
      }
      if(quad_elem->arg2 !=NULL && quad_elem->arg2->type<15){
	if(quad_elem->arg2->val!=-1)
	    fprintf (ifp, "%s:%d 		",vmarg_array[quad_elem->arg2->type],quad_elem->arg2->val);
	else{
	    fprintf (ifp,"			");
	}
      }
      
      if(quad_elem->result!=NULL && quad_elem->result->type<15){
// 	printf("Will print result \n");
	if(quad_elem->result->val!=-1)
	    fprintf (ifp, "%s:%d 		",vmarg_array[quad_elem->result->type],quad_elem->result->val);
	else{
	    fprintf (ifp,"			");
	}
      }
      
	
	
      
      
      
      
      fprintf(ifp, "\n");
      lineofnewfile++;
      counter++;
      quad_elem++;
    }
  if(arraysnot==1){
    
    if(flag_number_a)
    print_types(number_a);
    if(flag_global_a)
    print_types(global_a);
    if(flag_local_a)
    print_types(local_a);
    if(flag_formal_a)
    print_types(formal_a);
    if(flag_string_a)
    print_types(string_a);
    if(flag_userfunc_a)
    print_types(userfunc_a);
    if(flag_libfunc_a)
    print_types(libfunc_a);
    }
    fclose(ifp); /*close the file*/
}

print_types(enum vmarg_t type){
  
  
      FILE *ifp;
      char outputFilename[] = "FinalCode.my";
      
      
     
	  
      
      ifp = fopen(outputFilename, "a"); /*create the new file*/
      
    
    fprintf(ifp,"\n\n\n\n\n\n\n\n-----------------------------------------------------\n[%s]\n-----------------------------------------------------\n",vmarg_array[type]);
  int counter=0;
  struct instruction *quad_elem;
  quad_elem=instructions;
  while( counter < currQuadvm ){
  
      if( quad_elem->arg1 != NULL && quad_elem->arg1->type==type && quad_elem->arg1->name != NULL ){
	if( quad_elem->arg1->val != -1 && strcmp(quad_elem->arg1->name,"#") != 0 ){
	  fprintf(ifp,"%d	::	",quad_elem->arg1->val);
	  if( quad_elem->arg1->name != NULL ){
	    if(quad_elem->arg1->type==string_a)
	      fprintf(ifp,"\"%s\"\n",quad_elem->arg1->name);
	    else
	      fprintf(ifp,"%s\n",quad_elem->arg1->name);
	  }
	  else
	    fprintf(ifp,"\n");
	}
      }
      if( quad_elem->arg2 != NULL && quad_elem->arg2->type==type && quad_elem->arg2->name != NULL ){
	if(quad_elem->arg2->val!=-1 && strcmp(quad_elem->arg2->name,"#") != 0 ){
	  fprintf(ifp,"%d	::	",quad_elem->arg2->val);
	  if( quad_elem->arg2->name != NULL ){
	    if(quad_elem->arg2->type==string_a)
	      fprintf(ifp,"\"%s\"\n",quad_elem->arg2->name);
	    else
	      fprintf(ifp,"%s\n",quad_elem->arg2->name);
	  }
	  else
	    fprintf(ifp,"\n");
	}
      }
      if( quad_elem->result!=NULL && quad_elem->result->type==type && quad_elem->result->name != NULL ){
	  if(quad_elem->result->val!=-1 && strcmp(quad_elem->result->name,"#") != 0 ){
	    fprintf(ifp,"%d	::	",quad_elem->result->val);
	    if( quad_elem->result->name != NULL ){
	      if(quad_elem->result->type==string_a)
		fprintf(ifp,"\"%s\"\n",quad_elem->result->name);
	      else
		fprintf(ifp,"%s\n",quad_elem->result->name);
	    }
	    else
	      fprintf(ifp,"\n");
	  }
      }
  
      counter++;
      quad_elem++;
    }
}

void expand(void){
  assert(total==currQuad);
  struct quad* p=(struct quad*) malloc(NEW_SIZE);
  if(quads){
    memcpy(p,quads,CURR_SIZE);
    free(quads);
  }
  quads=p;
  total +=EXPAND_SIZE;
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

void emit(
     enum iopcode  op,
     struct expr*    arg1,
     struct expr*    arg2,
     struct expr*     result,
     unsigned int   label,
     unsigned int     iline,
     unsigned int     line
	 ){
  if( currQuad == total )
    expand();
  struct quad* p=quads+currQuad++;
  p->op=op;
  p->arg1=arg1;
  p->arg2=arg2;
  p->result=result;
  p->label=label;
  p->line=line; 
  p->iline=iline; 

	   
}

void produce_ins(struct quad *quad_elem){

  int counter=0;
  int line_counter=1;
  struct vmarg* try2;
  struct vmarg* try3;
  struct vmarg* try4;

  while(counter< currQuad){
  //produce instructions
  
  
  if(strcmp(vmopcode_array[quad_elem->op],"GETRETURNVAL")==0){
    counter++;
    quad_elem++;
    continue;
    
  }
  
  if( currQuadvm == totalvm )
    expandvm();
  struct instruction* ps=instructions+currQuadvm++;
  
  
  ps->opcode=quad_elem->op;
  
   
  

  
  
  
   if( quad_elem->op==IF_EQ ){
     int test_int=0;
      if( quad_elem->result == NULL ){//PERIPTWSI JUMP
	  
// 	    printf("\Elegxos %s gia jump\n",quad_elem->arg1->sym->name);
	//arg1
	if(quad_elem->arg1 !=NULL){
	      if( quad_elem->arg1->sym != NULL && quad_elem->arg1->sym->name != NULL && '_' == quad_elem->arg1->sym->name[0] && 't' == quad_elem->arg1->sym->name[1]  ){
		
		try2=find_temp(quad_elem->arg1->sym->name,instructions);
	      }
	      else if( quad_elem->arg1->sym != NULL){
		test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
		if( test_int == 1 ){
		  printf("\nANAFORA %s\n",quad_elem->arg1->sym->name);
		  try2=clean_make_operand(quad_elem->arg1);
		}
		else{
		  printf("\nFtiaksimo %s\n",quad_elem->arg1->sym->name);
		  try2=make_operand(quad_elem->arg1);
		}
	      }
	      else{
		try2=NULL;
	      }
	      ps->arg1=try2;
	  }
	  test_int=0;
	  
	  
	  //arg2
	  if(quad_elem->arg2 !=NULL){
	      if( quad_elem->arg2->sym != NULL && quad_elem->arg2->sym->name != NULL && '_' == quad_elem->arg2->sym->name[0] && 't' == quad_elem->arg2->sym->name[1]  ){
		
	      try3=find_temp(quad_elem->arg2->sym->name,instructions);
	      }
	      else if( quad_elem->arg2->sym != NULL){
		test_int=check_arg(quad_elem->arg2->sym->name,quad_elem->arg2->type,instructions);
		if( test_int == 1 ){
		   printf("\nANAFORA %s\n",quad_elem->arg2->sym->name);
		  try3=clean_make_operand(quad_elem->arg2);
		}
		else{
		   printf("\nAssign %s\n",quad_elem->arg2->sym->name);
		  try3=make_operand(quad_elem->arg2);
		}
		if(quad_elem->arg2!=NULL && quad_elem->arg2->sym!=NULL)
		try3->func_name=strdup(quad_elem->arg2->sym->name);
		
	      }
	      else{
		try3=make_operand(quad_elem->arg2);
	      }
	      ps->arg2=try3;
	  }
	  test_int=0;
	  
	  //result
	  try4=make_operand(constnewexpr(costnum_e,-2));
	  ps->result=try4;
	  ps->srcLine=line_counter;
	  add_incomplete_jump(ps->srcLine,quad_elem->label);  //new perister
	  quad_elem->taddress=ps->srcLine;
	  line_counter++;
      }
      else{//PERIPTWSI ASSIGN
	ps->opcode=EQ_ASSIGN;
	  
// 	    printf("\Elegxos %s gia assign\n",quad_elem->arg1->sym->name);
	//arg1
	if(quad_elem->arg1 !=NULL){
	      if( quad_elem->arg1->sym != NULL && quad_elem->arg1->sym->name != NULL && '_' == quad_elem->arg1->sym->name[0] && 't' == quad_elem->arg1->sym->name[1]  ){
		
	      try2=find_temp(quad_elem->arg1->sym->name,instructions);
	      }
	      else if( quad_elem->arg1->sym != NULL){
		test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
		if( test_int == 1 ){
		   printf("\nANAFORA %s\n",quad_elem->arg1->sym->name);
		  try2=clean_make_operand(quad_elem->arg1);
		}
		else{
		   printf("\nAssign %s\n",quad_elem->arg1->sym->name);
		  try2=make_operand(quad_elem->arg1);
		}
		if(quad_elem->arg1!=NULL && quad_elem->arg1->sym!=NULL)
		try2->func_name=strdup(quad_elem->arg1->sym->name);
		
	      }
	      else{
		try2=make_operand(quad_elem->arg1);
	      }
	      ps->arg1=try2;
	  }
	  test_int=0;

	  //arg2
	  if(quad_elem->arg2 !=NULL){
	      if( quad_elem->arg2->sym != NULL && quad_elem->arg2->sym->name != NULL && '_' == quad_elem->arg2->sym->name[0] && 't' == quad_elem->arg2->sym->name[1]  ){
		
	      try3=find_temp(quad_elem->arg2->sym->name,instructions);
	      }
	      else if( quad_elem->arg2->sym != NULL){
		test_int=check_arg(quad_elem->arg2->sym->name,quad_elem->arg2->type,instructions);
		if( test_int == 1 ){
		   printf("\nANAFORA %s\n",quad_elem->arg2->sym->name);
		  try3=clean_make_operand(quad_elem->arg2);
		}
		else{
		   printf("\nAssign %s\n",quad_elem->arg2->sym->name);
		  try3=make_operand(quad_elem->arg2);
		}
		if(quad_elem->arg2!=NULL && quad_elem->arg2->sym!=NULL)
		try3->func_name=strdup(quad_elem->arg2->sym->name);
		
	      }
	      else{
		try3=make_operand(quad_elem->arg2);
	      }
	      ps->arg2=try3;
	  }
	  test_int=0;

	//result
	try4=make_operand(quad_elem->result);
	ps->result=try4;
	ps->srcLine=line_counter;
	quad_elem->taddress=ps->srcLine;
	line_counter++;
      }
   }
   else if( quad_elem->op==jump ){
     ps->opcode=jump;
  
    ps->arg1=NULL;
    ps->arg2=NULL;
 
    try4=make_operand(constnewexpr(costnum_e,-1)); 
    ps->result=try4; //new
    
    ps->srcLine=line_counter;   //incomplete jump,null now
    quad_elem->taddress=ps->srcLine;
     
     add_incomplete_jump(ps->srcLine,quad_elem->label);  //new perister
     
	 
	line_counter++;  //doesnt need
     
    // print_incomplete_jump();
     counter++;
    
    quad_elem++;  
    continue;
     
     
 }  
 else if( quad_elem->op==and ){
    
    
    
      ps->opcode=if_eq;
      int test_int;
      //arg1
      if(quad_elem->arg1 !=NULL){
	    if( quad_elem->arg1->sym != NULL){
	      test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
	      if( test_int == 1 ){
		try2=clean_make_operand(quad_elem->arg1);
	      }
	    else{
	      try2=make_operand(quad_elem->arg1);
	    }
	    if(quad_elem->arg1!=NULL && quad_elem->arg1->sym!=NULL)
	    try2->func_name=strdup(quad_elem->arg1->sym->name);
	    
	  }
	  else{
	    try2=make_operand(quad_elem->arg1);
	  }
	  ps->arg1=try2;
      }
      else{//an den iparxei tote NULL
	ps->arg1=NULL;
      }
      test_int=0;
      ps->arg1=try2;
  
    
      if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
      else{
	try3=make_operand(boolnewexpr(false)); 
      }
	ps->arg2=try3;
	//EDW DES 
	try4=make_operand(constnewexpr(costnum_e,line_counter+4));
	ps->result=try4;
    
	ps->srcLine=line_counter;
	quad_elem->taddress=ps->srcLine;//taddress kleftog
	line_counter++;
      if( currQuadvm == totalvm )   //second
      {expandvm();}
      ps=instructions+currQuadvm++;
   
      ps->opcode=if_eq;
    

      //arg1
      if(quad_elem->arg2 !=NULL){
	    if( quad_elem->arg2->sym != NULL){
	      test_int=check_arg(quad_elem->arg2->sym->name,quad_elem->arg2->type,instructions);
	      if( test_int == 1 ){
		try3=clean_make_operand(quad_elem->arg2);
	      }
	    else{
	      try3=make_operand(quad_elem->arg2);
	    }
	    if(quad_elem->arg2!=NULL && quad_elem->arg2->sym!=NULL)
	    try3->func_name=strdup(quad_elem->arg2->sym->name);
	    
	  }
	  else{
	    try3=make_operand(quad_elem->arg2);
	  }
	  ps->arg1=try3;
      }
      else{//an den iparxei tote NULL
	ps->arg1=NULL;
      }
      test_int=0;
	  
      //arg2
	if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	  try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
	else{
	  try3=make_operand(boolnewexpr(false));
	}
	ps->arg2=try3;
	//EDW DES 
	try4=make_operand(constnewexpr(costnum_e,line_counter+3));
	ps->result=try4;
	
    
	ps->srcLine=line_counter;
	line_counter++;
      if( currQuadvm == totalvm )   //third
      {expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=assign ;
    
	  
      if( quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(boolnewexpr(true));
      }
	ps->arg1=try2;

    

	ps->arg2=NULL;
	
	try4=make_operand(quad_elem->result);
	ps->result=try4;
	ps->srcLine=line_counter; 
	line_counter++;
      if( currQuadvm == totalvm )   //forth
      {
      expandvm();}
      ps=instructions+currQuadvm++;
     
      ps->opcode=jump ;
    
      //DES EDW
      ps->arg1=NULL;
      ps->arg2=NULL;
      //incomplete JUMP
      ps->result=make_operand(constnewexpr(costnum_e,line_counter+2));
      ps->srcLine=line_counter; 
      line_counter++;
      if( currQuadvm == totalvm )   //fifth
      {expandvm();}
      ps=instructions+currQuadvm++;
      
       ps->opcode=assign ;
    
	  
      if( quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(boolnewexpr(false));
      }
      ps->arg1=try2;

      
      
      //result
      if(quad_elem->result !=NULL){
	    if( quad_elem->result->sym != NULL){
	      test_int=check_arg(quad_elem->result->sym->name,quad_elem->result->type,instructions);
	      if( test_int == 1 ){
		try4=clean_make_operand(quad_elem->result);
	      }
	    else{
	      try4=make_operand(quad_elem->result);
	    }
	    if(quad_elem->result!=NULL && quad_elem->result->sym!=NULL)
	    try4->func_name=strdup(quad_elem->result->sym->name);
	    
	  }
	  else{
	    try4=make_operand(quad_elem->result);
	  }
	  ps->result=try4;
      }
      else{//an den iparxei tote NULL
	ps->result=NULL;
      }
      test_int=0;
      ps->result=try4;

      
      ps->srcLine=line_counter; 
      line_counter++;
	
	
    counter++;
    
    quad_elem++;  
    continue;
    
  }
  else if(quad_elem->op==or)
  { printf("Entered or\n");
    
    
     
    
    
      ps->opcode=if_eq;
      int test_int;
      //arg1
      if(quad_elem->arg1 !=NULL){
	    if( quad_elem->arg1->sym != NULL){
	      test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
	      if( test_int == 1 ){
		try2=clean_make_operand(quad_elem->arg1);
	      }
	    else{
	      try2=make_operand(quad_elem->arg1);
	    }
	    if(quad_elem->arg1!=NULL && quad_elem->arg1->sym!=NULL)
	    try2->func_name=strdup(quad_elem->arg1->sym->name);
	    
	  }
	  else{
	    try2=make_operand(quad_elem->arg1);
	  }
	  ps->arg1=try2;
      }
      else{//an den iparxei tote NULL
	ps->arg1=NULL;
      }
      test_int=0;
      ps->arg1=try2;
  
    
      if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
      else{
	try3=make_operand(boolnewexpr(true)); 
      }
	ps->arg2=try3;
	//EDW DES 
	try4=make_operand(constnewexpr(costnum_e,line_counter+4));
	ps->result=try4;
    
	ps->srcLine=line_counter;
	quad_elem->taddress=ps->srcLine;//taddress kleftog
	line_counter++;
      if( currQuadvm == totalvm )   //second
      {expandvm();}
      ps=instructions+currQuadvm++;
   
      ps->opcode=if_eq;
    

      //arg1
      if(quad_elem->arg2 !=NULL){
	    if( quad_elem->arg2->sym != NULL){
	      test_int=check_arg(quad_elem->arg2->sym->name,quad_elem->arg2->type,instructions);
	      if( test_int == 1 ){
		try3=clean_make_operand(quad_elem->arg2);
	      }
	    else{
	      try3=make_operand(quad_elem->arg2);
	    }
	    if(quad_elem->arg2!=NULL && quad_elem->arg2->sym!=NULL)
	    try3->func_name=strdup(quad_elem->arg2->sym->name);
	    
	  }
	  else{
	    try3=make_operand(quad_elem->arg2);
	  }
	  ps->arg1=try3;
      }
      else{//an den iparxei tote NULL
	ps->arg1=NULL;
      }
      test_int=0;
	  
      //arg2
	if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	  try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
	else{
	  try3=make_operand(boolnewexpr(true));
	}
	ps->arg2=try3;
	//EDW DES 
	try4=make_operand(constnewexpr(costnum_e,line_counter+3));
	ps->result=try4;
	
    
	ps->srcLine=line_counter;
	line_counter++;
      if( currQuadvm == totalvm )   //third
      {expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=assign ;
    
	  
      if( quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(boolnewexpr(false));
      }
	ps->arg1=try2;

    

	ps->arg2=NULL;
	
	try4=make_operand(quad_elem->result);
	ps->result=try4;
	ps->srcLine=line_counter; 
	line_counter++;
      if( currQuadvm == totalvm )   //forth
      {
      expandvm();}
      ps=instructions+currQuadvm++;
     
      ps->opcode=jump ;
    
      //DES EDW
      ps->arg1=NULL;
      ps->arg2=NULL;
      //incomplete JUMP
      ps->result=make_operand(constnewexpr(costnum_e,line_counter+2));
      ps->srcLine=line_counter; 
      line_counter++;
      if( currQuadvm == totalvm )   //fifth
      {expandvm();}
      ps=instructions+currQuadvm++;
      
       ps->opcode=assign ;
    
	  
      if( quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(boolnewexpr(true));
      }
      ps->arg1=try2;

      
      
      //result
      if(quad_elem->result !=NULL){
	    if( quad_elem->result->sym != NULL){
	      test_int=check_arg(quad_elem->result->sym->name,quad_elem->result->type,instructions);
	      if( test_int == 1 ){
		try4=clean_make_operand(quad_elem->result);
	      }
	    else{
	      try4=make_operand(quad_elem->result);
	    }
	    if(quad_elem->result!=NULL && quad_elem->result->sym!=NULL)
	    try4->func_name=strdup(quad_elem->result->sym->name);
	    
	  }
	  else{
	    try4=make_operand(quad_elem->result);
	  }
	  ps->result=try4;
      }
      else{//an den iparxei tote NULL
	ps->result=NULL;
      }
      test_int=0;
      ps->result=try4;

      
      ps->srcLine=line_counter; 
      line_counter++;
	
	
    counter++;
    
    quad_elem++;  
    continue;
    
    
  }
  else if(quad_elem->op==not)
  { printf("Entered not\n");
      ps->opcode=if_eq;
      
      int test_int=0;
      
          //arg1
      if(quad_elem->arg1 !=NULL){
	  if( quad_elem->arg1->sym != NULL && quad_elem->arg1->sym->name != NULL && '_' == quad_elem->arg1->sym->name[0] && 't' == quad_elem->arg1->sym->name[1]  ){
	  try2=find_temp(quad_elem->arg1->sym->name,instructions);
	  }
	  else if( quad_elem->arg1->sym != NULL){
	    test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
	    if( test_int == 1 ){
	      try2=clean_make_operand(quad_elem->arg1);
	    }
	    else{
	      try2=make_operand(quad_elem->arg1);
	    }
	    if(quad_elem->arg1!=NULL && quad_elem->arg1->sym!=NULL)
	    try2->func_name=strdup(quad_elem->arg1->sym->name);
	    
	  }
	  else{
	    try2=make_operand(quad_elem->arg1);
	  }
	  ps->arg1=try2;
      }
      else{//an den iparxei tote NULL
	ps->arg1=NULL;
      }
      test_int=0;


	try3=make_operand(boolnewexpr(false));
	
	ps->arg2=try3;
	
	try4=make_operand(constnewexpr(costnum_e,line_counter+3));
	ps->result=try4;
    
	ps->srcLine=line_counter;
	quad_elem->taddress=ps->srcLine;//taddress kleftog
	line_counter++;
      if( currQuadvm == totalvm )   //second
      {expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=assign;
    
      

	try2=make_operand(boolnewexpr(false)); 
	ps->arg1=try2;
	ps->arg2=NULL;
	try4=make_operand(quad_elem->result);
	ps->result=try4;
	
    
	ps->srcLine=line_counter;
	line_counter++;
      if( currQuadvm == totalvm )   //third
      {expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=jump ;
      ps->arg1=NULL;
      ps->arg2=NULL;
      try4=make_operand(constnewexpr(costnum_e,line_counter+2));
      ps->result=try4;
      ps->srcLine=line_counter;
      line_counter++;
      if( currQuadvm == totalvm )   //fourth
      {expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=assign ;
    
	  
      if(quad_elem->arg1!=NULL && quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(boolnewexpr(true)); }
	ps->arg1=try2;
	ps->arg2=NULL;
	try4=clean_make_operand(quad_elem->result);
	ps->result=try4;
	ps->srcLine=line_counter; 	
	line_counter++;
    counter++;
    
    quad_elem++;  
    continue;
    
  } else if(quad_elem->op==ret){
    
   
  
    
     ps->opcode=assing;
      if((quad_elem->arg1!=NULL)&&( quad_elem->arg1->sym != NULL) && ('_' == quad_elem->arg1->sym->name[0] )){
	try2=find_temp(quad_elem->arg1->sym->name,instructions); }
    
      else{
	
	try2=make_operand(quad_elem->result);}
      ps->arg1=try2;
  
    
      if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
      else{
	
	try3=make_operand(tempexpr(var_e,var_s,programvarmvar,0,0,0));
      }
	ps->arg2=NULL;
	
	//try4=make_operand(constnewexpr(costnum_e,line_counter+3));
	ps->result=try4;
    
	ps->srcLine=line_counter;
	line_counter++;
      if( currQuadvm == totalvm )   //second
      {;expandvm();}
      ps=instructions+currQuadvm++;
    
      ps->opcode=jump;
    
      
	if(quad_elem->arg1!=NULL && quad_elem->arg1->sym != NULL && '_' == quad_elem->arg1->sym->name[0] ){
	try2=find_temp(quad_elem->arg1->sym->name,instructions);}
      
      else{
	try2=make_operand(constnewexpr(costnum_e,-8)); }
	ps->arg1=NULL;
	ps->arg2=NULL;
	//try4=clean_make_operand(quad_elem->result);
	ps->result=try2;
	
    
	ps->srcLine=line_counter;
	line_counter++;

    
    counter++;
   
    quad_elem++;  
    continue;

    
  }
  
  
  
  else if(quad_elem->op==uminus){
    ps->opcode=mul;
    
    if((quad_elem->arg1!=NULL)&&( quad_elem->arg1->sym != NULL) && ('_' == quad_elem->arg1->sym->name[0] )){
      try2=find_temp(quad_elem->arg1->sym->name,instructions); 
    }
    else{
      try2=make_operand(quad_elem->arg1);}
    ps->arg1=try2;

  
    if( quad_elem->arg2 != NULL && quad_elem->arg2->sym != NULL && '_' == quad_elem->arg2->sym->name[0] ){
      try3=find_temp(quad_elem->arg2->sym->name,instructions);
      }
    else{
      try3=make_operand(constnewexpr(costnum_e,-1));
    }
    ps->arg2=try3;

      try4=make_operand(quad_elem->result);

    ps->result=try4;

    ps->srcLine=line_counter;
    quad_elem->taddress=ps->srcLine;//taddress kleftog
    line_counter++;
  }
  else if(strcmp(vmopcode_array[quad_elem->op],"FUNCEND")==0){
    int test_int;
    
    ps->arg1=NULL;
    ps->arg2=NULL;
    
    if( quad_elem->result != NULL ){
	if( quad_elem->result->sym != NULL){
	  //printf("!!!!!!!![][%s][%d]\n",quad_elem->result->sym->name,quad_elem->result->type);
	  test_int=check_arg_for_func(quad_elem->result->sym->name,quad_elem->result->type,instructions);
	  if( test_int == 1 ){
	    try4=clean_make_operand(quad_elem->result);
	  }
	  else{
	    try4=make_operand(quad_elem->result);
	  }
	}
	else{
	  try4=make_operand(quad_elem->result);  
	}
	ps->result=try4;
	test_int=0;
    }
    else{
    try4=make_operand(quad_elem->result);
    }
    ps->result=try4;
    ps->srcLine=line_counter;
    quad_elem->taddress=ps->srcLine;
    line_counter++;
    
  }
  else{
//     printf("\n%d\n\n",quad_elem->op);
//     printf("top");
    int test_int;
    //arg1
    if(quad_elem->arg1 !=NULL){
	if( quad_elem->arg1->sym != NULL && quad_elem->arg1->sym->name != NULL && '_' == quad_elem->arg1->sym->name[0] && 't' == quad_elem->arg1->sym->name[1]  ){
	 try2=find_temp(quad_elem->arg1->sym->name,instructions);
	}
	else if( quad_elem->arg1->sym != NULL){
	  test_int=check_arg(quad_elem->arg1->sym->name,quad_elem->arg1->type,instructions);
	  if( test_int == 1 ){
	    try2=clean_make_operand(quad_elem->arg1);
	  }
	  else{
	    try2=make_operand(quad_elem->arg1);
	  }
	  if(quad_elem->arg1!=NULL && quad_elem->arg1->sym!=NULL)
	  try2->func_name=strdup(quad_elem->arg1->sym->name);
	  
	}
	else{
	  try2=make_operand(quad_elem->arg1);
	}
	ps->arg1=try2;
    }
    else{//an den iparxei tote NULL
      ps->arg1=NULL;
    }
    test_int=0;
    
    //arg2
    if(quad_elem->arg2 !=NULL){
	if( quad_elem->arg2->sym != NULL && quad_elem->arg2->sym->name != NULL && '_' == quad_elem->arg2->sym->name[0] ){
	  try3=find_temp(quad_elem->arg2->sym->name,instructions);
	}
	else if( quad_elem->arg2->sym != NULL){
	  test_int=check_arg(quad_elem->arg2->sym->name,quad_elem->arg2->type,instructions);
	  if( test_int == 1 ){
	    try3=clean_make_operand(quad_elem->arg2);
	  }
	  else{
	    try3=make_operand(quad_elem->arg2);
	  }
	}
	else{
	  try3=make_operand(quad_elem->arg2);  
	}
	ps->arg2=try3;
	test_int=0;
    }
    else{//an den iparxei tote NULL
//       printf("ARG2 NULL\n");
      ps->arg2=NULL;
    }
    
    test_int=0;
    
    
    //result
    if( quad_elem->result != NULL ){
	if( quad_elem->result->sym != NULL){
	 // printf("!!!!!!!![][%s][%d]\n",quad_elem->result->sym->name,quad_elem->result->type);
	  if(quad_elem->result->type==2)
	  test_int=check_arg_for_func(quad_elem->result->sym->name,quad_elem->result->type,instructions);
	  else
	  test_int=check_arg(quad_elem->result->sym->name,quad_elem->result->type,instructions);
	  if( test_int == 1 ){
	    try4=clean_make_operand(quad_elem->result);
	  }
	  else{
	    try4=make_operand(quad_elem->result);
	  }
	  
	  if(quad_elem->result!=NULL && quad_elem->result->sym!=NULL)
	  try4->func_name=strdup(quad_elem->result->sym->name);
	}
	else{
	  try4=make_operand(quad_elem->result);  
	}
	ps->result=try4;
	test_int=0;
    }
    else{
    try4=make_operand(quad_elem->result);
    }
    ps->result=try4;
    ps->srcLine=line_counter;
    quad_elem->taddress=ps->srcLine;
    line_counter++;
  }
  counter++;
  quad_elem++;
  }
}

int check_arg(char* name,unsigned int type,struct instruction *in){
    
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    int counter=currQuadvm;
    int counter2=0;
    int counter4=0;
    int e;
    
    
    
    while( counter2 < currQuadvm ){ 
      in++;
      counter2++;
    }
    
    while( counter >= 0 ){
      if( in->result == NULL ){
	counter4++;
	counter--;
	in--;
	continue;
      }
      
      e=(int)in->result;
      
     if( e<6000000)
       return 1;
      //printf("\n\nin->type(%s)-in->type(%d)\n\n",in->result->name,in->result->type);
      if(  in->result->name != NULL && strcmp(name,in->result->name) == 0 && type == in->result->type ){
	printf("\n\n%s\n\n",in->result->name);
// 	if( type == in->result->type || ( type == local_a && in->result->type == global_a ) || ( type == global_a && in->result->type==local_a ) )
	return 1;//found	
      }
      counter4++;
      counter--;
      in--;
    }
    
    return 0;
}



int check_arg_for_func(char* name,unsigned int type,struct instruction *in){
  //  printf("Mpike se function=\n");
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    int counter=currQuadvm;
    int counter2=0;
    int counter4=0;
    
    
   
    while( counter2 < currQuadvm ){ 
      in++;
      counter2++;
    }
    
    while( counter >= 0 ){
      if( in->result == NULL ){
	counter4++;
	counter--;
	in--;
	continue;
      }
      
      //printf("\n\nin->type(%s)-in->type(%d)\n\n",in->result->name,in->result->type);
      if( in->result->name != NULL && strcmp(name,in->result->name) == 0 && 7 == in->result->type ){
	printf("\n\n%s\n\n",in->result->name);
// 	if( type == in->result->type || ( type == local_a && in->result->type == global_a ) || ( type == global_a && in->result->type==local_a ) )
	return 1;//found	
      }
      counter4++;
      counter--;
      in--;
    }
    
    return 0;
}


struct vmarg* find_temp(char* name,struct instruction *in){
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    int counter=currQuadvm;
    int counter2=0;
    int counter4=0;
    int e;
    while( counter2 < currQuadvm ){ 
      in++;
      counter2++;
    }
    
    while( counter >= 0 ){
      if( in->result == NULL ){
	counter4++;
	counter--;
	in--;
	continue;
      }
      
      e=(int)in->result;
    
//       printf("\n\n%d\n\n",in->result);
      if( e>6000000 && in->result->name != NULL && strcmp(name,in->result->name) == 0 ){
	arg->type=in->result->type;
	arg->val=in->result->val;
	arg->name="#";//NO PRINT FLAG
	return arg;
	
      }
      counter4++;
      counter--;
      in--;
    }
    
    return arg;
}




/*
enum symbol_t 	 type;
   char*    	 name;
   enum scopespace_t  space;
   unsigned int  offset;
   unsigned int  scope;
   unsigned int   line;*/

extern struct expr *headforcall;

struct expr* lvaluenewexpr(enum expr_t type,enum symbol_t  symbol_type,char* name,enum scopespace_t  space,unsigned int  offset,unsigned int  scope,unsigned int   line){
  struct symbol* mysymbol=(struct symbol*) malloc(sizeof(struct symbol));
  struct expr* newexpression=(struct expr*) malloc(sizeof(struct expr));
  
  
 
  newexpression->type=type;
  newexpression->sym=mysymbol;
  newexpression->index=NULL;
  newexpression->numConst=0;
  newexpression->strConst=NULL;
  newexpression->boolConst=null;
  newexpression->next=NULL;
  
  mysymbol->name=name;
  mysymbol->type=symbol_type;
  mysymbol->space=space;
  mysymbol->offset=offset;
  mysymbol->scope=scope;
  mysymbol->line=line;
 /*
  printf("\n----------------QUADS---------------------\n");
  printf("\nexpr->type:[%s]",expr_t_array[type]);
  printf("\nsymbol->type:[%s]",symboltype_array[symbol_type]);
  printf("\nsymbol->name:[%s]",name);
  printf("\nsymbol->space:[%s]",scopespace_array[space]);
  printf("\nsymbol->offset:[%d]",offset);
  printf("\nsymbol->scope:[%d]",scope);
  printf("\nsymbol->line:[%d]\n\n\n",line);
  printf("\n-------------------------------------\n");
  */
 
  if(headforcall==NULL){
    headforcall=newexpression;
  }else{
    newexpression->next=headforcall;
    headforcall=newexpression;
    
  }
 
  return newexpression;
  
}




struct expr* tempexpr(enum expr_t type,enum symbol_t  symbol_type,enum scopespace_t  space,unsigned int  offset,unsigned int  scope,unsigned int   line){
  struct symbol* mysymbol=(struct symbol*) malloc(sizeof(struct symbol));
  struct expr* newexpression=(struct expr*) malloc(sizeof(struct expr));
  newexpression->type=type;
  newexpression->sym=mysymbol;
  newexpression->index=NULL;
  newexpression->numConst=0;
  newexpression->strConst=NULL;
  newexpression->boolConst=null;
  newexpression->next=NULL;
  
  exprnoname++;
  sprintf(bufferforexpr, "%d", exprnoname); 

  strcpy (nonameexpr,exprdefault);
  strcat (nonameexpr,bufferforexpr);
  
  mysymbol->name=strdup(nonameexpr);
  mysymbol->type=symbol_type;
  mysymbol->space=space;
  mysymbol->offset=offset;
  mysymbol->scope=scope;
  mysymbol->line=line;
 /*
  printf("\n----------------QUADS---------------------\ntemporary expression\n");
  printf("\nexpr->type:[%s]",expr_t_array[type]);
  printf("\nsymbol->type:[%s]",symboltype_array[symbol_type]);
  printf("\nsymbol->name:[%s]",nonameexpr);
  printf("\nsymbol->space:[%s]",scopespace_array[space]);
  printf("\nsymbol->offset:[%d]",offset);
  printf("\nsymbol->scope:[%d]",scope);
  printf("\nsymbol->line:[%d]\n\n\n",line);
  printf("\n-------------------------------------\n");
  */
  return newexpression;
}




struct expr* constnewexpr(enum expr_t type,double numConst){
  struct expr* newexpression=(struct expr*) malloc(sizeof(struct expr));
  newexpression->type=type;
  newexpression->sym=NULL;
  newexpression->index=NULL;
  newexpression->numConst=numConst;
  newexpression->strConst=NULL;
  newexpression->boolConst=null;
  newexpression->next=NULL;
 /* 
  printf("\n----------------QUADS---------------------\n");
  printf("\nexpr->type:[%s]",expr_t_array[type]);
  printf("\nexpr->numConst:[%f]",numConst);
  printf("\n-------------------------------------\n");
  */
  return newexpression;
}

struct expr* boolnewexpr(enum bool boolConst){
  struct expr* newexpression=(struct expr*) malloc(sizeof(struct expr));
  newexpression->type=boolexpr_e;
  newexpression->sym=NULL;
  newexpression->index=NULL;
  newexpression->numConst=0;
  newexpression->strConst=NULL;
  newexpression->boolConst=boolConst;
  newexpression->next=NULL;
  /*
  printf("\n----------------QUADS---------------------\n");
  printf("\nexpr->type:[%s]",expr_t_array[boolexpr_e]);
  printf("\nexpr->boolConst:[%s]",bool_array[boolConst]);
  printf("\n-------------------------------------\n");
  */
  return newexpression;
}

struct expr* stringnewexpr(char* strConst){
  struct expr* newexpression=(struct expr*) malloc(sizeof(struct expr));
  newexpression->type=conststring_e;
  newexpression->sym=NULL;
  newexpression->index=NULL;
  newexpression->numConst=0;
  newexpression->strConst=strConst;
  newexpression->boolConst=null;
  newexpression->next=NULL;
 /* 
  printf("\n----------------QUADS---------------------\n");
  printf("\nexpr->type:[%s]",expr_t_array[conststring_e]);
  printf("\nexpr->strConst:[%s]",strConst);
  printf("\n-------------------------------------\n");
  */
  return newexpression;
}

enum iopcode get_op(char *op){
   if(strcmp(op,"=")==0)
   { 
     return assign;}
   else if(strcmp(op,"+")==0)
   { 
     return add;
     
  }
     else if(strcmp(op,"-")==0)
   { return sub;
     
  }
      else if(strcmp(op,"*")==0)  //????????
   { 
     return mul;
     
  }
      else if(strcmp(op,"/")==0)
   { 
     return divi;
     
  }
      else if(strcmp(op,"%")==0)
   { 
     return mod;
     
  }
      else if(strcmp(op,">")==0)
   { 
     return if_greater;
     
  }
      else if(strcmp(op,">=")==0)
   { 
     return if_greatereq;
     
  }
      else if(strcmp(op,"<")==0)
   { 
     return if_less;
     
  }
      else if(strcmp(op,"<=")==0)
   {
     return if_lesseq;
     
  }
      else if(strcmp(op,"==")==0)
   {
     return if_eq;
     
  }
      else if(strcmp(op,"!=")==0)
   {
     return if_noteq;
     
  }
      else if(strcmp(op,"&&")==0)
   {return and;}
      else if(strcmp(op,"||")==0)
    {return or;}
}











void patchlabel(unsigned int label,unsigned int line_of_quad)
{int i=0;
// printf("\nLabel=%d \n ",label);
// printf(" Line==%d",line_of_quad);
  quads[line_of_quad-1].label=label;
}
  
  

        
  
void patchbreak(struct expr* break_head,unsigned int line_of_end,double loop_num)
{ struct expr* ptr=break_head;
//     printf("patch break begin!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  while(ptr!=NULL)
  { if((ptr->sym->line>0)&&(ptr->numConst==loop_num))   //not break head  &&(ptr->numConst==loop_num)
    { 
      quads[ptr->sym->line-1].label=line_of_end;
//     printf("patchbreak quad line =%d\n",ptr->sym->line);
//      printf("patchbreak quad loop_num =%f\n",loop_num);
//          printf("patchbreak quad loop_ ptr  =%f\n",ptr->numConst);
//      printf("patchbreak loop===%f\n",ptr->numConst);
    } 

  ptr=ptr->next;  
  }
//       printf("patch break end!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
 }
 
 
void patchcontinue(struct expr* continue_head,unsigned int line_of_end, double loop_num)
{ struct expr* ptr=continue_head;
//     printf("patch cont begin!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  while(ptr!=NULL)
  { if((ptr->sym->line>0)&&(ptr->numConst==loop_num))   //not break head  &&(ptr->numConst==loop_num)
    { 
            quads[ptr->sym->line-1].label=line_of_end;
//     printf("patchbreak quad line =%d\n",ptr->sym->line);
//      printf("patchbreak quad loop_num =%f\n",loop_num);
//          printf("patchbreak quad loop_ ptr  =%f\n",ptr->numConst);
//      printf("patchbreak loop===%f\n",ptr->numConst);
 
 
    } 

  ptr=ptr->next;  
  }
//       printf("patchcont end!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
 }
    
  
  
  

  
  struct expr* continue_insert(struct expr* break_head,struct expr* new_break,double loop_count)
  {struct expr* ptr=break_head;
    struct expr* prev;
     new_break->numConst=loop_count;  //use it for loop number
  while(ptr!=NULL)
  {
//     printf("insert continue!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  prev=ptr;
  ptr=ptr->next;  
  }
  prev->next=new_break;
     }
 
 
 
  
   
	struct expr *break_insert(struct expr* break_head,struct expr* new_break,double loop_count)
  {struct expr* ptr=break_head;
    struct expr* prev;
    new_break->numConst=loop_count;  //use it for loop number
   
  while(ptr!=NULL)
  {
//     printf("insert break!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  prev=ptr;
  ptr=ptr->next;  
  }
  prev->next=new_break;
   
  return break_head;}
  
  
  //phase4
  
  
struct vmarg* make_operand(struct expr* e){
    
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    if( e == NULL ){
      arg->name=NULL;
      arg->val=-1;
      return arg;
    }
    switch(e->type){
      
      case var_e:{
	
	if( e->sym->scope != 0 ){
	  arg->type=global_a; //local
	  arg->val=new_global();//local
	}
	else{
	  arg->type=global_a; 
	  arg->val=new_global();
	}
	arg->name=strdup(e->sym->name);
	break;
      }
      case tableitem_e:
      case arithexpr_e:
      case boolexpr_e:
      case nevitable_e:{
	
// 	arg->val=e->sym->offset;
// 	
// 	switch(e->sym->space)	{
// 	  case programvarmvar: arg->type=global_a; break;
// 	  case functionlocal: arg->type=local_a; break;
// 	  case formalarg: arg->type=formal_a; break;
// 	  default: assert(0);
// 	}
      }
      /*Constants*/
      case constbool_e:{
	arg->val=e->boolConst;
	arg->type=bool_a;
	arg->name=bool_array[e->boolConst];
	break;
      }
      case conststring_e:{
	arg->val=new_string();
	arg->type=string_a;
	arg->name=strdup(e->strConst);
	break;
      }
    case costnum_e:{
	if(e->numConst==-8){
	  arg->val=-8;
	}else{
	arg->val=new_const();
	}
	arg->type=number_a;
	arg->name=malloc(sizeof(char));
	sprintf(arg->name, "%f", e->numConst);
	break;
      }
    
    /* 
     case costnum_e:{
       printf("entered constnum\n");
	if(e->numConst==-8){
	  arg->val=-8;
	}else{
	 arg->val=e->numConst;
	}
	arg->type=number_a;
	arg->name=malloc(sizeof(char));
	double t=new_const();
	sprintf(arg->name, "%f",t);
	break;
      }
    */
      
      case nil_e: arg->type=nil_a; break;
      
      /* Functions */
      
      case programfunc_e:{
	  arg->type=userfunc_a;
	  arg->func_name=malloc(sizeof(char));
	  arg->val=new_userfunc();
	  arg->name=strdup(e->sym->name);
	  //arg->val=e->sym->taddress;
	  flag_userfunc_a++;
	  break;
      }
      
      case libraryfunc_e:{
		printf("malakieeeeeeeeeeeeeeeeeeeeeee=%s\n\n",e->sym->name);
	arg->type=libfunc_a;
	arg->func_name=malloc(sizeof(char));
	arg->val=new_lib();
	arg->name=strdup(e->sym->name);
	flag_libfunc_a++;
	break;
      }
      
      default: assert(0);
	  
	
	
	
      }
      return arg;
  }
  
  struct vmarg* clean_make_operand(struct expr* e){
    
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    struct vmarg* argtest;
    if( e == NULL ){
      arg->name=NULL;
      arg->val=-1;
      return arg;
    }
    switch(e->type){
      
      case var_e:{
	
	argtest=find_arg(e->sym->name,instructions);
	arg->type=argtest->type; 
	arg->val=argtest->val;
	arg->name=strdup(e->sym->name);
	break;
      }
      case tableitem_e:
      case arithexpr_e:
      case boolexpr_e:
      case nevitable_e:{
	
// 	arg->val=e->sym->offset;
// 	
// 	switch(e->sym->space)	{
// 	  case programvarmvar: arg->type=global_a; break;
// 	  case functionlocal: arg->type=local_a; break;
// 	  case formalarg: arg->type=formal_a; break;
// 	  default: assert(0);
// 	}
      }
      /*Constants*/
      case constbool_e:{
	arg->val=e->boolConst;
	arg->type=bool_a;
	arg->name=bool_array[e->boolConst];
	break;
      }
      case conststring_e:{
	arg->val=new_string();
	arg->type=string_a;
	arg->name=strdup(e->strConst);
	break;
      }
      case costnum_e:{
	arg->val=new_const();
	arg->type=number_a;
	arg->name=malloc(sizeof(char));
	sprintf(arg->name, "%f", e->numConst);
	break;
      }
      case nil_e: arg->type=nil_a; break;
      
      /* Functions */
      
      case programfunc_e:{
	  arg->type=userfunc_a;
	  arg->func_name=malloc(sizeof(char));
	  //arg->val=e->sym->taddress;
	  flag_userfunc_a++;
	  break;
      }
      
      case libraryfunc_e:{

	arg->type=libfunc_a;
	arg->val=new_lib(e->sym->name);
	break;
      }
      
      default: assert(0);
	  
	
	
	
      }
      return arg;
  }
  
unsigned  new_string(){
  flag_string_a=1;
  int vm=string_a_counter;
  string_a_counter++;
  return vm;
}
unsigned new_const(){
  flag_number_a=1;
  int vm=number_a_counter;
  number_a_counter++;
  return vm;
}
unsigned new_lib(){
  flag_libfunc_a=1;
  int vm=libfunc_a_counter;
  libfunc_a_counter++;
  return vm;
}
unsigned new_global(){
  flag_global_a=1;
  int vm=global_a_counter;
  global_a_counter++;
  return vm;
}
unsigned new_local(){
  flag_local_a=1;
  int vm=local_a_counter;
  local_a_counter++;
  return vm;
}
unsigned new_userfunc(){
  flag_userfunc_a=1;
  int vm=userfunc_a_counter;
   userfunc_a_counter++;
   return vm;
}

/*STACK FUNCS*/


/* Create empty stack */
void MakeEmptyStack()
{
    top = NULL;
}
 
/* Count stack elements */
void stack_count()
{
    printf("\n No. of elements in stack : %d", count);
}
 
/* Push data into stack */
void push(int offset,char *symbol_name,char *function_name)

{
    if (top == NULL)
    {   top =(struct funcstack *)malloc(1*sizeof(struct funcstack));
        top->next =NULL;
        top->offset = offset;
	top->symbol_name=symbol_name;
	 
	top->function_name=function_name;
	
    }
    else
    {   top2 =(struct funcstack *)malloc(1*sizeof(struct funcstack));
        top2->next = top;
        top2->offset = offset;
	top2->symbol_name=symbol_name;
	top2->function_name=function_name;
	//top->function_name=function_name;
        top = top2;
	}
    count++;}
 
/* Display stack elements */
void printStack()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("offset=%d ", top1->offset); 
	//printf("function=%s ",top1->function_name);
	printf("symbol=%s ",top1->symbol_name);
	printf("function=%s\n",top1->function_name);
        top1 = top1->next;
    }
 }
 
 
void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return;
    }
    else
        top1 = top1->next;
    //printf("\n Popped offset=%d  symbol=%s\n", top->offset,top->symbol_name);
    free(top);
    top = top1;
    count--;
}
 
/* Return top element */
int get_top()
{return(top->offset);}
 
/* Check if stack is empty or not */
void IsEmptyStack()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}





void returnListLookUp(struct returnList *returnList,char *fucname,int line){
  
  
  while(returnList!=NULL){
    
    
    if(strcmp(returnList->NameOfFunc,fucname)==0){
      
      returnList->jumpList=line;
    }
    
    returnList=returnList->next;
  }
  
  
}


void ReplaceJumpsFromFuncs(struct instruction *quad_elem){
   int counter=0;
   struct returnList *head;
   head=returnLists;
    
   if(head==NULL){
     return;
  }
     
    while( counter < currQuadvm ){
      
      
      
       if(strcmp(vmopcode_array[quad_elem->opcode],"JUMP")==0){
	  
	 if(quad_elem->result!=NULL){
	  if(quad_elem->result->val==-8){
	    
	    quad_elem->result=make_operand(constnewexpr(costnum_e,head->jumpList));
// 	      print_lines();
// 		printf("name=%s\n",quad_elem->result->name);
// 	       printf("val=%d\n",quad_elem->result->val);
// 	       print_lines();
	    head=head->next;
	    
	   
	  }}
       }
      
      lineofnewfile++;
      counter++;
      quad_elem++;
    }
  
  
} 

/*
 void returnListInsert(struct returnList *returnList,int jump,char *name,char *nameval)
  {
    struct returnList* teemo=(struct returnList*) malloc(sizeof(struct returnList));
    struct expr* prev;
    teemo->jumpList=jump;
    teemo->NameOfFunc=name;
    teemo->nameofval=nameval;
    
    if(returnList!=NULL){
      
      teemo->next=returnList;
    }
    
    returnLists=teemo;
    
 }
 */

  void returnListInsert(struct returnList *returnList,int jump,char *name,char *nameval)
  {
    struct returnList* teemo=(struct returnList*) malloc(sizeof(struct returnList));
    struct returnList	*prev,*current=returnList;
    
    teemo->jumpList=jump;
    teemo->NameOfFunc=name;
    teemo->nameofval=nameval;
    if(returnLists==NULL){
            returnLists=teemo;
    }else{
      
      while(current!=NULL){
	prev=current;
	current=current->next;
      }
      prev->next=teemo;
      teemo->next=NULL;
      
      
    }
    
   
    
 }
 void printreturnList(struct returnList *returnList){
    
    while(returnList!=NULL){
    
     returnList=returnList->next;
      
    }
      
   
   
}


struct vmarg* find_arg(char* name,struct instruction *in){
    struct vmarg* arg=(struct vmarg*) malloc(sizeof(struct vmarg));
    int counter=currQuadvm;
    int counter2=0;
    int counter4=0;
    int e;
    
    while( counter2 < currQuadvm ){ 
      in++;
      counter2++;
    }
    
    while( counter >= 0 ){
      if( in->result == NULL ){
	counter4++;
	counter--;
	in--;
	continue;
      }
      
      e=(int)in->result;
      
      if(e>6000000 &&  strcmp(name,in->result->name) == 0 ){
	arg->type=in->result->type;
	arg->val=in->result->val;
	arg->name=in->result->name;
	printf("\n-FOUND-\n");
	return arg;
	
      }
      counter4++;
      counter--;
      in--;
    }
    
    return arg;
}



void add_incomplete_jump(unsigned int instrNo,unsigned int iaddress){
  struct incomplete_jump *new_node=malloc(sizeof(struct incomplete_jump));  
  new_node->instrNo=instrNo;
  new_node->iaddress=iaddress;
  if(in_head==NULL){ 
    in_head=new_node;
    in_head->next=NULL;
  }
  else
  {
    new_node->next=in_head; 
    in_head=new_node;
  }
}
    
 void print_incomplete_jump(){
  struct incomplete_jump *ptr=in_head;
  if(in_head==NULL){
    return;
  }
//   printf("print inc jumps\n");
  while(ptr!=NULL){
//    printf("@instrNo=%d\n",ptr->instrNo);
//      printf("@iaddress=%d\n",ptr->iaddress);
    ptr=ptr->next;
  }
 }

void patch_inclomplete_jumps(){
  struct incomplete_jump *ptr=in_head;
  char  s[1000];
 // char  *t= currQuadvm+1;
  if(in_head==NULL)
  {return;}
  
   print_incomplete_jump();
 
  while(ptr!=NULL){
  //  instructions[ptr->instrNo].result=make_operand(constnewexpr(costnum_e,quads[ptr->iaddress].taddress));
 

    //    instructions[ptr->instrNo].result->val="yoo";  
//      printf("YOOOs=%d\n",quads[ptr->iaddress-1].taddress);
//       printf("YOOOOs=%d\n",currQuadvm);
	// printf("addr=%d\n",quads[ptr->iaddress-1].taddress);
// 	 	 printf("addr Iindex=%d\n",ptr->iaddress-1);
	//	 printf("Current quad max=%d\n",currQuadvm);
 
        
 
    if(  quads[ptr->iaddress-1].taddress==0)
	{
//  	  printf("ENTEREDdDDDDDDDDDDDDDDDDDDDDDDDD\n");
 strcpy(instructions[ptr->instrNo-1].result->name,"-666" );  //patch by copying	  
 
 
	   
	}
   else{ 	  
//      printf("nooooo ENTEREDdDDDDDDDDDDDDDDDDDDDDDDDD\n");
//       printf("Write to s=%d\n",quads[ptr->iaddress-1].taddress);
   //strcpy(s,'8' );  //patch by copying
 sprintf(s, "%d",quads[ptr->iaddress-1].taddress);
    
   printf("Sprinf OKKK\n");
  //   printf("s=%s\n",s);
     
      strcpy(instructions[ptr->instrNo-1].result->name, s);  //patch by copying
    
//     print_lines();
//     printf("instrNo=%d\n",ptr->instrNo);
//     printf("iaddress=%d\n",ptr->iaddress);
//      printf("final_llabel_address=%d\n",quads[ptr->iaddress-1].taddress);
    
//     printf("new name=%d\n",instructions[ptr->instrNo-1].result->val);
//     printf("new val=%s\n",instructions[ptr->instrNo-1].result->name);
    
  }
     ptr=ptr->next;
//   print_lines();

  }
}






void print_taddresses(struct quad *quad_elem) //new perister
{int counter=0;
  if( quad_elem == NULL )
  {return;}
//    printf("Taddress!!\n");
  while( counter < currQuad ){
//      printf("Taddress=%d\n",(quad_elem[counter]).taddress);
     
     
     
     counter++;
   } 
        
  
  
}


int create_bin(struct instruction* instr){
  int counter=0;
  int terminate=-3821;
  int niltemp=-1;
  char* temp1;
  char* temp2;
  char* temp3;
  int len1;
  int len2;
  int len3;
  int len;
  char* niltempchar="-1";
  len=strlen(niltempchar);
  FILE *fh = fopen ("file.bin", "wb");
  
      
  if (fh != NULL) {
	while( counter < currQuadvm ){
	  if( instr == NULL )
	    break;
	  
	
	  
	  //opcode
	  fwrite (&instr->opcode, sizeof (instr->opcode), 1, fh);
	  
	  //arg1
	  if(instr->arg1 != NULL){
	    fwrite (&instr->arg1->type, sizeof (instr->arg1->type), 1, fh); 
	    fwrite (&instr->arg1->val, sizeof (instr->arg1->val), 1, fh);
	    if( instr->arg1->name != NULL ){
	      temp1=instr->arg1->name;
	      len1=strlen(temp1);
	      fwrite (&len1, sizeof (int), 1, fh);
	      fwrite (temp1, sizeof (char), len1, fh);
	    }
	    else{
	      fwrite (&len,sizeof (int), 1, fh);
	      fwrite (niltempchar,sizeof (char), len, fh);
	    }
	  }
	  else{
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&len,sizeof (int), 1, fh);
	    fwrite (niltempchar,sizeof (char), len, fh);
	  }
	  
	  //arg2
	  if(instr->arg2 != NULL){
	    fwrite (&instr->arg2->type, sizeof (instr->arg2->type), 1, fh);
	    fwrite (&instr->arg2->val, sizeof (instr->arg2->val), 1, fh);
	    if( instr->arg2->name != NULL ){
	      temp2=instr->arg2->name;
	      len2=strlen(temp2);
	      fwrite (&len2, sizeof (int), 1, fh);
	      fwrite (temp2, sizeof (char), len2, fh);
	    }
	    else{
	      fwrite (&len,sizeof (int), 1, fh);
	      fwrite (niltempchar,sizeof (char), len, fh);
	    }
	  }
	  else{
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&len,sizeof (int), 1, fh);
	    fwrite (niltempchar,sizeof (char), len, fh);
	  }
	  
	  //result
	  if(instr->result != NULL){
	    fwrite (&instr->result->type, sizeof (instr->result->type), 1, fh);
	    fwrite (&instr->result->val, sizeof (instr->result->val), 1, fh);
	    if( instr->result->name != NULL ){
	      temp3=instr->result->name;
	      len3=strlen(temp3);
	      fwrite (&len3, sizeof (int), 1, fh);
	      fwrite (temp3, sizeof (char), len3, fh);
	    }
	    else{
	      fwrite (&len,sizeof (int), 1, fh);
	      fwrite (niltempchar,sizeof (char), len, fh);
	    }
	  }
	  else{
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&niltemp,sizeof (int), 1, fh);
	    fwrite (&len,sizeof (int), 1, fh);
	    fwrite (niltempchar,sizeof (char), len, fh);
	  }
	  
	  
	  if(instr->srcLine!=0){
	    fwrite (&instr->srcLine,sizeof (int), 1, fh);
	    
	  }
	  
	  counter++;
	  instr++;
    }
    
    fwrite (&terminate, sizeof (terminate), 1, fh);
    
    
    
    
    fclose (fh);
    
    
  }
    return 0;
}


struct expr *exprlook(struct expr *head,const char * name){
   struct expr *current;
  current=head;
  
  if(current==NULL){
    
    return ;
  }else{
    
    while(current!=NULL){
     if(current->sym!=NULL){
      if(strcmp(current->sym->name,name)==0){
	
	return current;
	
      }
     }
      current=current->next;
    }
 }

 return NULL;
}
void exprprint(struct expr *head){
  
  struct expr *current;
  current=head;
  
  if(current==NULL){
    return ;
  }else{
    
    while(current!=NULL){
      if(current->sym!=NULL){
	printf("\n!!current->name=%s \n",current->sym->name);
      }
      current=current->next;
    }
    
  }
  
  
}