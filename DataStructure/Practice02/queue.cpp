// implementation of queue
#include <iostream>
#include <conio.h>
#include <stdlib.h>
 using namespace std;
 ///////////////////////////////////////////////////////////////
struct Queue
{
    int  *a;
	int  front;
	int  rear;
	int  size;
    unsigned c;    // capacity
};
 ///////////////////////////////////////////////////////////////
struct Queue* create(unsigned c)
{
    struct Queue* q ;
    q = (struct Queue*) malloc(sizeof(struct Queue));
    
	q->c     = c;
    q->front = 0;
    q->rear  = c - 1;  
   	q->size  = 0; 
    q->a = (int*) malloc(q->c * 4);
    
	return q;
}
 ///////////////////////////////////////////////////////////////
int isEmpty(struct Queue* q)
{  
  return (q->size == 0); 
}
 ///////////////////////////////////////////////////////////////
int isFull(struct Queue* q)
{ 
  return (q->size == q->c);  
}
 ///////////////////////////////////////////////////////////////
void add(struct Queue* q, int item)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->c;
    int i;
    i=q->rear;
    q->a[i] = item;
    q->size = q->size + 1;
    cout<< item <<"  add"<<endl;
}
 
////////////////////////////////////////////////////////////////
int del(struct Queue* q)
{
    if (isEmpty(q))
        return INT_MIN;
    int item,i;
	i=q->front;
	item = q->a[i];
    q->front = (q->front + 1) % q->c;
    q->size = q->size - 1;
    return item;
}
 
///////////////////////////////////////////////////////////////
int main()
{
    struct Queue *q;
    
    q=create(5);
    
    add(q,1);
    add(q,5);
    add(q,75);
    
    cout<<"front="<<q->front<<endl;
    cout<<"rear="<<q->rear<<endl;
    cout<<"size="<<q->size<<endl;
      
    cout<<"delete="<<del(q)<<endl;
    
    cout<<"front="<<q->front<<endl;
    cout<<"rear="<<q->rear<<endl;
    cout<<"size="<<q->size<<endl;
    
    
    
getch();
}
