//
// Created by DaiZhe on 2018/5/28.
//
#include<iostream>
#include <strstream>

using namespace std;

// 通用元素类型声明
typedef int VertexType;

const int MaxVertexNum = 100;               // 图的最大顶点数
typedef int WeightType;                     // 权值的通用类型声明

struct edgenode {                           // 邻接表中的边结点类型
    int adjvex;                             // 邻接点域
    WeightType weight;                      // 权值域，无权图可省
    edgenode *next;                         // 下一个边的指针域
};
typedef edgenode *adjlist[MaxVertexNum];    // 存储表头指针的数组

#include "Ch5-2.h"
int main() {
    adjlist GA;
    InitAdjoin(GA);
    char *s = "{(0,1),(0,2),(0,3),(0,4),(1,4),(2,4),(2,5),(3,5),(4,5)}";
    CreateAdjoin(GA, 6, s, 0, 0);
    PrintAdjoin(GA, 6, 0, 0);


    return 0;
}