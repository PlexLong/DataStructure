#include "malloc.h"
#include "cstdio"

typedef struct DNode {
    int data;//数据域
    struct DNode *prior, *next;//前去、后继指针
} DNode, *DLinkList;

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



