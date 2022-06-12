// BST : insert
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
///////////////////////////////////////////////
struct node
{
    int  data;
    struct node *left, *right;
};
///////////////////////////////////////////////
struct node *create(int item)
{
    struct  node *t;
	t = new node;
    t->data = item;
    t->left = t->right = NULL;
    return t;
}
//////////////////////////////////////////////
struct node* insert(struct node* n, int item)
{
    if (n == NULL) 
	    return create(item);
 
    if (item < n->data)
        n->left  = insert(n->left , item);
        
    else if (item > n->data)
        n->right = insert(n->right, item);
 
    return n;
}
////////////////////////////////////////////////////// 
void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        cout<< r->data <<"  ";
        inorder(r->right);
    }
}
////////////////////////////////////////////////////// 
int main()
{
  /* 
              8
            /    \
          5      30
                 /  
              20   
*/
    struct node *r = NULL;
    
    r = insert(r, 8);
    insert(r, 5);
    insert(r, 30);
    insert(r, 20);
    
    insert(r, 9);
   
    inorder(r);

    
	getch();
}
