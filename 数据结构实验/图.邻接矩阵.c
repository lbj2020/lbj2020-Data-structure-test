#include <stdio.h>
#include <stdlib.h>
#include "标头.h"

#define MaxVertexNum 1000
typedef int WeightType;
typedef struct GNode* PtrToGNode;
typedef int Vertex;


struct GNode {
	int Nv;		// 顶点数
	int Ne;		// 边数
	WeightType G[MaxVertexNum][MaxVertexNum];

};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储图的类型

typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex v1, v2;		// 有向边
	WeightType weight;		// 权重
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{// 初始化一个有VertexNum个顶点但没有边的图
	Vertex v, w;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (v = 0; v < Graph->Nv; v++)
	{
		for (w = 0; w < Graph->Ne; w++) {
			Graph->G[v][w] = 0;
		}
	}
	return Graph;
}
void InsertEdge(MGraph Graph, Edge E)
{// 向MGraph 中插入边
	 //插入边
	Graph->G[E->v1][E->v2];
	 //若是无向图 还有插入边<v2,v1>
	Graph->G[E->v2][E->v1];
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex v;
	int Nv, i;
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	scanf("%d", &(Graph->Ne));
	if (Graph->Ne != 0) {
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d",
				&E->v1, &E->v2, &E->weight);
			InsertEdge(Graph, E);
		}
	}

	/*** 如果顶点有数据 ***/
	//for (v = 0; v < Graph->Nv; v++) {
	//	scanf("%c", &(Graph->data[v]));
	//}
	//return Graph;
}


int main()
{
	return EXIT_SUCCESS;
}
