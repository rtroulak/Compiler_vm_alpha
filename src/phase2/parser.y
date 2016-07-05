%{
#include<stdio.h>
#include "symtable.h"
#include "quads.c"
#include <stdlib.h> 
#include <string.h>
struct table *globalcurrentfunctions;
struct expr *headforcall;
int arraysnot=0;
int yyerror(char *yaccProvidedMessage);
int yylex(void);
extern int problem;
int rafa;
int kleftis;
extern int yylineno;
extern char* yytext; 
char* tempyytext;
char* symbol;  
extern FILE* yyin;

struct table *head;
struct mara *headf;
struct quad* quadtest;
char* temp=NULL;
struct expr* pinakastemp;
struct expr* objecttemp;
struct expr* insertelement;
struct expr* oneexpr;
struct expr* twoexpr;
struct expr* threeexpr;
struct expr* fourexpr;
struct expr* fiveexpr;
struct expr* sixexpr;
struct expr* coste;
struct expr* current_temp;
struct expr* break_head;	//per
struct expr* continue_head=NULL;//per
int funct_scope=0,scope=0;
int actif=0,actfuc=0;

int diaperasi=0;
int diaperasi2=0;
int activefunction=0;
int found=0;
int NoNameInt=0;
int exprnoname=0;
unsigned int total=0;
char bufferforint[9],nonamefunctionall[20],nonamedefault[12]="_f";
char bufferforexpr[9],nonameexpr[20],exprdefault[2]="_t";

int wehaveanstmt=0;
int NumOfLocVar=0;

int offset=1;
int global_offset=0;
int whichoffset=0;


int is_while;
int counter=0;
int tableitem=0;
int elistflag=0;
int indexedflag=0;
int coolflag=0;
int memberlvalue=0;
char* stringsave;
int CALLi=0;
int create=0;
int lineofnewfile=1;
int pincounter=0;
int help=0;

int anelistbegin=0;

int breakaccess=0;
int continueaccess=0;
  
double loop_counter=0;

int  global_a_counter=0,
  local_a_counter=0,
  formal_a_counter=0,
  bool_a_counter=0,
  string_a_counter=0,
  constnum_a_counter=0,
  number_a_counter=0,
  userfunc_a_counter=0,
  libfunc_a_counter=0,
  nil_a_counter=0;
%}

%start program
%token ID INTEGER FLOAT ifstmt whilestmt elsestmt forstmt returnstmt breakstmt continuestmt lesseq beq greq bne AND OR NOT plusplus minusminus 
%token	dblakt dblt functionstmt truestmt falsestmt local nil onelcomm mullcomm string2 librfunc


%right  '='
%left   ','
%left   OR
%left   AND 
%nonassoc beq bne
%nonassoc '<' '>' lesseq greq
%left   '+' '-'
%left   '*' '/' '%'
%right NOT plusplus minusminus 
%left   '.' dblt
%left   '[' ']'
%left   '(' ')'


%type <express> lvalue
%type <express> fucid
%type <express> Nonamefucid
%type <express> return;
%type <express> idlist
%type <express> assginexpr
%type <express> const
%type <express> expr
%type <express> primary
%type <express> term
%type <express> truestmt
%type <express> elist
%type <express> objelist
%type <express> objectdef
%type <express> indexedelem
%type <express> indexed
%type <stringVal> ID
%type <express> member

%type <express> N1
%type <express> N2
%type <express> N3
%type <express> M
%type <express> whilestart
%type <express> if
%type <express> forstmt
%type <express> ifprefix
%type <express> elseprefix
%type <express> whilesecond
 %type <express> loopstmt
%type <express> forprefix
%type <express> breakstmt
%type <express> break
%type <express> continue
%type <express> continuestmt
%type <express> stmt
%type <express> block

%type <express> call
%type <express> normcall
%type <express> callsuffix

//KLEFTOG FIXED WARNINGS
%type <express> lib
%type <express> lassign
%type <express> returnstmt
//KLEFTOG FIXED WARNINGS

%type <stringVal> op
%type <stringVal> '+'






%union
{
	 char* stringVal;
	 int intValue;
	 double realVal;
	 struct expr* express;
}

%%
program:        teststmt2 {
/* 		printf("One progrⒶ m \n"); */
		}
		|/*empty*/
		;

teststmt2: 	stmt
		|teststmt2 stmt;		
		

stmt:     	expr ';'
		{ 
		  memberlvalue=0;
		  diaperasi=0;
		  diaperasi2=0;
		  exprnoname=0;
		  help=0;
		  pincounter=0;
		  fiveexpr=NULL;
		if(kleftis==1){
		    kleftis=0;
		    ErrorM("Using ProgramFunc as an lvalue");
		  }
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);//kati trelo
		  //head=ST_Insert( head , temp, GLOBAL , 0 , yylineno , 1 );
		}
		|if	
		{
/* 		  printf("Here we have statement if\n"); */
		}
		| while 
		{
/* 		  printf("Here we have statement while\n"); */
		}
		| for 
		{
/* 		  printf("Here we have statement for\n"); */
		}
		| return 
		{
/* 		  printf("Here we have statement return\n"); */
		}
		| block 
		{
/* 		  printf("Here we have statement block\n"); */
		// printf("BLOCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK $$=%d $1=%d\n",$$->sym->line,$1->sym->line);
		 $$=$1;  //perister for if
		
		}
		| funcdef 
		{
/* 		  printf("Here we have statement funcdef\n"); */
		}
		 
		|onelcomm
		{
/* 		  printf("Here we have one line comment\n"); */
		}
		|mullcomm
		{
/* 		  printf("Here we have multiline comment\n"); */
		}
		| break 
		{
		if(breakaccess){
		  break_head=break_insert(break_head,$1,loop_counter);   //insert break to breaklist
		  breakaccess=0;
		}
		
/* 		printf("Here we have statement break\n"); */
		}
		| continue 
		{  
		
		if(continueaccess){
		  continue_insert(continue_head,$1,loop_counter);   //insert break to breaklist
		  continueaccess=0;
		  }
		
		
/* 		printf("Here we have statement continue\n"); */
		}
		;

		

		
expr:		 assginexpr
		|expr op expr
	       { $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    emit(get_op($2),$1,$3,$$,0,lineofnewfile,yylineno);
		     
		         current_temp=$$; //perister
		
		    lineofnewfile++;
		}
		
		 
		|term
		{
		  $$=$1;
		}
		|
		;

op : 		'+'
	        {
		  $$="+";
/* 		  printf("Here we have operator +\n"); */
		}
		|'-'
		{ 
		  $$="-";
/* 		  printf("Here we have operator -'\n"); */
		}
		|'*'
		{  
		  $$="*";	
/* 		printf("Here we have operator *\n"); */
		}
		|'/'
		{ 
		  $$="/";
/* 		printf("Here we have operator /\n"); */
		}
		|'%'
		{ 
		  $$="%";
/* 		printf("Here we have operator percent \n"); */
		}
		|'>'
		{ 
		  $$=">";
/* 		printf("Here we have operator >\n"); */
		}
		|lesseq
		{ 
		  $$="<=";
/* 		printf("Here we have operator <=\n"); */
		}
		|'<'
		{ 
		  $$="<";
/* 		  printf("Here we have operator <\n"); */
		}
		|greq
		{ 
		  $$=">=";
/* 		printf("Here we have operator >=\n"); */
		}
		|beq
		{ 
		  $$="==";
/* 		printf("Here we have operator ==\n"); */
		}
		|bne
		{ 
		  $$="!=";
/* 		 printf("Here we have operator !=\n"); */
		}
		|AND
		{ 
		  $$="&&";
/* 		printf("Here we have operator &&\n"); */
		}
		|OR
		{ 
		  $$="||";
/* 		  printf("Here we have operator ||\n"); */
		}
		;

term:		'(' expr ')'
		{
		  		  
		   current_temp=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  $$=$2;
/* 		  printf("Here we have term (expr)\n"); */
		}
		|'-' expr
		{
		   $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  emit(uminus,$2,NULL,$$,0,lineofnewfile,yylineno);
		  lineofnewfile++;
/* 		  printf("Here we have term -expr\n"); */
		} 
		|NOT expr
		{
		
		  sixexpr=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  $$=sixexpr;
		  emit(not,$2,NULL,sixexpr,0,lineofnewfile,yylineno);
		  lineofnewfile++;
/* 		 printf("Here we have term !expr\n"); */
		}
		|plusplus lvalue
		{
		  oneexpr=constnewexpr(costnum_e,1);
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		   current_temp=$$; //perister
		  emit(add,$2,oneexpr,$$,0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,$$,NULL,$2,0,lineofnewfile,yylineno);
		   lineofnewfile++;
/* 		  printf("Here we have term ++expr\n"); */
		}
		|lvalue plusplus
		{
		  oneexpr=constnewexpr(costnum_e,1);
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    
		  emit(add,$1,oneexpr,$$,0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,$$,NULL,$1,0,lineofnewfile,yylineno);
		   lineofnewfile++;
/* 		  printf("Here we have term expr++\n"); */
		}
		|minusminus lvalue
		{
		  oneexpr=constnewexpr(costnum_e,1);
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		 
		  emit(sub,$2,oneexpr,$$,0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,$$,NULL,$2,0,lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have term --expr\n"); */
		}
		|lvalue minusminus
		{
		  oneexpr=constnewexpr(costnum_e,1);
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		
		  emit(sub,$1,oneexpr,$$,0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,$$,NULL,$1,0,lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have term expr--\n"); */
		}
		|primary{
		  $$=$1;
		  
		
/* 		  printf("Here we have primary expr\n"); */
		  
		}
		;

primary:	lvalue
		{
		  $$=$1;
/* 		  printf("Here we have primary lvalue\n"); */
		}
		|call
		{
		
	
		struct expr *tmpexprlook;
		
/* 		struct expr *exprlook(struct expr *head,char * name); */
			 
		
		 if(CALLi==0)
		  ST_DeleteTheLast(head);
		  
		  
		    
		 if(globalcurrentfunctions->name!=NULL) 
		  tempyytext=strdup(globalcurrentfunctions->name);
		 else 
		  tempyytext="noname";
		 
     // printf("\n\t\t\t\t\t\t\t\t\ttempyytext=%s-uuuu=%s\n",tempyytext,globalcurrentfunctions->name);  
		  if(!ST_Lookup(head,tempyytext,scope,USERFUNC,actfuc))
		  {
		    ErrorM("Function Not founded to call");
		  }
		  else
		  {
		   
		  
		  
		  if( strcmp(globalcurrentfunctions->name,"print")==0|| strcmp(globalcurrentfunctions->name,"input")==0|| strcmp(globalcurrentfunctions->name,"objectmemberkeys")==0|| strcmp(globalcurrentfunctions->name,"objecttotalmembers")==0|| strcmp(globalcurrentfunctions->name,"objectcopy")==0|| strcmp(globalcurrentfunctions->name,"totalarguments")==0|| strcmp(globalcurrentfunctions->name,"typeof")==0|| strcmp(globalcurrentfunctions->name,"strtonum")==0|| strcmp(globalcurrentfunctions->name,"sqrt")==0|| strcmp(globalcurrentfunctions->name,"cos")==0|| strcmp(globalcurrentfunctions->name,"sin")==0){
		   
		   
		    $$=lvaluenewexpr(libraryfunc_e,libraryfunc_s,strdup(globalcurrentfunctions->name),functionlocal,1,scope,yylineno);
		    emit(call,NULL,NULL,$$,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		       
		       
		    $$=tempexpr(conststring_e,var_s,programvarmvar,0,0,0);
		   
		    emit(getretval,NULL,NULL,$$,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    }
		  else{
		    tmpexprlook=exprlook(headforcall,globalcurrentfunctions->name);
		 //   tmpexprlook->sym->type=7;
		    
		    emit(call,NULL,NULL,tmpexprlook,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		      
		    
		    $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		   
		    emit(getretval,NULL,NULL,$$,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		       
		    }
// 		/* while($1!=NULL){
// 			 // emit(param,lvaluenewexpr(var_e,var_s,$1->sym->name,formalarg,1,scope,yylineno),NULL,NULL,0,lineofnewfile,yylineno);
// 			  //lineofnewfile++;
// 			  $1=$1->next;
// 		   }*/
		  }
		  
		 
		
		 
		  
/* 		 printf("Here we have primary call\n"); */
		}
		|objectdef
		{
		  $$=$1;
/* 		  printf("Heere we have primary objectdef\n"); */
		}
		|'(' funcdef ')'
		{
/* 		  printf("Here we have primary (funcdef)\n"); */
		}
		|const
		{
		  $$=$1;
/* 		  printf("Here we have primary const\n"); */
		}
		|lib
		;
		
lib:		librfunc
		{
		  
/* 		  ErrorM("Variable used as library function"); */
		}
		|librfunc '=' expr
		{
/* 		  ErrorM("Variable used as library function1"); */
		}
		|plusplus librfunc
		{
/* 		  ErrorM("Variable used as library function2"); */
		}
		|minusminus librfunc
		{
/* 		  ErrorM("Variable used as library function3"); */
		}
		|librfunc plusplus 
		{
/* 		  ErrorM("Variable used as library function4"); */
		}
		|librfunc minusminus
		{
/* 		  ErrorM("Variable used as library function5"); */
		}
		|librfunc '(' lexpr ')'
		{
		    
/* 		  printf("Here we have primary librfunc\n"); */
		}	
		|lib '.' ID
		{
/* 		  printf("Here we have librfunc.ID\n"); */
		}
		|lassign
		;
		
lassign: 	lib '.' ID '=' expr
		{
/* 		  printf("Here we have librfunc lvalue \n"); */
		};
		
lexpr:		expr{
/* 		    printf("lexpr\n"); */
		}
		|expr ',' lexpr
		;
		
call:		lvalue callsuffix
		{
		
		 
		 $$=$2;
		 
		   
		
		  
/* 		  printf("Here we have call lvalue callsuffix\n"); */
		}
		|'(' funcdef ')' '(' elist ')'
		{
/* 		  printf("Here we have call (funcdef) (elist)\n"); */
		}
		;

callsuffix:	normcall	
		{
		  $$=$1;
		  kleftis=2;
/* 		  printf("Here we have callsuffix normcall\n"); */
		}
		|methodcall
		{
/* 		  printf("Here we have callsuffix methodcall\n"); */
		}
		;

normcall:	 '(' elist ')'
		{
		  $$=$2;
		emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		lineofnewfile++;
		/*while($$!=NULL){
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%s\n",$$->sym->name);
		
		
		$$=$$->next;
		
		}*/
		
/* 		printf("Here we have normcall\n"); */
		}
		|normcall normcall
		;

methodcall:	dblt ID '(' elist ')'
		{
		
/* 		printf("Here we have methodcall\n"); */
		}
		|methodcall methodcall
		;

assginexpr:	lvalue '=' expr
		{
/* 		  printf("Here we have an assignment\n"); */
		  
		if( tableitem == 1 ){
		    create=0;
		    if( elistflag ==1 ){//if [x,x,x]
		      oneexpr=$3;
		      while( oneexpr->next != NULL ){
			oneexpr->type=tableitem_e;
			oneexpr=oneexpr->next;
		      }
/* 		      printf("\n\n"); */
		      elistflag=0;

		      $1->type=tableitem_e;
		      $1->index=$3;
		    
		     
		      emit(assign,objecttemp,NULL,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    else if( indexedflag ==1 ){//if [x:y,x:y,x:y]
		      oneexpr=$3;
		      while( oneexpr->next != NULL ){
			oneexpr->type=tableitem_e;
			oneexpr=oneexpr->next;
		      }
/* 		      printf("\n\n"); */
		      indexedflag=0;

		      $1->type=tableitem_e;
		      $1->index=$3;
		      
		      
		      emit(assign,objecttemp,NULL,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    else{
		      $1->type=tableitem_e;
		      $1->index=$3;
		     
		   
		      emit(tablecreate,NULL,NULL,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    tableitem=0;
		  }
		  else if( diaperasi2 == 1 ){
/* 		    ErrorM("Table not found"); */
		  }
		  else if ( diaperasi == 1 ){
/* 		    printf("\n!!DIAPERASI!!\n"); */
		    if( $1->index == NULL ){// diladi einai tis morfis x=t[x]
		    
		     
		      emit(tablegetelem,pinakastemp,$3,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		      diaperasi == 0;
		    }
		    else if( $3->index == NULL ){// diladi einai tis morfis t[x]=x
/* 		      printf("YO2"); */
		      diaperasi= 2;
		    }
		  }
		  else if ( diaperasi == 3 ){
/* 		    printf("\n!!DIAPERASI EMPTY!!\n"); */
		    if( $3 == NULL ){// diladi einai tis morfis x=t[x]
/* 		      printf("x=t[x]\n"); */
		      
		     
		      emit(tablegetelem,NULL,NULL,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }		    
		    else{// diladi einai tis morfis t[x]=x
/* 		      printf("t[x]=x\n"); */
		      
		      insertelement->index=$3;
		      pinakastemp->index=insertelement;
		      emit(tablesetelem,insertelement,$3,pinakastemp,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    diaperasi= 0;
		  }
		  else if ( diaperasi == 4 ){
/* 		    printf("\n!!DIAPERASI NEW ENTRY!!\n"); */
		    //printf("{%s=%f}",$1->sym->name,$3->numConst);
		    if( $3 == NULL ){// diladi einai tis morfis x=t[x]
/* 		      printf("x=t[x]\n"); */
		      
		   
		      emit(tablegetelem,NULL,NULL,$1,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }		    
		    else{// diladi einai tis morfis t[x]=x
/* 		      printf("t[x]=x\n"); */
		      oneexpr=pinakastemp;
		      oneexpr=oneexpr->index;//paw sto prwto stoixeio
		      twoexpr=oneexpr;//to prwto stoixeio
		      while( oneexpr != NULL ){
			  twoexpr=oneexpr;
			  oneexpr=oneexpr->next;
		      }
		      insertelement->index=$3;
		      twoexpr->next=insertelement;
		      
		      
		      emit(tablesetelem,insertelement,$3,pinakastemp,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    diaperasi= 0;
		  }
		  else if( memberlvalue == 1 ){
		    if( found == 1 ){
			      found=0;
			      memberlvalue=0;
			      counter=0;
			      quadtest=quads;
			      while( counter < currQuad ){
				if( strcmp(quadtest->result->sym->name,$1->sym->name) == 0 ){//an vrethei o pinakas
				  oneexpr=quadtest->result;
				  if( oneexpr->index != NULL ){//an exei indexes
				    oneexpr=oneexpr->index;//paw sto prwto stoixeio
				    if( oneexpr->index == NULL ){
				      ErrorR(":wrong type of table",$1->sym->name);
				      break;
				    }
				    twoexpr=oneexpr;//to prwto stoixeio
				    threeexpr=oneexpr;
/* 				    printf("\n"); */
				    while( oneexpr != NULL ){
/* 					printf("{%s}",oneexpr->sym->name); */
					if( oneexpr->sym!=NULL && $3->sym != NULL ){
					  if( strcmp($1->index->sym->name,oneexpr->sym->name) == 0 ){
					    oneexpr->index=$3;
					    coolflag=1;
					    break;
					  }
					}
					else {
					  if( $3->numConst == oneexpr->numConst ){
					    $$=oneexpr;
/* 					    printf("\n!!FOUND!!\n"); */
					    coolflag=1;
					    break;
					  }
					}
					twoexpr=oneexpr;
					oneexpr=oneexpr->next;
				    }
				    if( coolflag == 1 ){
				      //printf("\n{%s}\n",$$->strConst);
				       			     
				      emit(tablesetelem,$1->index,$3,quadtest->result,0,lineofnewfile,yylineno);
				         lineofnewfile++;
				      coolflag=0;
				      break;
				    }
				    if( coolflag == 0 ){
				      //insert
				      $1->index->index=$3;
				      twoexpr->next=$1->index;
/* 				      printf("\ninserted\n"); */
							      while( threeexpr != NULL ){
/* 								printf("{%s}",threeexpr->sym->name); */
								threeexpr=threeexpr->next;
							      }
/* 							      printf("\n"); */
							       
				      emit(tablesetelem,$1->index,$3,quadtest->result,0,lineofnewfile,yylineno);
				      lineofnewfile++;
				      break;
				    }
				    coolflag=0;
				  }
				  else{
				    //insert
/* 				    printf("\nempty inserted{%s->%s}\n",oneexpr->sym->name,$1->index->sym->name); */
				    if($3 != NULL){
				    }
				    $1->index->index=$3;
				    oneexpr->index=$1->index;
				     
				 
				    emit(tablesetelem,$1->index,$3,quadtest->result,0,lineofnewfile,yylineno);
				       lineofnewfile++;
				    break;
				  }
				}
				quadtest++;
				counter++;
			      }
		    }
		  }
		  else{
		   
		    $$=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    emit(assign,$3,NULL,$$,0,lineofnewfile,yylineno);
			lineofnewfile++;
		    emit(assign,$$,NULL,$1,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		  }
		  
		  
		  if ( diaperasi == 2 ){
/* 		    printf("\n!!update!!\n"); */
		    
		    insertelement->index=$3;
		    
		    emit(tablesetelem,insertelement,$3,pinakastemp,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    diaperasi == 0;
		  }
/* 		  printf("Here we have a table insertion\n"); */
		    //printf("\n[%s]\n",yytext);
		}
		;

funcdef:	functionstmt Nonamefucid '(' idlist ')'  block
		{
		 
		  activefunction--;
		  
		  $2->NumberOfLocalVar=NumOfLocVar;
		  $2->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,$2, 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmt\n"); */
		}
		|functionstmt fucid '(' idlist ')'  block
		{
	 
		   activefunction--;
		
		  $2->NumberOfLocalVar=NumOfLocVar;
		  $2->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,$2, 0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmtBlock\n"); */
		}
		|functionstmt fucid '('  ')'  block
		{
	 
		   activefunction--;
		
		  $2->NumberOfLocalVar=NumOfLocVar;
		  $2->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,$2, 0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmtBlock\n"); */
		}
		|functionstmt Nonamefucid '('  ')'  block
		{
		  
		  activefunction--;
		  
		  $2->NumberOfLocalVar=NumOfLocVar;
		  $2->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,$2, 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmt\n"); */
		}
		;

	
Nonamefucid: {  
		   activefunction++;
		  int i;
		  
		  NoNameInt++;
		  sprintf(bufferforint, "%d", NoNameInt); 
		 
		  strcpy (nonamefunctionall,nonamedefault);
		  strcat (nonamefunctionall,bufferforint); 
		  
		    
		  
		 
		  
		  i=ST_Lookup(head,nonamefunctionall,scope,USERFUNC,actfuc);
		  
		  if( i==0 ){
		    head=ST_Insert( head , nonamefunctionall, USERFUNC , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		    {   
		     
		      ST_InsArg(head,  headf->name, funct_scope, nonamefunctionall, scope); 
		    }
		    
		    
		    
		    
		    
		  }
		  
		   if(activefunction==0)
		      $$=lvaluenewexpr(programfunc_e,programfunc_s,strdup(nonamefunctionall),programvarmvar,0,scope,yylineno);		//NSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    else
		      $$=lvaluenewexpr(programfunc_e,programfunc_s,strdup(nonamefunctionall),functionlocal,0,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		  
		  funct_scope=scope;
		  symbol=strdup(nonamefunctionall);
		  actfuc++;
		  headf=F_Insert(headf,symbol);
	 
		  $$->IntermediateCodesLine=lineofnewfile;
		  whichoffset=1;
		  emit(funcstart, NULL, NULL,$$, 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have function Noname ID\n"); */
		  
		  };
		
		
fucid:		ID
		{
		
		  activefunction++;
		  
		  int i;
		  problem=0;
		  i=ST_Lookup(head,yytext,scope,USERFUNC,actfuc);
		  
	
		  if(problem)
		  {
		    i=2; 
		  }

		  if( i==0 ){
		    head=ST_Insert( head , yytext, USERFUNC , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		    {   
		      
		      ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		    }
		    
		    
		  }
		  
		  if(activefunction==0)
		      $$=lvaluenewexpr(programfunc_e,programfunc_s,strdup(yytext),programvarmvar,0,scope,yylineno);		//NSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    else
		      $$=lvaluenewexpr(programfunc_e,programfunc_s,strdup(yytext),functionlocal,0,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		  
		  funct_scope=scope;
		  symbol=strdup(yytext);
		  headf=F_Insert(headf,symbol);
		  actfuc++;
	 
		  $$->IntermediateCodesLine=lineofnewfile;
		  whichoffset=1;
		emit(funcstart, NULL, NULL,$$,0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have function name ID\n"); */
		}
		;

teststmt: 	stmt
		{
		 
		}
		|teststmt stmt
		{
		  
		};

block: 		'{' '}'
 {$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); } //perister for if end of statement
		|'{' 
		
		  
		{
			
			scope++;
		}
			teststmt 
		{
			int ready=0;
			
			scope--;
			  
			  
		
		if(actfuc!=0)
			{
			  
			   ST_Hide(head,headf->name,funct_scope);
			   
			   actfuc--;
			   headf=F_Delete(headf);
			   funct_scope--;
			 }
			 wehaveanstmt=0;
		}  
			 
			 '}'
		 { $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);  //perister for if end of statement
		    
			  	
			  };
		  
		
		


		

const:		INTEGER
		{
		  $$=constnewexpr(costnum_e,atoi(yytext));
		  fourexpr=$$;
/* 		  printf("Here we have const integer\n"); */
		}
		|FLOAT
		{
/* 		  printf("Here we have const float\n"); */
		}
		|string2
		{
		  $$=stringnewexpr(strdup(stringsave));
		  fourexpr=$$;
/* 		  printf("Here we have const string\n"); */
		}
		|nil
		{
/* 		  printf("Here we have const nil\n"); */
		}
		|truestmt
		{

		  $$=boolnewexpr(true);
		  fourexpr=$$;
/* 		  printf("Here we have const true\n"); */
		}
		|falsestmt
		{
		  $$=boolnewexpr(false);
		  fourexpr=$$;
/* 		  printf("Here we have const true\n"); */
/* 		  printf("Here we have const false\n"); */
		}
		;

objectdef:	'[' indexed ']'  
		{
		  indexedflag=1;
		  tableitem=1;  
		  $$=$2;
/* 		  printf("Here we have [x:y,x:y,x:y]\n"); */
		}
		|'[' objelist ']'
		{
		  indexedflag=1;
		  tableitem=1;
		  $$=$2;
/* 		  printf("Here we have [x,x,x] \n"); */
		}
		|'['  ']'
		{
		  tableitem=1;//new table
/* 		  printf("Here we have [ ] \n"); */
		}
		;


lvalue:  	ID
		{
		
		char * tmpyy;
		tmpyy=strdup(yytext);
		//tmpyy[strlen(tmpyy)-1] = '\0';
		//printf("%s",tmpyy);
		if(ST_LookupFunc(head,yytext,scope,USERFUNC)==1){
		    
		
		 
		    printf("\nvrike userfunc\n");
		
		  }else if(ST_LookupFunc(head,tmpyy,scope,LIBFUNC)==3){
		  
		    
		    
		    
		    
		    printf("\nvrike librfunc\n");
		  
		  }
		  else{
		  int i,j;
		  if(anelistbegin==0){
		    tempyytext=strdup(yytext);
		      
		      }
		  i=ST_Lookup(head,yytext,scope,GLOBAL,actfuc);
		  j=ST_Lookup(head,yytext,scope,LOCAL,actfuc);

		  if(j!=0){
		      i=j;
		  }

		  if(problem)
		  {
		    i=2; 
		  }
      
		  CALLi=i;
	      
		  if( i==0 ){
		  
		    if(scope==0){
		      head=ST_Insert( head , yytext, GLOBAL , scope , yylineno , 1 ,actfuc);
		    }
		    else{
		      head=ST_Insert( head , yytext, LOCAL , scope , yylineno , 1 ,actfuc);
		      if(actfuc!=0)
		      {   
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		    }
		    
		    //quad
		 
		 

		  }

		  
		  if(activefunction==0){
		    global_offset++;
		    $$=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,global_offset,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    
		    
		    fourexpr=$$;
		  }
		  else{
		    $$=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,offset,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    offset++;
		    fourexpr=$$;
		    NumOfLocVar++;
		    }
		    
		    
		    
/* 		  printf("Here we lvalue=%s\n",tempyytext); */}
		}
		| local ID
		{
		  int i;
		  i=ST_Lookup(head,yytext,scope,LOCAL,actfuc);
		  if( i==0 ){
		    head=ST_Insert( head , yytext, LOCAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
		
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      if(activefunction==0)
			$$=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      else{
			$$=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
			NumOfLocVar++;
			}
		  }
/* 		  printf("Here we have const local ID\n"); */
		}
		| dblakt ID
		{
		  int i;
		  
		  i=ST_Lookup(head,yytext,0,GLOBAL,actfuc);
		  //printf("\nname=%s scope=%d\n",yytext,scope);
		  if( i==0 && scope==0){
		    head=ST_Insert( head , yytext, GLOBAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
		
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      if(activefunction==0)
			$$=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      else
			$$=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      
		  }
		  else if( i==0 && scope!=0){
		    ErrorM("Global Variable doesnot exist");
		  }
/* 		  printf("Here we have const global ID\n"); */
		}
		| member
		{
		  $$=$1;
/* 		  printf("Here we have const member\n"); */
		}
		;

member: 	lvalue '.' ID
		{
		  memberlvalue=1;
		  quadtest=quads;
		  counter=0;
		  found=0;
		  oneexpr=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);
		  while( counter < currQuad ){
		    if( $1 == NULL ){
		      break;
		    }
		    
		    /**ERROR MUST BE IMPROVED TRWEI SEMG*/
		   /* if(strcmp(quadtest->result->sym->name,$1->sym->name) == 0 )
		      found=1;
		     }*/
		    quadtest++;
		    counter++;
		  }
		    if( $1 == NULL ){
		      break;
		    }
		  if( found == 0 ){
		    if(  $1->sym != NULL ) 
		      ErrorR("is not a table",$1->sym->name);
		    else
		      ErrorM("Not a table");
		  }
		  $1->index=oneexpr;//test
		  $$=$1;
		  printf("Here we have lvalue.ID\n");
		}
		| lvalue '[' expr ']'
		{
		  help++;
		  if( fourexpr != NULL ){
		    if( fourexpr->sym != NULL )
		    printf("->%s<-,%d\n",fourexpr->sym->name,help);
		    else if( fourexpr->boolConst != null )
		    printf("->%s<-,%d\n",bool_array[fourexpr->boolConst],help);
		    else
		    printf("->%f<-,%d\n",fourexpr->numConst,help);

		  }
		  if( fiveexpr == NULL ){
		    fiveexpr=$1;
		  }
		  counter=0;
		  quadtest=quads;
		  while( counter < currQuad ){
		    printf("\nSearching:%s\n",fiveexpr->sym->name);
		    if( strcmp(quadtest->result->sym->name,fiveexpr->sym->name) == 0 ){//an vrethei o pinakas
/* 		      printf("\nPINAKAS FOUND\n"); */
		      found=1;
		      pinakastemp=quadtest->result;//o pinakas
		      oneexpr=quadtest->result;
		      if( oneexpr->index != NULL ){//an exei indexes
			oneexpr=oneexpr->index;//paw sto prwto stoixeio
			if( oneexpr->index == NULL ){
			  ErrorR(":wrong type of table",fiveexpr->sym->name);
			  break;
			}
			twoexpr=oneexpr;//to prwto stoixeio
			threeexpr=oneexpr;
			printf("\n");
			while( oneexpr != NULL ){
			    if( oneexpr->sym != NULL && fourexpr->sym != NULL ){
			      if( strcmp(fourexpr->sym->name,oneexpr->sym->name) == 0 ){
				$$=oneexpr;
				fiveexpr=$$->index;
/* 				printf("\n!!FOUND!!\n"); */
				diaperasi=1;
				insertelement=fourexpr;
				coolflag=1;
				break;
			      }
			    }
			    else {
				if( fourexpr->numConst == oneexpr->numConst ){
				  $$=oneexpr;
				  fiveexpr=$$->index;
/* 				  printf("\n!!FOUND!!\n"); */
				  diaperasi=1;
				  insertelement=fourexpr;
				  coolflag=1;
				  break;
			      }
			    }
			    twoexpr=oneexpr;
			    oneexpr=oneexpr->next;
			}
			if( coolflag == 1 ){
			  //printf("\n{%s}\n",$$->strConst);
			  coolflag=0;
			  break;
			}
			if( coolflag == 0 ){
			  //insert
			  $$=NULL;
			  insertelement=$3;
			  fourexpr=NULL;
/* 			  printf("\n!!NOT FOUND!!\n"); */
			  if( help != 1)
			    diaperasi2=1;
			  else
			    diaperasi=4;
			  break;
			}
			coolflag=0;
		      }
		      else{
			//insert
			$$=NULL;
			insertelement=$3;
			if( help != 1)
			  diaperasi2=1;
			else
			  diaperasi=3;
			fourexpr=NULL;
/* 			printf("\nempty\n"); */
			break;
		      }
		    }
		    quadtest++;
		    counter++;
		  }
		  if( found == 0 ){
		      if( fourexpr->sym != NULL )
			ErrorR("is not a table",fourexpr->sym->name);
		      else
			ErrorM("Table doesnot exist");
		  }
		  found=0;
/* 		  printf("Here we have [ expr ]\n"); */
		}
		| call '.' ID
		{
/* 		  printf("Here we have call.ID\n"); */
		}
		| call '[' expr ']' 
		{
/* 		  printf("Here we have call[ expr ]\n"); */
		}
		;

		


idlist: 	ID
		{
		  scope++;
		  int i;
		  i=ST_Lookup(head,yytext,scope,FORMAL,actfuc);

		  
		  
	
		  if(problem)
		  {
		    i=2;
		  }

		  if( i==0 ){
		    head=ST_Insert( head , yytext, FORMAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
			
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
			$$=lvaluenewexpr(var_e,var_s,strdup(yytext),formalarg,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
			 
		/*	emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
			   lineofnewfile++;
		   */
		  }
/* 		  printf("Here we have ID\n"); */
		  scope--;
		}
		|idlist ','ID
		{
		  scope++;
		  int i;
		  i=ST_Lookup(head,yytext,scope,FORMAL,actfuc);
		  
		
		  if(problem)
		  {
		    i=2;
		  }

		  if( i==0 ){
		  head=ST_Insert( head , yytext, FORMAL , scope , yylineno , 1 ,actfuc);
		  if(actfuc!=0)
		      {   
			
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      $$=lvaluenewexpr(var_e,var_s,strdup(yytext),formalarg,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		     /*
		      emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		      */
		  }
/* 		  printf("Here we have idlist,ID\n"); */
		  scope--;
		 }
		 
		; 


elist:		expr
		{
		  //$$=$1;
		/*
		  emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		*/
/* 		  printf("Here we have lexpr\n"); */
		}
		|elist ','expr
		{
		
		  $3->next=$1;
		  $$=$3;
		 /* 
		  emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		 */
		
/* 		  printf("Here we have elist,expr\n"); */
		}
		; 
		
		
objelist:	expr
		{
		 
		  objecttemp=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(tablecreate,NULL,NULL,objecttemp,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		  coste=constnewexpr(costnum_e,pincounter);
		  coste->index=$1;
		  emit(tablesetelem,coste,$1,objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
		  pincounter++;
		  $$=coste;
/* 		  printf("Here we have objexpr\n"); */
		}
		|objelist ','expr
		{
		  coste=constnewexpr(costnum_e,pincounter);
		  coste->index=$3;
		  coste->next=$1;
		  $$=coste;

		  emit(tablesetelem,coste,$3,objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
		  pincounter++;
/* 		  printf("Here we have objelist,expr\n"); */
		}
		; 

indexedelem: 	'{'expr':'expr'}' 
		{
		  $2->index=$4;
		  $$=$2;
		  if( create == 0 ){
		 
		    objecttemp=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		    emit(tablecreate,NULL,NULL,objecttemp,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    create=1;
		  }
		 
		  emit(tablesetelem,$2,$4,objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have expr : expr\n"); */
		}
		;
		

indexed:   	indexedelem
		{
		  $$=$1;
/* 		  printf("Here we have indexedelem\n"); */
		}
		|indexed ','indexedelem			
		{
		  $3->next=$1;
		  $$=$3;
/* 		  printf("Here we have indexed ','indexedelem\n"); */
		}	
		; 
		



		
		
		
		
		//perister
		
		
		
		

		
elseprefix:	elsestmt  
		{ 
/* 		  printf("\t\t\t\t\t\tELSE 1111111111\n");  */
		
		  wehaveanstmt=1;
		 
		  
		 
		 $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		   emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		      lineofnewfile++;
		  } ;
		
   
		 
		 
ifprefix:	ifstmt '(' expr ')' 
		{//printf("BEGIN IFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"); 
		
		  wehaveanstmt=1;
		 
		  
		 emit(if_eq,current_temp,boolnewexpr(true),NULL,lineofnewfile+2,lineofnewfile,yylineno);  //perister  
		    lineofnewfile++;
		
	 
 
		 $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
		  
		   
		};



if: 		 ifprefix stmt   
		{ 	
/* 		 printf("\t\t\t\t\t\tif1\n"); */
		  
	 
		 
		 patchlabel($2->sym->line,$1->sym->line);
		
		 wehaveanstmt=1; } 
		 
               | ifprefix stmt elseprefix stmt
		  {  
/* 		    printf("\t\t\t\t\t\tif2\n"); */
		
		   
		     patchlabel($2->sym->line+1,$1->sym->line);
		     patchlabel($4->sym->line,$3->sym->line);
		
		   };
		  
		     
		
	 
	
	 
		
		  
	
	
	 
 
return: 	returnstmt ';'
		{
		  if( scope == 0 ){
		    ErrorM("Use of 'return' while not in a funtion");
		  }else{
		   
		  emit(ret,NULL, NULL, NULL, 0, lineofnewfile,yylineno);
		  lineofnewfile++;}
/* 		  printf("Here we have return;\n"); */
		}	
		| returnstmt expr ';'
		{
		  if( scope == 0 ){
		    ErrorM("Use of 'return' while not in a funtion");
		  }else{
		   
		 emit(ret,NULL, NULL, $2, 0, lineofnewfile,yylineno);
		 lineofnewfile++;}
/* 		  printf("Here we have return expr;\n"); */
		 }
		 | returnstmt functionstmt ';'
		;  	
 



		/*
break: 		breakstmt  ';'  
		{  
		  if( scope == 0 ){
		    breakaccess=0;
		    ErrorM("Use of 'break' while not in a loop");
		  }
		  else if(wehaveanstmt!=1){
		    ErrorM("Use of 'break' while not in a loop");
		  }
		  else  //we are in loop
		  {$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		   emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		   lineofnewfile++; 
		
		  	  breakaccess=1; 
		   }}	
		; 	*/
		  

	loopstart:{
if(loop_counter==0)
 {break_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init breaklist with null
  continue_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init continuelist with null
 }
loop_counter++;};

loopend:{loop_counter--;
 
};
	
loopstmt:loopstart stmt loopend
    {$$=$2;
    
    
    };		
	
				
whilestart:  whilestmt
		{     
/* 		      printf("*****************************************************************************************************************************************\n"); */
		     
		
		      $$=tempexpr(constbool_e,var_s,programvarmvar,0,0,lineofnewfile);
		  
		   
		  
		  };	
		  
		 	
				
whilesecond:  '('expr')'
		{  emit(if_eq,current_temp,boolnewexpr(true),NULL,lineofnewfile+2,lineofnewfile,yylineno);
		  lineofnewfile++;
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		    lineofnewfile++;
		    $$=tempexpr(constbool_e,var_s,programvarmvar,0,0,lineofnewfile);
		  ;};
		  
		
		

while: 		 whilestart whilesecond loopstmt
{              
		wehaveanstmt=1;
		
		emit(jump,NULL,NULL,NULL,$1->sym->line,lineofnewfile,yylineno);
		 lineofnewfile++;
		 patchlabel(lineofnewfile,$2->sym->line-1);
	      patchbreak(break_head,lineofnewfile,loop_counter+1);   //??????
	      
/* 	      printf("WHILESTART LINE=%d\n",$1->sym->line); */
		 patchcontinue(continue_head,$1->sym->line,loop_counter+1);   //??????
		};			
 		
 	
 	
N1:{//printf("N11111111111111111111111111111111111111111111111111111111\n");
	$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
	lineofnewfile++;
 

};
N2:
{	$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("N2222222222222222222222222222222222222222222\n");
	 emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
	
	};
N3:{	$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("N333333333333333333333333333333333\n");
	 emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
	};
M:{	$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	};
		
forprefix:forstmt '('elist';' M expr';'
	{
	  //break_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init breaklist with null
	 //continue_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init continuelist with n
	$$=$5; 
	$$->next=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);;
	emit(if_eq,current_temp,boolnewexpr(true),NULL,0,lineofnewfile,yylineno);
	 lineofnewfile++; 
	
	};
	
		
  
for:		forprefix N1 elist')' N2 loopstmt N3  
		{
		  wehaveanstmt=1;
		//  printf("forrrrrrr $1=%d \n",$1->sym->line);
		    patchlabel($5->sym->line+1,$1->next->sym->line);//ok
		    patchlabel(lineofnewfile,$2->sym->line); //ok
	             patchlabel($1->sym->line,$5->sym->line);//ok
	            
	            patchlabel($2->sym->line+1,$7->sym->line);
	            
	            
	            patchbreak(break_head,lineofnewfile,loop_counter+1);
	           patchcontinue(continue_head,$1->sym->line,loop_counter+1);
	             
		 
/* 		  printf("Here we have for(elist;expr;elist)\n"); */
		}	
		;	 
	 


break: 		breakstmt  ';'  
		{  
		  if( scope == 0 ){
		    breakaccess=0;
		    ErrorM("Use of 'break' while not in a loop");
		  } 
		  else  //we are in loop
		  {
		  printf("BREAKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n");
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		   emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		   lineofnewfile++; 
		
		  	  breakaccess=1; 
		   }};	


continue: 	continuestmt   ';' 
		{
		
		
		  if( scope == 0 ){
		    ErrorM("Use of 'continue' while not in a loop");
		  }
		  else
		  {
		  printf("CONTINUe EMIT\n");
		  $$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
		  continueaccess=1; //why????
		  }
/* 		  printf("Here we have continue;\n"); */
		}	
		;		
/*
continue: 	continuestmt   ';' 
		{
		
		
		  if( scope == 0 ){
		    ErrorM("Use of 'continue' while not in a loop");
		  }
		  else
		  {$$=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
		  
		  }
 		  printf("Here we have continue;\n");  
		}	
		;				*/		

		
		
	
		
%%
int yyerror (char* yaccProvidedMessage)
{

  fprintf(stderr,"%s:at line %d,before token: %s\n",yaccProvidedMessage, yylineno,yytext);
  fprintf(stderr,"INPUT NOT VALID\n");
  exit(0);

}



//funcdef  function [id] (idlist) block

int main(int argc,char** argv){
  if(argc >1){
    if(!(yyin=fopen(argv[1],"r"))){
      fprintf(stderr,"Cannot read file %s\n",argv[1]);
      return 1;
    }
    
    }else
      yyin=stdin;
    
    //Insert Library Functions
    head=ST_Insert( head , "print", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "input", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objectmemberkeys", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objecttotalmembers", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objectcopy", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "totalarguments", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "argument", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "typeof", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "strtonum", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "sqrt", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "cos", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "sin", LIBFUNC , scope , yylineno , 1 ,-1);

    yyparse();
    ST_Print (head);
   // PrintFunc(head);
    print_lines();
    print_quad (quads);
    produce_quad (quads);
    produce_ins(quads);

      
   print_incomplete_jump();
    patch_inclomplete_jumps();//new perister  


    produce_finalquad(instructions);
    //printreturnList(returnLists);
   

    ReplaceJumpsFromFuncs(instructions); 
     
     arraysnot=1;
     produce_finalquad(instructions);
     
     
    print_taddresses(quads); //new
    create_bin(instructions);
    system("./exc"); 
    return 0;
    }
    