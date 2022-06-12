#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};
///////////////////////////////////////////////////////////
void display(struct node *head)
{
    if(head == NULL)
    {
        cout<<"NULL\n";
    }
    else
    {
        cout<< head -> data<<"->";
        display(head->next);
    }
}
///////////////////////////////////////////////////////////
void   concat(struct node *a,struct node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a->next == NULL)
            a->next = b;
        else
            concat(a->next,b);
    }
    else
    {
        cout<<"Either a or b is NULL\n";
    }
}
///////////////////////////////////////////////////////////
int main()
{
    struct node *prev,*a, *b, *p;
    int n,i;
    
	cout<<"num a:";
    cin>>n;
    
	a=NULL;
    for(i=0;i<n;i++)
    {
        p=new node;
		cin>>p->data;
		
        p->next=NULL;
        if(a==NULL)
            a=p;
        else
            prev->next=p;
        prev=p;
    }
    
	cout<<"num b:";
    cin>>n;
    b=NULL;
    
	for(i=0;i<n;i++)
    {
        p=new node;
        cin>>p->data;
        p->next=NULL;
        if(b==NULL)
            b=p;
        else
            prev->next=p;
        prev=p;
    }
    
    concat(a,b);
    
	cout<<"\n\nconcat:";
	
	display(a);
    
	getch();
}
