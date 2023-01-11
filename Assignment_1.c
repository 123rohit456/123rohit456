#include <stdio.h>

void addition();
void multiplication();
void saddle();
void transpose();

void addition()
{
    int a,b,c,d;
    printf("Enter size of matrix 1 : ");
    scanf("%d %d",&a,&b);
    printf("Enter size of matrix 2 : ");
    scanf("%d %d",&c,&d);
    
    if(a==c && b==d)
    {
        int x[a][b],y[c][d],z[a][b],*p,*q,*r,i,j;
        p=&x[0][0];
        q=&y[0][0];
        r=&z[0][0];
        
        printf("Enter elements of 1st matrix\n");
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        scanf("%d",(p+((i*b)+j)));
    
        printf("Enter elements of 2nd matrix\n");
        for(i=0;i<c;i++)
        for(j=0;j<d;j++)
        scanf("%d",(q+((i*d)+j)));
        
        for(i=0;i<c;i++)
        for(j=0;j<d;j++)
        *(r+((i*d)+j))=*(p+((i*b)+j))+*(q+((i*d)+j));
       
    printf("Addition of 2 matrices is : \n");
    for(i=0;i<a;i++)
    {
    for(j=0;j<d;j++)
    {
    printf("%d",*(r+(i*d)+j));
    printf("\t");
    }
    printf("\n");
    }
        
    }
    else{
        printf("Addition is not possible\n");
    }
    
}

void multiplication()
{
int a,b,c,d;
printf("Enter size of matrix 1 : ");
scanf("%d %d",&a,&b);
printf("Enter size of matrix 2 : ");
scanf("%d %d",&c,&d);
if(b!=c)
{
    printf("Multiplication is not possible\n");
}
else
{
    int x[a][b],y[c][d],z[a][d],*p,*q,*r,i,j,k;
    p=&x[0][0];
    q=&y[0][0];
    r=&z[0][0];
    
    printf("Enter elements of 1st matrix\n");
    for(i=0;i<a;i++)
    for(j=0;j<b;j++)
    scanf("%d",(p+((i*b)+j)));
    
    printf("Enter elements of 2nd matrix\n");
    for(i=0;i<c;i++)
    for(j=0;j<d;j++)
    scanf("%d",(q+((i*d)+j)));
    
    for(i=0;i<a;i++)
    for(j=0;j<d;j++)
    *(r+((i*d)+j))=0;
    
    for(i=0;i<a;i++)
    for(j=0;j<d;j++)
    for(k=0;k<b;k++)
    *(r+((i*d)+j))+= *(p+((i*b)+k))**(q+((k*d)+j));
    
    printf("Multiplication of 2 matrices is : \n");
    for(i=0;i<a;i++)
    {
    for(j=0;j<d;j++)
    {
    printf("%d",*(r+(i*d)+j));
    printf("\t");
    }
    printf("\n");
    }
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

void transpose()
{
int a,b;
printf("Enter the size of matrix ");
scanf("%d %d",&a,&b);

if(a==b)
{
    int x[a][a],y[a][a],*p,*q,i,j;
    p=&x[0][0];
    q=&y[0][0];
    
    printf("Enter matrix elements : ");
    for(i=0;i<a;i++)
    for(j=0;j<a;j++)
    scanf("%d",(p+((i*a)+j)));
    
    for(i=0;i<a;i++)
    for(j=0;j<a;j++)
    *(q+((j*a)+i))=*(p+((i*a)+j));
    
    printf("Transpose of matrix is \n");
    for(i=0;i<a;i++)
    {
    for(j=0;j<a;j++)
    {
        printf("%d",*(q+((i*a)+j)));
        printf("\t");
    }
    printf("\n");
    }
}
else
{
    printf("Transpose of matrix is not possible\n");
}
    
}

int main()
{   int ch,y;
    do
    {
       printf("Matrix operations : 1.Addition\n2.Multiplication\n3.Saddle point\n4.Transpose\nEnter choice : ");
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
           case 4:
           transpose();
           break;
       }printf("Do you wish to continue(0/1) ");
       scanf("%d",&y);
    }while(y==1);
}
