#include<stdio.h>
#include<stdbool.h>
int mt[100][100];
int x[100];
int n,e,c,m;
void nextvalue(k){
	while(1){
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0) return;
		int i;
		for(i=1;i<=n;++i){
			if(mt[i][k]==1 && x[i]==x[k]) break;
		}
		if(i==(n+1)) return;
	}
}
void mcolor(int k){
	while(1){
		nextvalue(k);
		if(x[k]==0) return;
		if(k==n){
			int j;
			printf("\nans set:\n");
			for(j=1;j<=n;++j){
				printf("%d ",x[j]);
			}
			c++;
			printf("\n");
		}else
		mcolor(k+1);
	}
}
int main(){
int i,j;
printf("\nenter nodes and edges:\n");
scanf("%d %d",&n,&e);
for(i=0;i<e;++i){
	int u,v;
	printf("\nenter source and destination:\n");
	scanf("%d%d",&u,&v);
	mt[u][v]=1;
	mt[v][u]=1;
}	
printf("\nenter total colours:\n");
scanf("%d",&m);
mcolor(1);
printf("\ntotal ans set:\t%d",c);
}
