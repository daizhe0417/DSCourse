//
// Created by DaiZhe on 2018/6/14.
//

#include<iostream>

using namespace std;

typedef int KeyType;

struct student {
    KeyType key;
    string name;
};
typedef student ElemType;


//1. 顺序查找算法
int Seqsch(ElemType A[], int n, KeyType K) {
    int i;
    //从表头元素A[0]开始顺序向后查找，查找成功则退出循环
    for (int i = 0; i < n; i++)
        if (A[i].key == K) break;
    //查找成功则返回该元素的下标i，否则返回-1
    if (i < n) return i;
    else return -1;
}

//2. 带岗哨的顺序查找算法
int Seqsch1(ElemType A[], int n, KeyType K) {
    int i;
    A[n].key = K;//设置岗哨
    for (int i = 0;; i++)
        if (A[i].key == K) break;
    if (i < n) return i;
    else return -1;
}
