// LevelOrder
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
///////////////////////////////////////////
struct node
{
    int           data;
    struct node*  left;
    struct node*  right;
};
 
///////////////////////////////////////////
struct node* create(int item)
{
    struct node* n;
	n= new(struct node);
    
	n->data  = item;
    n->left  = NULL;
    n->right = NULL;
 
    return(n);
}

/////////////////////////////////////////////////////////////////////////// 
struct node** createQueue(int *front, int *rear)
{
    struct node **q;
	
	q = (struct node **)malloc(sizeof(struct node*)*200);
 
    *front = *rear = 0;
    return q;
}
/////////////////////////////////////////////////////////////////////////// 
void insert(struct node **q, int *rear, struct node *n)
{
    q[*rear] = n;
    (*rear)++;
}
/////////////////////////////////////////////////////////////////////////// 
struct node *del(struct node **q, int *front)
{
    (*front)++;
    return q[*front - 1];
}
//////////////////////////////////////////////////////////////////////////
void levelorder(struct node* root)
{   
    struct node *t;
    t = root;
    
    struct node **q;
	int rear, front;
	q = createQueue(&front, &rear);

    while (t)
    {
        cout<<t->data<<"  ";
        
        if (t->left)
            insert(q, &rear, t->left);
 
        if (t->right)
            insert(q, &rear, t->right);
 
        t = del(q, &front);
    }
}
 

///////////////////////////////////////////

int main()
{
    struct node *r;
	
	r                     = create(1);
	
    r->left               = create(2);
    r->right              = create(3);
    
    r->left->left         = create(4);
    r->left->right        = create(5);
 
    r->left->right->left  = create(6);
     
    levelorder(r);
 
    getch();
}
