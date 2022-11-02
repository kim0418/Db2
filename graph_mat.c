#include<stdio.h>
#include<stdlib.h>

#define max_vertices 50

//using namespace std;

typedef struct GraphType{
    int n;
    int adj[max_vertices][max_vertices];
}GraphType;

void init(GraphType*s){
    s->n=0;
    for(int r=0;r<max_vertices;r++){
	for(int c=0;c<max_vertices;c++){
	    s->adj[r][c]=0;
	}
    }
}

void insert_vertex(GraphType*s,int v){
    if(((s->n)+1)>max_vertices){
	fprintf(stderr,"그래프: 정점의 개수초과");
	return;
    }
    s->n++;
}

void insert_edge(GraphType*s,int start,int end){
    if(start >= s->n || end >= s->n){
	fprintf(stderr,"그래프: 정점 번호 오류");
	return ;
    }
    s->adj[start][end]=1;
    s->adj[end][start]=1;
}

void print_adj(GraphType*s){
    for(int i=0;i<s->n;i++){
	for(int j=0;j<s->n;j++){
	    printf("%2d",s->adj[i][j]);
	}
	printf("\n");
    }
}

void main(int argc,char*argv[]){

    GraphType*s=(GraphType*)malloc(sizeof(GraphType));
    init(s);

    for(int i=0;i<4;i++){
	insert_vertex(s,i);
    }

    insert_edge(s,0,1);
    insert_edge(s,0,2);
    insert_edge(s,0,3);
    insert_edge(s,1,2);
    insert_edge(s,2,3);
    print_adj(s);

    free(s);
}



