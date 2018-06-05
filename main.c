#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost[10][10];
    int distance[10];
    int path[10][10];
    int n;
    int v;
    int p;
    int row;
    int column;
    int min;
    int index=1;
    int i;
    int j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix: ");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the node to visit: ");
    scanf("%d", &v);

	printf("Enter the paths for the selected node : ");
	scanf("%d", &p);

	printf("Enter path matrix \n");
	for(i=1; i<=p; i++)
	{
		for(j=1; j<=n; j++)
            {
			scanf("%d", &path[i][j]);
            }
	}

	for(i=1; i<=p; i++)
	{
		distance[i]=0;
		row=1;
		for(j=1; j<n; j++)
		{
			if(row!=v)
			{
				column=path[i][j+1];
				distance[i] =  distance[i]+cost[row][column];
			}
			row=column;
		}
	}

	min=distance[1];
	for(i=1; i<=p; i++)
	{
		if(distance[i] <= min)
		{
			min=distance[i];
			index=i;
		}
	}
	printf("min distance is %d\n",min);
	printf("min distance path is\n");
	for(i=1; i<=n; i++)
	{
		if(path[index][i]!=0)
			printf("--->%d", path[index][i]);
	}
    return 0;
}
