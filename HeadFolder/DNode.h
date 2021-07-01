#include "malloc.h"
#include "cstdio"

typedef struct DNode {
    int data;//������
    struct DNode *prior, *next;//ǰ�������ָ��
} DNode, *DLinkList;

//��ӡ˫������
/**
 *
 * @param DL ˫������
 */
void PrintDLinkList(DLinkList DL){
    DNode *q=DL->next;
    printf("==[ DL ]===\n");
    int i=1;
    while (q != NULL){
        printf("��%d�����: %d   \n",i,q->data);
        q=q->next;
        i++;
    }
    printf("===========\n");
    free(q);
}

//��ʼ��
/**
 *
 * @param L ˫����
 * @return true�ɹ� falseʧ��
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) return false;
    L->prior = NULL;//ͷ�ڵ��ǰ����Զָ��NULL
    L->next = NULL;
    return true;
}

//ָ���������
/**
 *
 * @param p ָ�����
 * @param s ��������
 * @return
 */
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL) //p֮���Ƿ��н��
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//ɾ��p�ĺ�̽��
/**
 *
 * @param p ɾ���Ľ���ǰ�����
 * @return
 */
bool DeleteNextDNode(DNode *p){
    if(p== nullptr) return false;
    DNode *q =p->next;//p�ĺ������
    if(q == nullptr) return false;
    p->next=q->next;
    if(q->next!= nullptr)
        q->next->prior=p;
    free(q);
    return true;
}

//˫���������
/* ������� */
/**
 *
 * @param DL ˫����
 * @return
 */
bool NextRead(DLinkList DL){
    DNode *q = DL->next;
    if(q == NULL)
        printf("�ձ�\n");
    int i=1;
    while (q != nullptr){
        printf("��%d����㣺%d\n",i,q->data);
        q=q->next;
        i++;
    }
    free(q);
    return true;
}

//ǰ�����
bool BeforeRead(DLinkList DL){
    DNode *q = DL->next;
    if(q == nullptr)
        printf("�ձ�\n");
    int i=1;
    while (q->next!=NULL){
        q=q->next;
        i++;
    }
    while(q->prior!=NULL){
        printf("��%d����㣺 %d\n",i,q->data);
        q=q->prior;
        i--;
    }
    free(q);
    return true;
}
//ѭ��˫����
bool InitDCyclicDLinklist(DLinkList DL){
    DL = (DNode *) malloc(sizeof(DNode));
    if(DL == NULL) return false;
    DL->next=DL;
    DL->prior=DL;
    return true;
}
//�п�
bool IsEmptyCDL(DLinkList DL){
    if(DL->next == DL) return true;
    else return false;
}
