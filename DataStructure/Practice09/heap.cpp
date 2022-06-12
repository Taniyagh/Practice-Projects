//Binary Heap 
#include<iostream>
#include<climits>
#include<conio.h>
using namespace std;
/////////////////////////////////////////
int  size = 0;
int  capacity = 11;
int  *a=new int[11];
/////////////////////////////////////////
 int parent(int i) 
   { return (i-1)/2; }
/////////////////////////////////////////
 int left(int i)   
   { return (2*i + 1); }
/////////////////////////////////////////
 int right(int i) 
   { return (2*i + 2); }
///////////////////////////////////////// 
//int getMin()      { return a[0]; }
/////////////////////////////////////////
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
/////////////////////////////////////////////////////
// Inserts a new data 'k'
void add(int k)
{
    if (size == capacity)
    {
        cout << "\n Overflow: Could not add \n";
        return;
    }
 
    // insert at the end
    size++;
    int i = size - 1;
    a[i] = k;
 
    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(&a[i], &a[parent(i)]);
       i = parent(i);
    }
}
//////////////////////////////////////////////////////
// Decreases value of data at index 'i' to new_val.  
// It is assumed that new_val is smaller than a[i].
void decreaseKey(int i, int new_val)
{
    a[i] = new_val;
    while (i != 0 && a[parent(i)] > a[i])
    {
       swap(&a[i], &a[parent(i)]);
       i = parent(i);
    }
}
///////////////////////////////////////////////////////////////// 
void Heapify(int i) ;
///////////////////////////////////////////////////////////////// 
// Method to remove minimum element (or root) from min heap
int extractMin()
{
    if (size <= 0)
        return INT_MAX;       
    if (size == 1)
    {
        size--;
        return a[0];
    } 
    // Store the minimum value, and remove it from heap
    int root = a[0];
    a[0] = a[size-1];
    size--;
    Heapify(0);
    return root;
} 
////////////////////////////////////////////////////////////////////// 
// This function deletes data at index i. 
// It first reduced value to minus infinite, then calls extractMin()
void deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
////////////////////////////////////////////////////////////////////// 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void Heapify(int i)
{
    int l,r,smallest;
    
	smallest = i;   
	l = left(i);
    r = right(i);
    
    if (l < size && a[l] < a[i])
        smallest = l;
        
    if (r < size && a[r] < a[smallest])
        smallest = r;
        
    if (smallest != i)
    {
        swap(&a[i], &a[smallest]);
        Heapify(smallest);
    }
}
//////////////////////////////////
int main()
{   
    
    add(5);
    add(3);
    add(4);
    add(2);
    
    deleteKey(1);
    
    //add(15);
    //add(5);
    //add(4);
   // add(45);
    
    cout << extractMin() << " "<<endl;
    
    cout << a[0] << " "<<endl;
    
    decreaseKey(2, 1);
    
    cout << a[0]<<endl;
    
   getch();
}
