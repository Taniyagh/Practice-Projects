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
///////////////////////////////////
void BubbleSortRecursive(int x[], int n)
{
    if (n == 1)
        return;
 
    for (int i=0; i<n-1; i++)
        if (x[i] > x[i+1])
            swap(x[i], x[i+1]);
 
    BubbleSortRecursive(x, n-1);
}
//////////////////////////////////////////
int main()
{
    int a[] = {5,1,4,2,8};
	int n=5;

	BubbleSortRecursive(a, n);
	
	for (int i=0; i < n; i++)
		cout<<a[i]<<"  ";
	
	getch();
}

