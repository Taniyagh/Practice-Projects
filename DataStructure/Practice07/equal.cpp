//Equal two tree 
#include <conio.h>
#include <stdlib.h>
#include <iostream> 
using namespace std;
/////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
///////////////////////////////////////////////////////////////// 
struct node* create(int item)
{
    struct node* n;
	
	n = new(struct node);
    n->data  = item;
    n->left  = NULL;
    n->right = NULL;
 
    return(n);
}
/////////////////////////////////////////////////////////////////  
int identical(struct node* a, struct node* b)
{
    if (a==NULL && b==NULL)
        return 1;
 
    if (a!=NULL && b!=NULL)
      return(a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right) );
        
    return 0;
} 
 
/////////////////////////////////////////////////////
int main()
{
    struct node *r1,*r2;
	
	r1 = create(1);
    r1->left  = create(2);
    r1->right = create(3);
    r1->left->left  = create(4);
 
    r2 = create(1);
	r2->left  = create(2);
    r2->right = create(3);
    r2->left->left  = create(4);
 
    if(identical(r1, r2))
        cout<<"yes";
    else
        cout<<"no";
 
    getch();
}
