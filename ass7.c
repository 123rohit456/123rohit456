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

void insertS(struct abc *);
void insertm(struct abc *);
void deletep(struct abc *);
void deletes(struct abc *);
void deletem(struct abc *);
void count(struct abc *);
void reverse(struct abc *);
void display(struct abc *);

void main()
{   
    int ch,y;
    struct abc *head;
    head=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter the name and prn of president \n");
    scanf(" %s",head->name);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;
    insertS(head);
    do
    {
        printf("Enter choice \n 1.INSERT MEMBER \n 2.DELETE PRESIDENT \n 3.DELETE SECRETARY \n 4.DELETE MEMBER \n 5.TOTAL MEMBERS \n 6.REVERSE \n 7.DISPLAY \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertm(head);
            break;
            /*case 2:deletep(head);
            break;
            case 3:deletes(head);
            break;
            case 4:deletem(head);
            break;
            case 5:count(head);
            break;
            case 6:reverse(head);
            break;
            case 7:display(head);
            break;*/
            default:
            printf("INVALID INPUT \n");
        }
     printf("Do you wish to continue : 0 or 1 \n");
     scanf("%d",&y);
    }while(y==1);
}

void insertS(struct abc *head)
{
    struct abc *new;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter the name and prn of secretary \n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    head->next=new;
    new->prev=head;
}

void insertm(struct abc *head)
{
    struct abc *new,*temp;
    new=(struct abc *)malloc(sizeof(struct abc));
    printf("Enter the name and prn of member \n");
    scanf(" %s",new->name);
    scanf("%d",&new->prn);
    new->next=NULL;
    new->prev=NULL;
    temp=head->next;
    head->next=new;
    new->prev=head;
    new->next=temp;
    temp->prev=new;
}
