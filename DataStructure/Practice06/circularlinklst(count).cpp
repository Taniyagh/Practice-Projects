//  count number of nodes .
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
///////////////////////////////////////////////
struct node {
    int data;
    struct node  *next;
};
 
/////////////////////////////////////////////////////////////////////////
void add_begin(struct node **h, int item)
{
  struct node *n,*t;
  
  n = new(struct node);
  
   
  n->data = item;  
  n->next = *h; 
  
  t = *h; 
  if(*h != NULL)
  {
    while(t->next != *h)
      t = t->next;        
    t->next = n; 
  }
  else
     n->next = n; 
 
  *h = n;     
} 
 
//////////////////////////////////////////////////////////////
int count(struct node *head)
{
    struct node *t;
    int c = 0;
    
    t = head;
    do {
            t = t->next;
            c++;
       } while (t != head);
       
    return c;
}
 
///////////////////////////////////////////////
int main()
{
    struct node *h=NULL;
    
    add_begin(&h,5);
    add_begin(&h,2);
    add_begin(&h,13);
    add_begin(&h,25);
    
    cout<<count(h);
    
    
 
    getch();
}
