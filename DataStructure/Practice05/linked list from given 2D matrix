// f a linked list from given 2D matrix
#include <iostream>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////
struct node {
    int    data;
    node  *right , *down;
};
//////////////////////////////////////////////////////////
node  *f(int a[][3], int i, int j, int n, int m)
{
    if (i > n - 1 || j > m - 1)
        return NULL;
 
    node  *t;
	t = new node();
    t->data = a[i][j];
    
    t->right = f(a, i, j + 1, n, m);
    t->down  = f(a, i + 1, j, n, m);
    
    return t;
}
/////////////////////////////////////////////////////////
void display(node  *head)
{
    node  *right,*down;             
    
    down = head;      

    while (down) 
	{
        right = down;
        while (right) 
		{
            cout << right->data << " ";
            right = right->right;
        }
        cout << "\n";
        down = down->down;
    }
}
 
/////////////////////////////////////////////////////////
int main()
{
    int a[2][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 }
    };
 
    node *head;
    
	head = f(a, 0, 0, 2, 3);
	
    display(head);
	
	getch();
}

