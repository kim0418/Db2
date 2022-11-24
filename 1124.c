#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<limits.h>
#include<time.h>

#define MAX_SIZE 1000000
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

#define True 1
#define False 0

//선택정렬
void selection_sort(int list[], int n){
	int least,temp;
	for(int i=0;i<n-1;i++){
		least=i;
		for(int j=i+1;j<n;j++){
			if(list[j]<list[least]){
				least=j;
			}
		}
		SWAP(list[i],list[least],temp);
	}
}
//삽입정렬
void insertion_sort(int list[], int n){
	int i,j,key;
	for(i=0;i<n;i++){
		key=list[i];
		for(j=i-1;j>=0 && list[j]>key;j--){
			list[j+1]=list[j];
		}
		list[j+1]=key;
	}
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
//셀 정렬  gap만큼 떨어진 요소들을 삽입정렬
void inc_insertion_sort(int list[],int first, int last, int gap){
	int i,j,key;
	for(i=first+gap;i<=last;i=i+gap){
		key=list[i];
		for(j=i-gap;j>=first && key<list[j];j=j-gap){
			list[j+gap]=list[j];
		}
		list[j+gap]=key;
	}
}
//n=size
void shell_sort(int list[],int n){
	for(int gap=n/2;gap>0;gap=gap/2){
		if((gap%2)==0) gap++;
		for(int i=0;i<gap;i++){
			inc_insertion_sort(list,i,n-1,gap);
		}
	}
}

double time_diff(struct timeval *start, struct timeval *end){
	return((end->tv_sec - start->tv_sec)+1e-6*(end->tv_usec - start->tv_usec));
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
	printf("Bouble Sort:");
	gettimeofday(&start,NULL);
	bouble_sort(list,n);
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
	printf("Insertion Sort Sort:");
	gettimeofday(&start,NULL);
	insertion_sort(list,n);
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
	printf("Selection Sort:");
	gettimeofday(&start,NULL);
	selection_sort(list,n);
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
