#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining a structure for the node//
struct contact
{
    char name[20];
    char contact[12];
    char gmail[30];
    char fb_id[20];
    struct contact *next;
};


int i = 1, size = 0;

struct contact *head;

void insert_contact();//Function to insert contact// 
void search_contact();//Function to search contact//
void delete_contact();//Function to delete contact//
void display_contact();//Function to display contact//

void main()
{
    struct contact *head = NULL;
    char c[40];
    int ch, y;
    printf("\n\n\t------------------------------------");
    printf("\n\t------WELCOME TO OUR PHONE BOOK------");
    printf("\n\t-----------------------------------\n");
    do
    {
        printf("-----------------------\n[1]Insert contact\n[2]Search contact\n[3]Delete contact\n[4]Display contact\n-----------------------\n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            delete_contact();
            break;
        case 4:
            display_contact();
            break;
        default:
            printf("\n\t------------Invalid choice-----------");
            break;
        }
        printf("\n--------Do you wish to continue(0/1)--------\n");
        scanf("%d", &y);
    } while (y == 1);
}

void insert_contact()
{
    //Size of the contact book list is 20//
    if (size == 20)
    {
        printf("\n\n\n\t --------Phone Memory is Full------------");
        printf("\n\tIf you want to add more contact,you have to delete some contact from your list...\n\n");
        return;
    }
    else
    {
    struct contact *new = (struct contact*)malloc(sizeof(struct contact));
    printf("------------------------------------------------\n");
    printf("\n\n\n\tContact Name : ");
    scanf(" %s", new->name);
    printf("\n\tContact Number : ");
    scanf(" %s", new->contact);
    printf("\n\tGmail id : ");
    scanf(" %s", new->gmail);
    printf("\n\tFacebook account : ");
    scanf(" %s", new->fb_id);
    printf("\n------------------------------------------------");
    new->next = NULL;
    size++;
        if (head == NULL)
        {
            head = new;
            printf("\n\n\t Done!!! \n\n");
            return;
        }
        else
        {
            struct contact *a = head;
            while (a->next != NULL)
            {
                a = a->next;
            }
            a->next = new;
            printf("\n\n\t Done!!! \n\n");
        }
        return;
    }
}

void search_contact()
{
    char d[20];
   
 

    if (head == NULL)
    {
        printf("\n\n\n\tNo contact exists in this phone book list!!!\n\n");
        return;
    }
    else
    {
        printf("\n\n\n\t Contact name : ");
        scanf(" %s", d);
        struct contact *a = head;
        while (a != NULL)
        {
            if (!strcmp(a->name,d))//This command is true when both the strings are equal//
            {  
                printf("------------------------------------------------\n");
                printf("\n\n\tContact name : %s ", a->name);
                printf("\n\tContact number : %s", a->contact);
                printf("\n\tGmail id : %s", a->gmail);
                printf("\n\tFacebook account : %s", a->fb_id);
                printf("\n------------------------------------------------");
                return;
            }
            a = a->next;
        }
        printf("\n\n\n\tThis contact does not exist in the list!!!");
    }
}
void delete_contact()
{
    char d[10];
   
    struct contact *temp=head,*temp1;
    if (head == NULL)
    {
        printf("\n\tNo Contact Exist in this Phone book List!\n\n");
    }
    else
    {
        printf("\n\n\n\t Contact name : ");
        scanf(" %s", d);
       
        if (!strcmp(head->name,d))
        {
            struct contact *a = head;
            head=head->next;
            free(a);
            printf("\n\t\t\t Done!!!\n\n\n");
        }
        else
        {
            while(strcmp(temp->name,d)!=0)//This command is true when both the strings are equal
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp->next==NULL)// if the contact to be deleted is the last one//
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


void display_contact()
{
    if (head == NULL)
    {
        printf("\n\n\n\tNo contact exists in this phone Book list!!!");
        return;
    }
    else
    {
        struct contact *a = head;
        while (a != NULL)
        {
            printf("------------------------------------------------\n");
            printf("\n\n\t%d.Contact name : %s", i, a->name);
            printf("\n\tContact number : %s", a->contact);
            printf("\n\tGmail id : %s", a->gmail);
            printf("\n\tFacebook account : %s", a->fb_id);
            printf("\n------------------------------------------------");
            a = a->next;
            i++;
        }
        i = 1;
        return;
    }
