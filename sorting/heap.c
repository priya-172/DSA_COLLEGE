#include<stdio.h>
//swap
void swap(int arr[],int i,int large){
	int temp=arr[i];
	arr[i]=arr[large];
	arr[large]=temp;
	
}
//max_heap
void heapify(int arr[],int n,int i){
	int largest=i;
	
	int left=2*i;
	int right=2*i+1;
	if(arr[left]>=arr[largest] && left<=n ){
		largest=left;
	}
		if(arr[right]>=arr[largest] && right<=n ){
		largest=right;
	}
	if(i!=largest){
		swap(arr,i,largest);
		heapify(arr,n,largest);
	}
}
//print
void print(int arr[],int n){
	int i;
	for(i=1;i<=n;++i){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
//build heap
void buildheap(int arr[],int n){
	int i;
	for(i=n/2;i>0;--i){
	heapify(arr,n,i);	
	}
	printf("After building max heap,heap is:-\n");
	print(arr,n);
}
void heapsort(int arr[],int n){
	int i;
	for(i=n;i>1;--i){
	swap(arr,i,1);
	heapify(arr,i-1,1);	
	}
	printf("\nafter heap sort-\n");
	print(arr,n);
}
int main(){
	int n,i;
	printf("\nenter the size of array:-\t");
	scanf("%d",&n);
	int arr[n];
	printf("\nenter elemnts:-\t");
	for(i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	 buildheap(arr,n);
	 heapsort( arr, n);
}
