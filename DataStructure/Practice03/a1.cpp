#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void f (int n)
{
     if (n==3) 
         return;
     else{
          n=n+1; 
          f(n);
          cout<<n;             
         }
}
/////////////////////////////

main()
{
	f(1);
	
	getch();
}

