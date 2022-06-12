// reverse circular linked list
#include <bits/stdc++.h>
#include <conio.h>  
using namespace std;
//////////////////////////////////////////////
struct node {
    int   data;
    node  *next;
};
////////////////////////////////////////////// 
node  *create(int item)
{
    node *n;
	n = new node;
    n->data = item;
    n->next = NULL;
    return n;
}
 
////////////////////////////////////////////// 
void reverse(node  **head)
{
    if (*head == NULL)
        return;
 
    node  *p1,*p2,*p3;
	
	p3 = NULL;
    p2 = *head;
    
    do {
        p1 = p2->next;
        p2->next = p3;
        p3 = p2;
        p2 = p1;
    } while (p2 != (*head));
 
    (*head)->next = p3;
    *head = p3;
}
 
////////////////////////////////////////////// 
void show(node* h)
{
    if (h == NULL)
        return;
 
    node *t;
	
	t = h;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != h);
}
 
////////////////////////////////////////////// 
int main()
{
    node *h;
	
	h = create(1);
    h->next = create(2);                // 1  -> 2
    h->next->next = create(3);          // 1  -> 2  -> 3
    h->next->next->next = create(4);   //  1  -> 2  -> 3 -> 4
    
    h->next->next->next->next = h;
 
    cout << "linked list : ";
    show(h);
 
    reverse(&h);
 
    cout << "\nReversed    : ";
    show(h);
 
    getch();
}
