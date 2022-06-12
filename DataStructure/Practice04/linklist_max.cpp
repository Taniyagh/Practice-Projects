// find largest elements in singly linked list.
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
///////////////////////////////////////////
struct node {
    int data;
    struct node* next;
};
/////////////////////////////////////////////////////////
int max(struct node* h)
{
    int max = INT_MIN;
 
    while (h != NULL) 
	{
        if (h->data > max)
            max = h->data;
        h = h->next;
    }
    return max;
}
 
/////////////////////////////////////////////////////////
void   add(struct node** h, int data)
{
    struct node* n;
	
	n = (struct node*)malloc(sizeof(struct node));
 
    n->data = data;
 
    n->next = (*h);
 
    (*h) = n;
}
 
/////////////////////////////////////////////////////////
void show(struct node* h)
{
    while (h != NULL) 
	{
        cout << h->data << "->";
        h = h->next;
    }
    cout << "NULL" << endl;
}
 
/////////////////////////////////////////////////////////
int main()
{
  struct  node *h;
  h =NULL;
  
  add(&h,5)  ;
  add(&h,26);
  add(&h,7);
  
  show(h);
  
  cout<<"\n\nmax="<<max(h);
  
 
getch();
}
