// Josephus
#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
/////////////////////////////////////////////// 
struct node
{
    int    data;
    struct node *next;
};
/////////////////////////////////////////////// 

node *create_node(int item)
{
   node *t ;
   
   t = new node;
   
   t->data = item;
   t->next = t;
}
 
////////////////////////////////////////
void create_list(node  **h , int n)
{
    node *k;

	*h = create_node(1);
    
	k = *h;
    
    for (int i = 2; i <= n; i++)
    {
        k->next = create_node(i);
        k = k->next;
    }
    
    k->next = *h;    
}
//////////////////////////////////
    
int Josephus(node **h)
{
    node *p;
	
	p= *h;
	
    while (p->next != p)
    {
        p->next = p->next->next;
        p = p->next;
    }
 
    return(p->data);
}

///////////////////////////////////////////////
int main()
{
   node *h;
   
   h=NULL;
   
   create_list(&h,1024);
   
   cout<<"Josephus Position : " << Josephus(&h);
    
   getch();
}
