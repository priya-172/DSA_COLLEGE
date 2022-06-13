//0 based-->prims' algo
//tc-->o(n^2)
//sc-->o(n^2)
/*entrer nodes and edges: 5 6

enter source , destination and weight:
0 1 2

enter source , destination and weight:
0 3 6

enter source , destination and weight:
1 3 8

enter source , destination and weight:
1 4 5

enter source , destination and weight:
1 2 3

enter source , destination and weight:
4 2 7

MST IS
0 1 2
1 2 3
0 3 6
1 4 5 
Minimum cost is 16
*/
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int main(){
	
	int n,e;//n-->vertices,e-->edges
	printf("\nentrer nodes and edges:\t");
	scanf("%d%d",&n,&e);
	int i,j,k;
	int edge[n][n];
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			edge[i][j]=0;
		}
	}
	for(i=0;i<e;++i){
		int u,v,wt;
		printf("\nenter source , destination and weight:\n");
		scanf("%d%d%d",&u,&v,&wt);
		edge[u][v]=wt;
		edge[v][u]=wt;	
			
	}
	int parent[n];
	int key[n];
	bool visited[n];
	for(i=0;i<n;++i){
		parent[i]=-1;
		key[i]=INT_MAX;
		visited[i]=false;
		
	}
	key[0]=0;
	parent[0]=-1;
	//find min key array go on the adj and repeat it n-1 time
	for(i=0;i<n-1;++i){
		int mini=INT_MAX;
		int source;
		//find min key
		for(j=0;j<n;++j){
		if(!visited[j] && key[i]<mini){
			mini=key[i];
			source=i;
			visited[source]=true;
		}	
		}
		for(k=0;k<n;++k){
			if(!visited[k] && edge[source][k]<key[k] && edge[source][k]!=0){
			key[k]=edge[source][k];
			parent[k]=source;
				
			
			}
		}
	}

	printf("\nMST IS\n");
	int total_cost=0;
	for(i=1;i<n;++i){
		printf("%d %d %d\n",parent[i],i,key[i]);
		total_cost += edge[parent[i]][i];
	}
	    printf("Minimum cost is %d\n", total_cost);
}
