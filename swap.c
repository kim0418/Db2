#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define MAX_SIZE 1000
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
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

int main(int argc, char*argv[]){
	int list[MAX_SIZE]={0,};
	int start,end;
	int n=MAX_SIZE;
	srand(time(NULL));
	for(int i=0;i<n;i++){
		list[i]=rand()%100;
	}
	start=clock();
	selection_sort(list,n);
	end=clock();
	printf("선택정렬\n");
	for(int i=0;i<n;i++){
		//printf("%d ",list[i]);
	}
	printf("\n");
	printf("소요시간 %lf\n",(double)(end-start)/(CLOCKS_PER_SEC)*n);
	for(int i=0;i<n;i++){
		list[i]=rand()%100;
	}
	start=clock();
	insertion_sort(list,n);
	end=clock();
	printf("삽입정렬\n");
	for(int i=0;i<n;i++){
		//printf("%d ",list[i]);
	}
	printf("\n");
	printf("소요시간 %lf\n",(double)(end-start)/(CLOCKS_PER_SEC)*n);
	start=clock();
	bouble_sort(list,n);
	end=clock();
	printf("버블정렬\n");
	for(int i=0;i<n;i++){
		//printf("%d ",list[i]);
	}
	printf("\n");
	printf("소요시간 %lf\n",(double)(end-start)/(CLOCKS_PER_SEC)*n);
	start=clock();
	shell_sort(list,n);
	end=clock();
	printf("셀 정렬\n");
	for(int i=0;i<n;i++){
		//printf("%d ",list[i]);
	}
	printf("\n");
	printf("소요시간 %lf\n",(double)(end-start)/(CLOCKS_PER_SEC)*n);
	return 0;
}
