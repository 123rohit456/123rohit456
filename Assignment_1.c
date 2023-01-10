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
    int i,j,k,a,b,m,n,*p,*q;
    printf("Enter the size of 1st matrix : ");
    scanf("%d %d",&a,&b);
    int c[a][b];
    p=&c[0][0];
    printf("Enter the size of 2nd matrix : ");
    scanf("%d %d",&m,&n);
    int d[m][n];
    q=&d[0][0];
    
    if(b!=m)
    {
        printf("Multiplication is not possible\n");
    }
    else
    {
    printf("Enter the elements of first array\n");
    for(i=0;i<a;i++)
    for(j=0;j<b;j++)
    scanf("%d",(p+((i*a)+j)));
    
    printf("Enter the elements of second array\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",(q+((i*m)+j)));
    
    int e[a][n],*r;
    r=&e[0][0];
    for(i=0;i<a;i++)
    for(j=0;j<n;j++)
    *(r+((i*a)+j))==0;
    
    for(i=0;i<a;i++)
    for(i=0;i<n;i++)
    for(k=0;k<n;k++)
    *(r+((i*a)+j))= *(r+((i*a)+j))
    
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
           case 2:
           multiplication();
           /*case 3:
           saddle();*/
       }printf("Do you wish to continue(0/1) ");
       scanf("%d",&y);
    }while(y==1);
}
