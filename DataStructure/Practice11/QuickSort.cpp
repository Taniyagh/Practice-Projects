//Quick Sort
#include <iostream>
#include <conio.h>
using namespace std;
////////////////////////////
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
///////////////////////////////////////
int partition (int a[], int p, int r)
{
    int pivot,i,j;
	
	pivot = a[r];    
    i = p - 1;      
 
    for (j = p; j <= r- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;    
            swap(&a[i], &a[j]);
        }
    }
    
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}
/////////////////////////////////////////////////
void quickSort(int a[], int p, int r)
{
    int q;
	if (p < r)
    {
        q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}
/////////////////////////////////////////////////
int main()
{
    int a[] = {2,8,7,1,3,5,6,4};
    int n=8;
    
    quickSort(a, 0, n-1);
    
	for (int i=0; i < n; i++)
        cout<<a[i]<<"  ";
    
    getch();
}
