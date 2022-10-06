#include <stdio.h>

int main()
{
    int i,j;
    int a[3][3],b[3][3];
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
    int c[3][3];
    
    printf("Enter the elements of first array");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    scanf("%d",(p+((i*3)+j)));
        
    printf("Enter the elements of second array");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    scanf("%d",(q+((i*3)+j)));
    
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    c[i][j]=*(p+((i*3)+j))+*(q+((i*3)+j));
    
    printf("The addition of 2 matrices is : \n ");
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",c[i][j]);
            printf("\t");
        }
       printf("\n");
    }
    
}
