// insert operation in an unsorted array.
    #include <iostream>
    #include <conio.h>
    using namespace std;
///////////////////////////////////////////////////////////////////
int insert(int a[], int key,int n,int c)
{
    if(n>=c)
       return n;
    
    a[n]=key;
    return(n+1);  
}
//////////////////////////////////////////////////////////////////// 

int main()
{
    int  a[10]={6,9,2,5,17,25,12};
    int c=sizeof(a)/sizeof(a[0]);
    int n=7;
    
    int key=13;
    
    n=insert(a,key,n,c);
    
    for(int i=0;i<n;i++)
       cout<<a[i]<<"\t";
 
    getch();
}
