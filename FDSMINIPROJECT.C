#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[20];
    char contact[10];
    char gmail[20];
    char fb_id[20];
    struct contact *next;
};
int i = 1, size = 0;
struct contact *head;
void insert_contact();
void search_contact();
struct contact * delete_contact();
void display_contact();

void main()
{
    struct contact *head = NULL;
    char c[40];
    int ch, y;
    printf("\n\n\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\t !!!!!!WELCOME TO OUR PHONE BOOK!!!!!!");
    printf("\n\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    do
    {
        printf("1.Insert contact\n2.Search contact\n3.Delete contact\n4.Display contact\n");
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
            head=delete_contact();
            break;
        case 4:
            display_contact();
            break;
        default:
            printf("\n\t Invalid choice!!Try again!!!");
            break;
        }
        printf("\nDo you wish to continue(0/1)\n");
        scanf("%d", &y);
    } while (y == 1);
}

void insert_contact()
{
    struct contact *new = (struct contact*)malloc(sizeof(struct contact));
    printf("\n\n\n\tContact Name : ");
    scanf(" %s", new->name);
    printf("\n\tContact Number : ");
    scanf(" %s", new->contact);
    printf("\n\tGmail id : ");
    scanf(" %s", new->gmail);
    printf("\n\tFacebook account : ");
    scanf(" %s", new->fb_id);
    new->next = NULL;
    size++;

    if (size == 20)
    {
        printf("\n\n\n\tPhone Memory is Full");
        printf("\n\tIf you want to add more contact,you have to delete some contact from your list...\n\n");
        return;
    }
    else
    {
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
    char d[10];
    printf("\n\n\n\t Contact number : ");
    scanf(" %s", d);

    if (head == NULL)
    {
        printf("\n\n\n\tNo contact exists in this phone book list!!!\n\n");
        return;
    }
    else
    {
        struct contact *a = head;
        while (a != NULL)
        {
            if (!strcmp(a->contact,d))
            {
                printf("\n\n\tContact name : %s ", a->name);
                printf("\n\tContact number : %s", a->contact);
                printf("\n\tGmail id : %s", a->gmail);
                printf("\n\tFacebook account : %s", a->fb_id);
                return;
            }
            a = a->next;
        }
        printf("\n\n\n\tThis contact does not exist in the list!!!");
    }
}

struct contact * delete_contact()
{
    char d[10];
    printf("\n\n\n\t Contact number : ");
    scanf(" %s", d);

    if (head == NULL)
    {
        printf("\n\tNo Contact Exist in this Phone book List!\n\n");
    }
    else
    {
        if (!strcmp(head->contact,d))
        {
            struct contact *a = head;
            head=head->next;
            free(a);
            printf("\n\t\t\t Done!!!\n\n\n");
        }
        else
        {
            struct contact *a=head;
            struct contact *b=head->next;

            while (b->next!= NULL)
            {
                if (!strcmp(b->contact,d))
                {
                    a->next = b->next;
                    free(b);
                    size--;
                    break;
                }
                a=a->next;
                b = b->next;
            }
            
            printf("\n\t\tInvalid Contact!!!\n\n");
        }
    }
    return head;
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

            printf("\n\n\t%d.Contact name : %s", i, a->name);
            printf("\n\tContact number : %s", a->contact);
            printf("\n\tGmail id : %s", a->gmail);
            printf("\n\tFacebook account : %s", a->fb_id);
            a = a->next;
            i++;
        }
        i = 1;
        return;
    }
}
