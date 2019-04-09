//
// Created by DaiZhe on 2018/5/14.
//
#include <iostream>
using namespace std;

// 通用元素类型声明
typedef int ElemType;

struct Queue{
    ElemType *queue;
    int MaxSize;
    int front,rear;
};

// 1.初始化队列
void InitQueue(Queue &Q){
    Q.MaxSize=10;
    Q.queue=new ElemType[Q.MaxSize];
    Q.front=Q.rear=0;
}

// 2.向队列中插入元素