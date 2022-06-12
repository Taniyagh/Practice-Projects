// sum number in all paths from root to leaves
#include<iostream>
#include<conio.h>
using namespace std;
///////////////////////////////////////////
struct node
{
    int            data;
    struct node*   left;
    struct node*   right;
};
 
///////////////////////////////////////////
struct node* create(int item)
{
    struct node* n;
	n= new(struct node);
    
	n->data  = item;
    n->left  = NULL;
    n->right = NULL;
 
    return(n);
}

///////////////////////////////////////////////////////////////
int  tps(struct node *p, int x)
{
    if (p == NULL)  
	    return 0;
 
    x = (x*10 + p->data);
 
    if (p->left == NULL && p->right == NULL)
         return x;
 
    return tps(p->left, x) + tps(p->right, x);
}
 

////////////////////////////////////////////////////////////////
int f(struct node *p)
{
    return tps(p, 0);
}

///////////////////////////////////////////

int main()
{
    struct node *r;
	
	r                     = create(1);
	
    r->left               = create(2);
    r->right              = create(3);
    
    r->left->left         = create(4);
    r->left->right        = create(5);
 
    r->left->right->left  = create(6);
     
    cout<<f( r);
 
    getch();
}
