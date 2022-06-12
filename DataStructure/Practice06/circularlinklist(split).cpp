//* split a circular linked list into two halves 
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
 
///////////////////////////////////////////
struct node
{
  int data;
  struct node *next;
}; 
 
///////////////////////////////////////////

void split(struct node *head , struct node **h1, struct node  **h2)
{
  struct node *sp,*fp;
  
  sp = head;
  fp = head; 
 
  if(head == NULL)
    return;
  
  // odd nodes  : head : fp->next 
  // even nodes : head : fp->next->next 
  while(fp->next != head && fp->next->next != head) 
  {
     fp = fp->next->next;
     sp = sp->next;
  }  
 
 //  even elements 
  if(fp->next->next == head)
    fp = fp->next;      
   
 
  *h1 = head;    
      
  if(head->next != head)
    *h2 = sp->next;
   
  fp->next = sp->next;   // second half   
   
  sp->next = head;       // first half    
}
 
/////////////////////////////////////////////////////////////////////////
void add_begin(struct node **h, int data)
{
  struct node *p1;
  
  p1 = new(struct node);
  struct node *t;
  
  t = *h; 
  p1->data = data;  
  p1->next = *h; 
   
  if(*h != NULL)
  {
    while(t->next != *h)
      t = t->next;        
    t->next = p1; 
  }
  else
     p1->next = p1; 
 
  *h = p1;     
} 
 
//////////////////////////////////////////////////////////////
void show(struct node *h)
{
  struct node *t;
  t = h; 
  if(h != NULL)
  {
    do {
      cout<< t->data << "  ";
      t = t->next;
    } while(t != h);
  }
}
 
////////////////////////////////////////////////////
int main()
{
  struct node *h  = NULL;
  struct node *h1 = NULL;
  struct node *h2 = NULL;  
 
  add_begin(&h, 14); 
  add_begin(&h, 13);   
  add_begin(&h, 12);   
  add_begin(&h, 11);   
  add_begin(&h, 10);   

 
  printf("list  : ");
  show(h);      
  
  cout<<endl<<endl<<"----------------------------" <<endl;

  split(h, &h1, &h2);
  
  printf("\nlist1 : ");
  show(h1);  
  
  cout<<endl;
  printf("\nlist2 : ");
  show(h2);  
   
  getch();
} 
