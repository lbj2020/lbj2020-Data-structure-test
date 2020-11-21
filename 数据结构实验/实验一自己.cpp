//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct PolyNode* Poly;
//struct PolyNode
//{// 多项式的每一项
//    int coef;   // 系数
//    int expon;  // 指数
//    Poly next;
//};
//
//
//void attach(int co, int ex, Poly* rear)
//{// 在表的最后插入一个结点
//
//    Poly p;
//    p = (Poly)malloc(sizeof(struct PolyNode));
//    p->coef = co;
//    p->expon = ex;
//    p->next = NULL;
//
//    (*rear)->next = p;
//    (*rear) = p;
//}
//int compare(int e1, int e2)
//{//比较两项的指数大小
//
//    if (e1 == e2) return 0;
//    else if (e1 > e2) return 1;
//    return -1;
//}
//
//Poly addPoly(Poly p1, Poly p2)
//{// 两个多项式相加
//    int sum;
//    p1 = p1->next;
//    p2 = p2->next;
//    Poly re = (Poly)malloc(sizeof(struct PolyNode));
//    Poly rear = re;
//    while (p1 && p2)
//    {
//        switch (compare(p1->expon, p2->expon))
//        {
//        case 1:
//            attach(p1->coef, p1->expon, &rear);
//            p1 = p1->next;
//            break;
//        case -1:
//            attach(p2->coef, p2->expon, &rear);
//            p2 = p2->next;
//            break;
//        case 0:
//            sum = p1->coef + p2->coef;
//            if (sum) //sum = 0则同类项合并时有抵消
//                attach(sum, p1->expon, &rear);
//            p1 = p1->next;
//            p2 = p2->next;
//            break;
//        }
//    }
//    while (p1)
//    {
//        attach(p1->coef, p1->expon, &rear);
//        p1 = p1->next;
//    }
//
//    while (p2)
//    {
//        attach(p2->coef, p2->expon, &rear);
//        p2 = p2->next;
//    }
//    return re;
//}
//
//Poly readPoly() 
//{// 读入多项式
//
//    int number = 0;
//    int co;
//    int ex;
//    printf("多项式项数：");
//    scanf("%d", &number);
//    Poly p = (Poly)malloc(sizeof(struct PolyNode));     // 带头结点的链表
//    p->next = NULL;
//    Poly rear = p;
//    while (number--)
//    {
//        scanf("%d %d", &co, &ex);
//        attach(co, ex, &rear);
//    }
//    return p;
//}
//
//void printPoly(Poly q)
//{// 输出多项式
//
//    Poly p = q->next;
//    if (p == NULL)
//    {
//        printf("0 0\n");
//        return;
//    }
//    while (p)
//    {
//        printf("%dX%d ", p->coef, p->expon);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//Poly multPoly(Poly p1, Poly p2)
//{// 乘法
//    if (!p1 || !p2)
//        return NULL;
//
//    int c, e;
//    Poly p = (Poly)malloc(sizeof(struct PolyNode));
//    Poly rear = p;
//    Poly temp1 = p1;
//    Poly temp2 = p2;
//    Poly temp;
//    while (temp2)  //p1的第一项乘p2，得到p
//    {
//        attach(temp1->coef * temp2->coef, temp1->expon + temp2->expon, &rear);
//        temp2 = temp2->next;
//    }
//    temp1 = temp1->next;
//    while (temp1)
//    {
//        temp2 = p2;
//        rear = p;
//        while (temp2)
//        {
//            e = temp1->expon + temp2->expon;
//            c = temp1->coef * temp2->coef;
//            while (rear->next && rear->next->expon > e)
//                rear = rear->next;
//            if (rear->next && rear->next->expon == e)
//            {
//                if (rear->next->coef + c)
//                    rear->next->coef += c;
//                else
//                {
//                    Poly temp = rear->next;
//                    rear->next = temp->next;
//                    free(temp);
//                }
//            }
//            else
//            {
//                temp = (Poly)malloc(sizeof(struct PolyNode));
//                temp->coef = c;
//                temp->expon = e;
//                temp->next = rear->next;
//                rear->next = temp;
//                rear = rear->next;
//            }
//            temp2 = temp2->next;
//        }
//        temp1 = temp1->next;
//    }
//    temp2 = p;
//    p = p->next;
//    free(temp2);
//    return p;
//}
//int main()
//{
//
//    Poly p1 = readPoly();
//    Poly p2 = readPoly();
//    Poly ps = addPoly(p1, p2);
//    printPoly(ps);
//
//    return 0;
//}