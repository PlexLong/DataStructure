// Created by 一只敦敦 on 2021/6/28.
/**
 *这就是 静态分配的顺序表
 */
#define Maxsize 10
typedef struct {
    int data[Maxsize];
    int length;
} SqList;

void InitList(SqList &L) {
    for (int &i : L.data) {
        i = 0;
    }
    L.length = 0;
}

void ListInsert(SqList &L, int i, int e) {  //插入位置为 i 插入元素 e
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];        //第i个元素后的元素后移
    }
    L.data[i - 1] = e;
    L.length++;
}

//感觉要加强健壮性。。。上面的太粗糙了
bool ListInsert_Stronger(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= Maxsize) return false;
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];        //第i个元素后的元素后移
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,int &e){
    if (i<1 || i>L.length) return false;//位置是否合法
    e = L.data[i-1];
    for (int j = i; j < L.length; j++) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}