// AVL(INSERT)
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
//////////////////////////////
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
/////////////////////////////
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
/////////////////////////////
int max(int a, int b)
{
    return (a > b)? a : b;
}
////////////////////////////////////////////////////////////////////
struct node* create(int item)
{
    struct node* n ;
	
	n= new(struct node);
    n->data   = item;
    n->left   = NULL;
    n->right  = NULL;
    n->height = 1; 
    return(n);
}
//////////////////////////////////////////////////////////////////////
struct node *rightRotate(struct node *y)
{
    struct node *x,*T2;
	
	x = y->left;
    T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
//////////////////////////////////////////////////////////////////////
struct node   *leftRotate(struct node *x)
{
    struct node *y,*T2;
	
	y = x->right;
    T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = 1 + max(height(x->left), height(x->right)) ;
    y->height = 1 + max(height(y->left), height(y->right)) ;
 
    return y;
}
////////////////////////////////////////////////////////// 
int Balance(struct node *p)
{
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}
//////////////////////////////////////////////////////////////////// 
struct node* add(struct node* p, int key)
{
    if (p == NULL)
        return(create(key));
 
    if (key < p->data)
        p->left  = add(p->left, key);
    else if (key > p->data)
        p->right = add(p->right, key);
    else // Equal datas are not allowed in BST
        return p;
 
    p->height = 1 + max(height(p->left), height(p->right));
 
    int b = Balance(p);
 
    // Left Left Case
    if (b >=2 && key < p->left->data)
        return rightRotate(p);
 
    // Right Right Case
    if (b <=-2 && key > p->right->data)
        return leftRotate(p);
 
    // Left Right Case
    if (b >=2 && key > p->left->data)
    {
        p->left =  leftRotate(p->left);
        return rightRotate(p);
    }
 
    // Right Left Case
    if (b <=-2 && key < p->right->data)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
 
    return p;
}
//////////////////////////////////////////////////////////////////////

void preorder(struct node *r)
{
    if(r != NULL)
    {
        cout<< r->data <<"  ";
        preorder(r->left);
        preorder(r->right);
    }
}
 
//////////////////////////////////////////////////////////////////////
int main()
{
  struct node *r = NULL;
 
  r = add(r, 1);
  r = add(r, 2);
  r = add(r, 3);
  r = add(r, 4);
  r = add(r, 5);
 
  /* 
            2
           /  \
         1     4
             /  \
             3   5
  */
 
  preorder(r);
 
  getch();
}
