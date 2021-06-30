#include <malloc.h>
#include <cstdio>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//带头结点
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) return false;
    L->next = NULL;
    return true;
}

//判空
bool IsEmpty(LinkList L) {
    if (L->next == NULL) return true;
    else return false;
}

//添加元素
bool ListInsert(LinkList &L, int i, int e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//-------------------------------
// 指定结点后插操作
//-------------------------------
/**
 *
 * @param p 结点
 * @param e 插入元素
 * @return
 *         true 成功
 *         false 失败
 */
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;//内存已满
    //下面操作不可改变
    s->data = e;   //s:data=e s:next=NULL
    s->next = p->next;  //s:data=e s:next=p->next
    p->next = s;   //p->next改为s
    return true;
}

//---------------------------------------
//指定结点前插操作
//---------------------------------------
/**
 *
 * @param p 结点
 * @param e 插入元素
 * @return
 *         true 成功
 *         false 失败
 */
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;//交换数据
    p->data = e;
    return true;
}

//----------------------------------------------
// 按位删除
//----------------------------------------------
/**
 *
 * @param L 单链表
 * @param i 删除结点位置
 * @param e 删除的元素
 * @return
 *         true 成功
 *         false 失败
 */
bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }//找到第i-1个位置
    if (p == NULL) return false;//i不合法
    if (p->next == NULL) return false;//i-1结点后已经没有其他结点了
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;//断开q结点
    free(q);
    return true;
}

//-------------------------
// 指定结点删除
//-------------------------
/**
 *
 * @param p 结点
 * @return true 成功  false 失败
 */
bool DeleteNode(LNode *p) {
    if (p == NULL) return false;
    //if( p->next == NULL) return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

//-----------------
//按位查找
//-----------------
/**
 *
 * @param L 单链表
 * @param i 查找位置
 * @return 结点
 */
LNode *GetElem(LinkList L, int i) {
    if (i < 0) return NULL; //i值不合法
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {//找到第i-1结点位置
        p = p->next;
        j++;
    }//p指向第i个结点
    return p;
}

//-------------
//按值查找
//--------------
/**
 *
 * @param L 单链表
 * @param e 值
 * @return -1 查找失败
 *          i!=0 && -1 查找成功 返回下标
 */
int LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    int i = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) return -1;
    return i;
}

//--------------
//表长
//--------------
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

void PrintLinkList(LinkList L){
    LNode *q=L->next;
    printf("==[ L ]===\n");
    int i=1;
    while (q != NULL){
        printf("第%d个结点: %d   \n",i,q->data);
        q=q->next;
        i++;
    }
    printf("===========\n");
    free(q);
}