// Circular Linked List 
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
///////////////////////////
struct node
{
    int          data;
    struct node  *next;
};
 
//////////////////////////////////////////////////////////////////////////
void  addbegin(struct node  **s, int item)
{
    struct node *n ,*t;
	
	n = new(struct node);        //  n= (struct node *)malloc(sizeof(struct node));
    n->data = item;
    n->next = *s;
    
	t = *s;
    if (*s != NULL)
    {
        while (t->next != *s)
            t = t->next;
        t->next = n;
    }
    else
        n->next = n;
 
    *s = n;
}
 
////////////////////////////////////
void show(struct node *h)
{
    struct node *t;
	
	t = h;
    if (h != NULL)
    {
        do
        {
            cout<< t->data<<"  ";
            t = t->next;
        }
        while (t != h);
    }
}
/////////////////////////////////
int main()
{
    struct node *h;
	
	h = NULL;
 
    addbegin(&h, 3);    // 3
    
    addbegin(&h, 2);   // 2  3
    
    addbegin(&h, 1);   // 1  2  3
 
    show(h->next);
 
 getch();
}
