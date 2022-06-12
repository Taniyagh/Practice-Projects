//infix  to postfix
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
///////////////////////////////////////////////////////
struct Stack
{
    int       *a;
	int       top;
    unsigned  c;
};
///////////////////////////////////////////////////////
struct Stack* create( unsigned c )
{
    struct Stack  *s;
    
	s = (struct Stack *) malloc(sizeof(struct Stack));

    if (!s) return NULL;

    s->top = -1;
    
    s->c = c;

    s->a = (int*) malloc(s->c * sizeof(int));

    if (!s->a)  return NULL;
        
    return s;
}
///////////////////////////////////////////////////////
int isEmpty(struct Stack* s)
{
    return s->top == -1;
}
///////////////////////////////////////////////////////
char peek(struct Stack* s)
{
    return s->a[s->top];
}
///////////////////////////////////////////////////////
char pop(struct Stack* s)
{
    if (!isEmpty(s))
        return s->a[s->top--];
    return '$';
}
///////////////////////////////////////////////////////
void push(struct Stack* s, char op)
{
    s->a[++s->top] = op;
}
///////////////////////////////////////////////////////
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
///////////////////////////////////////////////////////
int Prec(char ch)
{
    switch (ch)
    {
      case '+': case '-': return 1; break;
      case '*': case '/': return 2; break;
      case '^': return 3;
    }
    return -1;
}
///////////////////////////////////////////////////////
int inToPost(char* e)
{
    int i,k;
    struct Stack* s;
	s = create(strlen(e));
	
    if(!s) 
        return -1 ;

    for (i=0, k=-1  ; e[i]  ; ++i)
    {
        if (isOperand(e[i]))
            e[++k] = e[i];
        
        else if (e[i] == '(')
            push(s, e[i]);
        
        else if (e[i] == ')')
        {
            while (!isEmpty(s) && peek(s) != '(')
                e[++k] = pop(s);
        
		    if (!isEmpty(s) && peek(s) != '(')
                return -1;              
            else
                pop(s);
        }
        else // operator
        {
            while (!isEmpty(s) && Prec(e[i]) <= Prec(peek(s)))
                e[++k] = pop(s);
                
            push(s, e[i]);
        }
    }
    // pop all the operators 
    while (!isEmpty(s))
        e[++k] = pop(s );

    e[++k] = '\0';
    cout<<e;
}
////////////////////////////////////////////////////////////////////////
int main()
{
    char  e[]="a+b/(c*d+e)-f^g";
    
	inToPost(e);

    getch();
}
