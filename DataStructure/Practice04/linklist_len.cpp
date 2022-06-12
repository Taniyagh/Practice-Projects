// length link list
#include <iostream>
#include <conio.h>
using namespace std;
////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};
 
////////////////////////////////////////

void add_begin(struct node **s, int item)
{
    struct node *n ;
	
	n=new(struct node);
 
    n->data  = item;
 
    n->next = (*s);
 
    (*s)    = n;
}
 
////////////////////////////////////////
int len(struct node  *h)
{
    int count = 0;  
    struct node *x;
	
	x = h;  
    while (x != NULL)
    {
        count++;
        x = x->next;
    }
    return count;
}
/////////////////////////////////////////
int len_rec(struct node *h)
{
    if (h == NULL)
        return 0;
 
    return 1 + len_rec(h->next);
}

////////////////////////////////////////
 
int main()
{
    struct node *h;
	
	h = NULL;
  
    add_begin(&h, 11);
    add_begin(&h, 32);   // 32 ->11
    add_begin(&h, 47);   // 47 ->32 ->11
        
    cout<<len(h);  //3
    
	cout<<endl;
	
	cout<<len_rec(h); //3
    
    getch();
}
