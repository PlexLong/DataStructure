#define Maxsize 10
typedef struct {
    int data[Maxsize];
    int top0;
    int top1;
} shstack;

//初始化共享栈
void InitShStack(shstack &s) {
    s.top0 = -1;
    s.top1 = Maxsize;
}

bool IsFull(shstack s){
    if(s.top0+1 == s.top1) return true;
    else return false;
}