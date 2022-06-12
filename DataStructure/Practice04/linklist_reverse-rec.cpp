//Recursive-Reverse
#include  <iostream>
#include  <cstdlib>
#include  <conio.h>
using namespace std;

/////////////////////////////////
struct node
{
    int           data;
    struct node  *next;
};
/////////////////////////////////
void reverse(struct node  **head)
{
    struct node *first , *p;
          
    if (*head == NULL)
       return;   
 
    first = *head; 
	 
    p  = first->next;
 
    if (p == NULL)
       return;   
 
    reverse(&p);
    
    first->next->next  = first;  
     
    first->next  = NULL;          
 
    *head = p;              
}
/////////////////////////////////////////////////////////////
void add(struct node **head, int v)
{
    struct node *n;
	
	n = (struct node*) malloc(sizeof(struct node));
            
    n->data = v;
                
    n->next = (*head);    
        
    (*head)   = n;
}
 
/////////////////////////////////////////////////////////////
void show(struct node *h)
{
    struct node *t;
	
	t = h;
    while(t != NULL)
    {
        cout<<t->data<<"->";    
        t = t->next;  
    }
    cout<<"null";
}    
/////////////////////////////////////////////////////////////
int main()
{
    struct node *h = NULL;
   
     add(&h , 5);
     add(&h , 9);
     add(&h , 2); 
          
     show(h);
	     
     reverse(&h); 
	                      
     cout<<"\n\n";
     
	 show(h); 
	    
     getchar();
}
