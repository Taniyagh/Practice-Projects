 // A iterative binary search function.
 #include <iostream>
 #include <conio.h>
 using namespace std;
///////////////////////////////////////////////////////////////
int ibsearch(int a[], int low, int high, int key)
{
  int mid;
  while(low<=high)
  {
  	mid=low+(high-low)/2;
  	
	if(key==a[mid])   return mid;
  	
  	if(key>a[mid])    low=mid+1;
  	
  	else  high=mid-1;
  }
  
  return -1;
}
 
////////////////////////////////////////////////////////////
int main(void)
{
   int a[]={6,8,9,12,16,18,19};
   
   int n=sizeof(a)/sizeof(a[0]);
   
   int p;
   
   int key=190;
   
   p=ibsearch(a,0,n-1,key);
   
   cout<<p;
   
   getch();
}
