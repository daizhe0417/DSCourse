//
// Created by DaiZhe on 2018/5/28.
//
#include<iostream>
#include <strstream>

using namespace std;

// 通用元素类型声明
typedef int VertexType;

const int MaxEdgeNum = 9900;                        // 图的最大边数
typedef int WeightType;                             // 权值的通用类型声明
const WeightType MaxValue = 100000;                 // 特定权值，要大于所有有效权值之和

#include "Ch5-3.h"

int main() {
    edgeset GA;
    InitArray(GA);
    char *s = "{(0,1),(0,2),(0,3),(0,4),(1,4),(2,4),(2,5),(3,5),(4,5)}";
    CreateArray(GA, 6, s, 0);
    PrintArray(GA, 6, 0, 0);
    return 0;
}