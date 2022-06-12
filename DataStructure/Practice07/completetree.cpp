// binary tree is complete or not
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std; 
/////////////////////////
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
//////////////////////////////
struct node* create(int item)
{
  struct node* n;
  
  n = new(struct node);
  n->data = item;
  n->left = NULL;
  n->right = NULL;
 
  return(n);
}
//////////////////////////////////////////////////////////////////////////
struct node** createQueue(int *front, int *rear)
{
  struct node **q =(struct node **)malloc(sizeof(struct node*)*300);
 
  *front = *rear = 0;
  return q;
}
/////////////////////////////////////////////////////////////////////////
bool isEmpty(int *front, int *rear)
{
   return (*rear == *front);
} 
//////////////////////////////////////////////////////////
void enQueue(struct node **q, int *rear, struct node *n)
{
  q[*rear] = n;
  (*rear)++;
}
//////////////////////////////////////////////////////////
struct node *deQueue(struct node **q, int *front)
{
  (*front)++;
  return q[*front - 1];
}
////////////////////////////////////
bool iscomplete(struct node* r)
{
  struct node **q,*t;
  int rear, front;
  bool flag ;

  if (r == NULL)
    return true;
 
  q = createQueue(&front, &rear);
  enQueue(q, &rear, r);
 
  flag = false;
  while(!isEmpty(&front, &rear))
  {
    t = deQueue(q, &front);
 
    if(t->left)
    {
       if (flag == true)
         return false;
 
       enQueue(q, &rear, t->left);  
    }
    else flag = true;
 
 
    if(t->right)
    {
       if(flag == true)
         return false;
 
       enQueue(q, &rear, t->right); 
    }
    else flag = true;
  }
 
  return true;
}
//////////////////////////////////
int main()
{
    /* 
            11
          /   \
         12    13
        /     /     
       14    15   
   */
 
  struct node *r ;
  
  r = create(11);
  r->left   = create(12);
  r->right  = create(13);
  r->left ->left  = create(14);
  r->right->left  = create(15);
 
  if ( iscomplete(r) == true )
      cout<<"yes";
  else
      cout<<"no";
 
  getch();
}


