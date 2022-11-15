#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define max 100
#define INF 99999

#define TRUE 1
#define FALSE 0

typedef struct Graphtype{
    int n;
    int weight[max][max];
}Graphtype;

int GetMinDistIdx(Graphtype*g,int visited[max],int distance[max]){
	int foundIdx=-1;
	int minvalue=INT_MAX;
	for(int i=0;i<g->n;i++){
		if(visited[i]==TRUE) continue;
		if(minvalue>distance[i]){
			minvalue=distance[i];
			foundIdx=i;
		}
	}
	return foundIdx;
}

void updateDistance(Graphtype*g,int u,int distance[max]){
	for(int i=0;i<g->n;i++){
		if(distance[i]>distance[u]+g->weight[u][i]){
			distance[i]=distance[u]+g->weight[u][i];
		}
	}
}

void short_path(Graphtype*g,int s){
	int distance[max]={INT_MAX,};
	int visited[max]={FALSE,};
	
	for(int i=0;i<g->n;i++){
		distance[i]=g->weight[s][i];
	}
	for(int i=0;i<g->n;i++){
		int u=GetMinDistIdx(g,visited,distance);
		visited[u]=TRUE;
		printf("Found %d, distancce=%d\n",u,distance[u]);
		updateDistance(g,u,distance);
	}
}

int main(void){
	Graphtype g={7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}}
	};
	short_path(&g,0);
	return 0;
}
