#include <stdio.h>


int main()
{
    int i,j,k,e;
    int a[3][3],b[3][3];
    int *p,*q;
    p=&a[0][0];
    q=&b[0][0];
    int c[3][3];
    int d[3][3];
    
    printf("Matrix operations : \n");
    
    do
    {
    printf("Which operation do you want to perform 1.Addition 2.Multiplication 3.Saddle point 4.exit \n");
    scanf("%d",&e);
    switch(e){
    case 1:
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
    
    printf("\n");
    break;
    
    case 2:
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
    d[i][j]=0;
    
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    for(k=0;k<3;k++)
    d[i][j]=d[i][j]+(*(p+((i*3)+k)))*(*(q+((k*3)+j)));
    
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
    break;
    case 3:
    printf("Saddle");
    break;
    case 4:
    printf("No operation chosen");
    break;
    }
    }while(e!=4);
   
    
    
}
