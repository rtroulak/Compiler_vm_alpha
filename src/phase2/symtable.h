#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//extern int funct_name_assigned;

enum SymbolTableType {GLOBAL, LOCAL, FORMAL, USERFUNC, LIBFUNC};
extern int yylineno;
extern int actfuc;
extern int kleftis;
int problem;
extern int rafa;
char *s[] = {"GLOBAL", "LOCAL", "FORMAL", "USERFUNC", "LIBFUNC"};

struct table {
  const char *name;
  enum SymbolTableType type;
  unsigned int scope;
  unsigned int line;
  struct argument *first;//List of arguments
  int isActive;
  int actfuc;
  struct table *next;
};



struct argument{
  const char *name;
  unsigned int scope;
  struct argument *next;
};

struct mara{
  const char *name;
  struct mara *next;
};

/*
  ST_Arg_Hide(struct argument *head )
{struct argument *arg_ptr;
 struct table *table_ptr=head; 
   
   while(table_ptr!=NULL)
   {arg_ptr=table_ptr->arguments;
	  while(arg_ptr!=NULL)
	    {ST_HIDE();
	      //arg_ptr->isActive=0;
	     arg_ptr=arg_ptr->next; 
	    }
     
    table_ptr=table_ptr->next; 
   } }
  */
   

struct mara* F_Insert(struct mara *head, const char *name)
{
  struct mara *ptr;
  struct mara *new_argument=(struct mara*)malloc (sizeof (struct mara));
  
  new_argument->name=name;
  new_argument->next=NULL;

  ptr=head;
  
  
   if(ptr == NULL) {
    return new_argument;
  }
  
  else {
    new_argument->next=head;
    return new_argument;
  }
}

struct mara* F_Delete(struct mara *head)
{
  struct mara *ptr;
  ptr=head;
  
  
  if(ptr == NULL) {
    return NULL;
  }
  else {
    return head->next;
  }
}

void F_Print (struct mara *head) {
  struct mara *current;
  current=head;
  
  printf("\n-------------------------FUNCTION TABLE--------------------------\n\n");
    
  if(current!=NULL){
    while(current!=NULL){
      printf("%s \n",current->name);
      current=current->next;
    }
  }else{
    printf("Empty List\n");
  }
}


struct argument* Arg_Insert(struct argument *head, const char *name,unsigned int scope)
{
  struct argument *ptr;
  struct argument *new_argument=malloc (sizeof (struct argument));
  
  new_argument->name=name;
  new_argument->scope=scope;
  new_argument->next=NULL;

  ptr=head;
  
  
   if(ptr == NULL) {
    
    return new_argument;
  }
  
  else {
    /*while arguments ended*/
    while(ptr->next != NULL){
      ptr=ptr->next;
    }
    /*if we reached end of arguments*/
 
    if( ptr != NULL ){
      ptr->next=new_argument;
      return head;
  }}
}
   
  
  

int ST_InsArg(struct table *head, const char* name,unsigned int scope,const char *argname,unsigned int argscope){
  struct table *current,*temp;
  int flag=0;
  temp=(struct table*) malloc (sizeof (struct table));
  
  current=head;
  
  if( current == NULL ){
    return 0;
  }
  else{
    while( current != NULL ){
      
      if( strcmp(current->name,name) == 0 && current->scope == scope ){
// 	//printf("okkkkkkkkkk found symbol\n");
	current->first=Arg_Insert(current->first, argname, argscope);
	return 1;
      }
      
      current=current->next;
    }
  }
}
  
  
  
  
  
  
    
struct table *ST_DeleteTheLast(struct table *head){
  
  struct table *current,*prev;
  current=head;
  if(current==NULL){
    return NULL;
    
  }
  prev=current;
  while(current->next != NULL){
      prev=current;
      current=current->next;
    }
    prev->next=NULL;
    free(current);
    current=NULL;
  
    return NULL;
  
} 
  
  
  

/*
 * Insert a new node on the list
 * @return the head of the list
 * 
 */
struct table *ST_Insert(struct table *head, const char* name, enum SymbolTableType type, unsigned int scope, unsigned int line, int isActive, int actfuc)
{  //printf("ST  INSERT NAME=%s",name);
  struct table *current,*temp;
  temp=(struct table*) malloc (sizeof (struct table));
  temp->name=strdup(name);
  temp->type=type;
  temp->scope=scope;
  temp->first=NULL;
  temp->line=line;
  temp->isActive=isActive;
  temp->next=NULL;
  
  current=head;

  
  /*if table is empty*/
  if(current == NULL) {
    return temp;
  }
  /*if table is not empty*/
  else {
    /*while table hasnt ended*/
    while(current->next != NULL){
      current=current->next;
    }
    /*if we reached end of table*/
    current->next=temp;
    return head;
  } 
}

/*
 * Look up on the list for the given name
 * @return 1 if name given was found or 0 if not
 * 
 */
int ST_Lookup(struct table *head,  char* name,unsigned int scope,enum SymbolTableType type, int actfuc){
  
  struct table *current,*temp;
  int flag=0;
  temp=(struct table*) malloc (sizeof (struct table));
  
  current=head;
  if( type != LOCAL ){
    if( current == NULL ){
      return 0;
    }
    else{
      while( current != NULL ){
	
	
	if( strcmp(current->name,name) == 0 && current->scope==0){
	  
	  
	  if( current->type == GLOBAL ){
	   if(type==USERFUNC){
	    ErrorM("Variable global already exists");
	    problem=1;
	    return 2;//error
	  }
	    return 1;
	  }/*
	  if( current->type == LIBFUNC && type==USERFUNC ){
	    ErrorM("Variable used as library function");
	    return 2;//error
	  }*/
	  if( current->type == USERFUNC && type == GLOBAL ){
	   
	  
	      kleftis=1;
	    
	    return 2;//error
	  }
	  

	    return 1;
	  
	}
	else if( strcmp(current->name,name) == 0 && current->scope==scope && current->isActive==1){
	  flag=1;
	  break;
	}
	current=current->next;
      }
	
	if( flag == 1 ){
	  /*
	  if( current->type == LIBFUNC && type!=LIBFUNC){
	    ErrorM("Variable used as library function");
	    return 2;//error
	  }*/	  
	  if( (current->type== LOCAL) && type == USERFUNC ){
	    
	    ErrorM("Variable  already exists");
	    problem=1;
	    return 2;//error
	  }
	  if( current->type == USERFUNC && type == USERFUNC ){
	    
	    ErrorM("Function already exists");
	    problem=1;
	    return 2;//error
	  }
	  if(type==FORMAL && current->type==FORMAL){
	    ErrorM("Variable already defined");
	    return 2;
	  }
	  if(type==USERFUNC && current->type==FORMAL){
	    ErrorM("Variable already defined as formal");
	    return 2;
	  }

	  else{
	    
	    
	    return 1;
	  }
	}
	else
	  return 0;
	}
  }
  else{
    
    if( current == NULL ){
      return 0;
    }
    else{
      while( current != NULL ){
	if( strcmp(current->name,name) == 0 && actfuc>0 && current->isActive==1 && current->type != GLOBAL){
	  if( current->type ==USERFUNC) return 1;//reference
	  if(scope==current->scope)return 1;
	  if( current->actfuc != actfuc ){
	    ErrorM("Cannot acces variable inside function ");
	    return 2;
	  }
	  
	  return 1;
	  
	}
	if( strcmp(current->name,name) == 0 && current->scope==scope && current->isActive==1){/*
	  if( current->type == LIBFUNC ){
	    ErrorM("Variable used as library function");
	    return 2;//error
	  }*/
	  if( current->type == USERFUNC && type == LOCAL ){
	   
	  
	      kleftis=1;
	    
	    return 2;//error
	  }
	  if(type==FORMAL && current->type==USERFUNC){
	    ErrorM("Variable already defined as formal");
	    return 2;
	  }
	  return 1;
	}
	current=current->next;
      }
      return 0;
    }
  }
}


void Arg_Print (struct argument *head) {
  struct argument *ptr=head;
   //printf("Argument list:\n");
   if(head==NULL){
     //printf("no arguements\n");}
    while(ptr!=NULL){
    //printf("QQQQQQ%sQQQQQ ",ptr->name);
      ptr=ptr->next;
    } 
      printf("\n");
}
}





/*
 * Print list
 * @return void
 * 
 */
void ST_Print (struct table *head) {
  struct table *current;
  current=head;
  
  printf("\n-------------------------SYMBOL TABLE--------------------------\n\n");
  printf( "name			   	type		   scope		line		     Active\n");
  printf("-----------------------------------------------------------------------------------------------------\n");
    
  if(current!=NULL){
    while(current!=NULL){
      printf("%-30s %-20s %-20u %-20u %-20d\n",current->name,s[current->type],current->scope,current->line,current->isActive );
      current=current->next;
    }
  }else{
    printf("Empty List\n");
  }
}

/*
 * Hide the node of the list that matches the given name
 * @return 1 on success or else 0
 * 
 */
int ST_Hide(struct table *head,  const char *name,int scope) {
  struct table *current,*temp;
  struct argument *arg_ptr=NULL;
  
  current=head;
  if( current == NULL ){
    return 0;
  }
  else{
    while( (current != NULL)&&(strcmp(current->name,name)!=0)){
  
      current=current->next;
    }
    
    if( current == NULL ){
      return 0;
    }
    else{
     //   printf("current=%s",current->name); printf("  name=%s",name);
      //current->isActive=0;
     
     arg_ptr=current->first; 
     Arg_Print(arg_ptr);
     while(arg_ptr!=NULL)
     {
       ST_Hide2(head,arg_ptr->name,scope);  //deactivate arguement
       
       
     arg_ptr=arg_ptr->next;}
      
      return 1;
    }
  }
}


int ST_Hide2(struct table *head,  const char *name,int scope) {
  struct table *current,*temp;
  struct argument *arg_ptr=NULL;
  
  current=head;
  if( current == NULL ){
    return 0;
  }
  else{
    while( (current != NULL)){
      if((strcmp(current->name,name)==0) && current->isActive==1 && scope != current->scope){

	break;
      }
      
      current=current->next;
    }
    
    if( current == NULL ){
      return 0;
    }
    else{
     //   printf("current=%s",current->name); printf("  name=%s",name);
     if(current->isActive)
      current->isActive=0;
      
      return 1;
    }
  }
}


int ErrorM (char* yaccProvidedMessage)
{
  fprintf(stderr, "\n==========================================================================\n");
  
  fprintf(stderr,"%s\n",yaccProvidedMessage);
  fprintf(stderr,"ERROR");
  printf(":At line [%d]\n",yylineno);
  fprintf(stderr, "==========================================================================\n");
  //exit(0);

}

int ErrorR (char* yaccProvidedMessage,char* x)
{
  fprintf(stderr, "\n==========================================================================\n");
  
  fprintf(stderr,"ERROR\n");
  fprintf(stderr,"\"%s\" %s\n",x,yaccProvidedMessage);
  fprintf(stderr, "==========================================================================\n");
  //exit(0);

}

int PrintFunc(struct table *head){
  struct table *ptr=head;
  struct argument *arg_ptr;
  int i;
 
  
  if( ptr == NULL ){
    return 0;
  }   
  while(ptr!=NULL){
    if(ptr->first!=NULL){
      printf("\n\n\t\tFunction name=%s\narguements:\t",ptr->name);
      arg_ptr=ptr->first;
      i=0;
      while(arg_ptr!=NULL){
	printf("argument[%d]=%s\n",i,arg_ptr->name);
	i++;
      arg_ptr=arg_ptr->next;
      }
    }
  ptr=ptr->next; 
  }
}


extern struct table *globalcurrentfunctions;

int ST_LookupFunc(struct table *head,  char* name,unsigned int scope,enum SymbolTableType type){
  
  struct table *current,*temp;
  int flag=0;
  
  
  current=head;
  
    if( current == NULL ){
      return 0;
    }
    else{
      while( current != NULL ){
	
	
	if( strcmp(current->name,name) == 0 && current->type==USERFUNC){
	  globalcurrentfunctions=current;
	  return 1;
	}
	if(strcmp(current->name,name) == 0 && current->type==LIBFUNC){
	  
	  globalcurrentfunctions=current;
	  return 3;
	}
	current=current->next;
      }
      
    }
    return 0;
}

