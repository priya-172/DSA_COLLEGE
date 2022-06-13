//flyod_1 based-->
//tc-o(n^3)
//sc-o(n^2)
/*
enter nodes and edges:
4 6

enter source,destination and weight:    1 2 3

enter source,destination and weight:    1 4 5

enter source,destination and weight:    2 1 2

enter source,destination and weight:    2 4 4

enter source,destination and weight:    3 2 1

enter source,destination and weight:    4 3 2

reuslt matrix is:
0       3       7       5
2       0       6       4
3       1       0       5
5       3       2       0

*/

#include<stdio.h>
#include<limits.h>

int min(int x, int y)
{
    if (x > y)
        return y;
    return x;
}
int main(){
	int i,j,k;
	int n,e;
	printf("\nenter nodes and edges:\n");
	scanf("%d%d",&n,&e);
	int dist[n+1][n+1];

	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(i==j) dist[i][j]=0;
			else
			dist[i][j]=INT_MAX;
		}
	}
		for(i=1;i<=e;++i){
		int u,v,wt;
		printf("\nenter source,destination and weight:\t");
		scanf("%d%d%d",&u,&v,&wt);
		dist[u][v]=wt;
	}
	for(k=1;k<=n;++k){
		for(i=0;i<=n;++i){
			for(j=0;j<=n;++j){
				if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX ){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	
	}
	for(i=1; i<=n; i++)
		if(dist[i][i]<0){
			printf("\n-ve edge cycle detected\n");
			return;
		}
	printf("\nreuslt matrix is:\n");
	for(i=1;i<=n;++i){
    for(j=1;j<=n;++j){
        if(dist[i][j]==INT_MAX){
           printf("I\t");
        }else{
            printf("%d\t",dist[i][j]);
        }
    }
    printf("\n");
}
	
}
