// Heap Sort(Max heap)
#include <iostream>
#include <conio.h>
using namespace std;
///////////////////////////////////////// 
void Max_Heapify(int x[], int n , int i)
{
    int largest,l,r;
	
	largest = i;  
    l = 2*i + 1;  
    r = 2*i + 2;  
 
    if (l < n && x[l] > x[largest])
        largest = l;
 
    if (r < n && x[r] > x[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(x[i], x[largest]);
        Max_Heapify(x, n, largest);
    }
}
/////////////////////////////////////////
void heapSort(int x[], int n)
{
    int i;
	for (i = n / 2 - 1; i >= 0; i--)
        Max_Heapify(x, n, i);
  
    for (i=n-1; i>=0; i--)
    {
        swap(x[0], x[i]);
        Max_Heapify(x, i, 0);
    }
}
/////////////////////////////////////////
int main()
{
    int x[] = {6,5,3,1,8,7,2,4};
    int n = 8;
    int i;
 
    heapSort(x, n);
 
    for ( i=0; i<n; i++)
        cout << x[i] << "   ";
    
	getch();
}
