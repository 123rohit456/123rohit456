#include <stdio.h>
#include <stdlib.h>

struct rollinfo
{
    int roll_no;
    char a[50];
    struct rollinfo *next;
};

void main()
{
    int n,d,i;
    struct rollinfo *head,*new,*temp;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    head=(struct rollinfo *)malloc(sizeof(struct rollinfo));
    printf("Enter roll number of student 1 : ");
    scanf("%d",&d);
    head->roll_no=d;
    head->next=NULL;
    temp=head;
    
    for(i=0;i<n-1;i++)
    {
        new=(struct rollinfo *)malloc(sizeof(struct rollinfo));
        printf("Enter roll number of student %d : ",i+2);
        scanf("%d",&d);
        new->roll_no=d;
        new->next=NULL;
        temp->next=new;
        temp=temp->next;
    }
    
    temp=head;
    for(i=0;i<n;i++)
    {
        if(temp!=NULL)
        {
            printf("Roll number of student %d is %d \n",i+1,temp->roll_no);
            temp=temp->next;
        }
    }
}
