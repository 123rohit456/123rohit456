#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll_no;
    int marks;
    struct student *next;
}*head,*temp,*new;

struct student *reverse();
void display();
int max();
int min();
float avg(int);

void main()
{   int n,m,r,i,sum=0,a,b;
    struct student *q;
    float c;
    printf("\t \t MARKS RECORD PROGRAM\n \n");
    printf("Enter the number of students : ");
    scanf("%d",&n);
    head=(struct student *)malloc(sizeof(struct student));  
    printf("Enter roll number of student  : ");
    scanf("%d",&r);
    printf("Enter marks of student : ");
    scanf("%d",&m);
    head->roll_no=r;
    head->marks=m;
    head->next=NULL;
    temp=head;
   
    for(i=0;i<n-1;i++)
    {
        new=(struct student *)malloc(sizeof(struct student));
        printf("Enter roll number of student : ");
        scanf("%d",&r);
        printf("Enter marks of student : ");
        scanf("%d",&m);
        new->roll_no=r;
        new->marks=m;
        temp->next=new;
        temp=temp->next;
    }
    q=reverse();
    display(q);
    a=max();
    b=min();
    c=avg(n);
    printf("Maximum marks are %d \n",a);
    printf("Minimum marks are %d \n",b);
    printf("Average of marks is %.2f ",c);
}

struct student *reverse()
{
    struct student *p,*q,*r;
    p=head;
    q=p->next;
    r=q->next;
    while(1)
    {
        q->next=p;
        if(r==NULL)
        {
            break;
        }
        p=q;
        q=r;
        r=r->next;
    }
    head->next=NULL;
    head=q;
    return head;
}    

void display(struct student *q)
{
    struct student *temp=head;
    printf(" ROLLNO \tMARKS \n");
    while(temp!=NULL)
    {
        printf("    %d \t %d \n",temp->roll_no,temp->marks);
        temp=temp->next;
    }
    printf("\n");
}

int max()
{   
    struct student *temp;
    int max;
    temp=head->next;
    max=head->marks;
    while(temp!=NULL)
    {
        if(temp->marks>max)
        {
            max=temp->marks;
        }
        temp=temp->next;
    }
    return max;
}

int min()
{   int min;
struct student *temp;
    temp=head->next;
    min=head->marks;
    while(temp!=NULL)
    {
        if(temp->marks<min)
        {
            min=temp->marks;
        }
        temp=temp->next;
    }
    return min;
}

float avg(int n)
{
    int sum=0;
    float avg;
    while(temp!=NULL)
    {
     sum=sum+temp->marks;
     temp=temp->next;
    }
    avg=sum/n;
    return avg;
}
