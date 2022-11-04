#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FLASE 0
#define max 10

int visited[max];

typedef struct Graphtype{
	int vertex;
	int adj[max][max];
}Graphtype;

void init(Graphtype*g){
	g->vertex=0;
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			g->adj[i][j]=0;
		}
	}
	
}

void insert_vertex(Graphtype*g,int v){
	if((g->vertex)+1>max){
		fprintf(stderr,"error");
		return;
	}
	g->vertex++;
}

void insert_edge(Graphtype*g,int s,int e){
	if(s > g->vertex || e >= g->vertex){
		fprintf(stderr,"error");
		return ;
	}
	g->adj[s][e]=1;
	g->adj[e][s]=1;
}

void delete_edge(Graphtype*g,int s,int e){
	if(s > g->vertex || e >= g->vertex){
		fprintf(stderr,"error");
		return ;
	}
	g->adj[s][e]=0;
	g->adj[e][s]=0;
}

void print_adj(Graphtype*g){
	for(int i=0;i<(g->vertex);i++){
		for(int j=0;j<g->vertex;j++){
			printf("%2d",g->adj[i][j]);
		}
		printf("\n");
	}
}

void menu(){
	printf("1.엣지추가\n");
	printf("2.엣지삭제\n");
	printf("3.PATH찾기\n");
	printf("4.종료\n");
}

void add_edge(Graphtype*g){
	
	int num1,num2;
	while(1){
		scanf("%d %d",&num1,&num2);
		if(num1<0 || num2<0){
			break;
		}
		insert_edge(g,num1,num2);
	}
	printf("엣지 입력 완료\n");
}

void del_edge(Graphtype*g){
	int num1,num2;
	while(1){
		scanf("%d %d",&num1,&num2);
		if(num1<0 || num2<0){
			break;
		}
		delete_edge(g,num1,num2);
		printf("엣지 삭제 완료\n");
	}
}

static int a;

void dfs(Graphtype*g,int s,int e){
	visited[s]=TRUE;
	printf("%d ->",s);
	for(int i=0;i<g->vertex;i++){
		if(g->adj[s][i] && !visited[i] && a!=1){
			//printf("%d ->",s);
			if(i==e){
				printf("%d ->",e);
				a=1;
				break;
			}
			dfs(g,i,e);
		}
	}
}

void path(Graphtype*g,int s,int e){
	a=0;
	dfs(g,s,e);
	if(a==1) printf("발견\n");
	else printf("미발견\n");
	for(int i=0;i<max;i++){
		visited[i]=0;
	}
}

void find_path(Graphtype*g){
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	path(g,num1,num2);
}

void graph(Graphtype*g){
	int num=0;
	scanf(" %d",&num);
	switch(num){
		case 1:
			add_edge(g);
			break;
		case 2:
			del_edge(g);
			break;
		case 3:
			find_path(g);
			break;
		case 4:
			printf("BYE\n");
			print_adj(g);
			exit(1);
		
	}
}

void protocal(){
	Graphtype*g=(Graphtype*)malloc(sizeof(Graphtype));
	init(g);
	for(int i=0;i<10;i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,3);
	insert_edge(g,1,2);
	insert_edge(g,1,3);
	insert_edge(g,2,3);
	insert_edge(g,3,6);
	insert_edge(g,3,8);
	insert_edge(g,6,7);
	insert_edge(g,8,9);
	insert_edge(g,4,5);
	//print_adj(g);
	
	while(1){
		menu();
		graph(g);
		printf("\n");
	}
}

int main(int argc,char*argv[]){
	protocal();
	return 0;
}
