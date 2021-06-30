#include <malloc.h>
#include <cstdio>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

//带头结点
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) return false;
    L->next =NULL;
    return true;
}

bool IsEmpty(LinkList L){
    if (L->next == NULL) return true;
    else return false;
}

bool ListInsert(LinkList &L,int i,int e){
    if (i<1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p!=NULL && j<i-1){
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s =(LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}