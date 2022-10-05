#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int* MakeRoot(int levels){
	int arr_size=pow(2,levels);
	int*root=(int*)malloc(arr_size*sizeof(int));
	for(int i=0;i<arr_size;i++){
		root[i]=999;
	}
	return root;
}

void insertTree(int **arr){
	int pos,data;
	while(1){
		printf("pos, data = ? ");
		scanf("%d %d",&pos,&data);
		if(pos==0){
			printf("complete insert data\n");
			break;
		}
		(*arr)[pos]=data;
	}
}

void searchroot(int**arr,int levels){
	int target;
	int count=1;
	int root_size=pow(2,levels);
	while(1){
		printf("serch root-data(exit:999): ");
		scanf("%d",&target);
		if(target==999){
			printf("[EXIT]\n");
			exit(1);
		}
		for(int i=1;i<root_size;i++){
			if((*arr)[i]==target){
				printf("%d: ",target);
				printf("parant_root=%d,",(*arr)[i/2]);
				if((*arr)[i*2]==999){
					printf("left_root= NULL,");
				}
				else{
					printf("left_root=%d,",(*arr)[i*2]);
				}
				if((*arr)[i*2+1]==999){
					printf("right_root= NULL,");
				}
				else{
					printf("left_right=%d,",(*arr)[i*2+1]);
				}
				if(i%2==0){
					printf("brother_root=%d",(*arr)[i+1]);
				}
				else{
					printf("brother_root=%d",(*arr)[i-1]);
				}
				printf("\n");
				break;
			}
			count++;
			if(count==root_size){
				printf("%d is not exist\n",target);
			}
		}
		
	}
	
}

void printroot(int **arr,int levels){
	for(int i=0;i<levels;i++){
		int count=pow(2,i)-1;
		printf("Lev%d: ",i+1);
		for(int j=1;j<pow(2,i)+1;j++){
			if((*arr)[j+count]==999){
				printf(" - ");
			}
			else{
				printf(" %d ",(*arr)[j+count]);
			}
		}
		printf("\n");
	}
}

void printroot2(int **arr,int levels){
	int s,e=0;
	for(int h=0;h<=levels;h++){
		for(int i=0;i<pow(2,levels-h)-1;i++){
			printf("  ");
		}
		s=pow(2,h-1);
		if(h==levels){
			e=pow(2,levels);
		}
		else{
			e=s*2;
		}
		if(h!=1){
			for(int i=0;i<s;i++){
				if((*arr)[i]==999){
					printf(" /");
				}
				else{
					if(i%2==0){
						printf(" /");
					}
					else{
						printf("\\");
					}
				}
				for(int j=0;j<pow(2,levels-h+1)-1;j++){
					printf("  ");
				}
			}
			printf("\n");
			for(int i=0;i<pow(2,levels-h)-1;i++){
				printf("  ");
			}
		}
		for(int i=s;i<e;i++){
			if((*arr)[i]==999){
				printf(" -");
			}
			else{
				printf("%2d",(*arr)[i]);
			}
			for(int j=0;j<pow(2,levels-h+1)-1;j++){
				printf("  ");
			}
		}
		printf("\n");
	}
}

void protocal(){
	int levels=0;
	printf("tree height? :");
	scanf("%d",&levels);
	int *root=MakeRoot(levels);
	insertTree(&root);
	printroot(&root,levels);
	//printroot2(&root,levels);
	searchroot(&root,levels);
}

int main(int argc,char*argv[]){
	protocal();
	return 0;
}
