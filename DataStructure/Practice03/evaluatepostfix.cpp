//Evaluation of Postfix Expression
#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
////////////////////////////////////
struct Stack
{
    int      *a;
	int      top;
    unsigned c;
};
///////////////////////////////////////////////////////////////////////
struct Stack* create( unsigned c )
{
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    if (!s) return NULL;
    s->top = -1;
    s->c = c;
    s->a = (int*) malloc(s->c * sizeof(int));
    if (!s->a) return NULL;
    return s;
}
///////////////////////////////////////////////////////////////////////
int isEmpty(struct Stack* s)
{
    return s->top == -1 ;
}
///////////////////////////////////////////////////////////////////////
char peek(struct Stack* s)
{
    return s->a[s->top];
}
///////////////////////////////////////////////////////////////////////
char pop(struct Stack* s)
{
    if (!isEmpty(s))
        return s->a[s->top--] ;
    return '$';
}
////////////////////////////////////////////////////////
void push(struct Stack* s, char op)
{
    s->a[++s->top] = op;
}
////////////////////////////////////////////////////////////
int f(char* e)
{
    int a,b,i;
	struct Stack* s;
	s = create(strlen(e));
    if (!s) return -1;
    
	for (i = 0; e[i]; ++i)
    {
        if (isdigit(e[i]))
            push(s, e[i] - '0');
        else
        {
            a = pop(s);
            b = pop(s);
            switch (e[i])
            {
             case '+': push(s, b + a);  break;
             case '-': push(s, b - a);  break;
             case '*': push(s, b * a);  break;
             case '/': push(s, b / a);  break;
            }
        }
    }
    return pop(s);
}
//////////////////////////////////////////////////////////
int main()
{
	//infix: 3+5*(8-2)
    char  e[]="3582-*+";
    
	cout<<f(e);
   
    getch();
}
