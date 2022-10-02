#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int system_count;

typedef struct node{
	char data;
	struct node*next;
	struct node*prev;
}node;

node*Allocnode(char arr){
	node*newnode=(node*)malloc(sizeof(node));
	newnode->data=arr;
	newnode->next=NULL;
	newnode->prev=NULL;
}

void printlist(node**head){
	if(*head==NULL){
		printf("[EMPTY]\n");
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			printf("%c",curr->data);
		}
	}
}

void addnode(node**head,char a){
	if(*head==NULL){
		*head=Allocnode(a);
	}
	else{
		for(node*curr=*head;curr!=NULL;curr=curr->next){
			if(curr->next==NULL){
				node*newnode=Allocnode(a);
				curr->next=newnode;
				curr->next->prev=curr;
				break;
			}
		}
	}
}

void system_left(node**head){
	if(system_count>0){
		system_count--;
	}
}

void system_right(node**head){
	int i=0;
	node*select=NULL;
	for(node*curr=*head;i<system_count;curr=curr->next){
		i++;
		if(i==system_count){
			select=curr;
		}
	}
	if(select->next!=NULL){
		system_count++;
	}
}

void system_plus(node**head,char x){
	int i=0;
	node*select=NULL;
	if(system_count==0){
		system_count++;
		for(node*curr=*head;i<system_count;curr=curr->next){
			i++;
			if(i==system_count){
				select=curr;
			}
		}
		if(select->next==NULL){
			if(select->prev==NULL){
				node*newnode=Allocnode(x);
				newnode->next=*head;
				(*head)->prev=newnode;
				*head=newnode;
				}
			else{
				addnode(head,x);
			}	
		}	
		else if(select->prev==NULL){
			node*newnode=Allocnode(x);
			newnode->next=*head;
			(*head)->prev=newnode;
			*head=newnode;
		}
		else{
			node*newnode=Allocnode(x);
			select->next->prev=newnode;
			newnode->next=select->next;
			select->next=newnode;
			newnode->prev=select;
		}
	}
	else{
		for(node*curr=*head;i<system_count;curr=curr->next){
			i++;
			if(i==system_count){
				select=curr;
			}
		}
		if(select->next==NULL){
			addnode(head,x);
		}
		else if(select->prev==NULL){
			node*newnode=Allocnode(x);
			newnode->next=*head;
			(*head)->prev=newnode;
			*head=newnode;
		}
		else{
			node*newnode=Allocnode(x);
			select->next->prev=newnode;
			newnode->next=select->next;
			select->next=newnode;
			newnode->prev=select;
		}
		system_count++;
	}
}

void system_delete(node**head){
	int i=0;
	if(system_count==0){
		return;
	}
	if(system_count>0){
		node*remove=NULL;
		for(node*curr=*head;i<system_count;curr=curr->next){
			i++;
			if(i==system_count){
				remove=curr;
			}
		}
		if(remove->prev==NULL){
			if(remove->next==NULL){
				*head=NULL;
			}
			else{
				if(system_count!=0){
					remove=(*head)->next;
					free(*head);
					*head=remove;
					(*head)->prev=NULL;
				}
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
		system_count--;
	}
}

void system_protocal(node**head,int count){
	char instruction;
	char x;
	for(int i=0;i<count;i++){
		getchar();
		scanf("%c",&instruction);
		switch(instruction){
			case 'L':
				system_left(head);
				break;
			case 'D':
				system_right(head);
				break;
			case 'P':
				scanf(" %c",&x);
				system_plus(head,x);
				break;
			case 'B':
				system_delete(head);
				break;
			default:
				printf("%c instruction is not exist\n",instruction);
				break;
		}
	}
}

void protocal(node**head){
	int count;
	char*arr=(char*)malloc(10*sizeof(char));
	scanf("%s",arr);
	system_count=strlen(arr);
	for(int i=0;i<strlen(arr);i++){
		addnode(head,arr[i]);
	}
	scanf("%d",&count);
	system_protocal(head,count);
}

int main(int argc, char*argv[]){
	node*s=NULL;
	protocal(&s);
	printlist(&s);
	printf("\n");
	return 0;
}
