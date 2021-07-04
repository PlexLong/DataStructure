#include "malloc.h"
#include "cstdio"

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} *LinkStack;

void PrintLS(LinkStack LS) {
    LinkNode *s;
    s = LS->next;
    while (s != NULL) {
        printf("%d \n", s->data);
        s = s->next;
    }
}

//带头节点的链栈 初始化
bool InitLinkStack(LinkStack &LS) {
    LS = (LinkNode *) malloc(sizeof(LinkNode));
    if (LS == NULL) return false;
    LS->next = NULL;
    return true;
}

//元素进栈
/**
 *
 * @param LS 链栈
 * @param x 新元素
 * @return
 */
bool LinkStackPush(LinkStack &LS, int x) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == NULL) return false;
    s->data = x;
    s->next = LS->next;
    LS->next = s;
    return true;
}

//元素出栈
/**
 *
 * @param LS 链栈
 * @param x 出栈元素
 * @return
 */
bool LinkStackPop(LinkStack &LS, int &x) {
    if (LS->next == NULL) return false;
    LinkNode *s;
    s = LS->next;
    x = s->data;
    printf("被删除的是：%d\n", x);
    LS->next = s->next;
    free(s);
    return true;
}

//读栈顶元素
bool LinkStackGetTop(LinkStack LS, int &x) {
    if (LS->next == NULL) return false;
    x = LS->next->data;
    return true;
}

//判空
bool LinkStackEmpty(LinkStack LS){
    if(LS->next == NULL) return true;
    else return false;
}