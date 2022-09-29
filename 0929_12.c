#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char*data;
	struct node*next;
	struct node*prev;
}node;

node* Allocnode(char* arr){
	node*curr=(node*)malloc(sizeof(node));
	curr->data=(char*)malloc(strlen(arr)*sizeof(char));
	strcpy(curr->data,arr);
	curr->next=NULL;
	curr->prev=NULL;
	return curr;
}

void delete(node**head,char*arr){
	node*remove=NULL;
	for(node*curr=*head;curr!=NULL;curr=curr->next){
		if(strcmp(arr,curr->data)==0){
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
		remove->prev->next=NULL;
		free(remove);
	}
	else{
		remove->next->prev=remove->prev;
		remove->prev->next=remove->next;
		if(remove==NULL);
		else{free(remove);}
	}
}

void addnode(node**head,char*arr){
	if(*head==NULL){
		*head=Allocnode(arr);
		return;
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(strcmp(arr,curr->data)==0){
				delete(head,arr);
				break;
			}
			else{
				if(curr->next==NULL){
					node*newnode=Allocnode(arr);
					curr->next=newnode;
					curr->next->prev=curr;
					break;
				}
			}
		}
	}
}

void printlist(node**head){
	if(*head==NULL){
		printf("EMPTY\n");
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			printf("%s ",curr->data);
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
		printf("%s ",reve->data);
	}
	}
	printf("\n");
}

void protocal(node**head){
	char *data=(char*)malloc(10*sizeof(char));
	scanf("%s",data);
	if(strcmp(data,"0")==0){
		printf("[ Q]");printlist(head);
		//printf("[EXIT\n");
		exit(1);
	}
	else{
		addnode(head,data);
	}
}

int main(int argc,char*argv[]){
	node*s=NULL;
	do{
		protocal(&s);
		printf("[ Q]");printlist(&s);
		//printf("[PQ]");printreverse(&s);
		printf("\n");
	}while(1);
	return 0;
}
