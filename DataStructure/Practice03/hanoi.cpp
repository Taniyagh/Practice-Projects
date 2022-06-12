// hanoi
#include <iostream>
#include <conio.h>
using namespace std;
/////////////////////////////////////////////////////////////////////

void hanoi(int n , int a , int b , int c)
{
	char *m= " ABC ";
	static int count=1;
	
	if( n == 1 )
	{
	    cout<<endl<<count++<<":";
		cout<<" Move Disk # " <<n<<" from "<<m[a]<<" To "<<m[c]<<endl;
	}
	else
	{
		hanoi(n-1 , a , c , b);
		
		cout<<endl<<count++<<":";
		cout<<" Move Disk # " <<n<<" from "<<m[a]<<" To "<<m[c]<<endl;
		
		hanoi(n-1 , b , a , c);

	}
}
////////////////////////////////////////////////////////////////
int main()
{
	int n;
	cout<<"enter n:";
	cin>>n;
	cout<<endl;
	hanoi(n,1,2,3);
	
	getch();
}

