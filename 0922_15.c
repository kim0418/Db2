#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char data[3];
	struct node*next;
	struct node*prev;
}node;

node* Allocnode(char* arr){
	node*curr=(node*)malloc(sizeof(node));
	strcpy(curr->data,arr);
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void menu(){
	printf("insert data: EXIT:0\n");
}

void addnode(node**head,char*arr){
	if(*head==NULL){
		*head=Allocnode(arr);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(strcmp(arr,curr->data)<0){
				if(curr->prev==NULL){
					node*newnode=Allocnode(arr);
					newnode->next=*head;
					(*head)->prev=newnode;
					*head=newnode;
					break;
				}
				node*newnode=Allocnode(arr);
				newnode->next=curr;
				newnode->prev=curr->prev;
				curr->prev->next=newnode;
				curr->prev=newnode;
				break;
			}
			else if(curr->next==NULL){
				node*newnode=Allocnode(arr);
				curr->next=newnode;
				curr->next->prev=curr;
				break;
			}
		}
	}
}
void printlist(node**head){
	printf("[PQ] ");
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		printf("%s ",curr->data);
	}
	printf("\n");
}

void protocal(node**head){
	char data[3];
	scanf("%s",data);
	if(strcmp(data,"0")==0){
		printlist(head);
		printf("[EXIT]\n");
		exit(1);
	}
	else{
		addnode(head,data);
	}
}

int main(int argc,char*argv[]){

	node*s=NULL;
	do{
		menu();
		protocal(&s);
		printlist(&s);
		printf("\n");
	}while(1);

	return 0;
}
