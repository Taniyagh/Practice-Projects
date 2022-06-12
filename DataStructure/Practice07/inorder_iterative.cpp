// inorder(non recursive)
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define bool int
using namespace std;

///////////////////////////////////////////
struct node
{
   int           data;
   struct node*  left;
   struct node*  right;
};
///////////////////////////////////////////////////////////////////////////
// Linked List implementation is used for stack.
struct stacknode
{
  struct node       *t;
  struct stacknode  *next;
};
///////////////////////////////////////////////////////////////////////////
struct node* create(int item)
{
  struct node* n;
  
  n = new(struct node);
  n->data = item;
  n->left = NULL;
  n->right = NULL;

  return(n);
}
//////////////////////////////////////////////////
bool isEmpty(struct stacknode *top)
{
   return (top == NULL)? 1 : 0;
}   

///////////////////////////////////////////////////
void push(struct stacknode** topr, struct node *k)
{
   struct stacknode* n;
  
   n= new(struct stacknode);

   if(n == NULL)
      exit(0);       

   n->t = k;

   n->next = (*topr);   

  (*topr) = n;
}

///////////////////////////////////////////////////////////////////////////

struct node *pop(struct stacknode** topr)
{
  struct node       *q;  //result
  struct stacknode  *h;

  if(isEmpty(*topr))
      exit(0);
  else
  {
     h = *topr;
     q = h->t;
     *topr = h->next;
     free(h);
     return q;
  }
}

///////////////////////////////////////////////////////////////////////////
void inorder(struct node *r)
{
  struct node *cur;
  cur = r;
  
  struct stacknode *s;  
  s = NULL;  
  
  bool flag = 0;

  while (!flag)
  {
    if(cur !=  NULL)
    {
      push(&s, cur);                                               
      cur = cur->left;  
    }
    else                                                              
    {
      if (!isEmpty(s))
      {
        cur = pop(&s);
        cout<<cur->data<<" ";
        cur = cur->right;
      }
      else
        flag = 1; 
    }
  } 
}     


///////////////////////////////////////////

int main()
{
    struct node *r;
	
	r  = create(1);
	
    r->left    = create(2);
    r->right   = create(3);
    
    r->left->left  = create(4);
    r->left->right = create(5);
 
    inorder( r);
 
    getch();
}
