// converting singly linked list into convert linked list.

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
////////////////////////////////////////////////////////
 
struct node {
    int    data;
    struct node  *next;
};
 
////////////////////////////////////////////////////////

struct node  *convert(struct node *h)
{
    struct node *s;
	
	s = h;
 
    while (h->next != NULL)
        h = h->next;
         
    h->next = s;
    
    return s;
}
 
/////////////////////////////////////////////////////////////////////////
void add_begin(struct node **head, int item)
{
    struct node *n;
	
	n = new (struct node);
 
    n->data = item;
 
    n->next = (*head);
 
    (*head) = n;
}
 
//////////////////////////////////////////////////////////////

void show(struct node *n)
{
    struct node  *s;
	
	s = n;
 
    while (n->next != s) 
	{
        cout<< n->data <<"  ";
        n = n->next;
    }
     
    cout<< n->data;
}
 
//////////////////////////////////////////////////////////////
int main()
{
    struct node *h;
	
	h = NULL;
 
    add_begin(&h, 4);
    add_begin(&h, 3);
    add_begin(&h, 2);
    add_begin(&h, 1);
  
    convert(h);
 
    show(h);
 
 getch();
}
