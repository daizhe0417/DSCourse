//
// Created by DaiZhe on 2018/5/28.
//
#include <iostream>
#include <strstream>

using namespace std;

// 通用元素类型声明
typedef char VertexType;

const int MaxVertexNum = 100;                       // 图的最大顶点数
const int MaxEdgeNum = 9900;                        // 图的最大边数
typedef int WeightType;                             // 权值的通用类型声明
const WeightType MaxValue = 100000;                 // 特定权值，要大于所有有效权值之和
typedef VertexType vexlist[MaxVertexNum];           // 一维数组，存储顶点信息
typedef int adjmatrix[MaxVertexNum][MaxVertexNum];  // 二维数组，邻接矩阵

#include "Ch5-1.h"

int main() {
    adjmatrix GA;
    vexlist vx;
    vx[0]='A';vx[1]='B';
    InitMatrix(GA, 0);
    char *s = "{(0,1),(0,2),(0,3),(0,4),(1,4),(2,4),(2,5),(3,5),(4,5)}";
    CreateMatrix(GA, 6, s, 0, 0);
    PrintMatrix(GA, 6, 0, 0);

    s = "{(0,1)3,(0,2)5,(0,3)2,(0,4)4}";
    CreateMatrix(GA, 6, s, 0, 1);
    PrintMatrix(GA, 6, 0, 1);
    return 0;
}