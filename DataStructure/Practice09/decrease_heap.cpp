// MinHeap(decreaseKey)
#include<iostream>
#include<climits>
#include <conio.h>
using namespace std;
////////////////////
int   *x;             
int   c;              
int   size;           
/////////////////////////
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//////////////////////////
int parent(int i) 
{ 
	return (i-1)/2;
}
//////////////////////////
void add(int item)
{
    if (size == c)
       return;
 
    size++;
    int i = size - 1;
    x[i] = item;
 
    while (i != 0 && x[i] < x[parent(i)] )
    {
       swap(&x[i], &x[parent(i)]);
       i = parent(i);
    }
}
///////////////////////////////////////////////
void decreaseKey(int i, int v)
{
    x[i] = v;
    while (i != 0 && x[i]< x[parent(i)] )
    {
       swap(&x[i], &x[parent(i)]);
       i = parent(i);
    }
}
///////////////////////////////////////////////
int main()
{
    size = 0;
    c  = 5;
    x  = new int[5];

	add(2);
    add(3);
    add(5);
    add(9);
    add(6);
   
    
    for(int i=0;i<5;i++)
	  cout<<x[i]<<"  ";

	decreaseKey(3, 1);
	
	cout<<endl;
    
	for(int i=0;i<5;i++)
	  cout<<x[i]<<"  ";
	  
	  
	getch();
}
