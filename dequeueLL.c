#include<stdio.h>
void enqueue();
int dequeue();
void display();
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *start=NULL, *r=NULL, *f=NULL;
void main()
{
    int i,ch1,ele;
    do
    {
      printf("1.enqueue,2.dequeue,3.display");
      scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:enqueue();break;
            case 2:ele=dequeue();printf("deleted element =%d\n",ele);break;
            case 3:display();break;
            default: printf("Error\n");
        }
      printf("to continue press 1");
      scanf("%d",&i);
    }while(i==1);


}
void enqueue()
{
    int ele;
     struct node *temp,*p;
     p=(struct node *)malloc(sizeof(struct node *));
    printf("ele to insert");
    scanf("%d",&ele);
    p->info=ele;
    p->next=NULL;
    p->prev=NULL;
    if(r==NULL&&f==NULL)
    {
        start=r=f=p;
        r=p;
    }
    else
    {
        r->next=p;
        p->prev=r;
        r=p;
    }
}
int dequeue()
{
    int ele;
    struct node *temp;
    if(f==NULL&&r==NULL)
        ele=0;
    else if(f==r)
    {
        ele=f->info;
        f=r=NULL;
    }
    else
    {
        ele=f->info;
        f=f->next;
        f->prev=NULL;
    }
    return ele;
}
void display()
{
    struct node *temp;
    temp=f;
    while(temp!=r)
    {
        printf("%d->",temp->info);
        temp=temp->next;
    }
    printf("%d->NULL",temp->info);
}
