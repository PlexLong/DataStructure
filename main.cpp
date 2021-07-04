#include <cstdio>
//#include "HeadFolder/SqList.h"
//#include "HeadFolder/SeqList.h"
//#include "HeadFolder/LNode.h"
//#include "HeadFolder/LinkList_Tail_Insert.h"
//#include "HeadFolder/LinkList_Head_Insert.h"
//#include "HeadFolder/DNode.h"
//#include "HeadFolder/StaticLinkList.h"
//#include "HeadFolder/stack.h"
#include "HeadFolder/LinkStack.h"

int main() {
    /*SqList L;
    InitList(L);
    ListInsert_Stronger(L,1,2);
    ListInsert_Stronger(L,2,5);
    ListInsert_Stronger(L,3,6);

    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d] : %d \n",i,L.data[i]);
    }
    int e;
    ListDelete(L,3,e);
    printf("%d \n",e);
    for (int i = 0; i < L.length; i++) {
        printf("L.data[%d] : %d \n",i,L.data[i]);
    }*/

    /*SeqList seqList;
    InitList(seqList);
    bool q = SeqInsert(seqList,1,5);
    if (q) printf("true \n");
    else printf("false \n");
    printf("%d",seqList.data[1]);
    free(seqList.data);*/

    /*LinkList L;
    */
    /*InitList(L);
     * */
    /*
    ListInsert(L,1,1);
    ListInsert(L,2,3);
    LNode *q =L->next->next;//q指针 ->第2个结点
//    LNode *w =L->next;
    InsertNextNode(q,4);
    InsertPriorNode(q,2);
    q=L->next->next->next;
//    free(w);
    DeleteNode(q);
    printf("第%d个结点的Data域值为：%d \n",1,GetElem(L,1)->data);
    printf("值为%d的结点 在%d个 \n",4, LocateElem(L,4));
    printf("单链表L 长%d\n", Length(L));

//打印链表
    q=L->next;
    printf("==[ L ]===\n");
    while (q != NULL){
        printf("|  %d  | \n",q->data);
        q=q->next;
    }
    printf("===========\n");
    free(q);*/

    /*LinkList L1;
    //尾插法
    List_TailInsert(L1);
    //打印链表
    PrintLinkList(L1);
    LinkList L2;
    //头插法（逆序）
    List_HeadInsert(L2);
    //打印链表
    PrintLinkList(L2);*/

    /*DLinkList DL;
    *//*
     * 创建结点方法
     * 1.结构体变量的地址赋给指针
     * 2.直接malloc（注意释放指针空间）*//*
    DNode dNode;
    DNode *s=&dNode;
    DNode *t=(DNode *) malloc(sizeof(DNode));
    printf("%d \n",s);//打印s地址
    printf("%d \n",t);//打印t地址
    s->data=2;
    //s->next=NULL;
    //s->prior=NULL;
    t->data=3;
    //t->next=NULL;
    //t->prior=NULL;
    InitDLinkList(DL);

    InsertNextDNode(DL,s);
    InsertNextDNode(s,t);
    //PrintDLinkList(DL);

    DeleteNextDNode(s);
    DeleteNextDNode(DL);
    NextRead(DL);*/

  /*  SNode *s = InitSLL();
    AddNodeSLL(s, 101,1);
    AddNodeSLL(s,102,2);
    AddNodeSLL(s,103,3);
    AddNodeSLL(s,123,4);
    AddNodeSLL(s, 222,5);*/
//    through_1(s);

    /*int x;
    DeleteSSL(s,x,4);
    printf("被删除的数据为：%d \n",x);
    through_1(s);*/

/*------------------栈----------------*/
    /*SqStack s;
    InitStack(s);
    StackEmpty(s);
    push(s,1);
    push(s,2);
    push(s,3);
    int x;
    pop(s,x);
    printf("%d\n",x);
    for (int i=0;i<=s.top;i++) {
        printf("s[%d]:%d\n",i,s.data[i]);
    }*/

    LinkStack LS;
    InitLinkStack(LS);
    LinkStackPush(LS,1);
    LinkStackPush(LS,20);
    LinkStackPush(LS,33);

    int x;
    LinkStackPop(LS,x);
//    LinkStackPop(LS,x);
    PrintLS(LS);
    int topElem;
    LinkStackGetTop(LS,topElem);
    printf("栈顶元素为:%d \n",topElem);
    if(LinkStackEmpty(LS))
        printf("EMPTY!");
    else
        printf("NOT EMPTY!");



}
