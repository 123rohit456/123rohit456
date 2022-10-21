#include <stdio.h>

int main()
{
    int i,j,r,c,count=0,k=0,p=0,ct=0,t=0,q=0,x=0,y=0,u=0;
    printf("Enter number of rows : ");
    scanf("%d",&r);
    printf("Enter number of column : ");
    scanf("%d",&c);
    int a[r][c],b[r][c];
    printf("Enter elements of 1st matrix :");
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
    
    printf("Enter elements of 2nd matrix :");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
            if(b[i][j]==0)
            {
                ct++;
            }
            else
            {
                t++;
            }
        }
    }
printf(" 1st Matrix elements are \n");
 for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
   printf(" 2nd Matrix elements are \n");
 for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    
    
    if(count>(r*c)/2)
    {
        printf("1st matrix is sparse \n");
        printf("Number of zeros of 1st matrix : %d and nonzeros of 1st matrix : %d \n",count,k);
        int s[k][3];
       if(count>(r*c)/2)
    {
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                s[p][0]=i;
                s[p][1]=j;
                s[p][2]=a[i][j];
                p++;
            }
        }
    }
 }
 printf("Triplet Representation of 1st matrix \n");
 printf("R \t C \t V \n");
 for(i=0;i<k;i++)
 {
     printf("%d \t %d \t %d \n",s[i][0],s[i][1],s[i][2]);
 }
}
    else
    {
        printf("1st matrix is not sparse \n");
        printf("Number of zeros of 1st matrix : %d and nonzeros of 1st matrix : %d \n",count,k);
    }

 if(ct>(r*c)/2)
    {
        printf("2nd matrix is sparse \n");
        printf("Number of zeros of 2nd matrix : %d and nonzeros of 2nd matrix : %d \n",ct,t);
        int d[t][3];
       if(ct>(r*c)/2)
    {
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                d[q][0]=i;
                d[q][1]=j;
                d[q][2]=b[i][j];
                q++;
            }
        }
    }
 }
 printf("Triplet Representation of 2nd matrix \n");
 printf("R \t C \t V \n");
 for(i=0;i<k;i++)
 {
     printf("%d \t %d \t %d \n",d[i][0],d[i][1],d[i][2]);
 }
}
    else
    {
        printf("1st matrix is not sparse \n");
        printf("Number of zeros of 2nd matrix : %d and nonzeros of 2nd matrix : %d \n",ct,t);
    }
}
