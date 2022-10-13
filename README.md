#include <stdio.h>

int main()
{ 
int i,j,k,e,min,max;
int a[3][3],b[3][3],s[2][2];
int *p,*q,*r;
p=&a[0][0];
q=&b[0][0];
r=&s[0][0];
int c[3][3]; 
int d[3][3];

printf("Matrix operations : \n");

do
{
printf("Which operation do you want to perform\n 1.Addition\n 2.Multiplication\n 3.Saddle point\n 4.exit \n");
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
 printf("Enter matrix elements");
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    scanf("%d",p+i*3+j);
    
    for(i=0;i<3;i++)
    {
        min=*(p+i*3+j);
        for(j=0;j<3;j++)
        {
            if(min>=*(p+i*3+j))
            {
                min=*(p+i*3+j);
                *(r+0*3+0)=i;
                *(r+0*3+1)=j;
            }
        }
        j=*(r+0*3+1);
        max=*(p+0*3+j);
    
    for(k=0;k<3;k++)
    {
        if(max<=*(p+k*3+j))
        {
        max=*(p+k*3+j);
        *(r+1*3+0)=k;
        *(r+1*3+1)=j;
        }
    }
    
    if(min==max)
    {
        if(*(r+0*3+0)==(*(r+1*3+0)) && *(r+0*3+1)==(*(r+1*3+1)))
        {
            printf("Saddle point is at row %d and column %d which is %d",*(r+0*3+0),*(r+0*3+1),min);
        }
     
    }
    }
case 4:
printf("No operation chosen \n");
break;

default:
printf("Invalid input \n");
}
}while(e!=4);

}
