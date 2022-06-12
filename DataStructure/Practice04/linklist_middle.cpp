// middle in link list
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
//////////////////////////
struct node
{
    int data;
    struct node* next;
};

//////////////////////////////////////////// 
void add_begin(struct node** s, int item)
{
 
    struct node *n;
	
	n =new(struct node);
 
    n->data  = item;
  
    n->next = (*s);
 
    (*s) = n;
}
 
///////////////////////////////////////
void show(struct node *p)
{
    while (p != NULL)
    {
        cout<< p->data<<"->";
        p = p->next;
    }
    cout<<"NULL\n";
}
//////////////////////////////////////////////
void middle(struct node *h)
{
    struct node *sp,*fp;
	 
    sp=h;
    fp=h;
    
    if (h!=NULL)
    {
        while (fp != NULL && fp->next != NULL)
        {
            fp = fp->next->next;
            sp = sp->next;
        }
        cout<< sp->data;
    }
}
///////////////////////////////////////////////
int main()
{
    struct node *h = NULL;
    int i;
 
    
        add_begin(&h, 5);
        add_begin(&h, 4);
        add_begin(&h, 3);
        add_begin(&h, 2);
        add_begin(&h, 1);   // 1 ->  2 -> 3  -> 4  -> 5
        
        show(h);
        
        middle(h);
   
 
 getch();
}
