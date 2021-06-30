#include <malloc.h>
#include <cstdio>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

//��ͷ���
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) return false;
    L->next = NULL;
    return true;
}

//�п�
bool IsEmpty(LinkList L) {
    if (L->next == NULL) return true;
    else return false;
}

//���Ԫ��
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
// ָ����������
//-------------------------------
/**
 *
 * @param p ���
 * @param e ����Ԫ��
 * @return
 *         true �ɹ�
 *         false ʧ��
 */
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;//�ڴ�����
    //����������ɸı�
    s->data = e;   //s:data=e s:next=NULL
    s->next = p->next;  //s:data=e s:next=p->next
    p->next = s;   //p->next��Ϊs
    return true;
}

//---------------------------------------
//ָ�����ǰ�����
//---------------------------------------
/**
 *
 * @param p ���
 * @param e ����Ԫ��
 * @return
 *         true �ɹ�
 *         false ʧ��
 */
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL) return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;//��������
    p->data = e;
    return true;
}

//----------------------------------------------
// ��λɾ��
//----------------------------------------------
/**
 *
 * @param L ������
 * @param i ɾ�����λ��
 * @param e ɾ����Ԫ��
 * @return
 *         true �ɹ�
 *         false ʧ��
 */
bool ListDelete(LinkList &L, int i, int &e) {
    if (i < 1) return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }//�ҵ���i-1��λ��
    if (p == NULL) return false;//i���Ϸ�
    if (p->next == NULL) return false;//i-1�����Ѿ�û�����������
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;//�Ͽ�q���
    free(q);
    return true;
}

//-------------------------
// ָ�����ɾ��
//-------------------------
/**
 *
 * @param p ���
 * @return true �ɹ�  false ʧ��
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
//��λ����
//-----------------
/**
 *
 * @param L ������
 * @param i ����λ��
 * @return ���
 */
LNode *GetElem(LinkList L, int i) {
    if (i < 0) return NULL; //iֵ���Ϸ�
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i) {//�ҵ���i-1���λ��
        p = p->next;
        j++;
    }//pָ���i�����
    return p;
}

//-------------
//��ֵ����
//--------------
/**
 *
 * @param L ������
 * @param e ֵ
 * @return -1 ����ʧ��
 *          i!=0 && -1 ���ҳɹ� �����±�
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
//��
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
        printf("��%d�����: %d   \n",i,q->data);
        q=q->next;
        i++;
    }
    printf("===========\n");
    free(q);
}