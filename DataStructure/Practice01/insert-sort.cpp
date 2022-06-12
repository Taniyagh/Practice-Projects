// insert operation in an sorted array.
    #include <iostream>
    #include <conio.h>
    using namespace std;
///////////////////////////////////////////////////////////////////
int insert(int a[], int key,int n,int c)
{
   if(n>=c)  
     return n;
   
   int i;
   for(i=n-1; (i>=0 && a[i]>key) ; i--)
         a[i+1]=a[i];

   a[i+1]=key;
   return (n+1);
}
   
//////////////////////////////////////////////////////////////////// 

int main()
{
    int a[10]={1,3,4,6,8};
    int key=-7;
    int n=5;
    
	n=insert(a,key,n,10);
    
    for(int i=0;i<n;i++)
      cout<<a[i]<<"\t";
	
	getch();
}
