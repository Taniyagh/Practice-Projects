// search an element in a sorted and pivoted array
 #include <iostream>
 #include <conio.h>
 using namespace std;
 ///////////////////////////////////////////////////////////////////////
int binarySearch(int a[], int low, int high, int key)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2; 
    
   if (key == a[mid])
       return mid;
       
   if (key > a[mid])
       return binarySearch(a, (mid + 1), high, key);
       
   return binarySearch(a, low, (mid -1), key);
}
//////////////////////////////////////////////////////////

int f(int a[], int low, int high)
{
   if (high < low)  return -1;
   
   if (high == low) return low;

   int mid = (low + high)/2;   
   
   if (mid < high && a[mid] > a[mid + 1])
       return mid;
       
   if (mid > low && a[mid] < a[mid - 1])
       return (mid-1);
   
   if (a[low] >= a[mid])
       return f(a, low, mid-1);
   
   return f(a, mid + 1, high);
}
///////////////////////////////////////////////////////////////////////

int search(int a[], int n, int key)
{
   int pivot = f(a, 0, n-1);

   if (pivot == -1)
       return binarySearch(a, 0, n-1, key);

   if (a[pivot] == key)
       return pivot;
       
   if (a[0] <= key)
       return binarySearch(a, 0, pivot-1, key);
       
   return binarySearch(a, pivot+1, n-1, key);
}
///////////////////////////////////////////////////////////////////////
int main()
{
   int a[9]={5,6,7,8,9,1,2,3,4};
   
   cout<<search(a,9,9);
   
   
   getch();
}
