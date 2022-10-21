#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	char*data_eng;//영어단어를 입력받기 위함
	char*data_kor;//영어단어의 뜻을 입력받기 위함
	struct node*left;
	struct node*right;
}node;

void menu(){
	printf("1. view_all_dictionary\n");//사전의 내용을 중위출력으로 확인
	printf("2. serch_word\n");//단어검색기능 영한,한영모두 지원
	printf("3. insert_word\n");//새로운 단어 추가
	printf("4. delete_word\n");//기존의 단어 삭제
	printf("5. find_leafroot\n");//lesfnode찾기
	printf("6. system_out\n");
}

node*Allocnode(char*eng,char*kor){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data_eng=(char*)malloc(strlen(eng)*sizeof(char));//입력받는 크기를 모릅으로 동적할당으로 지정
	strcpy(newnode->data_eng,eng);//문자열임으로 strcpy로 복사하여 넣어줌
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
	else if(*root!=NULL){//최초로 입력받은 영어단어를 기준으로 앞선단어면 왼쪽노드, 후위단어면 오른쪽 노드로 넣어준다. 크기별로 넣은 BST이다.
		if(strcmp((*root)->data_eng,eng_data)>0){
			insert_root(&(*root)->left,eng_data,kor_data);
		}
		else{
			insert_root(&(*root)->right,eng_data,kor_data);
		}
	}
}

void print_root(node**root){//abc의 단어순서로 출력을 하기 위해서 중위 출력을 사용한다.
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
		if(strcmp((*root)->data_eng,data)==0){//strcmp는 찾으려는 단어와 같으면 0을 반환하고 작으면 -1, 크다면 1을 반환한다.
			printf("%s : %s\n",(*root)->data_eng,(*root)->data_kor);
		}
		else if(strcmp((*root)->data_eng,data)>0){//찾으려는 단어보다 노드의 단어순서가 후위이다.
			eng_searching(&(*root)->left,data);
		}
		else if(strcmp((*root)->data_eng,data)<0){
			eng_searching(&(*root)->right,data);
		}
	}
}

void kor_searching(node**root,char*data){
	if((*root)==NULL) return;
	else{//영단어의 뜻을 찾을수있지만 찾으려는 의미를 가진 단어가 어디에 위치하는지 모름으로 전 노드를 검색해본다.
		if(strstr(((*root)->data_kor),data)!=NULL){//strstr(A,B)은 A의 문자열안에 B의 문자열이 포함되어 있으면NULL이아닌 A의 값을 반환하고, 포함되지않으면 NULL을 반환한다.
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
	//영한검색과 한영검색 모두 지원
	printf("-serch english -press 1\n");
	printf("-serch korea -press 2\n");
	scanf("%d",&press);
	//찾으려는 검색엔진선택
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
	FILE*fp=fopen("dictionary.txt","a");//기존파일에 새로운 단어를 추가할것임으로 W가 아닌 append타입으로 파일을 연다.
	char*arr=(char*)malloc(70*sizeof(char));
	char*kordata=(char*)malloc(50*sizeof(char));
	printf("insert_word(english:kor_mean) : ");//영단어 파일이 영어단어:한글뜻으로 구성되어있다.
	scanf("%s",arr);
	//fgets(arr);
	fprintf(fp,"%s\n",arr);//기존의 파일과 같은 형식으로 받아주었음으로 그대로 fprintf를 하여 TXT파일에 입력한다.
	char*engdata=strtok_r(arr,":",&kordata);//strtok_r(A,C,B)은 A의 문자열을 C문자열에서 잘라주고 자르고 남은 뒷부분을 B에 넣어주는 연산을 한다. 
	insert_root(root,engdata,kordata);
	fclose(fp);
}

node*max_value(node*root){//root의 기준에서 왼쪽부분에서 가장 큰 수를 찾는 함수
	node*curr=root;
	while(curr->right!=NULL){//큰값이 오른쪽에 있음으로 오른쪽으로 이동한다.
		curr=curr->right;
	}
	return curr;
}

void target_delete(node**root,char*target){
	if(*root==NULL) printf("삭제대상 없음");
	else if(strcmp((*root)->data_eng,target)>0){//삭제하려는 대상을 특정한다. 기준에서 작으면 왼쪽,크면 오른쪽으로 이동한다.
		target_delete(&(*root)->left,target);
	}
	else if(strcmp((*root)->data_eng,target)<0){
		target_delete(&(*root)->right,target);
	}
	else{//삭제하려는 값을 찾았을경우
		if((*root)->left!=NULL && (*root)->right!=NULL){//자식노드가 둘다 있는경우
			node*temp=max_value((*root)->left);//왼쪽자식중 가장 큰값 찾기
			strcpy((*root)->data_eng,temp->data_eng);//삭제하려는 위치에 값을 복사해주기
			strcpy((*root)->data_kor,temp->data_kor);//삭제하려는 위치에 값을 복사해주기
			target_delete(&(*root)->left,(*root)->data_eng);//자식중 가장큰값을 복사해 주었으니 값을 제거하기 위함
		}
		else{//자식노드가 하나만 있는 경우
			node*temp=*root;
			if((*root)->left==NULL){
				*root=(*root)->right;
			}
			else if((*root)->right==NULL){
				*root=(*root)->left;
			}
			//leafnode일경우 root를 바로 제거해주면 된다.
			free(temp);
		}
	}
}

void delete_word(node**root){
	char*target=(char*)malloc(20*sizeof(char));
	scanf("%s",target);
	target_delete(root,target);
}

void leaf_root(node**root){//leafnode(terminal node)찾기
	if(*root==NULL) return;
	else{
		leaf_root(&(*root)->left);
		leaf_root(&(*root)->right);
		if((*root)->left==NULL && (*root)->right==NULL){//leafnode는 자식이 없는 노드임으로 조건을 만족하는 값을 찾늗다.
			printf("%s : %s\n",(*root)->data_eng,(*root)->data_kor);
		}
	}
}

void read_dic(node**root){//영단어txt파일을 찾아서 정렬하기
	FILE*fp=fopen("dictionary.txt","r");
	char*data=(char*)malloc(70*sizeof(char));
	//char*eng_data=(char*)malloc(20*sizeof(char));
	char*kor_data=(char*)malloc(50*sizeof(char));
	while(fscanf(fp,"%s",data)!=EOF){//파일을 읽어오는데 EOF(End of FILE)즉 파일이 종료되지않는다면 실행된다.
		char*temp=strtok_r(data,":",&kor_data);//strtok_r(A,C,B)은 A의 문자열을 C문자열에서 잘라주고 자르고 남은 뒷부분을 B에 넣어주는 연산을 한다. 
		insert_root(root,temp,kor_data);
	}
	fclose(fp);
}

void protocal(node**root){
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
	read_dic(&s);//한번만 데이터를 가져오면 됨으로 while문안에 넣지 않는다.
	do{
		menu();
		protocal(&s);
		printf("\n");
	}while(1);
	return 0;
}
