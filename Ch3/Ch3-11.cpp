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

struct LinkQueue{
    LNode* front;
    LNode* rear;
};

void InitQueue(LinkQueue& HQ){
    HQ.front=HQ.rear=NULL;
}

void EnQueue(LinkQueue& HQ,ElemType item){
    LNode * newptr=new LNode;

}