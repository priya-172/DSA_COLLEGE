//bottom-up
//tc->o(n^3)
//sc->o(n^2)
/*
enter size of array:     4

enter dimension 5 4 6 2 7
operations 1-
0       120     88      158
I       0       48      104
I       I       0       84
I       I       I       0
for parentheses-
I 1 1 3
I I 2 3
I I I 3
I I I I

min cost-       158
((A1    (A2     A3      ))A4    )
*/
#include<stdio.h>
#include<limits.h>

int p[100][100];
void Braces(int i,int j)
{
    if(i==j)
    {
        printf("A%d\t",i);
        return;
    }
    else
    {
        printf("(");
        Braces(i,p[i][j]);
        Braces(p[i][j]+1,j);
        printf(")");
    }
}

int main(){
	int n,i,j,k,d;
	printf("\nenter size of array:\t ");
	scanf("%d",&n);
	int a[n+1];
	int dp[n+1][n+1];
	
	printf("\nenter dimension\t");
	for(i=0;i<=n;++i){
		scanf("%d",&a[i]);
	}
	    for (i =0; i <=n; i++)
    {
        for (j =0; j <=n; j++)
        {
            if (i == j)
                dp[i][j] =0;
            else
            {
                dp[i][j] =INT_MAX;
            }
            p[i][j] =INT_MAX; 
        }
    }
for(d=1;d<=n-1;++d){
	for(i=1;i<=n-d;++i){
		j=i+d;
		int mini=INT_MAX;
		for(k=i;k<j;++k){
				int s=a[i-1]*a[j]*a[k]+dp[i][k]+dp[k+1][j];
				if(s<mini){
					mini=s;
					p[i][j]=k;
				}
		}
		dp[i][j]=mini;
	}
}
    printf("operations 1-\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (dp[i][j] == INT_MAX) 
                printf("I");
            else
                printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
        printf("for parentheses-\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (p[i][j] == INT_MAX)
                printf("I ");
            else
                printf("%d ", p[i][j]);
        }
        printf("\n");
    }
printf("\nmin cost-\t%d\n",dp[1][n]);
 Braces(1, n);
}
