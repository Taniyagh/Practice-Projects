//Find  Predecessor and Successor in BST
#include <iostream>
#include <conio.h>
using namespace std;
///////////////////////////////
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
/////////////////////////////////////////////////////
node *create(int item)
{
    node *t =  new node;
    t->data = item;
    t->left = t->right = NULL;
    return t;
}
//////////////////////////////////////////////////////
node* add(node* p, int item)
{
    if (p == NULL) 
	    return create(item);
	    
    if (item < p->data)
        p->left  = add(p->left, item);
    else
        p->right = add(p->right, item);
    return p;
}
///////////////////////////////////////////////////////////
void   PreSuc(node* r, node*&  pre, node*&  suc , int item)
{
    node* t;
	if (r == NULL)  return;

    if ( item == r->data )
    {
        if (r->left != NULL)
        {
            t = r->left;
            while (t->right)
                t = t->right;
            pre = t ;
        }

        if (r->right != NULL)
        {
            t = r->right ;
            while (t->left)
                t = t->left ;
            suc = t ;
        }
        return ;
    }

    if (item < r->data )
    {
        suc = r ;
        PreSuc(r->left, pre, suc, item) ;
    }
    else 
    {
        pre = r ;
        PreSuc(r->right, pre, suc, item) ;
    }
}

///////////////////////////////////////////////////////
int main()
{
   /* 
              5
           /     \
          3       7
         / \     /  \
       2    4   6    8
   */
   
    node *r,*p,*s;
    
	r = NULL;
    r = add(r, 5);
    add(r, 3);
    add(r, 2);
    add(r, 4);
    add(r, 7);
    add(r, 6);
    add(r, 8);
    
	p = NULL;
	s = NULL;
    PreSuc(r, p, s, 7);
    
    if (p != NULL)
      cout << p->data << endl;
    else
      cout << "No Predecessor";

    if (s != NULL)
      cout << s->data;
    else
      cout << "No Successor";
      
getch();
}


