// use Linked List and subtract two large Numbers
/////////////////////////////////////////////////////////
#include <iostream>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////
struct node
{
    int  data;
    struct node *next;
};
/////////////////////////////////////////////////////////
node* create(int data)
{
    node *t;
    
	t = new node;
    t->data = data;
    t->next = NULL;
    
    return t;
}
/////////////////////////////////////////////////////////
int getLength(node *n)
{
    int c = 0;
    while (n != NULL)
    {
        n = n->next;
        c++;
    }
    return c;
}
/////////////////////////////////////////////////////////////////////////////////
node* addZero(node* s, int d)
{
    node* z,*t;
	
	if (s == NULL)
        return NULL;
 
    z = create(0);
    d--;
    
    t = z;
    while (d--)
    {
        t->next = create(0);
        t = t->next;
    }
    t->next = s;
    return z;
}
//////////////////////////////////////////////////////////////////////////
/* a recursive function, move till the last node,  
   and subtract the digits and create the node and return the node. 
   If d1 < d2, we borrow the number from previous digit. */
node* sub(node* l1, node* l2, bool& borrow)
{
	node *previous,*current;
	
	if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;
 
	previous= sub(l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);
  
    int   d1,d2,sub;
    d1 = l1->data;
    d2 = l2->data;
    sub = 0;
 
    /* if you have given the value value to next digit then reduce the d1 by 1 */
    if (borrow)
    {
        d1--;
        borrow = false;
    }
 
    /* If d1 < d2 , then borrow the number from previous digit.
       Add 10 to d1 and set borrow = true; */
    if (d1 < d2)
    {
        borrow = true;
        d1 = d1 + 10;
    }
 
    sub = d1 - d2;
 
    current = create(sub);
 
    current->next = previous;
 
    return current;
}
/////////////////////////////////////////////////////////
node* subtract(node* l1, node* l2)
{
    node *lnode,*snode,*t1,*t2;
	int   len1,len2;

	if (l1 == NULL &&  l2 == NULL)
            return NULL;
    
    len1 = getLength(l1);
    len2 = getLength(l2);
     
	lnode = NULL;
	snode = NULL;
    t1 = l1;
    t2 = l2;
 
    // If lengths differ, calculate the smaller node and add zeros for smaller node 
    if (len1 != len2)
    {
        lnode = len1 > len2 ? l1 : l2;
        snode = len1 > len2 ? l2 : l1;
        snode = addZero(snode, abs(len1 - len2));
    }
 
    else
    {
        // If both list lengths are equal, then calculate the larger and smaller list. 
		// If 5-6-7 & 5-6-8 are linked list, 
		// then walk through linked list at last node as 7 < 8, 
		// larger node is 5-6-8 and smaller node is 5-6-7.
        while (l1 && l2)
        {
            if (l1->data != l2->data)
            {
                lnode = l1->data > l2->data ? t1 : t2;
                snode = l1->data > l2->data ? t2 : t1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
 
    bool borrow = false;
   
    return sub(lnode, snode, borrow);
}
/////////////////////////////////////////////////////////
void show(struct node *n)
{
    while (n != NULL)
    {
        cout<< n->data;
        n = n->next;
    }
    cout<<"\n";
}
/////////////////////////////////////////////////////////
int main()
{
    node  *h1,*h2,*r;
    
	h1 = create(1); 
    h1->next = create(2);    
    h1->next->next = create(3);
 
    h2 = create(4);

    r = subtract(h1, h2);
 
    show(r);
 
	getch();
}
