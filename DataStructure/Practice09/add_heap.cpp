// insert to MinHeap
#include<iostream>
#include<climits>
#include <conio.h>
using namespace std;
////////////////////
int   *x;             
int   size;            
int   c;     // capacity
//////////////////////////////
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
////////////////////////////
int parent(int i) 
{ 
	return (i-1)/2;
}
////////////////////////////
void add(int item)
{
    if (size == c)
       return;
 
    size++;
    int i = size - 1;
    x[i] = item;
 
    while (i != 0 && x[i] > x[parent(i)] )
    {
       swap(&x[i], &x[parent(i)]);
       i = parent(i);
    }
}
////////////////////////////////////////////
int main()
{
    x  = new int[6];
	
	size = 0;
    c  = 6;
    

	add(4);
    add(8);
    add(3);
    add(1);
    add(5);
    add(2);
    
   for(int i=0;i<=5; i++)
      cout<<x[i]<< "  ";
    
	getch();
}
