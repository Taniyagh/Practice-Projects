// insert in double link list
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
 
/////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
 
/////////////////////////////////////////////////////////////////

void addfirst(struct node  **s, int item)
{
    struct node *n;
	
	n = (struct node*) malloc(sizeof(struct node));
 
    n->data  = item;
 
    n->next = *s;
    n->prev = NULL;
 
    if( *s != NULL)
      (*s)->prev = n ;
 
    *s = n;
}
 
/////////////////////////////////////////////////////////////////
void addafter(struct node *p, int item)   
{
    if (p == NULL)
        return;
 
    struct node *n;
	
	n =(struct node*) malloc(sizeof(struct node));
 
    n->data  = item;
 
    n->next = p->next;
    n->prev = p;
    
	p->next = n;
 
    if (n->next != NULL)
      n->next->prev = n;
}
 

/////////////////////////////////////////////////////////////////
void show(struct node *k)
{
	while (k != NULL)
    {
        cout<< k->data << " -> ";
        k = k->next;
    }
    cout<<"NULL";
    
}
/////////////////////////////////////////////////////////////////
int main()
{
    struct node *h;
	
	h = NULL;
 
    addfirst(&h,3);                      //  3 
    
	addfirst(&h,2);                      //  2 -> 3 
	
	addfirst(&h,1);                      //  1 -> 2 -> 3 
  
    addafter(h->next->next,4);           //  1 -> 2 -> 3 -> 4
	

    show(h);
 
    getch();
}
