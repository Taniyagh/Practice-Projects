// traverse(inorder , preorder, postorder)
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
void preorder(struct node *p)
{
    if (p != NULL)
    {
        cout << p->data <<"  ";
		preorder(p->left);
        preorder(p->right);
    }
}
///////////////////////////////////////////
void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data <<"  ";
        inorder(p->right);
    }
}
///////////////////////////////////////////
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data <<"  ";
    }
}
///////////////////////////////////////////
int main()
{
    struct node *r;
	
	r  = create(1);
	
    r->left  = create(2);
    r->right = create(3);
    
    r->left->left  = create(4);
    r->left->right = create(5);
 
    r->left->right->left  = create(6);
   
    cout<<"preorder  : "; 
    preorder (r);  // 124563
    
	cout<<endl<<endl;
    
    cout<<"inorder   : "; 
	inorder  (r);  //426513
    
	
	cout<<endl<<endl;
    
    cout<<"postorder : "; 
	postorder(r);  //465231
 
    getch();
}
