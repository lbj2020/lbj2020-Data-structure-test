#include <stdio.h>
#include <stdlib.h>
#include "��ͷ.h"

#define MaxVertexNum 1000
typedef int WeightType;
typedef struct GNode* PtrToGNode;
typedef int Vertex;


struct GNode {
	int Nv;		// ������
	int Ne;		// ����
	WeightType G[MaxVertexNum][MaxVertexNum];

};
typedef PtrToGNode MGraph;  // ���ڽӾ���洢ͼ������

typedef struct ENode* PtrToENode;
struct ENode
{
	Vertex v1, v2;		// �����
	WeightType weight;		// Ȩ��
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum)
{// ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
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
{// ��MGraph �в����
	 //�����
	Graph->G[E->v1][E->v2];
	 //��������ͼ ���в����<v2,v1>
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

	/*** ������������� ***/
	//for (v = 0; v < Graph->Nv; v++) {
	//	scanf("%c", &(Graph->data[v]));
	//}
	//return Graph;
}


int main()
{
	return EXIT_SUCCESS;
}
