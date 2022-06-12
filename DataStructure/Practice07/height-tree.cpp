// find height 
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

int height(struct node* n)
{
    int  lh,rh;
    
	if (n==NULL)
       return -1;
        
    if( (n->left==NULL) && (n->right==NULL)  )
        return 0;
    
	else
    {
        lh = height(n->left);
        rh = height(n->right);
 
        if (lh > rh)
            return(lh+1);
        else 
		    return(rh+1);
    }
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
     
    cout<<height( r->right);
 
    getch();
}
