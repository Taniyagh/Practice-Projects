// BST  (search)
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
struct node* search_rec(struct node* r, int key)
{
    if (r == NULL || r->data == key)
       return r;
   
    if (r->data < key)
       return search_rec(r->right, key);

    return search_rec(r->left, key);
} 
/////////////////////////////////////////////// 
bool search(struct node *r, int key)
{
    while (r != NULL)
    {
        if (key > r->data)
            r = r->right;
 
        else if (key < r->data)
            r = r->left;
        else
            return true;
    }
    return false;
}
 
////////////////////////////////////////////////////// 


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
int main()
{
    /* 
              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80 
*/
    struct node *r = NULL;
    
    r = insert(r, 50);
    insert(r, 30);
    insert(r, 20);
    insert(r, 40);
    insert(r, 70);
    insert(r, 60);
    insert(r, 80);
    
    if (search(r, 40))
        cout << "Yes";
    else
        cout << "No";
    
	getch();
}
