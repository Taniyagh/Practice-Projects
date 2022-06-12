//delete : Doubly Linked List 
    #include<iostream>
    #include<cstdlib>
    #include<conio.h>
    using namespace std;
///////////////////////////////////////
    struct node
    {
        int         data;
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
    void deletenode(int item)
    {
        struct node *t, *q;
        
        if (start->data == item)
        {
            t = start;
            start = start->next;  
            start->prev = NULL;
            free(t);
            return;
        }
        
        q = start;
        while (q->next->next != NULL)
        {   
           if (q->next->data == item)  
            {
                t = q->next;
                q->next = t->next;
                t->next->prev = q;
                free(t);
                return;
            }
            q = q->next;
        }
        
        if (q->next->data == item)    
        { 	
            t = q->next;
            free(t);
            q->next = NULL;
            return;
        }
        
        cout<<"not found"<<endl;
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

///////////////////
    int main()
    {
        create(5);
        create(3);
        create(8);
        create(12);
        
        show();
       
        deletenode(25);
        
        show();
       
		getch();
    }
