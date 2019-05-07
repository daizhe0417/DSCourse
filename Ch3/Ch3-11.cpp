//
// Created by DaiZhe on 2018/5/14.
//
#include <iostream>

using namespace std;

typedef int ElemType;

struct LNode {
    ElemType data;
    LNode *next;
};

struct LinkQueue {
    LNode *front;
    LNode *rear;
};

void InitQueue(LinkQueue &HQ) {
    HQ.front = HQ.rear = NULL;
}

void EnQueue(LinkQueue &HQ, ElemType item) {
    LNode *newptr = new LNode;
    newptr->data = item;
    newptr->next = NULL;
    if (HQ.rear == NULL) {
        HQ.front = HQ.rear = newptr;
    } else {
        HQ.rear = HQ.rear->next = newptr;
    }
}

ElemType OutQueue(LinkQueue &HQ) {
    if (HQ.front == NULL) {
        cerr << "链队为空，无法删除！" << endl;
        exit(1);
    }
    ElemType tmp = HQ.front->data;
    LNode *p = HQ.front;
    HQ.front = p->next;
    if (HQ.front == NULL) {
        HQ.rear = NULL;
    }
    delete p;
    return tmp;
}

ElemType PeekQueue(LinkQueue &HQ) {
    if (HQ.front == NULL) {
        cerr << "链队为空，无法删除！" << endl;
        exit(1);
    }
    return HQ.front->data;
}

bool EmptyQueue(LinkQueue &HQ) {
    return HQ.front==NULL;
}

void ClearQueue(LinkQueue &HQ) {
    LNode* p=HQ.front;
    while(p!=NULL){
        HQ.front=HQ.front->next;
        delete p;
        p=HQ.front;
    }
    HQ.rear=NULL;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    int a[9] = {3, 8, 5, 17, 9, 30, 15, 22, 20};
    for (int i = 0; i < 9; i++) {
        EnQueue(Q, a[i]);
    }
    cout << OutQueue(Q) << "  ";
    cout << OutQueue(Q) << "  ";
    cout << OutQueue(Q) << "  " << endl;

    EnQueue(Q, 68);
    cout << PeekQueue(Q) << "  " << endl;
    for (int i = 0; i < 9; i += 2) {
        EnQueue(Q, a[i]);
    }
    cout << PeekQueue(Q) << "  ";
    cout << OutQueue(Q) << "  " << endl;

    while (!EmptyQueue(Q)) {
        cout << OutQueue(Q) << "  ";
    }
    cout << endl;
    ClearQueue(Q);
}