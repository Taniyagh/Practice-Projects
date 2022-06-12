//Circular Doubly Linked List(insert)
    #include<iostream>
    #include<cstdio>
    #include<cstdlib>
    #include<conio.h>

    using namespace std;
///////////////////////////////////////////
struct node
    {
        int          data;
        struct node  *next;
        struct node  *prev;
    }*start, *last;

int counter = 0;
/////////////////////////////////////////////////
node  *create(int item)
    {
        struct node *n;
        n = new(struct node);
        n->data = item;
        n->next = n;
        n->prev = n;
        counter++;  
        return n;
    }
//////////////////////////////////////////////////////////////
void add_begin(int item)
    {
        struct node *n;
        n = create(item);
        
        if (start==NULL && last == NULL)
        {    
            start = last = n;
            n->next = n;
            n->prev = n;
        }
        else
        {
            n->next = start;
            start->prev = n;
            start = n;
            start->prev = last;
            last->next = start;
        }
    }
//////////////////////////////////////////////////////////////
void add_end(int item)
 {
        struct node *n;
        n = create(item);
       if (start==NULL && last == NULL)
        {    
            start = last = n;
            n->next = n;
            n->prev = n;
        }
        else
        {
            last->next = n;
            n->prev = last;
            last = n;
            start->prev = last;
            last->next = start;
        }
}
//////////////////////////////////////////////////////////////
void display()
    {
        int i;
        struct node *s;
        if (start == last && start == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        
        s = start;
        for (i = 1;i <=counter-1 ; i++)
        {	
            cout<<s->data<<" <-> ";
            s = s->next; 
        }
        cout<<s->data<<endl;
    }
  
/////////////////////////////////////////////////////////////
int main()
    {
		add_begin(13);
        add_begin(12);
        add_begin(11);
        display();
        
        add_end(14);
        
		display();
		          
        getch();
    }

     

