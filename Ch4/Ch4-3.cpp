//
// Created by DaiZhe on 2018/5/24.
//
#include<iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

struct Heap {
    ElemType *heap; //堆空间
    int len;        //堆长度
    int MaxSize;    //动态数组的大小
};

//1．初始化堆
void InitHeap(Heap &HBT)        //置HBT为一个空堆
{
    HBT.MaxSize = 10;           //初始定义数组长度为10，以后可增减
    HBT.heap = new ElemType[HBT.MaxSize]; //动态分配存储堆的数组空间
    if (!HBT.heap) {
        cout << "用于动态分配的内存空间用完，退出运行!" << endl;
        exit(1);
    }
    HBT.len = 0;                //设置len域的初值为0
}

//2．清除堆
void ClearHeap(Heap &HBT)    //清除HBT，使之成为一个空堆
{
    if (HBT.heap != NULL) {
        delete[] HBT.heap;
        HBT.heap = NULL;
        HBT.len = 0;
        HBT.MaxSize = 0;
    }
}

//3．检查一个堆是否为空
bool EmptyHeap(Heap &HBT) {
    return HBT.len == 0;
}

//4．向堆中插入一个元素
void InsertHeap(Heap &HBT, ElemType item) {
    if (HBT.len == HBT.MaxSize) {
        int k = sizeof(ElemType);
        HBT.heap = (ElemType *) realloc(HBT.heap, 2 * HBT.MaxSize * k);
        if (HBT.heap == NULL) {
            cout << "动态可分配的存储空间用完，退出运行!" << endl;
            exit(1);
        }
        HBT.MaxSize = 2 * HBT.MaxSize;
    }
    int i = HBT.len;
    while (i != 0) {
        int j = (i - 1) / 2;
        if (item >= HBT.heap[j]) break;
        HBT.heap[i] = HBT.heap[j];
        i = j;
    }
    HBT.heap[i] = item;
    HBT.len++;
}

//5．从堆中删除元素
ElemType DeleteHeap(Heap &HBT) {
    if (HBT.len == 0) {
        cerr << "堆为空，退出运行!" << endl;
        exit(1);
    }
    ElemType temp = HBT.heap[0];
    HBT.len--;
    if (HBT.len == 0) return temp;
    ElemType x = HBT.heap[HBT.len];
    int i = 0;
    int j = 1;
    while (j <= HBT.len - 1) {
        if (j < HBT.len - 1 && HBT.heap[j] > HBT.heap[j + 1]) j++;
        if (x <= HBT.heap[j]) break;
        HBT.heap[i] = HBT.heap[j];
        i = j;
        j = 2 * i + 1;
    }
    HBT.heap[i] = x;
    return temp;
}

int main() {
    int a[8] = {23, 56, 40, 62, 38, 55, 10, 16};
    Heap b;
    InitHeap(b);
    int i, x;
    for (i = 0; i < 8; i++) {
        InsertHeap(b, a[i]);
    }
    for (i = 0; i < 7; i++) {
        cout << b.heap[i] << "," << endl;
    }
    cout << b.heap[7] << endl;
    while (!EmptyHeap(b)) {
        x = DeleteHeap(b);
        cout << x;
        if (!EmptyHeap(b)) {
            cout << ",";
        }
    }
    cout << endl;
    ClearHeap(b);
    return 0;
}