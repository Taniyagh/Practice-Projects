#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void f (int n,int m)
{
      if (n==4) 
          return;
     else{
          n=n+1; 
          m=m+1;
          f(n,m);
          cout<<n;
          cout<<m;
          }
}
/////////////////////////////

main()
{
	f(1,4);
	
	getch();
}

