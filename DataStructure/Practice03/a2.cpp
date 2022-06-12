#include <iostream>
#include <conio.h>
using namespace std;
//////////////////////////////
void f (int n)
{
      if (n>=3) 
      {        
        f(n-1);
        cout<<'a';
        cout<< n;
		cout<<'b';         
      }
}
/////////////////////////////

main()
{
	f(4);
	
	getch();
}

