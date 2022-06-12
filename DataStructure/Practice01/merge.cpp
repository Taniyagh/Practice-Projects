// merge 
    #include <iostream>
    #include <conio.h>
    using namespace std;
//////////////////////////////////////////////////////////////////
int merge(int a[], int b[], int m, int n)
{
  int i = n;  
  int j = 0;
  int k = 0; 
  while (k < (m+n))
  {
     if ((i < (m+n) && a[i] <= b[j]) || (j == n))
    {
      a[k] = a[i];
      k++;
      i++;
    }
    else  
    {
      a[k] = b[j];
      k++;
      j++;
    }
  }
}
 
///////////////////////////////////////////////////////////////////
 
int main()
{
  int a[8]={-1,-1,-1,-1,-1,10,30,50};
  int b[5]={2,5,20,40,60};
  
  int m=3;
  int n=5;
  
  merge(a,b,m,n);
  
  for(int i=0;i<m+n; i++)
     cout<<a[i]<<"\t";
  
  
  
  
getch();
}
