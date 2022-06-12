// Priority Queue
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
/////////////////////////////////////////
struct node
{
    int          data;
  	int          priority;
    struct node  *next;
}*front = NULL;
/////////////////////////////////////////
void insert(int item, int prio)
 {
    node *t, *q;
    
    t = new node;
    t->data = item;
    t->priority = prio;
    
    if (front == NULL || prio < front->priority)
       {
          t->next = front;
          front = t;
        }
    else
        {
            q = front;
            while (q->next != NULL && q->next->priority <= prio)
                        q=q->next;
            t->next = q->next;
            q->next = t;
        }
 }
/////////////////////////////////////////
void del()
{
    node *t;
    if(front == NULL)
       cout<<"Underflow";
    else
        {
          t = front;
          front = front->next;
          free(t);
        }
}
/////////////////////////////////////////
void display()
{
   node *p;
   p = front;
   if (front == NULL)
       cout<<"empty";
   else
       {	
        cout<<"Item      Priority\n";
        cout<<"------------------\n";
        while(p != NULL)
            {
              cout << p->data <<"               " << p->priority <<endl;
              p = p->next;
            }
   }
   cout<<"\n\n";
}

/////////////////////////////////////////
int main()
    {
		 insert( 45 , 4);
		 insert( 25 , 2);
		 insert( 15 , 1);
 		 insert( 35 , 3);

         display();	 
        
		 del();

         display();

        getch();
        

    }
