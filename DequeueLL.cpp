#include<bits/stdc++.h>
using namespace std;

class node{
    public: long long int data;
    node* npx;
};

node *head = NULL, *tail= NULL;

long long int s = 0;

node* XOR(node *x,node *y)
{
    return reinterpret_cast<node*>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

node* create(long long int x)
{
    node *newnode = new node();
    newnode->data = x;
    newnode->npx = NULL;
    return newnode;
}

void push_f(long long int x)
{
    node* n = create(x);
    node* p = NULL;
    if(head == NULL&&tail==NULL)
    {
        n->npx = XOR(p,head);
        head = n;
        tail = n;
    }
    else
    {
        n->npx = XOR(p,head);
        head->npx = XOR(n,head->npx);
        head = n;
    }
    s++;
}

void push_b(long long int x)
{
    node* n = create(x);
    node* p = NULL;
    if(head == NULL&&tail==NULL)
    {
        n->npx = XOR(p,tail);
        tail = n;
        head = n;
    }
    else
    {
        n->npx = XOR(tail,p);
        tail->npx = XOR(n,tail->npx);
        tail = n;
    }
    s++;
}

bool pop_f()
{
    if(head==NULL&&tail==NULL)
    {
        return false;
    }
    else
    {
        node* p = NULL;
        node* n = XOR(head->npx,p);
        if(n==NULL)
        {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            n->npx = XOR(head,n->npx);
            n->npx = XOR(p,n->npx);
            free(head);
            head = n;
        }
        s--;
        return true;
    }
}

bool pop_b()
{
    if(head==NULL&&tail==NULL)
    {
        return false;
    }
    else
    {
        node* p = NULL;
        node* n = XOR(tail->npx,p);
        if(n==NULL)
        {
            free(tail);
            head = NULL;
            tail = NULL;
        }
        else
        {
            n->npx = XOR(tail,n->npx);
            n->npx = XOR(p,n->npx);
            free(tail);
            tail = n;
        }
        s--;
        return true;
    }
}

long long int get_f()
{
    if(head==NULL&&tail==NULL)
    {
        cout<<"No elements in the queue ";
        return 0;
    }
    return head->data;
}

long long int get_b()
{
    if(tail==NULL&&head==NULL)
    {
        cout<<"No elements in the queue ";
        return 0;
    }
    return tail->data;
}

long long int get_2_f()
{
     if((tail==NULL&&head==NULL))
    {
        cout<<"Queue is empty ";
        return 0;
    }
	else if(head==tail)
	{
		cout<<"Less than 2 elements";
		return 0;
	}
    node *p = NULL;
    node *n = XOR(head->npx,p);
    return n->data;
}

long long int get_2_b()
{
    if((tail==NULL&&head==NULL))
    {
        cout<<"Queue is empty ";
        return 0;
    }
	else if(head==tail)
	{
		cout<<"Less than 2 elements";
		return 0;
	}
    node *p = NULL;
    node *n = XOR(tail->npx,p);
    return n->data;
}

long long int sz()
{
    return s;
}

bool deleteAll()
{
    if(head == NULL&&tail==NULL)
    {
        return false;
    }
    else
    {
        node* tmp = NULL;
        node* next;
        while(head!=tail)
        {
            next = XOR(head->npx, tmp);
            tmp = head;
            free(head);
            head = next;
        }
        free(tail);
        head = NULL;
        tail = NULL;
    }
	s=0;
	return true;
}

int main()
{
    long long int i;
    for(i=0;i<100;i++)
    {
    	push_f(i);
    	push_b(i+1);
    }
    cout<<get_f()<<"\n";
    cout<<get_b()<<"\n";
    cout<<get_2_f()<<"\n";
    cout<<get_2_b()<<"\n";
    cout<<sz()<<"\n";
    cout<<pop_f()<<"\n";
    cout<<pop_b()<<"\n";
    cout<<sz()<<"\n";
    cout<<deleteAll()<<"\n";
    cout<<sz()<<"\n";
    return 0;
}
