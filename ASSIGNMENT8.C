#include <stdio.h>

int main()
{
    int e=1,v,min=0,total,c,d;
    printf("Enter the number of vertices : ");
    scanf("%d",&v);
    
    int a[v][v];
    printf("Enter the cost matrix : \n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            a[i][j]=999;
        }
    }
    
    int visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    visited[0]=1;
    
    while(e<v)
    {
        for(int i=0,min=999;i<v;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<v;j++)
                {
                    if(min>a[i][j])
                    {
                        min=a[i][j];
                        c=i;
                        d=j;
                    }
                }
            }
            if(visited[d]==0)
            {
                total+=min;
                printf("Edge : (%d,%d) Cost : %d\n",c,d,min);
                visited[d]=1;
                a[c][d]=a[d][c]=999;
            }
        }
        e++;
    }
    printf("Total cost of the spanning tree is : %d",total);
}
