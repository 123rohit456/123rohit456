
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abc
{
    char name[20];
    int prn;
    struct abc *prev;
    struct abc *next;
};

struct abc *head,*temp;

void  create_secretary();
void insert_member();
void delete_president();
void delete_secretary();
void delete_member();
void count();
void reverse();
void display();

void main()
{  
    int ch,y;
    head=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter Name of President : ");
    scanf(" %s",head->name);
    printf("\nEnter Prn of President : ");
    scanf("%d",&head->prn);
    printf("\n");
    head->next=NULL;
    head->prev=NULL;
    create_secretary();
    do
    {
        printf("Enter choice : 1.Insert Member\n2.Delete President\n3.Delete Secretary\n4.Delete Member\n5.Total Members\n6.Reverse\n7.Display");
        temp=head;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_member();
            break;
            case 2:delete_president();
            break;
            case 3:delete_secretary();
            break;
            case 4:delete_member();
            break;
            case 5:count();
            break;
            case 6:
            printf("Reversed order is : \n");
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            reverse();
            break;
            case 7:display();
            break;
            default:
            printf("Invalid input\n");
        }printf("Do you wish to continue : 0/1 \n");
        scanf("%d",&y);
    }while(y==1);
}    
    
void create_secretary()
{
    struct abc *new=malloc(sizeof(struct abc));
    printf("Enter Name of Secretary : ");
    scanf(" %s",new->name);
    printf("\nEnter Prn of Secretary : ");
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    head->next=new;
    new->prev=head;
}

void insert_member()
{
    struct abc *new=malloc(sizeof(struct abc));
    printf("Enter Name of Member : ");
    scanf(" %s",new->name);
    printf("\nEnter Prn of Member : ");
    scanf("%d",&new->prn);
    new->prev=NULL;
    new->next=NULL;
    temp=head->next;
    head->next=new;
    new->prev=head;
    new->next=temp;
    temp->prev=new;
}

void delete_president()
{
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void delete_secretary()
{
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void delete_member()
{
    temp=head->next;
    head->next=temp->next;
    temp->next->prev=head;
    free(temp);
}

void count()
{
    int n=0;
    temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    printf("\nNumber of committee members are %d \n",n);
}

void reverse()
{
    while(temp!=NULL)
    {
        printf("Name : %s\nPrn : %d\n",temp->name,temp->prn);
        temp=temp->prev;
        reverse(temp);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("Committee is empty");
    }
    else
    {
    temp=head;
    while(temp!=NULL)
    {
        printf("Name : %s\nPrn : %d\n",temp->name,temp->prn);
        temp=temp->next;
    }
    }
}
