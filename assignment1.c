#include <stdio.h>

void addition();
void multiplication();
void saddle();

void addition()
{
    int i,j,n,*p,*q,*r;
    printf("Enter the size of matrix : ");
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    p=&a[0][0];
    q=&b[0][0];
    r=&c[0][0];
    
    printf("Enter the elements of first array\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",(p+((i*n)+j)));
    
    printf("Enter the elements of second array\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",(q+((i*n)+j)));
    
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    *(r+((i*n)+j))=*(p+((i*n)+j)) + *(q+((i*n)+j));
    
    printf("The addition of 2 matrices is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",*(r+((i*n)+j)));
            printf("\t");
        }
        printf("\n");
    }
}

void multiplication()
{

int a[3][3],b[3][3],*p,*q,*r,d[3][3],i,j,k;
p=&a[0][0];
q=&b[0][0];
r=&d[0][0];

printf("Enter the elements of first array \n");
for(i=0;i<3;i++)
for(j=0;j<3;j++)
scanf("%d",(p+((i*3)+j)));
    
printf("Enter the elements of second array \n");
for(i=0;i<3;i++)
for(j=0;j<3;j++)
scanf("%d",(q+((i*3)+j)));

for(i=0;i<3;i++)
for(j=0;j<3;j++)
*(r+((i*3)+j))=0;

for(i=0;i<3;i++)
for(j=0;j<3;j++)
for(k=0;k<3;k++)
*(r+((i*3)+j))=*(r+((i*3)+j))+(*(p+((i*3)+k)))*(*(q+((k*3)+j)));

 printf("The multiplication of 2 matrices is : \n ");
 for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%d ",d[i][j]);
        printf("\t");
    }
   printf("\n");
}
}


void saddle()
{
    int a[3][3],*p,i,j,min,max,s[2][2],*r,k;
    p=&a[0][0];
    r=&s[0][0];
    printf("Enter matrix elements : ");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    scanf("%d",(p+((i*3)+j)));
    
    for(i=0;i<3;i++)
    {
        min=*(p+((i*3)+0));
        for(j=0;j<3;j++)
        {
            if(min>=*(p+((i*3)+j)))
            {
                min=*(p+((i*3)+j));
                *(r+((0*2)+0))=i;
                *(r+((0*2)+1))=j;
            }
        }
        j=*(r+((0*3)+1));
        max=*(p+0*3+j);
        
        for(k=0;k<3;k++)
        {
            if(max<=*(p+((k*3)+j)))
            {
                max=*(p+((k*3)+j));
                *(r+((1*2)+0))=k;
                *(r+((1*2)+1))=j;
            }
        }
        
        if(min==max)
        {
            if(*(r+((0*2)+0))==*(r+((1*2)+0)) && *(r+((0*2)+1))==*(r+((1*2)+1)))
            {
                printf("Saddle point is at row %d and column %d which is %d \n",*(r+((0*2)+0)),*(r+((0*2)+1)),min);
            }
        }
    }
}


int main()
{   int ch,y;
    do
    {
       printf("Matrix operations : 1.Addition\n2.Multiplication\n3.Saddle point\nEnter choice : ");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:
           addition();
           break;
           case 2:
           multiplication();
           break;
           case 3:
           saddle();
           break;
       }printf("Do you wish to continue(0/1) ");
       scanf("%d",&y);
    }while(y==1);
}
