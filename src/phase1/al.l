%{
#include <math.h>
#include <string.h>
#include <assert.h>

#ifdef HAVE_ASPRINTF
#define _GNU_SOURCE
#include <stdio.h>
#endif
#include "parser.h"

extern int scope;
extern char* symbol;
extern int funct_scope;
extern int actif;
extern int anelistbegin;
extern char* stringsave;

int wno = 0; /*count of words*/
struct alpha_token_t {
  unsigned int     numline;
  unsigned int     numToken;
  char *content;
  char *type;
  struct alpha_token_t *next;
 };

struct alpha_token_t *head;

int alpha_yylex (struct alpha_token_t* yylval);
void alpha_yylex_print (void);
char *append(const char *oldstring, const char c);


%}

%option noyywrap
%option yylineno
%x CMNT
%option nounput


KEYWORD (if|else|while|for|function|return|break|continue|and|not|or|local|true|false|nil)

SYMBOL ("."|","|"{"|"}"|"["|"]"|"("|")"|";"|":"|"::"|"..")
OPERATOR ("="|"+"|"-"|"*"|"/"|"%"|"=="|"!="|"++"|"--"|">"|"<"|">="|"<=")
DIGIT    [0-9]
ONELETTER [a-zA-Z]
id       {ONELETTER}+({ONELETTER}+|{DIGIT}+|"_"+)+|{KEYWORD}({ONELETTER}+|{DIGIT}+|{KEYWORD}+)*|{ONELETTER}
integer [0-9]+
%%


{DIGIT}+"."{DIGIT}*      {
	    wno++;
	    return FLOAT;
            }

"," {return ',';}
"." {return '.';}
"{" { 
     // scope++;
      return '{';}
"}" {
   // scope--;
    return '}';}
"[" {return '[';}
"]" {return ']';}
"(" {
      anelistbegin=1;
      return '(';}
")" {
      anelistbegin=0;
      return ')';}
";" {return ';';}
":" {return ':';}
"::" {return dblakt;}
".." {return dblt;}


"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"%" {return '%';}
"++" {return plusplus;}
"--" {return minusminus;}
"=" {return '=';}
"<" {return '<';}
">" {return '>';}
"<=" {return lesseq;}
">=" {return greq;}
"==" {return beq;}
"!=" {return bne;}
"not" {return NOT;}
"and" {return AND;}
"or" {return OR;}




"if" {
      actif=1;
      return ifstmt;}
"while" {
  actif=1;
return whilestmt;}
"for" {
  actif=1;
return forstmt;}
"return" {return returnstmt;}
"else" {
 actif=1;
return elsestmt;}
"break" {return breakstmt;}
"continue" {return continuestmt;}

"function" {

return functionstmt;}
"local" {return local;}
"true" {return truestmt;}
"false" {return falsestmt;}
"nil" {return nil;}


{integer} {return INTEGER;}
{id} {return ID;}	





"//" {   //one line comment
    char c;
 
      

    int found_newline=0;	//boolean for newline or EOF
    
    while(found_newline==0)
    {c=input();
    
     if(c=='\n') 
       { found_newline=1;}
     else if(c==EOF)    
        { found_newline=1;}
       }
    BEGIN(0);
    return onelcomm;
}

"/*" {
    char c;
    int  comment_close=0; //boolean
    int nested_comment=0;   //counter for how many active nested comments exist
      
 
 
  while(comment_close==0){
    c=input();
   
   if((c==EOF)&&(comment_close==0))//file ends and comment hasnt closed
       {printf("ERROR!Comment not closed!\n");
       comment_close=1;}   //to end loop
    else if((c=='/'))		//nested comment open
       {c=input();
	  if('*'){
	    nested_comment++;
	  }
    }
    else if(c=='*'){
      c=input(); 
	if(c=='/'){               //comment or nested comment close
	  if(nested_comment==0){
	    comment_close=1;
	  }
	  else if(nested_comment!=0){
	    nested_comment--;   }
	  }
    }
  }
               
         BEGIN(0);   
 
	 return mullcomm;
}

"\""     {   				 //string
            char *string="";
            
            int i=0;
          //  strcpy(string," ");
            
            int closing_quote=0;
             char    c;
             

             while( closing_quote==0)
             {c=input();    
               
             if((c==EOF)&&(closing_quote==0))
                {printf("ERROR! STRING NOT CLOSED\n");
                closing_quote=1;}
             else if(c=='\"')
            { 
            closing_quote=1;}
             else if(c=='\\') 
              {c=input();
              if(c=='t')
              {string=append(string,'	');}
               if(c=='n')
              {string=append(string,'\n');}
	      if(c=='\\')
              {string=append(string,'\\');}
              }
            
            
            else
            {string=append(string,c);}
            
            i++;
/*             if(i==10000000000000000)closing_quote=1; */
            
            } 
          stringsave=strdup(string); 
	  return string2;
	  
}
                       
    
    
[ \n]+ {printf("\n");}

[ \t]+ {}
  
.  {fprintf(stderr,"Cannot match char %s with any rule\n",yytext);}

%%

int alpha_yylex (struct alpha_token_t* yylval){
  struct alpha_token_t *current,*temp;
  temp=(struct alpha_token_t*) malloc (sizeof (struct alpha_token_t));
  temp->content=(char*) malloc (sizeof (char));
  temp->type=(char*) malloc (sizeof (char));
  memcpy(temp->content, yylval->content, sizeof(struct alpha_token_t));
  memcpy(temp->type, yylval->type, strlen(yylval->type)+1);
  temp->numline=yylval->numline;
  temp->numToken=yylval->numToken;
  temp->next=NULL;
  
  current=head;
  /*if alpha_token_t is empty*/
  if(current == NULL) {
    //printf( "LISTlala%d: #%d	\"%s\"	%s\n",temp->numline,temp->numToken,temp->content,temp->type );
    head=temp;
    return 0;
  }
  /*if alpha_token_t is not empty*/
  else {
    /*while alpha_token_t hasnt ended*/
    while(current->next != NULL){
      current=current->next;
    }
    /*if we reached end of alpha_token_t*/
    current->next=temp;
   // printf( "lalahead%d: #%d	\"%s\"	%s\n",head->numline,head->numToken,head->content,head->type );
    //printf( "LIST2%d: #%d	\"%s\"	%s\n",temp->numline,temp->numToken,temp->content,temp->type );
    return 0;
  }
}

void alpha_yylex_print (void) {
  
  struct alpha_token_t *current;
    current=head;
  
    
    
    if(current!=NULL){
      while(current!=NULL){
	  printf( "%d: #%d	\"%s\"	%s\n",current->numline,current->numToken,current->content,current->type );
	  current=current->next;
	
	  
	}
    }else{
      printf("Empty List\n");
    }
  
}

char *append(const char *oldstring, const char c)
{
    int result;
    char *newstring;
    result = asprintf(&newstring, "%s%c", oldstring, c);
    if (result == -1) newstring = NULL;
    return newstring;
}

//if|else|while|for|function|return|break|continue|and|not|or|local|true|false|nil
//SYMBOL ("."|","|"{"|"}"|"["|"]"|"("|")"|";"|":"|"::"|"..")
//("="|"+"|"-"|"*"|"/"|"%"|"=="|"!="|"++"|"--"|">"|"<"|">="|"<=")