//matrix_chain-top_down approch
//tc-->o(n^3)
//sc-->o(n^2)
/*
enter size of array:     4

enter dimension
5 4 6 2 7

min cost-
158
*/


#include<stdio.h>
#include<limits.h>
	int dp[50][50];
int f(int i,int j,int a[]){
	if(i>j) return;
	if(i==j) return 0;
	 if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
	int mini=INT_MAX;
	int k;
	for(k=i;k<j;++k){
		int s=a[i-1]*a[j]*a[k]+f(i,k,a)+f(k+1,j,a);
		if(s<mini) mini=s;
	}

return dp[i][j]=mini;
}
int main(){
	int n,i,j,k;
	printf("\nenter size of array:\t ");
	scanf("%d",&n);
	int a[n+1];

	printf("\nenter dimension\t");
	for(i=0;i<=n;++i){
		scanf("%d",&a[i]);
	}
	    for (i =0; i <=n; i++)
    {
        for (j =0; j <=n; j++)
        {
          dp[i][j]=-1;
        }
    }

int t=f(1,n,a);
printf("\nmin cost-\n");
printf("\n%d\n",t);

}
