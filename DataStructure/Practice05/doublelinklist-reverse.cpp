//reverse : Doubly Linked List 
    #include<iostream>
    #include<cstdio>
    #include<conio.h>

    using namespace std;
///////////////////////////////////////
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    }*start;

/////////////////////////////////////////////////////////
    void create(int item)
    {
        struct node *s, *t;
        t = new(struct node); 
        t->data = item;
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
    void show()
    {
        struct node *q;
        if (start == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        
		q = start;
        while (q != NULL)
        {
            cout<<q->data<<" <-> ";
            q = q->next;
        }
        cout<<"NULL"<<endl;
    }
/////////////////////////////////////////////////////////
    void reverse()
    {
        struct node *p1, *p2;
        
        p1 = start;
        p2 = p1->next;
        
		p1->next = NULL;
        p1->prev = p2;
        
        while (p2 != NULL)
        {
            p2->prev = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2->prev; 
        }
        start = p1;
        
   }
///////////////////
    int main()
    {
       create(4);
       create(7);
       create(2);
       
       show();
       
       reverse();
       
       show();
       
       
	   getch();
    }
