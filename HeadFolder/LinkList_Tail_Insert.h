#include "cstdio"
#include "malloc.h"
//尾插法
LinkList List_TailInsert(LinkList &L){
    int x;//设置ElemType 为 int
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while (x!=9999){
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}