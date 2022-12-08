#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int);
void dequeue();
void print();

void main()
{
    int ch,d,y;
    printf("Circular array operations : \n ");
    do
    {
    printf("1.Insert \n2.Delete\n3.Print\n");
    printf("Enter choice : ");
    scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("Enter data");
            scanf("%d",&d);
            enqueue(d);
            break;
            
            case 2:
            dequeue();
            break;
            
            case 3:
            print();
            break;
        }
        printf("Do you wish to continue(0/1)");
        scanf("%d",&y);
    }while(y==1);
}

void enqueue(int d)
{
    if((rear+1)%max==front || (rear==max-1 && front==0))
    {
        printf("Queue is full");
        return;
    }
    else if(rear=-1)
    {
        front=rear=0;
        queue[rear]=d;
    }    
    else
    {
        rear=(rear+1)%max;
        queue[rear]=d;
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("Stack is empty");
        return;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
}

void print()
{
    if(rear>front)
    {
    for(int i=0;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
    }
    else
    {
        for(int i=front;i<max;i++)
        {printf("%d",queue[i]);}
        for(int i=0;i<=rear;i++)
        {printf("%d",queue[i]);}
    }
}
