// find k'th largest element(BST)
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//////////////////////////////
struct node
{
    int           data;
    struct node*  left;
    struct node*  right;
};

//////////////////////////////
struct node *create(int item)
{
    struct node *n ;
	n= new(struct node);
    n->data  = item;
    n->left  = NULL;
    n->right = NULL;
    return n;
}
///////////////////////////////////////////
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
////////////////////////////////////////////
void kthLargest(node *r, int k, int &c)
{
    if (r == NULL || c >= k)
        return;
 
    kthLargest(r->right, k, c);
 
    c++;
 
    if (c == k)
    {
        cout << r->data << endl;
        return;
    }
 
    kthLargest(r->left, k, c);
}
/////////////////////////////////////////////
void kth(node *r, int k)
{
    int c = 0;
    kthLargest(r, k, c);
}
 
///////////////////////////
int main()
{
    /* 
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 
	*/
	
    node *r = NULL;
    r = add(r, 50);
    add(r, 30);
    add(r, 20);
    add(r, 40);
    add(r, 70);
    add(r, 60);
    add(r, 80);
   
    kth(r, 4);
 
    getch();
}
