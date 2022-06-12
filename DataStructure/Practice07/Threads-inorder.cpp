// Inorder Taversal using Threads
#include<iostream>
#include<conio.h>
using namespace std;
///////////////////////////////////////////
struct node 
{
    int    data;
    node   *left;
    node   *right;
    int   rflag; 
};
///////////////////////////////////////////
struct node* create(int item)
{
    struct node* n;
	n= new(struct node);
    
	n->data  = item;
    n->left  = NULL;
    n->right = NULL;
    n->rflag = 0;
   
    return(n);
}
///////////////////////////////////////////
struct node* leftmost(struct node *n)
{
    if (n == NULL)
       return NULL;
 
    while (n->left != NULL)
        n = n->left;
 
    return n;
}
///////////////////////////////////////////
void inorder(struct node *root)
{
    struct node *cur;
	
	cur = leftmost(root);
    
    while (cur != NULL)
    {
       cout<<cur->data;
 
        if (cur->rflag==1)
            cur = cur->right;
        else
            cur = leftmost(cur->right);
    }
}

 
////////////////////////////////////////////

int main()
{
    struct node *r;
	
	r                     = create(1);
	
    r->left               = create(2);
    r->right              = create(3);
    
    r->left->left         = create(4);
    r->left->right        = create(5);
 
    inorder( r);
 
    getch();
}
