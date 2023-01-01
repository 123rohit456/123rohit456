#include <stdio.h>
#include <stdlib.h>

void dijkstras(int n,int cost[10][10],int s,int dist[10])
{
    int i,v,count=1,min,visited[10];
    for(i=1;i<=n;i++)
    {
        visited[i]=0;//Mark all vertex as not visited//
        dist[i]=cost[s][i];
    }
    visited[s]=1;//Mark source vertex as visited//
    dist[s]=0;//Distance from source to source is 0//
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        if(dist[i]<min && visited[i]==0)
        {
            min=dist[i];
            v=i;
        }
        visited[v]=1;//Marking the node as visited//
        count++;
        
        //To update the distance//
        for(i=1;i<=n;i++)
        if(dist[i]>dist[v]+cost[v][i])
        dist[i]=dist[v]+cost[v][i];
    }
}



int main()
{
    int i,j,n,s,cost[10][10],dist[10];
    //distance matrix to contain shortest distance from a source to onother nodes//
    
    //Enter the number of nodes//
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    
    //Enter the cost matrix//
    printf("Cost matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=999;
        }
    }
    
    //Read the source//
    printf("Enter the source : ");
    scanf("%d",&s);
    
    dijkstras(n,cost,s,dist);//calling dijkstras function//
    
    //Printing shortest path//
    printf("Shortest path distance from %d \n",s);
    for(i=1;i<=n;i++)
    if(s!=i)
    printf("%d->%d=%d\n",s,i,dist[i]);
    return 0;
}
