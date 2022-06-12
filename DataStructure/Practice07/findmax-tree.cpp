// find maximum in a Bianry Tree
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
int max(struct node* p)
{
    int m,lmax,rmax;
	if (p == NULL)
      return INT_MIN;
    
	m = p->data;
    lmax = max(p->left);
    rmax = max(p->right);

   
    if (lmax > m)
      m = lmax;
      
    if (rmax > m)
      m = rmax;

    return m;
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
     
    cout<<max(r);
 
    getch();
}
