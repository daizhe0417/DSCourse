#include<iostream>

#define MAX_SIZE 10

// 通用元素类型声明
using namespace std;

// 线性表的元素类型
typedef int ElemType;

// 线性表结构体
struct List {
    ElemType *list = NULL;      // 指向线性表的数据存储空间（数组首地址）
    int size = 0;               // 当前线性表长度
    int MaxSize = MAX_SIZE;     // 线性表最大长度
};

////////////////////////////////////////////////////////////////////////////
//线性表顺序存储函数声明部分
void InitList(List &L);                                 //初始化L为空
void InitList(List &L, int size);

void ClearList(List &L);                                //清空线性表L
int LenthList(List &L);                                 //返回L的长度
bool isEmpty(List &L);                                  //判断L是否为空
ElemType GetList(List &L, int pos);                     //返回L中第pos个元素的值
void TraverseList(List &L);                             //遍历输出L中的所有元素
bool FindList(List &L, ElemType &item);                 //从L中查找并返回元素
bool UpdateList(List &L, const ElemType &item);         //修改L中元素
bool InsertList(List &L, ElemType item, int pos);       //向L插入元素
bool DeleteList(List &L, ElemType &item, int pos);      //从L删除元素
void SortList(List &L);                                 //对L中的所有元素重新按给定条件排序
//线性表顺序存储函数声明部分
////////////////////////////////////////////////////////////////////////////

int main() {
    List l;
    cout << l.list << "===" << l.MaxSize << "===" << l.size << endl;
    cout << LenthList(l) << endl;
    InitList(l);
    cout << "线性表当前长度为：" << LenthList(l) << endl;
    InsertList(l, 10, -1);
    InsertList(l, 7, -1);
    InsertList(l, 3, -1);
    InsertList(l, 8, -1);
    InsertList(l, 5, -1);
    InsertList(l, 2, -1);
    InsertList(l, 9, -1);
    InsertList(l, 6, -1);
    TraverseList(l);
    SortList(l);
    TraverseList(l);
    InitList(l);
    InsertList(l, 4, 0);
    TraverseList(l);
    int pos = 10;
    if (FindList(l, pos)) {
        cout << "找到元素" << pos << endl;
    } else {
        cout << "未找到元素" << endl;
    }
    int d = 4;
    DeleteList(l, d, 0);
    TraverseList(l);
    //l.size=100;
    //delete l.list;
    //cout << GetList(l,80) << endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//线性表顺序存储函数定义部分

// 1. 初始化线性表
void InitList(List &L) {
    InitList(L, MAX_SIZE);
}

// 重载初始化线性表方法，用指定长度len创建数组
void InitList(List &L, int len) {
    // 如果线性表不为空，则不再重复初始化
    if (L.list != NULL) {
        cout << "线性表已存在，不再重复初始化，如要清空线性表，请调用ClearList()方法" << endl;
        return;
    }
    cout << "开始初始化线性表......" << endl;
    //初始定义数组长度为10，以后可增减
    L.MaxSize = len;
    //动态存储空间分配
    L.list = new ElemType[L.MaxSize];
    if (L.list == NULL) {
        cout << "动态可分配的存储空间用完，退出运行!" << endl;
        exit(1);
    }
    //置线性表长度为0，即为空表
    L.size = 0;
}

// 2. 清空线性表
void ClearList(List &L) {
    // 释放空间
    if (L.list != NULL) {
        delete[]L.list;
        L.list = NULL;
    }
    //置线性表长度为0，即为空表
    L.size = 0;
}

// 3. 返回L的长度
int LenthList(List &L) {
    return L.size;
}

// 4. 判断L是否为空
bool isEmpty(List &L) {
    return L.size == 0;
}

// 5. 返回L中第pos个元素的值
ElemType GetList(List &L, int pos) {
    if (pos < 1 || pos > L.size)    //若pos越界则退出程序
    {
        cerr << "pos 越界了!" << endl;
        exit(1);
    }
    return L.list[pos - 1];    //返回第pos个元素的值
}

// 6. 遍历输出L中的所有元素
void TraverseList(List &L) {
    for (int i = 0; i < L.size; i++)
        cout << L.list[i] << ' ';
    cout << endl;
}

// 7. 从L中查找并返回元素
bool FindList(List &L, ElemType &item) {
    for (int i = 0; i < L.size; i++)
        if (L.list[i] == item) {
            // 通过实参item返回找到的元素
            item = L.list[i];
            // 返回值表示是否找到指定元素
            return true;
        }
    return false;
}

// 8. 修改L中元素
bool UpdateList(List &L, const ElemType &item) {
    for (int i = 0; i < L.size; i++)
        if (L.list[i] == item) {
            L.list[i] = item;    //进行更新赋值操作
            return true;
        }
    return false;
}

// 9. 向L插入元素
// pos值：-1表尾，0有序，1~MaxSize+1第pos个位置（下标是pos-1）
bool InsertList(List &L, ElemType item, int pos) {
    if (pos < -1 || pos > L.size + 1) {
        cout << "pos值无效!" << endl;
        return false;
    }
    int i;
    // 重新计算要插入元素的位置pos
    // 当pos==0时，按排序插入，找到第一个比item大的元素，插入到这个位置的前面
    if (pos == 0) {
        for (i = 0; i < L.size; i++) {
            if (item < L.list[i]) {
                break;
            }
        }
        pos = i + 1;
        // 当pos==-1，插入位置是表尾
    } else if (pos == -1) {
        pos = L.size + 1;
    }


    // 空间已达最大时，扩展空间为原来的2倍
    if (L.size == L.MaxSize) {
        int k = sizeof(ElemType);
        L.list = (ElemType *) realloc(L.list, 2 * L.MaxSize * k);
        if (L.list == NULL) {
            cout << "动态可分配的存储空间用完，退出运行!" << endl;
            exit(1);
        }
        L.MaxSize = 2 * L.MaxSize;
    }

    // 插入位置之后的所有元素，向后移动1位
    for (i = L.size - 1; i >= pos - 1; i--) {
        L.list[i + 1] = L.list[i];
    }

    // 插入元素
    L.list[pos - 1] = item;
    // 增加线性表长度
    L.size++;
    return true;
}

// 10. 从L删除元素
bool DeleteList(List &L, ElemType &item, int pos) {
    if (L.size == 0) {
        cout << "线性表为空，删除无效!" << endl;
        return false;
    }
    if (pos < -1 || pos > L.size) {
        cout << "pos值无效!" << endl;
        return false;
    }
    int i;
    if (pos == 0) {
        for (i = 0; i < L.size; i++) {
            if (item == L.list[i]) {
                break;
            }
        }
        if (i == L.size) {
            return false;
        }
        pos = i + 1;
    } else if (pos == -1) {
        pos = L.size;
    }
    item = L.list[pos - 1];
    for (i = pos; i < L.size; i++) {
        L.list[i - 1] = L.list[i];
    }
    L.size--;
    if (float(L.size) / L.MaxSize < 0.4 && L.MaxSize > 10) {
        //if (float(L.size) / L.MaxSize < 0.4 && L.MaxSize > "2？"0) {
        int k = sizeof(ElemType);
        L.list = (ElemType *) realloc(L.list, L.MaxSize * k / 2);
        L.MaxSize = L.MaxSize / 2;
    }
    return true;
}

// 11. 对L中的所有元素重新按给定条件排序
void SortList(List &L) {
    int i, j;
    ElemType x;
    for (i = 1; i < L.size; i++) {
        x = L.list[i];
        for (j = i - 1; j >= 0; j--) {
            if (x < L.list[j]) {
                L.list[j + 1] = L.list[j];
            } else {
                break;
            }
        }
        L.list[j + 1] = x;
    }
}


