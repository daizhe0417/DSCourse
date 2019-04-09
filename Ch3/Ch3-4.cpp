//
// Created by DaiZhe on 2018/5/7.
// 语法检查:括号匹配
//

#include<iostream>
#include<stdlib.h>
#include<fstream>

#define MAX_SIZE 10

using namespace std;

// 通用元素类型声明
typedef int ElemType;

// 栈的定义
struct Stack {
    ElemType *stack;    // 栈的存储空间
    int top;            // 栈顶下标
    int MaxSize;        // 栈的长度
};

//1. 初始化栈S为空
void InitStack(Stack &S) {
    //初始设置栈空间大小为10
    S.MaxSize = 10;
    //动态存储空间分配
    S.stack = new ElemType[S.MaxSize];
    if (!S.stack) {
        cerr << "动态存储分配失败！" << endl;
        exit(1);
    }
    //初始置栈为空
    S.top = -1;
}

//2. 元素item进栈，即插入到栈顶
void Push(Stack &S, ElemType item) {
    //若栈空间用完则自动扩大2倍空间，原有栈内容不变
    if (S.top == S.MaxSize - 1) {
        int k = sizeof(ElemType);  //计算每个元素存储空间的长度
        S.stack = (ElemType *) realloc(S.stack, 2 * S.MaxSize * k);
        S.MaxSize = 2 * S.MaxSize;   //把栈空间大小修改为新的长度
    }
    //栈顶指针后移一个位置
    S.top++;
    //将新元素插入到栈顶
    S.stack[S.top] = item;
}

//3. 删除栈顶元素并返回
ElemType Pop(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "栈空，退出运行!" << endl;
        exit(1);
    }
    //栈顶指针减1表示退栈
    S.top--;
    //返回原栈顶元素的值
    return S.stack[S.top + 1];
}

//4. 读取栈顶元素的值
ElemType Peek(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "Stack is empty!" << endl;
        exit(1);
    }
    //返回栈顶元素的值
    return S.stack[S.top];
}

//5. 判断栈是否为空
bool EmptyStack(Stack &S) {
    return S.top == -1;
}

//6. 清除栈中的所有元素并释放动态存储空间
void ClearStack(Stack &S) {
    if (S.stack) {
        delete[]S.stack;
        S.stack = 0;
    }
    S.top = -1;
    S.MaxSize = 0;
}

int BracketsCheck(char *fname) {
    ifstream ifstr(fname, ios::in);
    if (!ifstr) {
        cerr << "File（（（&））&&" << "\'" << fname << "\'" << "not found!" << endl;
        exit(1);
    }
    Stack a;
    InitStack(a);
    char ch;
    while (ifstr >> ch) {
        if (ch == 39) {//单引号的ASCII值
            while (ifstr >> ch)
                if (ch == 39) break;
            if (!ifstr) return 0;// 读到文件结束返回
        } else if (ch == 34) {// 双引号
            while (ifstr >> ch)
                if (ch == 34) break;
            if (!ifstr) return 0;
        }
        switch (ch) {
            case '{':
            case '[':
            case '(':
                Push(a, ch);
                break;
            case '}':
                if (EmptyStack(a)) {
                    cout << "少{" << endl;
                    return 0;
                }
                if (Peek(a) == '{')
                    Pop(a);
                else {
                    cout << "少{" << endl;
                    return 0;
                }
                break;
            case ']':
                if (EmptyStack(a)) return 0;
                if (Peek(a) == '[')
                    Pop(a);
                else return 0;
                break;
            case ')':
                if (EmptyStack(a)) return 0;
                if (Peek(a) == '(')
                    Pop(a);
                else return 0;
        }
    }
    if (EmptyStack(a)) return 1;
    else{
        cout << "多左括号:" << endl;
        while (!EmptyStack(a)){
            cout << Pop(a)<<"  " << endl;
        }
        return 0;
    }
}

int main() {
    char *fileName = "Ch3-3.cpp";
    int b = BracketsCheck("Ch3-3.cpp");
    if (b) {
        cout << fileName << "文件中括号匹配正确" << endl;
    } else {
        cout << fileName << "文件中括号匹配不正确" << endl;
    }
    return 0;
}