
#define Maxsize 10
typedef struct {
    int data[Maxsize];//静态数组存放栈中元素
    int top;//栈顶指针
}SqStack;

/**
 *
 * @param S 顺序栈
 * @return
 */
// 初始化
bool InitStack(SqStack &s){
    s.top = -1;//初始化栈顶指针
    return true;
}
//判空
bool StackEmpty(SqStack s){
    if(s.top == -1) return true;
    else return false;
}
//入栈
/**
 *
 * @param s 顺序栈
 * @param x 新元素
 * @return
 */
bool push(SqStack &s,int x){
    if(s.top == Maxsize-1) return false;//栈满
    s.top = s.top+1;//栈顶指针加 1
    s.data[s.top] = x;//新元素入栈
    //以上两步骤可以合并
//    s.data[++s.top]=x;
    return true;
}
//出栈
bool pop(SqStack &s,int &x){
    if(s.top == -1) return false;//判空
    x=s.data[s.top];//栈顶元素出栈
    s.top--;//栈顶指针减 1
    //以上两步骤可以合并
//    x=s.data[s.top--];
    return true;
}
//读取栈顶元素
bool GetTop(SqStack s,int &x){
    if(s.top == -1) return false;
    x=s.data[s.top];
    return true;
}
