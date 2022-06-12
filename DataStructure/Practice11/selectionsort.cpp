// selection sort
#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////////////////////    
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
///////////////////////////////////////////////
int main()
{
	int a[] = {10,30,17,12,1,21,15};
	int n = 7;
	int i,j,m;
	
    for (i = 0; i < n-1; i++)
    {
        m = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[m])
            m = j;
        swap(&a[m], &a[i]);
    }
	
	for (int i=0; i < n; i++)
		cout<<a[i]<<"\t";
		
	getch();
}

