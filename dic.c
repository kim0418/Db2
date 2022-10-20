#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char*data_eng;
	char*data_kor;
	struct node*left;
	struct node*right;
}node;

void menu(){
	printf("1. view_all_dictionary\n");
	printf("2. serch_word\n");
	printf("3. insert_word\n");
	printf("4. delete_word\n");
	printf("5. find_leafroot\n");
	printf("6. system_out\n");
}

node*Allocnode(char*eng,char*kor){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data_eng=(char*)malloc(strlen(eng)*sizeof(char));
	strcpy(newnode->data_eng,eng);
	newnode->data_kor=(char*)malloc(strlen(kor)*sizeof(char));
	strcpy(newnode->data_kor,kor);
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void insert_root(node**root,char*eng_data,char*kor_data){
	if(*root==NULL){
		*root=Allocnode(eng_data,kor_data);
	}
	else if(*root!=NULL){
		if(strcmp((*root)->data_eng,eng_data)>0){
			insert_root(&(*root)->left,eng_data,kor_data);
		}
		else{
			insert_root(&(*root)->right,eng_data,kor_data);
		}
	}
}

void print_root(node**root){
	if(*root==NULL) return;
	else{
		print_root(&(*root)->left);
		printf("%s: %s\n",(*root)->data_eng,(*root)->data_kor);
		print_root(&(*root)->right);
	}
}

void eng_searching(node**root,char*data){
	if((*root)==NULL) printf("단어를 찾을 수 없습니다.\n");
	else{
		if(strcmp((*root)->data_eng,data)==0){
			printf("%s : %s\n",(*root)->data_eng,(*root)->data_kor);
		}
		else if(strcmp((*root)->data_eng,data)>0){
			eng_searching(&(*root)->left,data);
		}
		else if(strcmp((*root)->data_eng,data)<0){
			eng_searching(&(*root)->right,data);
		}
	}
}

void kor_searching(node**root,char*data){
	if((*root)==NULL) return;
	else{
		if(strstr(((*root)->data_kor),data)!=NULL){
			printf("%s : %s\n",(*root)->data_eng,(*root)->data_kor);
		}
		else if(strstr((*root)->data_kor,data)==NULL){
			kor_searching(&(*root)->left,data);
			kor_searching(&(*root)->right,data);
		}
		else{
			printf("단어를 찾을 수 없습니다.\n");
		}
	}
}

void search_word(node**root){
	int press;
	char *data=(char*)malloc(50*sizeof(char));
	printf("-serch english -press 1\n");
	printf("-serch korea -press 2\n");
	scanf("%d",&press);
	switch(press){
		case 1:
			scanf("%s",data);
			eng_searching(root,data);
			break;
		case 2:
			scanf("%s",data);
			kor_searching(root,data);
			break;
		default:
			printf("잘못된 입력으로 시스템 종료");
			exit(1);
	}
}

void insert_word(node**root){
	FILE*fp=fopen("dictionary.txt","a");
	char*arr=(char*)malloc(70*sizeof(char));
	char*kordata=(char*)malloc(50*sizeof(char));
	printf("insert_word(english:kor_mean) : ");
	scanf("%s",arr);
	//fgets(arr);
	fprintf(fp,"%s\n",arr);
	char*engdata=strtok_r(arr,":",&kordata);
	insert_root(root,engdata,kordata);
	fclose(fp);
}

void target_delete(node**root,char*target){
	node*parent=NULL;
	node*p;
	p=*root;
	node*delete_target;
	node*target_parent;
	node*child;
	//삭제하려는 대상 찾기
	while(p!=NULL && strcmp(p->data_eng,target)!=0){
		parent=p;
		if(strcmp((*root)->data_eng,target)>0){
			p=p->left;
		}
		if(strcmp((*root)->data_eng,target)<0){
			p=p->right;
		}
	}
	if(p==NULL){
		printf("삭제하려는 대상이 사전에 없습니다.\n");
	}
	//삭제하려는 대상이 leafnode인경우
	if(p->left==NULL && p->right==NULL){
		if(parent!=NULL){
			if(parent->left==p) parent->left=NULL;
			else parent->right=NULL;
		}
		else *root=NULL;//트리의 구성이 root만 있는경우
	}
	//삭제하려는 대상의 자식이 하나인경우
	else if(p->left==NULL ||p->right==NULL){
		if(p->left!=NULL) child=p->left;
		else child= p->right;
		
		if(parent!=NULL){
			if(parent->left==p) parent->left=child;
			else parent->right=child;
		}
		else *root=child;
	}
	//삭제하려는 대상의 자식이 두개인경우 왼쪽자식중 제일 큰값을 가져온다.
	else{
		target_parent=p;
		delete_target=p->left;
		
		while(delete_target->right!=NULL){
			target_parent=delete_target;
			delete_target=delete_target->right;
		}
		
		if(target_parent->left==delete_target){
			target_parent->left=delete_target->left;
		}
		else target_parent->right=delete_target->left;
		
		p->data_eng=delete_target->data_eng;
		p=delete_target;
	}
	free(p);
}

void delete_word(node**root){
	char*target=(char*)malloc(20*sizeof(char));
	scanf("%s",target);
	target_delete(root,target);
}

void leaf_root(node**root){
	if(*root==NULL) return;
	else{
		leaf_root(&(*root)->left);
		leaf_root(&(*root)->right);
		if((*root)->left==NULL && (*root)->right==NULL){
			printf("%s : %s\n",(*root)->data_eng,(*root)->data_kor);
		}
	}
}

void read_dic(node**root){
	FILE*fp=fopen("dictionary.txt","r");
	char*data=(char*)malloc(70*sizeof(char));
	//char*eng_data=(char*)malloc(20*sizeof(char));
	char*kor_data=(char*)malloc(50*sizeof(char));
	while(fscanf(fp,"%s",data)!=EOF){
		char*temp=strtok_r(data,":",&kor_data);
		insert_root(root,temp,kor_data);
	}
	fclose(fp);
}

void protocal(node**root){
	//getchar();
	int num=0;
	scanf("%d",&num);
	switch(num){
		case 1:
			print_root(root);
			break;
		case 2:
			search_word(root);
			break;
		case 3:
			insert_word(root);
			break;
		case 4:
			delete_word(root);
			break;
		case 5:
			leaf_root(root);
			break;
		case 6:
			printf("시스템 종료\n");
			exit(1);
	}
}

int main(int argc, char*argv[]){
	node*s=NULL;
	read_dic(&s);
	do{
		menu();
		protocal(&s);
		printf("\n");
	}while(1);
	return 0;
}
