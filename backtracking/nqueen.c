#include<stdio.h>
#include<stdbool.h>
int c=0;
bool canplace(int row,int col,int x[]){
int i;
for(i=1;i<=row-1;++i){
	if(x[i]==col) return false;
	int diff_col=x[i]-col;
	int diff_row=i-row;
	if(diff_col<0) diff_col=-diff_col;
	if(diff_row<0) diff_row=-diff_row;
	if(diff_col==diff_row) return false;
}
return true;	
}
void nqueen(int i,int n,int x[]){
	int j;
	for(j=1;j<=n;++j){
		if(canplace(i,j,x)){
			x[i]=j;
			if(i==n){
				int k=1;
				printf("\nsol set:\n");
				for(k=1;k<=n;++k){
					printf("%d ",x[k]);
				}
				printf("\n");
				c++;
				return;
			}
				else
		nqueen(i+1,n,x);
		}
	
	}
}
int main(){
	int n;
	printf("\nenter number of queens:\t");
	scanf("%d",&n);
	int x[n+1];
	nqueen(1,n,x);
}
