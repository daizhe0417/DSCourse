//
// Created by DaiZhe on 2018/5/18.
//

#include<iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

// 单链表结点
struct LNode {
    ElemType data;
    LNode *next;
};

// 双链表结点
struct DNode {
    ElemType data;
    DNode *pre;
    DNode *next;
};

// 单链表逆置
void fun1(LNode *&HL) {
    LNode *SL = NULL;
    LNode *cp = HL;
    while (cp) {
        HL = HL->next;
        cp->next = SL;
        SL = cp;
        cp = HL;
    }
    HL = SL;
}

// 取最大值
void fun2(LNode *&HL) {
    LNode *cp = HL;
    ElemType x = HL->data;
    while (cp) {
        if (x < cp->data) {
            x = cp->data;
        }
        cp = cp->next;
    }
    cout << x << endl;
}

// 值等于给定值x的个数
void fun3(LNode *&HL, const ElemType x) {
    LNode *cp = HL;
    int num = 0;
    while (cp) {
        if (x == cp->data) {
            num++;
        }
        cp = cp->next;
    }
    cout << num << endl;
}

// 建立链表，与给定数组的次序相同，时间复杂度为O(n)
void fun4(LNode *&HL, const ElemType x[], const int len) {
    HL = NULL;
    for (int i = len - 1; i >= 0; i--) {
        LNode *cp = new LNode;
        cp->data = x[i];
        if (HL == NULL) {
            cp->next = NULL;
        } else {
            cp->next = HL;
        }
        HL = cp;
    }
}

int main() {
    LNode *HL = NULL;
    LNode *x = new LNode, *y = new LNode, *z = new LNode;
    x->data = 1;
    y->data = 2;
    z->data = 3;
    x->next = y;
    y->next = z;
    z->next = NULL;

    HL = x;

    cout << "初始链表：" << endl;
    LNode *tmp = HL;
    {
        while (tmp != NULL) {        //从表头开始依次输出每个结点的值
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    cout << "逆置后链表：" << endl;
    fun1(HL);

    tmp = HL;
    {
        while (tmp != NULL) {        //从表头开始依次输出每个结点的值
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    cout << "链表中元素最大值：" << endl;
    fun2(HL);

    cout << "链表中含有3的个数：" << endl;
    fun3(HL, 3);

    cout << "从数据创建链表" << endl;
    int a[6] = {2, 3, 4};
    fun4(HL, a, 3);
    tmp = HL;
    {
        while (tmp != NULL) {        //从表头开始依次输出每个结点的值
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    return 0;
}