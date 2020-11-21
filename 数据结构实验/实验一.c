//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct PolyNode *Poly;
//struct PolyNode
//{
//    int coef;
//    int expon;
//    Poly next;
//};
//
//void attach(int co, int ex, Poly *pre)
//{
//    Poly p;
//    p = (Poly)malloc(sizeof(struct PolyNode));
//    p->coef = co;
//    p->expon = ex;
//    p->next = NULL;
//
//    (*pre)->next = p;
//    (*pre) = p;
//}
//
//Poly readPoly()
//{
//    Poly p, rear;
//    int number;
//    int co;
//    int ex;
//    scanf("%d", &number);
//    p = (Poly)malloc(sizeof(struct PolyNode));
//    p->next = NULL;
//    rear = p;
//    while (number--)
//    {
//        scanf("%d %d", &co, &ex);
//        attach(co, ex, &rear); //形成一个链表
//    }
//
//    Poly temp = p;
//    p = p->next;
//    free(temp);
//
//    return p;
//}
//
//int compare(int e1, int e2)
//{
//    if (e1 == e2) return 0;
//    else if (e1 > e2) return 1;
//    return -1;
//}
//
//Poly add(Poly p1, Poly p2)
//{
//    int sum;
//    Poly rear = (Poly)malloc(sizeof(struct PolyNode));
//    Poly front = rear;
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
//    rear->next = NULL;
//    Poly temp = front;
//    front = front->next;
//    free(temp);
//    return front;
//}
//
//Poly mult(Poly p1, Poly p2)
//{
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
//
//void printPoly(Poly p)
//{
//    if (p == NULL)  //输入有零多项式和常数多项式
//    {
//        printf("0 0\n");
//        return;
//    }
//
//    int flag = 0;
//    while (p)
//    {
//        if (!flag)
//            flag = 1;
//        else
//            printf(" ");
//        printf("%d %d", p->coef, p->expon);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//int main()
//{
//    Poly p1 = readPoly();
//    Poly p2 = readPoly();
//    Poly pp = mult(p1, p2);
//    printPoly(pp);
//    Poly ps = add(p1, p2);
//    printPoly(ps);
//    return 0;
//}
