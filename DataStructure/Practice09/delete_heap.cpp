// Delete of MinHeap
#include<iostream>
#include <conio.h>
using namespace std;
////////////////////
int   *x;            
int   c;             
int   size;          
//////////////////////////////
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//////////////////////////////////////////////////////
int parent(int i) 
{ 
	return (i-1)/2;
}
//////////////////////////////
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
///////////////////////////////////
// heapify a subtree with root i
void MinHeapify(int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    
    if (l < size && x[l] < x[i])
        smallest = l;
        
    if (r < size && x[r] < x[smallest])
        smallest = r;
        
    if (smallest != i)
    {
        swap(&x[i], &x[smallest]);
        MinHeapify(smallest);
    }
} 

//////////////////////////////////
int remove()
{
    int root;
	if (size <= 0)
        return INT_MAX;
        
    if (size == 1)
    {
        size--;
        return x[0];
    }
 
    root = x[0];
    x[0] = x[size-1];
    size--;
    MinHeapify(0);
 
    return root;
}
///////////////////////////////
int main()
{
    size = 0;
    c  = 6;
    x  = new int[6];

	add(4);
    add(8);
    add(3);
    add(1);
    add(5);
    add(2);
    
	remove();

	for(int i=0;i<size;i++)
	  cout<<x[i]<<"  ";


	getch();
}
