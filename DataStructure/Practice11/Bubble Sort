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
//////////////////////////////////////////
int main()
{
    int a[] = {5,1,4,2,8,3,7,6};
	int n=8;
    int i, j;
    bool flag;
   
    for (i = 0; i <= n-2; i++)
    {
       flag = false;
       for (j = 0; j <= n-2-i; j++)
         {
            if (a[j] > a[j+1])
            {
              swap(&a[j], &a[j+1]);
              flag = true;
            }
         }
       if (flag == false)
           break;
     } 
   
   	
	for (i=0; i < n; i++)
		cout<< a[i]<<"  ";
	
	getch();
}

