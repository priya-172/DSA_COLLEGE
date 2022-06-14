//bellman-->single source shortest path
//tc->O((n-1)*E)
//sc->O(n^2)
//only for directed graph-->used to detect -ve edge cycle
/*
enter node and edges:
4 6

enter source, destination and weight:   0 1 2

enter source, destination and weight:   0 3 4

enter source, destination and weight:   1 0 1

enter source, destination and weight:   1 3 3

enter source, destination and weight:   2 1 0

enter source, destination and weight:   3 2 1

distance:
0 0
1 2
2 5
3 4

matrix is:
0 2 5 4
0 2 5 4
0 2 5 4
*/
#include<stdio.h>
#include<limits.h>
struct node{
	int u;
	int v;
	int wt;
};
int main(){
int i,j,src;
int n,e;
printf("\nenter node and edges:\n");
scanf("%d%d",&n,&e);
struct node edges[e];
int m[n-1][n];
for(i=0;i<e;++i){
printf("\nenter source, destination and weight:\t");
int u,v,wt;
scanf("%d%d%d",&u,&v,&wt);
edges[i].u=u;
edges[i].v=v;
edges[i].wt=wt;
}
int dist[n];
for(i=0;i<n;++i){
	dist[i]=INT_MAX;
}
src=0;
dist[src]=0;
for(i=0;i<n-1;++i){

	for(j=0;j<n;++j){
		m[i][j]=INT_MAX;
	}
}
for(i=0;i<n-1;++i){
	for(j=0;j<e;++j){
		if(dist[edges[j].u]==INT_MAX) continue;
		if(dist[edges[j].u]+edges[j].wt<dist[edges[j].v]){
			dist[edges[j].v]=dist[edges[j].u]+edges[j].wt;
		}
	}
	for(j=0;j<n;++j){
		m[i][j]=dist[j];
	}
}
int fl=0;

	for(j=0;j<e;++j){
		if(dist[edges[j].u]==INT_MAX) continue;
		if(dist[edges[j].u]+edges[j].wt<dist[edges[j].v]){
			printf("\n-ve cycle is detected\n");
			fl=1;
			break;
		}
	}
if(fl==0){
	printf("\ndistance:\n");
	for (i = 0; i < n; i++){
	printf("%d %d\n", i, dist[i]);
}
}
printf("\nmatrix is:\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
        	if(m[i][j]==INT_MAX){
        		printf("I ");
			}
			else
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
