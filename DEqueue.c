#include <stdio.h>

#define n 6
int queue[n];
int F=-1,R=-1;

void enqueuef();
void dequeuef();
void enqueuer();
void dequeuer();

void enqueuef()
{
    int d;
    printf("Enter data you want to insert : ");
    scanf("%d",&d);
    if(F==0)
    printf("NOT POSSIBLE\n");
    else
    {
        if(F==-1)
        {
            F=R=0;
            queue[F]=d;
        }
        else
        {
            F--;
            queue[F]=d;
        }
    }
}

void dequeuef()
{
    if(F==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        if(F==R)
        {
            F=R=-1;
        }
        else
        {
            F++;
        }
    }
}

void enqueuer()
{
 int d;
 printf("Enter data to be inserted : ");
 scanf("%d",&d);
 if(F==n-1)
 printf("Queue is full\n");
 else
 {
     if(F==-1)
     {
         F=R=0;
         queue[R]=d;
     }
     else
     {
         R++;
         queue[R]=d;
     }
 }
}

void dequeuer()
{
    if(F==-1)
    printf("Underflow\n");
    else
    {
        int p=queue[R];
        if(F==R)
        {
            F=R=-1;
        }
        else
        R--;
    }
}

void display()
{
    for(int i=F;i<=R;i++)
    {
        printf("%d",queue[i]);
    }
}

void main()
{
    int ch,y;
    do
    {
        printf("\n1.INSERT at front \n2.DELETE at front\n3.INSERT at rear\n4.DELETE at rear\n5.Display\n");
        printf("Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueuef();
            break;
            case 2:dequeuef();
            break;
            case 3:enqueuer();
            break;
            case 4:dequeuer();
            break;
            case 5:display();
            break;
        }printf("Do you wish to continue : (0/1)");
        scanf("%d",&y);
    }while(y==1);
}
