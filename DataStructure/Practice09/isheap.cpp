// a given aay represents a max-heap or not
#include <stdio.h>
#include <conio.h>
//////////////////////////////////////////////////////////////
// Returns true if a[i..n-1] represents a max-heap
bool isHeap(int a[], int i, int n)
{
   // If a leaf node
   if (i > (n - 2)/2)
       return true;
 
   if (a[i] >= a[2*i + 1] && a[i] >= a[2*i + 2] && isHeap(a, 2*i + 1, n) && isHeap(a, 2*i + 2, n))
       return true;
 
   return false;
}
 
//////////////////////////////////////////////////////////////
int main()
{
    int x[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n=8;
 
    isHeap(x, 0, n)? printf("Yes"): printf("No");
 
    getch();
}
