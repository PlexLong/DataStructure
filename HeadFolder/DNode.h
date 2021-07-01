#include "malloc.h"
#include "cstdio"

typedef struct DNode {
    int data;//数据域
    struct DNode *prior, *next;//前驱、后继指针
} DNode, *DLinkList;

//打印双向链表
/**
 *
 * @param DL 双向链表
 */
void PrintDLinkList(DLinkList DL){
    DNode *q=DL->next;
    printf("==[ DL ]===\n");
    int i=1;
    while (q != NULL){
        printf("第%d个结点: %d   \n",i,q->data);
        q=q->next;
        i++;
    }
    printf("===========\n");
    free(q);
}

//初始化
/**
 *
 * @param L 双链表
 * @return true成功 false失败
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) return false;
    L->prior = NULL;//头节点的前驱永远指向NULL
    L->next = NULL;
    return true;
}

//指定结点后插入
/**
 *
 * @param p 指定结点
 * @param s 待插入结点
 * @return
 */
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL) //p之后是否还有结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除p的后继结点
/**
 *
 * @param p 删除的结点的前驱结点
 * @return
 */
bool DeleteNextDNode(DNode *p){
    if(p== nullptr) return false;
    DNode *q =p->next;//p的后续结点
    if(q == nullptr) return false;
    p->next=q->next;
    if(q->next!= nullptr)
        q->next->prior=p;
    free(q);
    return true;
}

//双向链表遍历
/* 后向遍历 */
/**
 *
 * @param DL 双链表
 * @return
 */
bool NextRead(DLinkList DL){
    DNode *q = DL->next;
    if(q == NULL)
        printf("空表\n");
    int i=1;
    while (q != nullptr){
        printf("第%d个结点：%d\n",i,q->data);
        q=q->next;
        i++;
    }
    free(q);
    return true;
}

//前向遍历
bool BeforeRead(DLinkList DL){
    DNode *q = DL->next;
    if(q == nullptr)
        printf("空表\n");
    int i=1;
    while (q->next!=NULL){
        q=q->next;
        i++;
    }
    while(q->prior!=NULL){
        printf("第%d个结点： %d\n",i,q->data);
        q=q->prior;
        i--;
    }
    free(q);
    return true;
}
//循环双链表
bool InitDCyclicDLinklist(DLinkList DL){
    DL = (DNode *) malloc(sizeof(DNode));
    if(DL == NULL) return false;
    DL->next=DL;
    DL->prior=DL;
    return true;
}
//判空
bool IsEmptyCDL(DLinkList DL){
    if(DL->next == DL) return true;
    else return false;
}
