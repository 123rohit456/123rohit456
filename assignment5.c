#include<stdio.h>
#define n 5

int queue[n];

void Enqueue(int);
int Dequeue();
void Display();
int F=-1,R=-1;

int main()
{
int ch,d,y;
do
{
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
printf("Enter your choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element you want to enter :");
scanf("%d",&d);
Enqueue(d);
break;
case 2:
d=Dequeue();
printf("Deleted element is %d",d);
break;
case 3:
Display();
break;
default:printf("Invalid");
}printf("Do you wish to continue : [0/1] ");
scanf("%d",&y);
}while(y==1);
}

void Enqueue(int p)
{
if((R==n-1 && F==0) || (R+1)%n==F)
{
printf("Overflow\n");
}
else
{
if(R==-1)
{
R++;
queue[R]=p;
F=R;
}
else
{
R=(R+1)%n;
queue[R]=p;
}
}
}

int Dequeue()
{
int p;
if(F==-1)
{
return -1;
}
else
{
p=queue[F];
if(F==R)
{
F=-1;
R=-1;
}
else
{
F=(F+1)%n;


}
return p;
}
}


void Display()
{
if(R>=F)
{
for(int i=F;i<=R;i++)
{
printf("%d ",queue[i]);
}
}
else
{
for (int i = 0; i <=R ; i++)
printf("%d ", queue[i]);
for (int i = F; i < n; i++)
printf("%d ", queue[i]);


}
}
