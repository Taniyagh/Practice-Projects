// find sum of all left leaves
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
///////////////////////////////////////////
bool isLeaf(node *p)
{
   if (p == NULL)
       return false;
       
   if (p->left == NULL && p->right == NULL)
       return true;
       
   return false;
}
 
///////////////////////////////////////////////////////////////
int lls(node *p)
{
    int s = 0;
 
    if (p != NULL)
    {
       if (isLeaf(p->left))
            s = s + p->left->data;
       else 
            s = s + lls(p->left);
       
       s = s + lls(p->right);
    }
    return s;
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
   
     
    cout<<lls( r);
 
    getch();
}
