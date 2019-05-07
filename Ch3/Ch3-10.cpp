//
// Created by DaiZhe on 2018/5/14.
//
#include <iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

struct Queue {
    ElemType *queue;
    int MaxSize;
    int front, rear;
};

// 1.初始化队列
void InitQueue(Queue &Q) {
    Q.MaxSize = 10;
    Q.queue = new ElemType[Q.MaxSize];
    Q.front = Q.rear = 0;
}

// 2.向队列中插入元素
void EnQueue(Queue &Q, ElemType item) {
    if ((Q.rear + 1) % Q.MaxSize == Q.front) {
        int k = sizeof(ElemType);
        Q.queue = (ElemType *) realloc(Q.queue, 2 * Q.MaxSize * k);
        if (Q.rear != Q.MaxSize - 1) {
            for (int i = 0; i <= Q.rear; i++) {
                Q.queue[i + Q.MaxSize] = Q.queue[i];
            }
            Q.rear += Q.MaxSize;
        }
        Q.MaxSize = 2 * Q.MaxSize;
    }
    Q.rear = (Q.rear + 1) % Q.MaxSize;
    Q.queue[Q.rear] = item;
}

// 3. 从队列中删除元素并返回
ElemType OutQueue(Queue &Q) {
    if (Q.front == Q.rear) {
        cerr << "队列已空，无法删除！" << endl;
        exit(1);
    }
    Q.front = (Q.front + 1) % Q.MaxSize;
    return Q.queue[Q.front];
}

// 4.读取队首元素，不改变队列状态
ElemType PeekQueue(Queue &Q) {
    if (Q.front == Q.rear) {
        cerr << "队列已空，无法读取！" << endl;
        exit(1);
    }
    return Q.queue[(Q.front + 1) % Q.MaxSize];
}

// 5.检查一个队列是否为空
bool EmptyQueue(Queue &Q) {
    return Q.front == Q.rear;
}

// 6.清除一个队列为空，释放空间
void ClearQueue(Queue &Q) {
    if (Q.queue != NULL) {
        delete[]Q.queue;
    }
    Q.front = Q.rear = 0;
    Q.queue = NULL;
    Q.MaxSize = 0;
}

int main() {
    Queue Q;
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