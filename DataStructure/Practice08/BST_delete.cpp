// BST (delete)
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
///////////////////////////////////////////////
struct node
{
    int           data;
    struct node*  left;
    struct node*  right;
};

///////////////////////////////////////////////
struct node *create(int item)
{
    struct node *n ;
	n= new(struct node);
    n->data  = item;
    n->left  = NULL;
    n->right = NULL;
    return n;
}

///////////////////////////////////////////////
void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        cout<< r->data <<"  ";
        inorder(r->right);
    }
}
///////////////////////////////////////////////
struct node* add(struct node* n, int item)
{
    if (n == NULL) 
	    return create(item);

    if (item < n->data)
        n->left  = add(n->left, item);
    else
        n->right = add(n->right, item);

    return n;
}
///////////////////////////////////////////////
struct node * min(struct node* n)
{
    struct node* t;
	
	t = n;
    while (t->left != NULL)
        t = t->left;

    return t;
}
///////////////////////////////////////////////

struct node* remove(struct node* r, int key)
{
     struct node *t;
	if (r == NULL) return r;

    if (key < r->data)
        r->left  = remove(r->left, key);

    else if (key > r->data)
        r->right = remove(r->right, key);

    else
    {
        // one child or no child
        if (r->left == NULL)
        {
            t = r->right;
            free(r);
            return t;
        }
        else if (r->right == NULL)
        {
            t = r->left;
            free(r);
            return t;
        }

        // two children
        t = min(r->right);  //insucc

        r->data = t->data;

        r->right = remove(r->right, t->data);
    }
    return r;
}

///////////////////////////////////////////////
int main()
{
    /* 
               5
            /    \
           3      8
         /  \   /  \
        2   4  7    9
              /
             6
   */
   
    struct node *r = NULL;
    r = add(r, 5);
    r = add(r, 3);
    r = add(r, 8);
    r = add(r, 4);
    r = add(r, 7);
    r = add(r, 2);
    r = add(r, 9);
    r = add(r, 6);

    inorder(r);
    
	cout<<endl<<endl;
    
	r = remove(r, 5);
    inorder(r);
    

    getch();
}
