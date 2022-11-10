#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define TRUE 1
#define FLASE 0

#define max 10
#define INF INT_MAX

int visited[max];
int selected[max];
int distance[max];

typedef struct Graphtype{
	int vertex;
	int adj[max][max];
}Graphtype;

void init(Graphtype*g){
	g->vertex=0;
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			if(i==j){
				g->adj[i][j]=0;
			}
			else{
				g->adj[i][j]=INF;
			}
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

void insert_edge(Graphtype*g,int s,int e,int w){
	if(s > g->vertex || e >= g->vertex){
		fprintf(stderr,"error");
		return ;
	}
	g->adj[s][e]=w;
	g->adj[e][s]=w;
}

void c_edge(Graphtype*g,int s,int e,int w){
	if(s > g->vertex || e >= g->vertex){
		fprintf(stderr,"error");
		return ;
	}
	g->adj[s][e]=w;
	g->adj[e][s]=w;
}

void print_adj(Graphtype*g){
	for(int i=0;i<(g->vertex);i++){
		for(int j=0;j<g->vertex;j++){
			printf("%2d",g->adj[i][j]);
		}
		printf("\n");
	}
}

int get_min_vertex(int n){
	int v,i;
	for(i=0;i<n;i++){
		if(!selected[i]){
			v=i;
			break;
		}
	}
	for(i=0;i<n;i++){
		if(!selected[i] && distance[i]<distance[v]){
			v=i;
		}
	}
	return v;
}

static int a_prim;

int prim(Graphtype*g,int s){
	for(int u=0;u<g->vertex;u++){
		distance[u]=INF;
	}
	distance[s]=0;
	for(int i=0;i<g->vertex;i++){
		int u=get_min_vertex(g->vertex);
		selected[u]=TRUE;
		if(distance[u]==INF){
			return 0;
		}
		printf("%d-> ",u);
		a_prim+=distance[u];
		for(int v=0;v<g->vertex;v++){
			if(g->adj[u][v]!=INF){
				if(!selected[v] && g->adj[u][v]<distance[v]){
					distance[v]=g->adj[u][v];
				}
			}
		}
	}
}

void menu(){
	printf("1.추가\n");
	printf("2.변경\n");
	printf("3.비교\n");
	printf("4.종료\n");
}

void add_edge(Graphtype*g){
	
	int num1,num2,num3;
	while(1){
		scanf("%d %d %d",&num1,&num2,&num3);
		if(num1<0 || num2<0 || num3<0){
			break;
		}
		insert_edge(g,num1,num2,num3);
	}
	printf("엣지 입력 완료\n");
}

void change_edge(Graphtype*g){
	int num1,num2,num3;
	while(1){
		scanf("%d %d %d",&num1,&num2,&num3);
		if(num1<0 || num2<0 || num3<0){
			break;
		}
		c_edge(g,num1,num2,num3);
	}
}

static int a_dfs;

void dfs(Graphtype*g,int s){
	visited[s]=TRUE;
	printf("%d ->",s);
	for(int i=0;i<g->vertex;i++){
		if(g->adj[s][i] && !visited[i] && g->adj[s][i]!=INF){
			//printf("%d ->",s);
			a_dfs+=g->adj[s][i];
			dfs(g,i);
		}
	}
}

void path(Graphtype*g,int s){
	dfs(g,s);
	printf("=%d\n",a_dfs);
	prim(g,s);
	printf("=%d\n",a_prim);
	a_dfs=0;
	a_prim=0;
	for(int i=0;i<max;i++){
		visited[i]=0;
		selected[i]=0;
		distance[i]=INF;
	}
}

void find_path(Graphtype*g){
	int num1;
	scanf("%d",&num1);
	path(g,num1);
}

void graph(Graphtype*g){
	int num=0;
	scanf(" %d",&num);
	switch(num){
		case 1:
			add_edge(g);
			break;
		case 2:
			change_edge(g);
			break;
		case 3:
			find_path(g);
			break;
		case 4:
			printf("BYE\n");
			//print_adj(g);
			exit(1);
		
	}
}

void protocal(){
	Graphtype*g=(Graphtype*)malloc(sizeof(Graphtype));
	init(g);
	for(int i=0;i<10;i++){
		insert_vertex(g,i);
	}
	insert_edge(g,0,1,1);
	insert_edge(g,0,4,1);
	insert_edge(g,0,5,1);
	insert_edge(g,1,2,5);
	insert_edge(g,2,3,6);
	insert_edge(g,3,4,3);
	insert_edge(g,2,5,4);
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
