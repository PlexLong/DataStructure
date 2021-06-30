typedef struct DNode{
    int data;//数据域
    struct DNode *prior,*next;//前去、后继指针
}DNode,*DLinkList;

//初始化
