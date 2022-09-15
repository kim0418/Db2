#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node*next;
	struct node*prev;
}node;

void menu(){
	printf("1. Add\n");
	printf("2. Delete\n");
	printf("3. Exit\n");
}

node* addnode(int data){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=data;
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void printlist(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			printf("%d ",curr->data);
		}
	}
	printf("\n");
}

void printreverse(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		node*rev;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->next==NULL){
			rev=curr;
			break;
		}
	}
	for(node*reve=rev;reve!=NULL;reve=reve->prev){
		printf("%d ",reve->data);
	}
	}
	printf("\n");
}

void Add(node**head,int data){
	if((*head)==NULL){
		*head=addnode(data);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				curr->next=addnode(data);
				curr->next->prev=curr;
				break;
			}
		}
	}
}

void Delete(node**head, int target){
	if(*head==NULL) return;
	node*remove=NULL;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(curr->data==target){
			remove=curr;
			break;
		}
	}
	if(remove->prev==NULL){
		if(remove->next==NULL){
			*head=NULL;	
		}
		else{
			remove=(*head)->next;
			free(*head);
			*head=remove;
			remove->prev=NULL;
		}
	}
	else if(remove->next==NULL){
		remove->prev->next=remove->prev;
		free(remove);
	}
	else{
		remove->next->prev=remove->prev;
		remove->prev->next=remove->next;
		if(remove==NULL);
		else{free(remove);}
	}
}

void protocal(node**head){
	int num=0;
	int input=0;
	scanf("%d",&num);
	switch(num){
		case 1:
			scanf("%d",&input);
			Add(head,input);
			printf("[List] "); printlist(head);
			printf("[Reversed] "); printreverse(head);
			break;
		case 2:
			if(*head!=NULL){
				scanf("%d",&input);
				Delete(head,input);
			}
			printf("[List] "); printlist(head);
			printf("[Reversed] "); printreverse(head);
			break;
		case 3:
			printf("EXIT\n");
			exit(1);
		default:
			printf("system error\n");
			exit(1);
	}
}

int main(int argc, char*argv[]){
	
	node*s=NULL;
	
	do{
		menu();
		protocal(&s);
		printf("\n");
	}while(1);
	
	return 0;
}
