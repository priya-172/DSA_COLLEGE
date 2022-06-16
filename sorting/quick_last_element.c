#include<stdio.h>

int partition(int p,int r,int a[]){
	int pivot=a[r];
	int i=p-1;
	int j;
	for(j=p;j<=r-1;++j){
		if(a[j]<=pivot){
			i++;
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
		
	}

		int t=a[i+1];
			a[i+1]=a[r];
			a[r]=t;
	return i+1;
}
void quicksort(int l,int h,int a[]){
	if(l>=h) return;
	int p=partition(l,h,a);
	quicksort(l,p-1,a);
	quicksort(p+1,h,a);
}
int main(){
	int n,i;
	printf("\nenter size of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("\nenter elements of arr:\n");
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	
	quicksort(0,n-1,a);
	for(i=0;i<n;++i){
		printf("%d\t",a[i]);
	}
	
}
