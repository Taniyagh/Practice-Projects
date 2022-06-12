// delete tree 
#include<iostream>
#include<conio.h>
#include<stdlib.h>

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

void deleteTree(struct node* p) 
{
    if (p == NULL) 
	    return;
	    cout<< p->data<< "  ";
    
    deleteTree(p->right);
    deleteTree(p->left);

	free(p);
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
    
    deleteTree(r);  
    r = NULL;
 
    getch();
}
