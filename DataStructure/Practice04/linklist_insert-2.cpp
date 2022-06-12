 //Linked List
    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <conio.h>
    using namespace std;
/////////////////////////////////////////////////
    struct node
    {
        int          data;
        struct node  *next;
    }*start;
     
/////////////////////////////////////////////////
node *create_node(int val)
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
            n->data = val;
            n->next = NULL;  
			   
            return n;
        }
    }
     
/////////////////////////////////////////////////
    void insert_begin()
    {
        struct node *n, *p;
        int v;
        cout<<"value : ";
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
    
/////////////////////////////////////////////////
    void insert_last()
    {
        struct node *n, *s;
		int v;
        cout<<"value : ";
        cin>>v;
        
        
        n = create_node(v);
        
		s = start;     
        while (s->next != NULL)
        {         
            s = s->next;        
        }
        
        n->next = NULL;
        s->next = n;
    }
  
/////////////////////////////////////////////////
void insert_pos()
    {
        struct node *n, *s, *p;
		int v, pos, c = 0; 
        cout<<"data : ";
        cin>>v;
        
        
        n = create_node(v);
        
        cout<<"postion : ";
        cin>>pos;
        
        int i;
        s = start;
        
        while (s != NULL)
        {
            s = s->next;
            c++;
        }
        
        if (pos == 1)
        {
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
        else if (pos > 1  && pos <= c)
        {
            s = start;
            for (i = 1; i < pos; i++)
            {
                p = s;
                s = s->next;
            }
            p->next = n;
            n->next = s;
        }
        else
        {
            cout<<"Positon out of range"<<endl;
        }
    }
//////////////////////////////////////////////////////
 void display()
    {
        struct node *t;
        if (start == NULL)
        {
            cout<<"Empty"<<endl;
            return;
        }

        t = start;
        cout<<"Elements: "<<endl;
        
		while (t != NULL)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout<<"NULL"<<endl;
   }
//////////////////////////////////////////////////
main()
 {
   int x;
   start=NULL;
   
   while(1)     
   {
   	cout<<"1. insert in begin     " << endl;
   	cout<<"2. insert in end       " << endl;
   	cout<<"3. insert in position  " << endl;
   	cout<<"4. show list           " << endl;
   	cout<<"5. exit                " << endl;
   	cout<<"enter(1..5):           " << endl;
   	
	cin >>x;
	
	switch(x)
	{
		case 1:
			    insert_begin();
			    cout<<endl;
			    break;
		case 2:
			    insert_last();
			    cout<<endl;
			    break;
		case 3:
			    insert_pos();
			    cout<<endl;
			    break;
		case 4:
			    display();
			    cout<<endl;
			    break;
		case 5:
			    exit(1);
			    break;
	}
   	
   }
        
        
        
        
    getch();
 }
