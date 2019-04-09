//
// Created by DaiZhe on 2018/5/18.
// 习题2-4
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

// 遍历链表
void TraverseList(LNode *HL) {
    while (HL != NULL) {        //从表头开始依次输出每个结点的值
        cout << HL->data << " ";
        HL = HL->next;
    }
    cout << endl;
}


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

// 将两个有序链表合并成一个有序链表，原链表为空
void fun5(LNode *&HL1, LNode *&HL2, LNode *&SL) {
    LNode *ep = NULL;

    if (HL1->data > HL2->data) {
        SL = HL2;
        HL2 = HL2->next;
        ep = SL;
    } else {
        SL = HL1;
        HL1 = HL1->next;
        ep = SL;
    }

    while (HL1 != NULL && HL2 != NULL) {
        if (HL1->data > HL2->data) {
            ep->next = HL2;
            HL2 = HL2->next;
            ep = ep->next;
        } else {
            ep->next = HL1;
            HL1 = HL1->next;
            ep = ep->next;
        }
    }
    while (HL1) {
        ep->next = HL1;
        HL1 = HL1->next;
        ep = ep->next;
    }
    while (HL2) {
        ep->next = HL2;
        HL2 = HL2->next;
        ep = ep->next;
    }
}

// 将两个有序链表合并为一个有序列表，原链表保持不变
void fun6(LNode *HL1, LNode *HL2, LNode *&SL) {
    LNode *ep = new LNode;
    SL = ep;
    if (HL1->data > HL2->data) {
        ep->data = HL2->data;
        HL2 = HL2->next;
    } else {
        ep->data = HL1->data;
        HL1 = HL1->next;
    }

    while (HL1 != NULL && HL2 != NULL) {
        LNode *cp = new LNode;
        if (HL1->data > HL2->data) {
            cp->data = HL2->data;
            HL2 = HL2->next;
        } else {
            cp->data = HL1->data;
            HL1 = HL1->next;
        }
        ep->next = cp;
        ep = cp;
    }
    while (HL1) {
        LNode *cp = new LNode;
        cp->data = HL1->data;
        HL1 = HL1->next;
        ep->next = cp;
        ep = cp;
    }
    while (HL2) {
        LNode *cp = new LNode;
        cp->data = HL2->data;
        HL2 = HL2->next;
        ep->next = cp;
        ep = cp;
    }
}

// 一个链表按照奇偶数分裂成两个链表，原链表保持不变
void fun7(LNode *SL, LNode *&HL1, LNode *&HL2) {
    while (SL) {
        LNode *cp = new LNode;
        cp->data = SL->data;
        SL = SL->next;
        if (cp->data % 2 == 0) {
            cp->next = HL2;
            HL2 = cp;
        } else {
            cp->next = HL1;
            HL1 = cp;
        }
    }
}

int main() {
    cout << "初始化链表：" << endl;
    LNode *HL = NULL;
    LNode *x = new LNode, *y = new LNode, *z = new LNode;
    x->data = 1;
    y->data = 2;
    z->data = 3;
    x->next = y;
    y->next = z;
    z->next = NULL;
    HL = x;
    TraverseList(HL);

    cout << "************第一小题************" << endl;
    cout << "逆置后链表：" << endl;
    fun1(HL);
    TraverseList(HL);

    cout << "************第二小题************" << endl;
    cout << "链表中元素最大值：" << endl;
    fun2(HL);

    cout << "************第三小题************" << endl;
    int num = 3;
    cout << "链表中含有" << num << "的个数：" << endl;
    fun3(HL, num);

    cout << "************第四小题************" << endl;
    cout << "从数组{2, 3, 6, 6, 2, 8}创建链表" << endl;
    int a[6] = {2, 3, 6, 6, 2, 8};
    fun4(HL, a, 3);
    TraverseList(HL);

    cout << "************第五小题************" << endl;
    LNode *HL1, *HL2, *SL;
    int b[3] = {1, 4, 5};
    cout << "数组a创建链表：" << endl;
    fun4(HL1, a, 3);
    TraverseList(HL1);
    cout << "数组b创建链表：" << endl;
    fun4(HL2, b, 3);
    TraverseList(HL2);
    cout << "合并之后的新链表：" << endl;
    fun5(HL1, HL2, SL);
    TraverseList(SL);
    cout << "合并之后的原链表一：" << endl;
    TraverseList(HL1);
    cout << "合并之后的原链表二：" << endl;
    TraverseList(HL2);

    cout << "************第六小题************" << endl;
    HL1 = NULL, HL2 = NULL, SL = NULL;
    int aa[] = {2, 8, 10, 20};
    int bb[] = {3, 8, 9, 15, 16};
    cout << "数组aa创建链表：" << endl;
    fun4(HL1, aa, 4);
    TraverseList(HL1);
    cout << "数组bb创建链表：" << endl;
    fun4(HL2, bb, 5);
    TraverseList(HL2);
    cout << "合并之后的新链表：" << endl;
    fun6(HL1, HL2, SL);
    TraverseList(SL);
    cout << "原链表一：" << endl;
    TraverseList(HL1);
    cout << "原链表二：" << endl;
    TraverseList(HL2);

    cout << "************第七小题************" << endl;
    HL1 = NULL, HL2 = NULL, SL = NULL;
    int cc[] = {2, 3, 8, 10, 20, 9, 15, 16};
    cout << "数组cc创建链表：" << endl;
    fun4(SL, cc, 8);
    TraverseList(SL);
    cout << "分解链表：" << endl;
    fun7(SL, HL1, HL2);
    cout << "奇数链表：" << endl;
    TraverseList(HL1);
    cout << "偶数链表：" << endl;
    TraverseList(HL2);
    cout << "原链表：" << endl;
    TraverseList(SL);
    return 0;
}