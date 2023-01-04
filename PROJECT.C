#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

struct contact
{
    char name[40];
    long int contact[10];
    char gmail[40];
    char fb_id[40];
    struct contact *next;
};
int i=1,size=0;

void insert_contact(struct contact *);
void search_contact(struct contact *);
void delete_contact(struct contact *);
void display_contact(struct contact *);

void main()
{
    struct contact *head=NULL;
    char c[40];
    int ch,y;
    system("cls");
    printf("\n\n\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\t !!!!!!WELCOME TO OUR PHONE BOOK!!!!!!");
    printf("\n\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    do 
    {
      printf("Enter choice : ");
      scanf("%d",&ch);
     switch(ch)
     {
      case 1:system("cls");
      insert_contact(head);
      break;
      case 2:system("cls");
      insert_contact(head);
      break;
      case 3:system("cls");
      insert_contact(head);
      break;
      case 4:system("cls");
      insert_contact(head);
      break;
      default:printf("\n\t Invalid choice!!Try again!!!");
      break;
     }
     printf("\nDo you wish to continue(0/1)\n");
     scanf("%d",&y);
    }while(y==1);
    
}

void insert_contact(struct contact *head)
{
    struct contact *new=malloc(sizeof(struct contact));
    printf("\n\n\n\tContact Name : ");
    scanf(" %s",new->name)
    printf("\n\tContact Number : ");
    scanf("%ld",new->contact);
    printf("\n\tGmail id : ");
    scanf(" %s",new->gmail);
    printf("\n\tFacebook account : ");
    scanf(" %s",new->fb_id);
    system("cls");
    new->next=NULL;
    size++;
    
    if(size==20)
    {
        system("cls");
        printf("\n\n\n\tPhone Memory is Full");
        printf("\n\tIf you want to add more contact,you have to delete some contact from your list...\n\n");
        return;
    }
    else
    {
        if(head==NULL)
        {
            head=new;
            printf("\n\n\T Done!!! \n\n");
            system("cls");
            return;
        }
        else
        {
            struct contact *a=head;
            while(a->next!=NULL)
            {
                a=a->next;
            }
            a->next=new;
            printf("\n\n\T Done!!! \n\n");
            system("cls");
        }return;
    }
}

void search_contact(struct contact *head)
{
    char ch[40];
    printf("\n\n\n\t Contact name : ");
    scanf(" %s",&ch);
    system("cls");
    
    if(head==NULL)
    {
        system("cls");
        printf("\n\n\n\tNo contact exists in this phone book list!!!\n\n");
        return;
    }
    else{
        struct contact *a=head;
        while(a!=NULL)
        {
            if(strcmp((a->name),ch)==0)
            {
                system("cls");
                printf("\n\n\tContact name : %s ",a->name);
                printf("\n\tContact number : %ld",a->contact);
                printf("\n\tGmail id : %s",a->gmail);
                printf("\n\tFacebook account : %s",a->fb_id);
                return;
            }
            a=a->next;
        }
        system("cls");
        printf("\n\n\n\tThis contact does not exist in the list!!!");
    }
}

void delete_contact(struct contact *head)
{
    char ch[40];
    printf("\n\n\tContact Name : ");
    scanf(" %s",&ch);
    system("cls");
    
    if(head==NULL)
    {
        system("cls");
        printf("\n\tNo Contact Exist in this Phone book List!\n\n");
        return;
    }
    else
 {
      if(strcmp((head->name),ch)==0)
    {
        struct contact *a=head;
        a=a->next;
        free(a);
        printf("\n\t\t\t Done!!!\n\n\n");
        return;
    }
    else
    {
        struct contact *a=head;
        struct contact *b=head->next;
        
        while(b!=NULL)
       {
         if(strcmp((b->name),ch)==0)
          {
              a->next=b->next;
              free(b);
              size--;
              
          }
          a=a->next;
          b=b->next;
       }
       system("cls");
       printf("\n\t\tInvalid Contact!!!\n\n");
    }
  }
}

void display_contact(struct contact *head)
{
    if(head==NULL)
    {
        system("cls");
        printf("\n\n\n\tNo contact exists in this phone Book list!!!");
        return;
    }
    else
    {
     struct contact *p=head;
     while(p!=NULL)
     {
        
        printf("\n\n\t%d.Contact name : %s ",i,a->name);
        printf("\n\tContact number : %ld",a->contact);
        printf("\n\tGmail id : %s",a->gmail);
        printf("\n\tFacebook account : %s",a->fb_id);
        a=a->next;
        i++;
     }
     i=1;
     return;
    }
}


