//
// Created by DaiZhe on 2018/5/7.
//

#include<iostream>

#define MAX_SIZE 10

using namespace std;

// 通用元素类型声明
typedef int ElemType;

// 栈的链接存储结构
struct SNode {
    ElemType data;      // 数据域
    SNode *next;        // 指针域
};

//1. 初始化链栈
void InitStack(SNode *&HS) {
    HS = NULL;  //将链栈的栈顶指针置为空。
}

//2. 向链栈中插入一个元素
void Push(SNode *&HS, const ElemType &item) {
    //为插入元素获取动态结点
    SNode *newptr = new SNode;
    //给新分配的结点赋值
    newptr->data = item;
    //向栈顶插入新结点
    newptr->next = HS;
    HS = newptr;
}

//3. 从链栈中删除一个元素并返回
ElemType Pop(SNode *&HS) {
    if (HS == NULL) {         //不能从空栈中删除
        cerr << "Linked stack is empty!" << endl;
        exit(1);
    }
    SNode *p = HS;            //暂存栈顶结点指针
    HS = HS->next;            //使栈顶指针指向下一结点
    ElemType temp = p->data;  //暂存原栈顶元素
    delete p;               //回收原栈顶结点
    return temp;            //返回原栈顶元素
}

//4. 读取栈顶元素
ElemType Peek(SNode *HS)  //HS为值参或引用形参均可
{
    if (HS == NULL) {  //无法从空栈中读取
        cerr << "Linked stack is empty!" << endl;
        exit(1);
    }
    return HS->data;  //返回栈顶结点的值
}

//5. 检查链栈是否为空
bool EmptyStack(SNode *HS)   //HS为值参或引用形参均可
{
    return HS == NULL;
}

//6 清除链栈为空
void ClearStack(SNode *&HS) {
    SNode *cp, *np;
    cp = HS;  //给cp指针赋初值，使之指向栈顶结点
    while (cp != NULL) {  //从栈顶到栈底依次删除每个结点
        np = cp->next;
        delete cp;
        cp = np;
    }
    HS = NULL;  //置链栈为空
}

int main() {
    SNode *s;
    InitStack(s);
    int a[5] = {3, 7, 1, 8, 5};
    for (int i = 0; i < 5; i++) {
        Push(s, a[i]);
    }
    cout << Pop(s) << endl;
    Push(s, 10);
    cout << Peek(s) << endl;

    while (!EmptyStack(s)) {
        cout << Pop(s) << ' ';
    }

    ClearStack(s);

    return 0;
}