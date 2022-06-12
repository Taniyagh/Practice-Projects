//delete
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
/////////////////////////////
struct node
    {
        int          data;
        struct node  *next;
    }*start;   
/////////////////////////////
node *create_node(int v)
    {
        struct  node *n , *s;
        
        n = new(struct node); 
        if (n == NULL)
        {
            cout<<"not allocated "<<endl;
            return 0;
        }
        else
        {
            n->data = v;
            n->next = NULL;     
            return n;
        }
    }
     
////////////////////////////////
void insert_begin()
    {
        struct node *n, *p;
		int v;
        cout<<"data: ";
        cin>>v;
        
        
        n = create_node(v);
        
        if (start == NULL)
        {
            start = n;
            start->next = NULL;          
        } 
        else
        {
            p = start;
            start = n;
            start->next = p;
        }
    }
    
///////////////////////////////////
void del_pos()
    {
        struct node  *s ,*p;
		int pos,i,c=0;

        if (start == NULL) return;
        
		cout << "position: ";
        cin  >> pos;
        
        s = start;
        if (pos == 1) 
		     start = s->next;
        else{
            while (s != NULL) 
			{
                s = s->next;
                c++;  
            }
            
            if (pos>=2 && pos<=c) 
			{
                s = start;
                for (i=1; i<=pos-1; i++) 
				{
                    p = s;
                    s = s->next;
                }
                p->next = s->next;
            }
            else
                cout<<"out of range"<<endl;
            free(s);
        }
}
     
///////////////////////////////////
void show()
    {
        struct node *n;
        if (start == NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }

        n = start;
        cout<<"Elements: "<<endl;
        while (n != NULL)
        {
            cout<<n->data<<"->";
            n = n->next;
        }
        cout<<"NULL"<<endl;
    }
/////////////////////////////////////
main()
    {
        int   x;
        start = NULL;
        
        while (1)
        {
            cout <<"1 . Insert at beginning "  << endl;
            cout <<"2 . delete              " << endl;
            cout <<"3 . Display             " << endl;
            cout <<"4 . Exit                " << endl;
            cout <<"Enter (1 or 2 or 3 or 4) : ";
            
            cin>>x;
            switch(x)
            {
            case 1:
                insert_begin();
                cout<<endl;
                break;

            case 2:
                del_pos();
                break;

            case 3:
                show();
                cout<<endl;
                break;

            case 4:
                exit(1);
                break;  

            }
        }
    getch();
 }
