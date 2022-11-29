#include<stdio.h>
#include<stdlib.h>
//분할합병
int getmax(int* arr,int left, int right){
    if(left==right) return arr[left];
    int mid=(left+right)/2;
    int lmax=getmax(arr,left,mid);
    int rmax=getmax(arr,mid+1,right);
    return lmax > rmax ? lmax : rmax;
}

int main(int argc, char*argv[]){
    
    int arr[10]={69,47,34,54,75,23,12,2,78,3};
    int arr1[10]={2,5,1,4,9,7,8,0,3,6};
    int magicarr[10]={0,};

    for(int i=0;i<10;i++){
	magicarr[arr1[i]]=1;
    }
    for(int i=0;i<10;i++){
	if(magicarr[i]!=0)
	    printf("%d ",i);
    }
    printf("\n");
    printf("max=%d\n",getmax(arr,0,9));

    return 0;
}
