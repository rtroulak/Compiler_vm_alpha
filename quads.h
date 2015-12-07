#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define EXPAND_SIZE 1204
#define CURR_SIZE (total*sizeof(struct quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quads)+CURR_SIZE)

#define EXPAND_SIZEvm 1204
#define CURR_SIZEvm (totalvm*sizeof(struct instruction))
#define NEW_SIZEvm (EXPAND_SIZEvm*sizeof(instructions)+CURR_SIZEvm)

unsigned int total;
unsigned int currQuad;

unsigned int totalvm;
unsigned int currQuadvm;

//HEADS
struct quad *quads;

struct instruction *instructions;

struct returnList *returnLists;

struct incomplete_jump *in_head=NULL;  //new perister
unsigned int in_total=0;		//new perister
//phase3
enum expr_t{
  var_e,
  tableitem_e,
  programfunc_e,
  libraryfunc_e,
  arithexpr_e,
  boolexpr_e,
  nevitable_e,
  costnum_e,
  constbool_e,
  conststring_e,
  nil_e
};    


enum iopcode{
  assign,add,sub,
  mul,divi,mod,
  uminus,if_eq,if_noteq,
  if_lesseq,if_greatereq,if_less,
  if_greater,call,param,
  ret,getretval,funcstart,
  funcend,tablecreate,
  tablegetelem,tablesetelem
  ,and,or,not  ,jump ,assing ,eq_assign 
};

enum vmopcode{
  ASSIGN,ADD,SUB,
  MUL,DIVI,MOD,
  UMINUS,IF_EQ,IF_NOTEQ,
  IF_LESSEQ,IFGREATEREQ,IF_LESS,
  IF_GREATER,CALL,PARAM,
  RET,GETRETVAL,FUNCSTART,
  FUNCEND,TABLECREATE,
  TABLEGETELEM,TABLESETELEM
  ,ANDI,ORI,NOTI,JUMP ,ASSING ,EQ_ASSIGN 
};
  
  
enum scopespace_t{
  programvarmvar,
  functionlocal,
  formalarg
};
  
enum symbol_t{var_s,programfunc_s,libraryfunc_s};

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

 
enum bool{
  true,
  false,
  null
};  
  
struct symbol{
   enum symbol_t 	 type;
   char*    	 name;
   enum scopespace_t  space;
   unsigned int  offset;
   unsigned int  scope;
   unsigned int   line;
};

struct instruction{
  enum vmopcode opcode;
  struct vmarg* result;
  struct vmarg* arg1;
  struct vmarg* arg2;
  unsigned srcLine;
};
  
unsigned int programVarOffset=0;
unsigned int functionLocalOffset=0;
unsigned int formalArgOffset=0;
unsigned int scopeSpaceCounter=1;

  
struct expr{
  enum expr_t type;
  struct  symbol* sym;
  struct  expr* index;
  double numConst;
  char* strConst;
  unsigned int NumberOfLocalVar;
  unsigned int IntermediateCodesLine;
  unsigned int IntermediateCodesLineENDforfunc;
  enum bool boolConst;
  struct  expr* next;
};
 

struct vmarg { 
  enum vmarg_t type;
  unsigned val;
  char* name;
  char* func_name;
};




struct quad{
  enum iopcode op;
  struct expr* result;
  struct expr* arg1;
  struct  expr* arg2;
  unsigned int label;
  unsigned int line;
  unsigned int iline;
  unsigned int taddress;
};
   
struct incomplete_jump{
  unsigned int instrNo;
  unsigned int iaddress;
  struct incomplete_jump *next;
};

char* bool_array[3] = {
      ""
      "true",
      "false",
      "null"
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

char* iopcode_array[27] = {
      ""
      "ASSIGN",
      "ADD",
      "SUB",
      "MUL",
      "DIV",
      "MOD",
      "UMINUS",
      "IF_EQ",
      "IF_NOTEQ",
      "IF_LESSEQ",
      "IF_GREATEREQ",
      "IF_LESS",
      "IFGREATER",
      "CALL",
      "PARAM",
      "RETURN",
      "GETRETURNVAL",
      "FUNCSTART",
      "FUNCEND",
      "TABLECREATE",
      "TABLEGETELEM",
      "TABLESETELEM",
      "AND",
      "OR",
      "NOT","JUMP" ,"ASSING" 
};

char* vmopcode_array[28] = {
      ""
      "ASSIGN",
      "ADD",
      "SUB",
      "MUL",
      "DIV",
      "MOD",
      "UMINUS",
      "JEQ",
      "JNE",
      "JLE",
      "JGE",
      "JLT",
      "JGT",
      "CALLFUNC",
      "PUSHARG",
      "RETURN",
      "GETRETURNVAL",
      "FUNCSTART",
      "FUNCEND",
      "TABLECREATE",
      "TABLEGETELEM",
      "TABLESETELEM",
      "AND",
      "OR",
      "NOT","JUMP" ,"ASSING" ,"JEQ_ASSIGN" 
};
char* expr_t_array[11] = {
      ""
       "var_e",
      "tableitem_e",
      "programfunc_e",
      "libraryfunc_e",
      "arithexpr_e",
      "boolexpr_e",
      "nevitable_e",
      "costnum_e",
      "constbool_e",
      "conststring_e",
      "nil_e"
};
char* scopespace_array[3]={
  "programvarmvar",
  "functionlocal",
  "formalarg"
  
};

char* symboltype_array[3]={
  "var_s","programfunc_s","libraryfunc_s"
  
};
      
void print_lines();     
void print_quad (struct quad* quad_elem);
void expand(void);
void emit(
     enum iopcode  op,
     struct expr*    arg1,
     struct expr*    arg2,
     struct expr*     result,
     unsigned int   label,unsigned int iline,
     unsigned int     line
	 );
struct expr* lvaluenewexpr(enum expr_t type,enum symbol_t  symbol_type,char* name,enum scopespace_t  space,unsigned int  offset,unsigned int  scope,unsigned int   line);
struct expr* tempexpr(enum expr_t type,enum symbol_t  symbol_type,enum scopespace_t  space,unsigned int  offset,unsigned int  scope,unsigned int   line);
struct expr* constnewexpr(enum expr_t type,double numConst);
struct expr* boolnewexpr(enum bool boolConst);
struct expr* stringnewexpr(char* strConst);
enum iopcode get_op(char *op);
void produce_quad (struct quad *quad_elem);
void breaklist_expr_patch (struct expr *expr_head);
void continue_expr_patch (struct expr *expr_head);
void patchlabel(unsigned int label,unsigned int line_of_quad);


void patchbreak(struct expr* break_head,unsigned int line_of_end,double loop_num);
 
void patchcontinue(struct expr* continue_head,unsigned int line_of_end,double loop_num); 
struct expr *continue_insert(struct expr* continue_head,struct expr* new_continue,double loop_count);
struct expr *break_insert(struct expr* break_head,struct expr* new_break,double loop_count);
struct vmarg* make_operand(struct expr* e);
unsigned new_string();
unsigned new_const();
unsigned new_lib();
void expandvm(void);
unsigned new_global();
unsigned new_local();
unsigned new_userfunc();
void produce_ins(struct quad *quad_elem);
struct vmarg* find_temp(char* name,struct instruction *in);




/*returnList */
 struct returnList{
   
   unsigned int jumpList;
   char *NameOfFunc;
   char *nameofval;
   struct returnList* next;
};

void returnListInsert(struct returnList *returnList,int jump,char *name,char *nameval);
void returnListLookUp(struct returnList *returnList,char *fucname,int line);



/*STACK FUNCS*/
int count = 0;
struct funcstack
{   unsigned int offset;
    char *symbol_name;
    char *function_name;
    struct funcstack *next;
}*top,*top1,*top2;
 
int get_top();
void push(int offset,char *symbol_name,char *function_name);
void pop();
void IsEmptyStack();
void printStack();
void stack_count();
void MakeEmptyStack();
struct vmarg* clean_make_operand(struct expr* e);
struct vmarg* find_arg(char* name,struct instruction *in);
 
void ReplaceJumpsFromFuncs(struct instruction *instruction);
void add_incomplete_jump(unsigned int instrNo,unsigned int iaddress);  //new perister
void print_incomplete_jump();  //new perister
void print_taddresses(struct quad *quad_elem); //new perister
void patch_inclomplete_jumps(); //new perister
int create_bin(struct instruction* instr);
int check_arg(char* name,unsigned int type,struct instruction *in);