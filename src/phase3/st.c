#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 
#include <stdint.h>


 
int count = 0;
struct node
{   unsigned int offset;
    char *symbol_name;
    char *function_name;
    struct node *next;
}*top,*top1,*top2;
 
int get_top();
void push(int offset,char *symbol_name,char *function_name);
void pop();
void IsEmptyStack();
void printStack();
void stack_count();
void MakeEmptyStack();
 


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
    {   top =(struct node *)malloc(1*sizeof(struct node));
        top->next =NULL;
        top->offset = offset;
	top->symbol_name=symbol_name;
	 
	top->function_name=function_name;
	printf("ok1\n");
    }
    else
    {   top2 =(struct node *)malloc(1*sizeof(struct node));
        top2->next = top;
        top2->offset = offset;
	top2->symbol_name=symbol_name;
	top2->function_name=function_name;
	//top->function_name=function_name;
        top = top2;
	printf("ok2\n");}
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
    printf("\n Popped offset=%d  symbol=%s\n", top->offset,top->symbol_name);
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

void main(void)
{  MakeEmptyStack();
    push(0,"x","f");
    push(1,"y","f");
    push(2,"z","f");
    push(3,"w","f");
    
    
    push(0,"x1","g");
    push(1,"y1","g");
    push(2,"z1","g");
    push(3,"w1","g");
     
  /*  push(0,"x","g");
    push(1,"y","g");
    push(2,"z","g");
   push(3,"w","g"); */
   pop();
   printStack();
 //printf("top->function=%s",top->function_name);
  
}