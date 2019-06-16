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
    // 若空间不足，补充分配
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
    // 从堆尾元素开始，自底向上，大于要插入元素的结点下移
    while (i != 0) {
        int j = (i - 1) / 2; // j是i的父节点下标
        if (item >= HBT.heap[j]) break; //要插入元素大于等于父节点时停止，此时i是要插入元素的位置
        HBT.heap[i] = HBT.heap[j];
        i = j;
    }
    // 执行到这里有两种情况，一是i=HBT.len==0，不经过while循环，这时堆是空的，直接在i=0的位置插入新元素；
    // 另一种情况是循环之后，这时i是找到的新元素值小于结点值的最终位置
    // 插入新元素
    HBT.heap[i] = item;
    HBT.len++;
}

//5．从堆中删除元素
ElemType DeleteHeap(Heap &HBT) {
    if (HBT.len == 0) {
        cerr << "堆为空，退出运行!" << endl;
        exit(1);
    }
    ElemType temp = HBT.heap[0];    // temp是堆顶元素
    HBT.len--;
    if (HBT.len == 0) return temp;  // len--后是0，说明原来是1，堆中只有一个元素，直接返回堆顶
    // 堆中有多个元素，开始调整
    ElemType x = HBT.heap[HBT.len]; // 此时的堆尾元素（len已经--过了，下标是对的）
    int i = 0;  // 当前堆顶元素下标
    int j = 1;  // 当前堆顶元素的左孩子（右孩子）下标
    // 从堆顶元素开始，自顶向下调整，
    while (j <= HBT.len - 1) {
        // j<len-1，即j不是堆尾元素时，如果左孩子(j)大于右孩子(j+1)，j++，即下标变为右孩子（比较小的那个）
        if (j < HBT.len - 1 && HBT.heap[j] > HBT.heap[j + 1]) j++;
        // 堆尾元素小于等于当前左孩子（右孩子）时停止循环，i是原堆尾元素要移动的位置
        if (x <= HBT.heap[j]) break;
        // 否则左孩子（右孩子）上移
        HBT.heap[i] = HBT.heap[j];
        i = j;
        j = 2 * i + 1; // j是i的左孩子下标
    }
    // 原堆尾元素x，移动到i
    HBT.heap[i] = x;
    // 返回堆顶元素
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
    cout << "按下标遍历堆：" << endl;
    for (i = 0; i < 7; i++) {
        cout << b.heap[i] << ",";
    }
    cout << endl;
    cout << "依次删除堆顶元素：" << endl;
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