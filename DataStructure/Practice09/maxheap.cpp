// Max Heap
#include <iostream>
#include <conio.h>
using namespace std;
/////////////////////////////////////////////////////////////////
void  exchange(int *x,int *y)
{
	int temp;
	
	temp=*x;
	*x=*y;
	*y=temp;
}
/////////////////////////////////////////////////////////////////
void  Maxheapify ( int a[],int i, int n ) 
{
   int l,r,largest;
   
   l = 2*i;    
   r = 2*i+1;
   
   if ( l <=n  &&  a[l] > a[i] )    
        largest = l;   
   else   
        largest = i ;
   
   if ( r <=n  &&  a[r]  > a[largest] )  
         largest = r ;
   
   if ( largest != i )   
         exchange( &a[i] , &a[largest] );
   
   Maxheapify ( a , largest , n );
}
/////////////////////////////////////////////////////////////////
void BuildMaxheap(int a[],int n)
{
   int i;
   for ( i=n/2 ;  i>=1 ; i--)
       Maxheapify(a , i , n);
}
/////////////////////////////////////////////////////////////////

void heapsort ( int a[],int n )
{
   BuildMaxheap(a , n);
   int i;
   for ( i=n ; i >=2 ; i--)
   { 
       exchange( &a[1] , &a[i]);   
       Maxheapify(a , 1 , i-1 ); 
   }
}
/////////////////////////////////////////////////////////////////
 int main()
    {
        int n, i, x;
        int a[20]={};
        
		cout<<"enter n:";
        cin>>n;
        
		for (i = 0; i < n; i++)
        {
            cout<<"enter: "<<(i)<<endl;
            cin>>a[i];
        }

        heapsort(a,n);

        cout<<"Max Heap\n";

        for (i = 0; i < n; i++)
           cout<<a[i]<<endl;


        getch();

    }
