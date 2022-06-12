#include <iostream>
#include <conio.h>
using namespace std;

/////////////////////////////
void swap(int *a, int *b)
{
	int t;
	
	t  = *a;
	*a = *b;
	*b = t;
}
/////////////////////////////////
void  BubbleSort(int a[], int n)
{
   int count=0, j=0,t;
   bool sorted = false;
   
   while (!sorted) 
   {
		j++;
        sorted = true;
        for (int i=0; i<n-1; i++)
        {
             count++;
             if(a[i] > a[i+1])
                {
                        t = a[i];
                        a[i] = a[i+1];
                        a[i+1] = t;
                        sorted = false;
                }

             cout<< count <<" : ";
             for(int k=0; k< n; k++)
                    cout<< a[k] <<"  ";
             cout<<"\n";
            }           
	cout<<"-----------------\n";   
	} 
}
//////////////////////////////////////////
int main()
{
    int a[] = {5,1,4,2,8};
	int n=5;

    BubbleSort(a,n);
      	
	for (int i=0; i < n; i++)
		cout<< a[i]<<"  ";
	
	getch();
}

