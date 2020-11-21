//#include <stdio.h>
//#define MAXSIZE 100
//
//typedef struct Data
//{
//	int i;
//	int j;
//	int e;
//}Triple;
//
//typedef struct 
//{
//	Triple data[MAXSIZE+1];
//	int mu, nu, tu;
//}TSMatrix;
//
//// +-------------------------------------+
//// |           ��������                   |
//// +-------------------------------------+
//void createMatrix(TSMatrix* m);
//void printMatrix(TSMatrix* m);
//void transPoseMatrix(TSMatrix* m, TSMatrix* t);
//
//int main()
//{
//	TSMatrix t,m;
//	createMatrix(&m);
//	printMatrix(&m);
//	transPoseMatrix(&m, &t);
//	printMatrix(&t);
//
//	return 0;
//
//}
//
//// +-------------------------------------+
//// |           ��������                   |
//// +-------------------------------------+
//void createMatrix(TSMatrix* m)
//{
//	// ��ʼ������ data[0]δ��
//	int i, j, e;
//	m->mu = m->nu =0;
//	m->tu = 1;
//	printf("�������Ԫ�ص��к� �к� ֵ�������ַ��������룩\n");
//	while (scanf("%d%d%d",&i,&j,&e)==3)
//	{
//		m->data[m->tu].i = i;
//		m->data[m->tu].j = j;
//		m->data[m->tu++].e = e;
//		if(i>m->mu)
//			m->mu=i;
//		if(j>m->nu)
//			m->nu=j;
//	}
//
//}
//
//void printMatrix(TSMatrix* m)
//{//�������
//	int count =1;
//	while (count<m->tu)
//	{
//		printf("----------\n");
//		printf("|%d|%d|ֵ:%d|\t", m->data[count].i, m->data[count].j, m->data[count].e);
//		printf("\n");
//		count++;
//	}
//	printf("\n");
//}
//
//void transPoseMatrix(TSMatrix* m, TSMatrix* t )
//{// ת�þ���
//	t->mu = m->nu;
//	t->nu = m->mu;
//	t->tu = m->tu;
//
//	int num[MAXSIZE];
//	int cpot[MAXSIZE];
//
//	cpot[1] = 1;
//	if (t->nu)
//	{
//		// ��ÿһ�еĺ�����Ԫ�ĸ���
//		for (int i = 1; i <= m->nu; i++) num[i] = 0;
//		for (int j = 1; j <m->tu; j++) num[m->data[j].j]++;
//		
//		// ÿ��Ԫ�صĿ�ʼλ��
//		for (int i = 2; i <= m->nu; i++) cpot[i] = cpot[i - 1] + num[i - 1];
//		
//		//ת��
//		for (int i = 1; i < m->tu; i++) 
//		{
//			int col = m->data[i].j;
//			int q = cpot[col];
//			t->data[q].i = m->data[i].j;
//			t->data[q].j = m->data[i].i;
//			t->data[q].e = m->data[i].e;
//			cpot[col]++;
//		}
//
//	}
//}