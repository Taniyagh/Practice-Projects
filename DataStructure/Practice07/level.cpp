//level of the node 
#include <iostream>
#include<conio.h>
using namespace std; 
///////////////////////////////////////////
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
///////////////////////////////////////////
struct node* create(int item)
{
    struct node *t;
	t = new struct node;
    t->data = item;
    t->left = NULL;
    t->right = NULL;
 
    return t;
}
///////////////////////////////////////////////
int levelnode(struct node *n, int item, int level)
{
    if (n == NULL)
        return 0;
 
    if (n->data == item)
        return level;
 
    int d = levelnode(n->left, item, level+1);
    
    if (d != 0)
      return d;
 
    d = levelnode(n->right, item, level+1);
    
    return d;
}
 
////////////////////////////////////////////
int getLevel(struct node *p, int item)
{
    return levelnode(p,item,1);
}
 
////////////////////////////////////////////
int main()
{
    struct node *r;
	r = new struct node;
 
    r = create(5);
    r->left  = create(7);
    r->right = create(9);
    r->left->left  = create(8);
    r->left->right = create(6);
 
    cout<< getLevel(r, 8);
 
    getch();
}
