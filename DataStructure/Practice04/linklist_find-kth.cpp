// find node in kth position
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
////////////////////////////////////////////////
struct node
{
    int data;
    struct node* next;
};
 
////////////////////////////////////////////////

void add_begin(struct node** s, int item)
{
    struct node  *n;
    
	n=(struct node*) malloc(sizeof(struct node));
 
    n->data = item;
 
    n->next = (*s);
 
    (*s) = n;
}
 
/////////////////////////////////////////////////

int find(struct node *h,int k)
{
    int count;
	
	count = 1;
     
    if(count == k)
       return h->data;
     
    return  find(h->next, k-1); 
}
 
/////////////////////////////////////////////////

int main()
{  
    struct node *h = NULL;
     
    add_begin(&h, 5);
    add_begin(&h, 4);
    add_begin(&h, 6);
    add_begin(&h, 8);    // 8 -> 6 -> 4 -> 5
    
    cout<<find(h, 4);  
    
    getch();
}
