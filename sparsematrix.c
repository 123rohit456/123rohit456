#include <stdio.h>

int main()
{
    int i,j,r,c,count=0,k=0;
    printf("Enter number of rows : ");
    scanf("%d",&r);
    printf("Enter number of column : ");
    scanf("%d",&c);
    int a[r][c];
    printf("Enter matrix elements :");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
                count++;
            }
            else
            {
                k++;
            }
        }
    }
printf("Matrix elements are \n");
 for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    
    if(count>(r*c)/2)
    {
        printf("Given matrix is sparse \n");
        printf("Number of zeros : %d and nonzeros : %d",count,k);
    }
    else
    {
        printf("Given matrix is not sparse \n");
        printf("Number of zeros : %d and nonzeros : %d",count,k);
    }
}
