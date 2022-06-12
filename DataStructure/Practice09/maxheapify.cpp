
    #include <iostream>
    #include <conio.h>
    using namespace std;
////////////////////////////////////////////////
    
void maxHeapify( int i , int *a , int n )
{
    int largest = i;

    int left  = i * 2 + 1;
    int right = i * 2 + 2;

    if( left < n && a[ largest] < a[ left ])
        largest = left;
        
    if( right < n  && a[ largest ] < a[right])
        largest = right;
        
    if( largest != i )
	{
        swap( a[i], a[largest]);
        maxHeapify( largest , a,  n );
    }
}
////////////////////////////////////////////////

int main()
{
    int n;
    int * a;
    
	cout << "n: ";
    cin >> n ;
    
    a = new int[n];
    
    for( int i = 0; i < n ; i++)
        cin >> a[i];


    for( int i = n/2 -1 ; i >= 0 ; i-- )
        maxHeapify( i , a, n);
    
    for(int i = 0; i < n ; i++)
        cout << a[i] << " ";

     
getch();
}
