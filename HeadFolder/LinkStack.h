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

//��ͷ�ڵ����ջ ��ʼ��
bool InitLinkStack(LinkStack &LS) {
    LS = (LinkNode *) malloc(sizeof(LinkNode));
    if (LS == NULL) return false;
    LS->next = NULL;
    return true;
}

//Ԫ�ؽ�ջ
/**
 *
 * @param LS ��ջ
 * @param x ��Ԫ��
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

//Ԫ�س�ջ
/**
 *
 * @param LS ��ջ
 * @param x ��ջԪ��
 * @return
 */
bool LinkStackPop(LinkStack &LS, int &x) {
    if (LS->next == NULL) return false;
    LinkNode *s;
    s = LS->next;
    x = s->data;
    printf("��ɾ�����ǣ�%d\n", x);
    LS->next = s->next;
    free(s);
    return true;
}

//��ջ��Ԫ��
bool LinkStackGetTop(LinkStack LS, int &x) {
    if (LS->next == NULL) return false;
    x = LS->next->data;
    return true;
}

//�п�
bool LinkStackEmpty(LinkStack LS){
    if(LS->next == NULL) return true;
    else return false;
}