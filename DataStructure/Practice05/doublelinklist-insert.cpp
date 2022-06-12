//Doubly Linked List 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
using namespace std;
///////////////////////////////////////
struct node
{
        int            data;
        struct node   *next;
        struct node   *prev;
}*start;
/////////////////////////////////////////////////////////
void create(int value)
{
        struct node *s,*t;
        
        t = new(struct node); 
        t->data = value;
        t->next = NULL;
        
        if (start == NULL)
        {
            t->prev = NULL;
            start = t;
        }
        else
        {
            s = start;
            while (s->next != NULL)
                s = s->next;
            s->next = t;
            t->prev = s;
        }
}
/////////////////////////////////////////////////////////
void add_first(int value)
{
        if (start == NULL)
        {
            cout<<"First Create the list."<<endl;
            return;
        }
        
        struct node *t;
        t = new(struct node);
        
        t->data = value;
		t->prev = NULL;
        t->next = start;
        
        start->prev = t;
        start = t;    
}
    
/////////////////////////////////////////////////////////
void add_pos(int value, int pos)
{
        struct node *t, *p;
        
		if (start == NULL)
              return;
    
        p = start;
        for (int i = 0;i < pos-1 ; i++)
        {
            p = p->next;
            if (p == NULL)
            {
                cout<<"Error"<<endl;
                return;
            }
        }
        
        t = new(struct node);
        t->data = value;
        if (p->next == NULL)
        {
            p->next = t;
            t->next = NULL;
            t->prev = p;      
        }
        else
        {
            t->next = p->next;
            t->next->prev = t;
            p->next = t;
            t->prev = p;
        }
}
/////////////////////////////////////////////////////////
void show()
{
        struct node *t;
        if (start == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        
        t = start;
        while (t != NULL)
        {
            cout<<t->data<<" <-> ";
            t = t->next;
        }
        cout<<"NULL"<<endl;
}
///////////////////
int main()
{
        int choice, x, pos;
        
        while (1)
        {
            cout<<"1. Create"<<endl;
            cout<<"2. Insert at begining"<<endl;
            cout<<"3. Insert after position"<<endl;
            cout<<"4. Display"<<endl;
            cout<<"5. Exit"<<endl;
			
			cout<<"\n\nEnter(1..5): ";
            cin>>choice;
            
			switch ( choice )
            {
            case 1:
                cout<<"Enter: ";
                cin>>x;
                create(x);
                cout<<endl;
                break;

            case 2:
                cout<<"Enter: ";
                cin>>x;
                add_first(x);
                cout<<endl;
                break;

            case 3:
                cout<<"Enter: ";
                cin>>x;
                cout<<"Insert Element after postion: ";
                cin>>pos;
                add_pos(x, pos);
                cout<<endl;
                break;

            case 4:
                show();
                cout<<endl;
                break;

            case 5:
                exit(1);
            }
        }

	getch();
}
