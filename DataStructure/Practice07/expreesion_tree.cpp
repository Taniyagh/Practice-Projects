// expression tree
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
 
//////////////////////////
struct node
{
    char   value;
    node*  left;
    node*  right;
};
///////////////////////////
node* create(int item)
{
    node *t;
	
	t = new node;
    t->value = item;
    t->left = t->right = NULL;
    return t;
};
////////////////////////////////////////////////////////////////

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                    return true;
    return false;
}
 
/////////////////////////////////////////////////////////////////
void inorder(node *t)
{
    if(t)
    {
        inorder(t->left);
        cout<< t->value;
        inorder(t->right);
    }
}
/////////////////////////////////////

node* et(char a[])
{
    stack<node *> s;
    node *t, *t1, *t2;
 
    for (int i=0; i<strlen(a); i++)
    {
        if (!isOperator(a[i]))
        {
            t = create(a[i]);
            s.push(t);
        }
        else // operator
        {
            t = create(a[i]);
 
            t1 = s.top(); 
            s.pop();      
            t2 = s.top();
            s.pop();
 
            t->right = t1;
            t->left  = t2;
 
            s.push(t);
        }
    }
 
    t = s.top();
    s.pop();
 
    return t;
}
 
//////////////////////////////////
int main()
{
    node* r;

    char x[] = "ab+cd/*";
	
	r = et(x);
    
	inorder(r);
    
    getch();
}
