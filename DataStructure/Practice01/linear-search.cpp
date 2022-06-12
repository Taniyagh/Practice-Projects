// linear search 
#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
int find(int a[] , int n, int key)
{
	for(int i=0;i<=n-1 ; i++)
	   if (key==a[i])
	       return i;
	
	return -1;
}
//////////////////////////////
main()
{
   int  a[]={17,8,13,20,6,14};
   
   int n;
   n=sizeof(a)/sizeof(a[0]);
   
   int key=80;
   int p;
   p=find(a,n,key);
   
   if(p==-1)
      cout<<"not found";
   else
      cout<<p;



	
	
getch();
}
