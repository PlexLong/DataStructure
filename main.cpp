#include <cstdio>
#include "HeadFolder/SqList.h"
#include "HeadFolder/SeqList.h"
#include "HeadFolder/LNode.h"
#include "HeadFolder/LinkList_Tail_Insert.h"
int main(){
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
    *//*InitList(L);*//*
    ListInsert(L,1,1);
    ListInsert(L,2,3);
    LNode *q =L->next->next;//qָ�� ->��2�����
//    LNode *w =L->next;
    InsertNextNode(q,4);
    InsertPriorNode(q,2);
    q=L->next->next->next;
//    free(w);
    DeleteNode(q);
    printf("��%d������Data��ֵΪ��%d \n",1,GetElem(L,1)->data);
    printf("ֵΪ%d�Ľ�� ��%d�� \n",4, LocateElem(L,4));
    printf("������L ��%d\n", Length(L));

//��ӡ����
    q=L->next;
    printf("==[ L ]===\n");
    while (q != NULL){
        printf("|  %d  | \n",q->data);
        q=q->next;
    }
    printf("===========\n");
    free(q);*/

    LinkList L;
    List_TailInsert(L);
    //��ӡ����
    PrintLinkList(L);
}
