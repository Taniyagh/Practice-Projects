// Merge Sort
#include <iostream>
#include <conio.h>
using namespace std;
///////////////////////////////////////////
void merge(int a[], int p, int m, int r)
{
    int i, j, k;
    int n1 = m - p + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = a[p + i];
        
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = p; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
///////////////////////////////////////
void mergeSort(int a[], int p, int r)
{
    int m;
	if (p < r)
    {
        m = (p+r)/2;
        mergeSort(a, p, m);
        mergeSort(a, m+1, r);
        merge(a, p, m, r);
    }
} 
///////////////////////////////////////
int main()
{
    int  a[] = {5,2,4,7,1,3,2,6};
    int  n = 8;
  
    mergeSort(a, 0, n-1);
 
    for (int i=0; i < n; i++)
        cout<< a[i]<<"  ";
    
    getch();
}
