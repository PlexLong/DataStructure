#include <malloc.h>

#define InitSize 10
typedef struct {
    int *data;
    int MaxSize; //顺序表最大容量
    int length;  //当前数据个数
}SeqList;

void InitList(SeqList &L){
    //用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}


bool SeqInsert(SeqList &L,int i,int e){
    if(i<1) return false;
    if (L.length >= Maxsize) return false;

    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];        //第i个元素后的元素后移
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool SeqDelete(SeqList &L,int i,int &e){
    if (i<1 || i>L.length) return false;//位置是否合法
    e = L.data[i-1];
    for (int j = i; j < L.length; j++) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

