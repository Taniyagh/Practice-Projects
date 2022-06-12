 // Circular Linked List 
    #include<iostream>
    #include<cstdlib>
    #include<conio.h>
    using namespace std;
///////////////////////////////////////////
struct node
{
        int data;
        struct node *next;
}*last;
//////////////////////////////////////////////////////////
void create(int item)
{
        struct node *n;

        n = new(struct node);
        n->data = item;
        
        if (last == NULL)
        {
            last = n;
            n->next = last;   
        }

        else
        {
            n->next = last->next; 
            last->next = n;
            last = n;
        }
}  
//////////////////////////////////////////////////////////////////
void del(int item)
{
        struct node *f, *s;
        
        s = last->next;
     
        if (last->next == last && last->data == item)  
        {
            f = last;
            last = NULL;
            free(f);
            return;
        }

        if (s->data == item)  
        {
            f = s;
            last->next = s->next;
            free(f);
            return;
        }

        while (s->next != last)
        {
            if (s->next->data == item)    
            {
                f= s->next;
                s->next = f->next;
                free(f);
                return;
            }
            s = s->next;
        }

        if (s->next->data == item)    
        {
            f = s->next;
            s->next = last->next;
            free(f);		
            last = s;
            return;
        }
        cout<<" not found "<<endl;
}

///////////////////////////////////////////////////////////////////////
void show()
{
        struct node *t;

        t = last->next;
        do{
            cout<< t->data <<"  ";
            t = t->next;
        }while (t != last->next);
     
	 cout<<endl;
}
///////////////////////////////////////////////////////////

int main()
{
          
                
               
  getch();
}
