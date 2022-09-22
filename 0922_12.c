#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node*next;
	struct node*prev;
}node;

node* Allocnode(int data){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=data;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void menu(){
	printf("insert data: EXIT:0\n");
}

void addnode(node**head,int data){
	if(*head==NULL){
		*head=Allocnode(data);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->data > data){
				if(curr->prev==NULL){
					node*newnode=Allocnode(data);
					newnode->next=*head;
					(*head)->prev=newnode;
					*head=newnode;
					break;
				}
				node*newnode=Allocnode(data);
				newnode->next=curr;
				newnode->prev=curr->prev;
				curr->prev->next=newnode;
				curr->prev=newnode;
				break;
			}
			else if(curr->next==NULL){
				node*newnode=Allocnode(data);
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
		printf("%d ",curr->data);
	}
	printf("\n");
}

void protocal(node**head){
	int input;
	scanf("%d",&input);
	if(input==0){
		printlist(head);
		printf("[EXIT]\n");
		exit(1);
	}
	else{
		addnode(head,input);
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
