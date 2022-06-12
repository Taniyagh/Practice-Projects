// Ancestors of a node
#include<iostream>
#include<conio.h>
 
using namespace std;
///////////////////////////////////////////////// 
struct node
{
   int           data;
   struct node*  left;
   struct node*  right;
};
///////////////////////////////////////////////// 
struct node* create(int item)
{
  struct node* n;
  
  n = new (struct node);
  n->data = item;
  n->left = NULL;
  n->right = NULL;
 
  return(n);
}
///////////////////////////////////////////////// 
bool ancestors(struct node *r, int x)
{
  if (r == NULL)
     return false;
 
  if (r->data == x)
     return true;
 
  if ( ancestors(r->left, x) || ancestors(r->right, x) )
  {
    cout << r->data << " ";
    return true;
  }
 
  return false;
}
/////////////////////////////////////////////////
int main()
{
 
  /*
  
              6
            /   \
          2      3
        /  \
      7     5
       \
        8
        
  */
  struct node *r;
  
  r = create(6);
  r->left        = create(2);
  r->right       = create(3);
  r->left->left  = create(7);
  r->left->right = create(5);
  r->left->left->right = create(8);

 
  ancestors(r,3);
 
  getch();
}
