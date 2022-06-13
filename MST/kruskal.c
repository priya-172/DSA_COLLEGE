//0 based
//tc-->o(E^2)
//sc-->o(n^2)
/*
enter number total num of vertices:     5 6

enter number total num of edges:
enter source[1]:        0

enter destination[1]:   1

enter weight[1]:        2

enter source[2]:        1

enter destination[2]:   2

enter weight[2]:        3

enter source[3]:        3

enter destination[3]:   0

enter weight[3]:        6

enter source[4]:        1

enter destination[4]:   4

enter weight[4]:        5

enter source[5]:        4

enter destination[5]:   2

enter weight[5]:        7

enter source[6]:        3

enter destination[6]:   1

enter weight[6]:        8

source- 0        to destination-        1 and weight is->       2

source- 1        to destination-        2 and weight is->       3

source- 1        to destination-        4 and weight is->       5

source- 3        to destination-        0 and weight is->       6
 total min cost is-     16
*/
#include<stdio.h>
#include<stdlib.h>

int parent[100000];
int rank[100000];
struct node{
	int u;
	int v;
	int wt;
};
void bubble_wt(struct node edges[],int e){
	int i,j;
	struct node temp;
	for(i=0;i<e-1;++i){
		for(j=0;j<e-i-1;++j){
			if(edges[j].wt>edges[j+1].wt){
				temp=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=temp;
			}
		}
	}
}
void make(int n){
	int i;
for(i=0;i<n;++i)
{
	parent[i]=i;
	rank[i]=0;
}
}
int find(int a){
	if(parent[a]==a)
	return a;
	return parent[a]=find(parent[a]);
}
void unionn(int a,int b){
   a=find(parent[a]);
    b=find(parent[b]);
    if(rank[a]<rank[b]){
        parent[a]=b;
    }
     else if(rank[a]>rank[b]){
        parent[b]=a;
    }
    else{
    	
      parent[b]=a;
      rank[a]++ ; 
    }
}
void kruskal(struct node edges[],int e,int n){
make(n);
int cost=0,i;
for(i=0;i<e;++i){
	if(find(edges[i].u)!=find(edges[i].v)){
		printf("\nsource-\t%d\t to destination-\t%d and weight is->\t%d\n",edges[i].u,edges[i].v,edges[i].wt);
		cost+=edges[i].wt;
		unionn(edges[i].u,edges[i].v);
	}
}	
printf(" total min cost is-\t%d",cost)	;
}
int main(){
	int n,e,i;
	printf("\nenter number total num of vertices:\t");
	scanf("%d",&n);
	printf("\nenter number total num of edges:\t");
	scanf("%d",&e);
	struct node *edges=NULL;
	edges=(struct node*)(calloc(e,sizeof(struct node)));
	for(i=0;i<e;++i){
		printf("\nenter source[%d]:\t",i+1);
		scanf("%d",&edges[i].u);
		printf("\nenter destination[%d]:\t",i+1);
		scanf("%d",&edges[i].v);
		printf("\nenter weight[%d]:\t",i+1);
		scanf("%d",&edges[i].wt);
	}
bubble_wt(edges,e);
kruskal(edges,e,n);

}
