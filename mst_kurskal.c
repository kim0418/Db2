#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

#define max 100
#define INF INT_MAX

int parent[max];

typedef struct Edge{
	int start;
	int end;
	int weight;
}Edge;

typedef struct Grapytype{
	int n;
	struct Edge edges[2*max];
}Graphtype;

void set_init(int n){
	for(int i=0;i<n;i++){
		parent[i]=-1;
	}
}

int set_find(int curr){
	if(parent[curr]==-1){
		return curr;
	}
	while(parent[curr]!=-1){
		curr=parent[curr];
	}
	return curr;
}

void set_union(int a, int b){
	int root_a=set_find(a);
	int root_b=set_find(b);
	if(root_a != root_b){
		parent[root_a]=root_b;
	}
}

void graph_init(Graphtype*g){
	g->n=0;
	for(int i=0;i<2*max;i++){
		g->edges[i].start=0;
		g->edges[i].end=0;
		g->edges[i].weight=INF;
	}
}

void insert_edge(Graphtype*g,int start,int end, int weight){
	g->edges[g->n].start=start;
	g->edges[g->n].end=end;
	g->edges[g->n].weight=weight;
	g->n++;
}

int compare(const void*a,const void*b){
	struct Edge*x=(struct Edge*)a;
	struct Edge*y=(struct Edge*)b;
	return (x->weight-y->weight);
}

void kruskal(Graphtype*g){
	int edge_accepted=0;
	int uset,vset;
	struct Edge e;
	
	set_init(g->n);
	qsort(g->edges,g->n,sizeof(struct Edge),compare);
	
	printf("kruskal 신장 트리 알고리즘\n");
	int i=0;
	while(i<(g->n-1)){
		e=g->edges[i];
		uset=set_find(e.start);
		vset=set_find(e.end);
		if(uset!=vset){
			printf("간선 (%d,%d)%d 선택\n",e.start,e.end,e.weight);
			edge_accepted++;
			set_union(uset,vset);
		}
		i++;
	}
}

int main(int argc, char*argv[]){
	Graphtype*g=(Graphtype*)malloc(sizeof(Graphtype));
	graph_init(g);
	
	insert_edge(g,0,1,29);
	insert_edge(g,1,2,16);
	insert_edge(g,2,3,12);
	insert_edge(g,3,4,22);
	insert_edge(g,4,5,27);
	insert_edge(g,5,0,10);
	insert_edge(g,6,1,15);
	insert_edge(g,6,3,18);
	insert_edge(g,6,4,25);
	
	kruskal(g);
	free(g);
	return 0;
}
