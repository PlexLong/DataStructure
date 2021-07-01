#define MaxSize 10
struct SNode {
    int data;
    int next;
} SLinkList[Maxsize];

SNode* InitSLL() {
    SLinkList[0].next = -1;
    return SLinkList;
}
void through(SNode *s){
    SNode *q = s;
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", s->data);
        if (s->next == -1)
            break;
        s = (q + (s->next));
    }
}
void through_1(SNode *s){
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",s[i].data);
    }
}
bool AddNodeSLL(SNode *s, int x,int addr) {
    if(s[addr].data!=0) return false;
    SNode *head=s;
    while (s->next != -1){
        s=head+s->next;  //找到末尾结点
    }
    s->next=addr;//末尾结点的next指到新加结点位置（游标）
    head[addr].data=x;//数组的addr位置的data
    head[addr].next=-1;//数组的addr为末尾位置
    return true;
}
