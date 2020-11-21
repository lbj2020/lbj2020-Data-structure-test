//#include <stdio.h>
//#include <stdlib.h>
//#pragma once
//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFEASIBLE -1
//#define OVERFLOW -2
//typedef int status;
//
//typedef struct BinaryTree
//{
//	int data;
//	struct BinaryTree* lchild;
//	struct BinaryTree* rchild;
//}BinaryTree;
//
//
//status creatBinaryTree(BinaryTree** t)
//{
//	int a;
//	if (scanf("%d",&a)!= 1)
//	{
//		*t = NULL;
//		getchar();
//	}
//	else
//	{
//		if (!((*t) = (BinaryTree*)malloc(sizeof(BinaryTree))))
//		{
//			exit(OVERFLOW);
//		}
//		else
//		{
//			(*t)->data = a;
//			printf("请输入%d的左结点：" ,a);
//			creatBinaryTree(&((*t)->lchild));     // 构造左子树
//			printf("请输入%d的右结点：",a);
//			creatBinaryTree(&((*t)->rchild));     // 构造右子树
//
//		}
//	}
//	return OK;
//}
//
//// 先序遍历
//status preOrderTraverse(BinaryTree*t) 
//{
//	if (t)
//	{
//		printf("%d ", t->data);
//		preOrderTraverse(t->lchild);
//		preOrderTraverse(t->rchild);
//	}
//
//}
//// 中序遍历
//status inOrderTraverse(BinaryTree* t)
//{
//	if (t)
//	{
//		inOrderTraverse(t->lchild);
//		printf("%d ", t->data);
//		inOrderTraverse(t->rchild);
//	}
//
//}
//// 后序遍历
//status postOrderTraverse(BinaryTree* t)
//{
//	if (t)  
//	{
//		postOrderTraverse(t->lchild);
//		postOrderTraverse(t->rchild);
//		printf("%d ", t->data);
//	}
//
//}
//
//int main()
//{
//
//	BinaryTree* ptree;
//	printf("请输入第一个结点的值 任意字母表示没有叶结点：");
//	creatBinaryTree(&ptree);
//	printf("先序遍历：");
//	preOrderTraverse(ptree);
//	printf("中序遍历：");
//	inOrderTraverse(ptree);
//	printf("后序遍历：");
//	postOrderTraverse(ptree);
//
//	return EXIT_SUCCESS;
//
//}
////int count(BinaryTree* top)
////{
////	if (top == NULL)
////	{
////		return 0;
////	}
////	else if ((top->lchild == NULL) && (top->rchild == NULL))
////	{
////		​return 1;
////	}
////	else
////	{
////		return count(top->lchild) + Count(top->rchild);
////	}
////}
////
////int depth(BinaryTree* node)
////{
////	if (node == NULL)
////	{
////		return 0;
////	}
////	return max(maxDepth(node.lchild) + 1, depth(node.rchild) + 1);
////}