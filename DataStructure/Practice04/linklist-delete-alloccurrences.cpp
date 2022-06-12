//  delete all occurrences of a given item in linked list
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
 
///////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};
 
//////////////////////////////////////////////////////////

void add_begin(struct node** s, int item)
{
    struct node* n;
	
	n = (struct node*) malloc(sizeof(struct node));
    n->data  = item;
    n->next = (*s);
    (*s) = n;
}
 
/////////////////////////////////////////////

void del(struct node **s, int item)
{
    struct node *f , *p;
 
    f=*s;
    
    while (f != NULL && f->data == item)
    {
        *s = f->next;   
        free(f);               
        f = *s;         
    }
 
    while (f != NULL)
    {
        while (f != NULL && f->data != item)
        {
            p = f;
            f = f->next;
        }
 
        if (f == NULL) return;
 
        p->next = f->next;
 
        free(f);  
 
        f = p->next;
    }
}
 
/////////////////////////////////////////////

void show(struct node *t)
{
    while (t != NULL)
    {
        cout<<t->data<<"  ";
        t = t->next;
    }
  cout<<endl<<"------------------------"<<endl;
}
 
/////////////////////////////////////////////

int main()
{
   
    struct node  *h;
	
	h = NULL;
 
    add_begin(&h, 13);
    add_begin(&h, 14);
    add_begin(&h, 13);
    add_begin(&h, 12);
    add_begin(&h, 11);
    add_begin(&h, 13);
 
    show(h);
 
    del(&h, 13);
 
    show(h);
    
    
    getch();
}
