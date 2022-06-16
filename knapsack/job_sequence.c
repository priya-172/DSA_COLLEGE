#include<stdio.h>
#include<limits.h>
int maxi;
void print(int a[],int n){
	int i,j;
	for(i=0;i<n;++i){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void jobseq(int id[],int deadline[],int profit[],int n ){
	int i,j;
	maxi=INT_MIN;
	int curr_job=0;
	int curr_profit=0;

	for(i=0;i<n;++i){
		if(deadline[i]>maxi){
			maxi=deadline[i];
		}
	}
		int res[maxi+1];
		for(i=0;i<n;++i){
			res[i]=-1;
		}
		for(i=0;i<n;++i){
			for(j=deadline[i];j>0;--j){
				if(res[j]==-1){
					res[j]=i;
					curr_job++;
					curr_profit+=profit[i];
					break;
				}
			}
		}
		printf("\ntotal job-\t%d",curr_job);
printf("\ntotal profit-\t%d",curr_profit);
}
void sort(int id[],int deadline[],int profit[],int n){
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n-i-1;++j){
			if(profit[j]<profit[j+1]){
			int temp=profit[j];
			profit[j]=profit[j+1];
			profit[j+1]=temp;
			int temp1=id[j];
			id[j]=id[j+1];
			id[j+1]=temp1;
			int temp2=deadline[j];
			deadline[j]=deadline[j+1];
			deadline[j+1]=temp2;	
			}
		}
	}
}
int main(){
	int i,j,n;
	printf("\n\tenter the size of array-\t");
	scanf("%d",&n);
	int id[n],deadline[n], profit[n];
	printf("\n\tenter id__deadline__profit\n");
	for(i=0;i<n;++i){
		scanf("%d%d%d",&id[i],&deadline[i],&profit[i]);
	}
	sort(id,deadline,profit,n);
	//print(profit,n);
	jobseq(id,deadline,profit, n );
}
