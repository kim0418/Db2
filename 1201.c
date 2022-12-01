#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
#include<algorithm>
#include<vector>

#define MAX_SIZE 1000000

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

#define True 1
#define False 0

using namespace std;

//Gettimeofday함수
double time_diff(struct timeval *start, struct timeval *end){
	return((end->tv_sec - start->tv_sec)+1e-6*(end->tv_usec - start->tv_usec));
}

//버블정렬
void bouble_sort(int list[],int n){
	int temp;
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(list[j]>list[j+1]){
				SWAP(list[j],list[j+1],temp);
			}
		}
	}
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

void time_check(double bouble_time,double merge_time,double quick_time,double STL_time){
	printf("정렬 시간:\n");
	printf("Bubble_sort:%.1lf초, Merge_sort:%.1lf초, Quick_sort:%.1lf초, STL_sort:%.1lf초\n",bouble_time,merge_time,quick_time,STL_time);
	if(quick_time<1){
		bouble_time=bouble_time*900000;
		merge_time=merge_time*900000;
		quick_time=quick_time*900000;
		STL_time=STL_time*900000;
	}
	printf("성능 비교\n");
	if(bouble_time>quick_time) printf("Buble_sort: 내가 구현한 Quick_sort보다 %.1lf배 느림(%lf / %lf)\n",(bouble_time)/(quick_time),bouble_time/900000,quick_time/900000);
	else printf("Buble_sort: 내가 구현한 Quick_sort보다 %.1lf배 빠름(%lf / %lf)\n",(quick_time)/(bouble_time),(quick_time/900000),(bouble_time/900000));
	if(merge_time>quick_time) printf("Merge_sort: 내가 구현한 Quick_sort보다 %.1lf배 느림(%lf / %lf)\n",(merge_time)/(quick_time),merge_time/900000,quick_time/900000);
	else printf("Merge_sort: 내가 구현한 Quick_sort보다 %.1lf배 빠름(%lf / %lf)\n",(quick_time)/(merge_time),quick_time/900000,merge_time/900000);
	if(STL_time>quick_time) printf("STL_sort: 내가 구현한 Quick_sort보다 %.1lf배 느림(%lf / %lf)\n",(STL_time)/(quick_time),STL_time/900000,quick_time/900000);
	else printf("STL_sort: 내가 구현한 Quick_sort보다 %.1lf배 빠름(%lf / %lf)\n",(quick_time)/(STL_time),quick_time/900000,STL_time/900000);
}

int main(int argc, char*argv[]){
	int list[MAX_SIZE]={0,};
	int list2[MAX_SIZE]={0,};
	struct timeval start;
	struct timeval end;
	int n;
	double bouble_time,merge_time,quick_time,STL_time;
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
	printf("Bouble Sort:");
	gettimeofday(&start,NULL);
	bouble_sort(list,n);
	gettimeofday(&end,NULL);
	bouble_time=time_diff(&start,&end);
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
	printf("merge_sort: ");
	gettimeofday(&start,NULL);
	merge_sort(list,0,n-1);
	gettimeofday(&end,NULL);
	merge_time=time_diff(&start,&end);
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
	printf("quick_sort: ");
	gettimeofday(&start,NULL);
	quick_sort(list,0,n-1);
	gettimeofday(&end,NULL);
	quick_time=time_diff(&start,&end);
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
	printf("STL_sort: ");
	vector<int> arr;
	for(int i=0;i<n;i++){
		arr.push_back(list[i]);
	}
	gettimeofday(&start,NULL);
	sort(arr.begin(),arr.end());
	gettimeofday(&end,NULL);
	STL_time=time_diff(&start,&end);
	printf(" %.3lf초",time_diff(&start,&end));
	if(n>30){
		for(int i=0;i<10;i++){
			printf(" %d",arr[i]); 
		}
	}
	else{
		for(int i=0;i<n;i++){
			printf(" %d",arr[i]);
		}
	}
	printf("\n\n");
	time_check(bouble_time,merge_time,quick_time,STL_time);
	return 0;
}
