// A recursive binary search function. 
 #include <iostream>
 #include <conio.h>
 using namespace std;

// t(n)= t(n/2) + 1    o(logn)
////////////////////////////////////////////////////////////

int bsearch(int a[], int low, int high, int key)
{
 int mid;
 if(low<=high)
 {
 	mid=low +(high-low)/2;
	
	if (key== a[mid])  return mid;
	
	if (key < a[mid])  return bsearch(a,low,mid-1,key);
	
	if (key> a[mid])   return bsearch(a,mid+1,high,key);
 }
 
 return -1;
}
////////////////////////////////////////////////////////////
int main(void)
{
   int a[]={6,8,9,12,16,18,19};
   
   int n=sizeof(a)/sizeof(a[0]);
   
   int p;
   
   int key=50;
   
   p=bsearch(a,0,n-1,key);
   
   cout<<p;
   
   getch();
}
