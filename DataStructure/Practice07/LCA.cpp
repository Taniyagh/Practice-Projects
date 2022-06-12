// LCA :Lowest Common Ancestor
#include <iostream>
#include <conio.h>
using namespace std;
 
//////////////////////////
struct node
{
    int data;
	struct node *left;
	struct node *right;
};
 
/////////////////////////
node* create(int item)
{
    node *t = new node;
    
    t->data  = item;
    t->left  = NULL;
    t->right = NULL;
    
	return t;
}
//////////////////////////////////////////////////////////////////
// if a is found :  fa =true
// returns pointer to LCA of two given values a and b.

struct node *LCA(struct node* r, int a , bool  &fa , int b, bool  &fb)
{
    if (r == NULL) return NULL;
 
    if (r->data == a) { fa = true; return r;}
    
    if (r->data == b) { fb = true; return r; }
 
    node *l_lca,*r_lca;
    
    l_lca  = LCA(r->left , a , fa , b , fb);
    r_lca  = LCA(r->right, a , fa , b , fb);
 
    if (l_lca && r_lca)  return r;
 
    return (l_lca != NULL) ? l_lca : r_lca;
}
////////////////////////////////////////////////////////////////
bool find(node *r, int k)
{
    if (r == NULL)
        return false;
 
    if (r->data == k || find(r->left, k) ||  find(r->right, k))
        return true;
 
    return false;
}
/////////////////////////////////////////////////////////////////
node *f(node *r, int a, int b)
{
    bool fa = false, fb = false;
    node *x;
	
	x = LCA(r, a, fa, b, fb);
    
	if (fa && fb || fa && find(x,b) || fb && find(x,a))
            return x;
    return NULL;
}
///////////////////////////////////
int main()
{
    node *r;
	node *x;
	 
	r = create(1);
    r->left  = create(2);
    r->right = create(3);
    r->left ->left   = create(4);
    r->left ->right  = create(5);
    r->right->left   = create(6);
    r->right->right  = create(7);
    r->left ->right->right = create(8);

    x = f(r, 4 , 2);
    
    if (x!=NULL)
	  cout << x->data;
    
 
    getch();
}
