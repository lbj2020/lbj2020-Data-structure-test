//#include <stdio.h>
//#include <stdlib.h>
//#define ERROR -1
//
//typedef struct DataList* DataNode;
//struct DataList {
//	int data;
//	DataNode next;
//};
//
//DataNode creatList(int number, int toBase);
//void print(const DataNode l,int number);
//int main()
//{
//	int number;
//	printf("����һ������");
//	if (scanf("%d", &number) != 1) 
//	{
//		printf("Not a number!");
//		return ERROR;
//	}
//	int toBase;
//	printf("������Ҫת���Ľ��ƣ�");
//	if (scanf("%d", &toBase) != 1)
//	{
//		printf("Not a number!");
//		return ERROR;
//	}
//
//	DataNode re = creatList(number, toBase);
//	printf("ת�������");
//	print(re,number);
//
//	return 0;
//}
//
//DataNode creatList(int number,int toBase)
//{// ������ջ
//	DataNode re = (DataNode)malloc(sizeof(struct DataList));		// ����ͷ���
//	if(re)
//		re->next = NULL;
//	DataNode p;
//	while (number)
//	{
//		p = (DataNode)malloc(sizeof(struct DataList));
//		if (number < 0)
//			number = -number;
//		if (p)
//		{
//			p->data = (number % toBase);
//			number /= toBase;
//		}
//		if (p && re)
//		{
//			p->next = re->next;
//			re->next = p;
//		}
//	}
//
//	return re;
//
//}
//
//void print(const DataNode l,int number)
//{// ����������Ԫ��
//
//	DataNode p = l->next;
//	while (p)
//	{
//		if(p)
//			if (number <0)
//				putchar('-');
//		if (p->data<=9)
//		{
//			printf("%d", p->data);
//		}
//		else
//		{
//			putchar(p->data-10+'a');
//		}
//			
//		p = p->next;
//	}
//}