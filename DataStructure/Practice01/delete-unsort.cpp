// delete operation in a unsorted array
    #include <iostream>
    #include <conio.h>
    using namespace std;
///////////////////////////////////////////////
int findElement(int arr[], int n, int key);

int deleteElement(int arr[], int n, int key)
{
    int pos = findElement(arr, n, key);
 
    if (pos==-1)
    {
        printf("Element not found");
        return n;
    }
 
    // Deleting element
    int i;
    for (i=pos; i<n-1; i++)
        arr[i] = arr[i+1];
 
    return n-1;
}
 
///////////////////////////////////////////////////
int findElement(int arr[], int n, int key)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == key)
            return i;
 
    return -1;
}
 
///////////////////////////////////////////////////
int main()
{
    int i;
    int arr[] = {10, 50, 30, 40, 20};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 30;
 
    n = deleteElement(arr, n, key);
 
    printf("\n\nArray after deletion\n");
    for (i=0; i<n; i++)
      printf("%d  ", arr[i]);
 
    return 0;
}
