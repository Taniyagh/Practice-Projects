// AVL(DELETE)
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
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}
//////////////////////////////////////////////////////////////////////
struct node   *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
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
struct node* add(struct node* root, int key)
{
    if (root == NULL)
        return(create(key));
 
    if (key < root->data)
        root->left  = add(root->left, key);
    else if (key > root->data)
        root->right = add(root->right, key);
    else 
        return root;
 
    root->height = 1 + max(height(root->left), height(root->right));
 
    int balance = Balance(root);
 
    if (balance >=2 && key < root->left->data)
        return rightRotate(root);
 
    if (balance <=-2 && key > root->right->data)
        return leftRotate(root);
 
    if (balance >=2 && key > root->left->data)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    if (balance <=-2 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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
struct node * min(struct node* p)
{
    struct node* t = p;
 
    while (t->left != NULL)
        t = t->left;
 
    return t;
}
//////////////////////////////////////////////////////////////// 
struct node* remove(struct node* r, int key)
{
    struct node* t;
	if (r == NULL)
        return r;
    if ( key < r->data )
        r->left = remove(r->left, key);
     else if( key > r->data )
        r->right = remove(r->right, key);
     else
    {
        if( (r->left == NULL) || (r->right == NULL) )
        {
            t = r->left ? r->left : r->right;
            if (t == NULL)
            {
                t = r;
                r = NULL;
            }
            else 
             *r = *t; 
            free(t);
        }
        else
        {
             t = min(r->right);
             r->data = t->data;
             r->right = remove(r->right, t->data);
        }
    }
     if (r == NULL)
      return r;
 
     r->height = 1 + max(height(r->left), height(r->right));
 
    int b = Balance(r);
 
    if (b > 1 && Balance(r->left) >= 0)
        return rightRotate(r);
 
    if (b > 1 && Balance(r->left) < 0)
    {
        r->left =  leftRotate(r->left);
        return rightRotate(r);
    }
 
    if (b < -1 && Balance(r->right) <= 0)
        return leftRotate(r);
 
    if (b < -1 && Balance(r->right) > 0)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
 
    return r;
}
///////////////////////////////////////////////////////////////
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
  
  r = remove(r, 2);
     
  cout<<endl<<endl;
	
  preorder(r);
  
  
  getch();
}
