#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct db 
{
    int id;
    char name[20];
    char mono[20];
    char salary[20];
    struct db *prev,*next;
};

struct db *head=NULL,*temp;

void insert_record();
void delete_record();
void modify_record();
void display_forward();
void display_backward();

void insert_record()
{ 
    struct db *new=malloc(sizeof(struct db));
    new->prev=NULL;
    new->next=NULL;
    printf("Enter Id : ");
    scanf("%d",&new->id);
    printf("Enter name : ");
    scanf(" %s",new->name);
    printf("Enter mobile number : ");
    scanf(" %s",new->mono);
    printf("Enter salary : ");
    scanf(" %s",new->salary);
    
    if(head==NULL)
    {
        head=new;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
}

void delete_record()
{
    char d[20];
    struct db *temp=head,*temp1;
    if (head == NULL)
    {
        printf("Database is empty");
    }
    else
    {
        printf("\nEmployee name : ");
        scanf(" %s",d);
       
        if (!strcmp(head->name,d))
        {
            struct db *a = head;
            head=head->next;
            free(a);
            printf("\n\t\t\t Done!!!\n\n\n");
        }
        else
        {
            while(strcmp(temp->name,d)!=0)
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                temp1->next=NULL;
                free(temp);
            }
            else//if the contact is somewhere in between//
            {
                temp1->next=temp->next;
                free(temp);
            }
        }
    }
}

void display_forward()
{
    if(head==NULL)
    {
        printf("Database  is empty : ");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("------------------------------------------------\n");
            printf("Employe id : %d\n",temp->id);
            printf("Employee name : %s\n",temp->name);
            printf("Employee mobile number : %s\n",temp->mono);
            printf("Employee salary : %s\n",temp->salary);
            printf("------------------------------------------------\n");
            temp=temp->next;
        }
    }
}

void display_backward()
{
    if(temp!=NULL)
    {
            printf("------------------------------------------------\n");
            printf("Employe id : %d\n",temp->id);
            printf("Employee name : %s\n",temp->name);
            printf("Employee mobile number : %s\n",temp->mono);
            printf("Employee salary : %s\n",temp->salary);
            printf("------------------------------------------------\n");
            temp=temp->prev;
            display_backward(temp);
    }
}

void modify_record()
{
    int i,ch;
    temp=head;
    printf("Enter id you want to modify ");
    scanf("%d",&i);
    while(temp->id!=i)
    {
        temp=temp->next;
    }
    printf("\nEnter what you want to modify : 1.Mobile number 2.Salary\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter updated mobile number : ");
        scanf(" %s",temp->mono);
    }
    else
    {
        printf("Enter updated salary : ");
        scanf(" %s",temp->salary);
    }
}

void main()
{
    int ch,y;
    
    do
    {
    printf("-------MENU-------\n");
    printf("[1]Insert a record\n[2]Delete a record\n[3]Modify a record\n[4]Display forward\n[5]Display backward\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert_record();
        break;
        case 2:delete_record();
        break;
        case 3:modify_record();
        break;
        case 4:display_forward();
        break;
        case 5:
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        display_backward();
        break;
        default:
        printf("Invalid choice");
    }printf("Do you wish to continue : [0/1] ");
    scanf("%d",&y);
    }while(y==1);
}
