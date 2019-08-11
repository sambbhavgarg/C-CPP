#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert_beg(int d);
void insert_end(int d);
void insert_btw(int, int);
void search (int);
void del_beg();
void del_end();
void del_btw();
void display();


void main()
{
    int ch, d, n;
    do
    {
        printf ("\nPress:\n1.Insert in beginning\n2.insert at end\n3.Insert after a node\n4.Delete from beginning\n5.Delete from end\n6.Delete from a specific node\n7.Search a node\n8.Display all nodes");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1: printf ("\nEnter the data to be inserted");
                    scanf ("%d",&d);
                    insert_beg(d);
                    break;
            case 2: printf ("\nEnter the data to be inserted");
                    scanf ("%d",&d);
                    insert_end(d);
                    break;
            case 3: printf ("\nEnter the data to be inserted");
                    scanf ("%d",&d);
                    printf ("\nEnter the data of the node after which you want to insert the node");
                    scanf ("%d",&n);
                    insert_btw(d,n);
                    break;
            case 4: del_beg();
                    break;
            case 5: del_end();
                    break;
            case 6: printf ("\nEnter the node data you want to delete");
                    scanf("%d",&d);
                    del_btw();
                    break;
            case 7: printf ("\nEnter the node data you want to search");
                    scanf ("%d",&d);
                    search(d);
                    break;
            case 8: display();
                    break;

        }
    } while (ch!=9);
}




void insert_beg(int d)
{
    struct node *new1;
    new1= (struct node*)malloc(sizeof(struct node));
    new1->data=d;
    if (head==NULL)
    {
        head=new1;
        new1->next=NULL;
    }
    else
    {
        new1->next=head;
        head=new1;
    }
}



void insert_end(int d)
{
    struct node *new1;
    struct node *temp=head;
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=d;
    new1->next=NULL;
    if (head==NULL)
    head=new1;
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new1;
    }
}




void insert_btw(int d, int n)
{
    struct node *new1;
    struct node *temp=head;
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=d;
    while(temp->data!=n)
    {
        temp=temp->next;
    }
    new1->next=temp->next;
    temp->next=new1;
}



void del_beg()
{
    struct node *temp=head;
    if (head==NULL)
    printf ("Linked list is empty");
    else
    {
        head=head->next;
        printf ("The deleted data is: %d",temp->data);
        free (temp);
    }
}



void del_end()
{
    struct node *temp=head;
    if (head==NULL)
    printf ("Linked list is empty");
    else if (head->next==NULL)
    {
        printf ("The deleted data is: %d", head->data);
        free(head);
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf ("The deleted data is: %d", temp->next->data);
        free(temp->next);
        temp->next=NULL;
    }
}



void del_btw(int d)
{
    struct node *temp1=head;
    struct node *temp2;
    if(head==NULL)
    printf ("Linked list is empty");
    else
    {
        while((temp1->data!=d)&&(temp1->next!=NULL))
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if (temp1->data==d)
        {
            temp2->next=temp1->next;
            free(temp1);
            printf("Node with data %d is deleted",d);
        }
        else
        printf ("Node not found");
    }
}



void search(int d)
{
    int flag=-1;
    int count=1;
    struct node *temp=head;
    while (temp!=NULL)
    {
        if (temp->data==d)
        {
            flag=1;
            printf ("Node founded at %d position", count);
            break;
        }
        count++;
        temp=temp->next;
    }
    if (flag==-1)
    printf ("Node not found in the linked list");
}



void display()
{
    struct node *temp=head;
    printf ("\nData in the linked list:");
    while(temp!=NULL)
    {
        printf ("\n%d", temp->data);
        temp=temp->next;
    }
}
