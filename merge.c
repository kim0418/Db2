#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<limits.h>
#include<time.h>

#define MAX_SIZE 1000000
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

#define True 1
#define False 0
//Gettimeofday함수
double time_diff(struct timeval *start, struct timeval *end){
	return((end->tv_sec - start->tv_sec)+1e-6*(end->tv_usec - start->tv_usec));
}

//merge_sort
int sorted[MAX_SIZE];

void merge(int list[],int left, int mid, int right){
	int i=left;
	int j=mid+1;
	int k=left;
	while(i<=mid && j<=right){
		if(list[i]<=list[j]) sorted[k++]=list[i++];
		else sorted[k++]=list[j++];
	}
	if(i>mid){
		for(int l=j;l<=right;l++){
			sorted[k++]=list[l];
		}
	}
	else{
		for(int l=i;l<=mid;l++){
			sorted[k++]=list[l];
		}
	}
	for(int l=left;l<=right;l++){
		list[l]=sorted[l];
	}
}

void merge_sort(int list[],int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		merge_sort(list,left,mid);
		merge_sort(list,mid+1,right);
		merge(list,left,mid,right);
	}
}

//quick_sort
int partition(int list[],int left,int right){
	int temp;
	int low=left;
	int high=right+1;
	int pivot=list[left];
	do{
		do{low++;}while(low<=right && list[low]<pivot);
		do{high--;}while(high>=left && list[high]>pivot);
		if(low<high) SWAP(list[low],list[high],temp);
	}while(low<high);
	SWAP(list[left],list[high],temp);
	return high;
}

void quick_sort(int list[],int left, int right){
	if(left<right){
		int q=partition(list,left,right);
		quick_sort(list,left,q-1);
		quick_sort(list,q+1,right);
	}
}

int main(int argc, char*argv[]){
	int list[MAX_SIZE]={0,};
	int list2[MAX_SIZE]={0,};
	struct timeval start;
	struct timeval end;
	int n;
	printf("Input Size: ");
	scanf(" %d",&n);
	srand(time(NULL));
	for(int i=0;i<n;i++){
		list2[i]=rand()%n;
	}
	printf("생성배열: ");
	if(n>30){
		for(int i=0;i<10;i++){
			printf("%d ",list2[i]);
		}
	}
	else{
		for(int i=0;i<n;i++){
			printf("%d ",list2[i]);
		}
	}
	printf("\n");
	for(int i=0;i<n;i++){
		list[i]=list2[i];
	}
	printf("merge_sort: ");
	gettimeofday(&start,NULL);
	merge_sort(list,0,n-1);
	gettimeofday(&end,NULL);
	printf(" %.3lf초",time_diff(&start,&end));
	if(n>30){
		for(int i=0;i<10;i++){
			printf(" %d",list[i]); 
		}
	}
	else{
		for(int i=0;i<n;i++){
			printf(" %d",list[i]);
		}
	}
	printf("\n");
	for(int i=0;i<n;i++){
		list[i]=list2[i];
	}
	printf("\n");
	printf("quick_sort: ");
	gettimeofday(&start,NULL);
	quick_sort(list,0,n-1);
	gettimeofday(&end,NULL);
	printf(" %.3lf초",time_diff(&start,&end));
	if(n>30){
		for(int i=0;i<10;i++){
			printf(" %d",list[i]); 
		}
	}
	else{
		for(int i=0;i<n;i++){
			printf(" %d",list[i]);
		}
	}
	printf("\n");
	return 0;
}
