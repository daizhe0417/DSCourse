#include<iostream>

using namespace std;

typedef int ElemType;



struct List {
    ElemType *list;
    int size;
    int MaxSize;
};

////////////////////////////////////////////////////////////////////////////
//线性表顺序存储函数声明部分
void InitList(List &L);                            //初始化L为空
void ClearList(List &L);                           //清除L中的所有元素
int LenthList(List &L);                           //返回L的长度
bool EmptyList(List &L);                           //判断L是否为空
ElemType GetList(List &L, int pos);                //返回L中第pos个元素的值
void TraverseList(List &L);                        //遍历输出L中的所有元素
bool FindList(List &L, ElemType &item);             //从L中查找并返回元素
bool UpdateList(List &L, const ElemType &item);    //修改L中元素
bool InsertList(List &L, ElemType item, int pos);  //向L插入元素
bool DeleteList(List &L, ElemType &item, int pos); //从L删除元素
void SortList(List &L);                            //对L中的所有元素重新按给定条件排序
//线性表顺序存储函数声明部分
////////////////////////////////////////////////////////////////////////////

int main() {
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//线性表顺序存储函数定义部分

//1. 初始化线性表
void InitList(List &L) {
    //初始定义数组长度为10，以后可增减
    L.MaxSize = 10;
    //动态存储空间分配
    L.list = new ElemType[L.MaxSize];
    if (L.list == NULL) {
        cout << "动态可分配的存储空间用完，退出运行!" << endl;
        exit(1);
    }
    //置线性表长度为0，即为空表
    L.size = 0;
}

void ClearList(List &L) {
    if (L.list != NULL) {
        delete[]L.list;
        L.list = NULL;
    }
    L.size = 0;
}

int LenthList(List &L) {
    return L.size;
}

bool EmptyList(List &L) {
    return L.size == 0;
}

ElemType getList(List &L, int pos) {
    if (pos < 1 || pos > L.size)    //若pos越界则退出程序
    {
        cerr << "pos 越界了!" << endl;
        exit(1);
    }
    return L.list[pos - 1];    //返回第pos个元素的值
}

void TraverseList(List &L) {
    for (int i = 0; i < L.size; i++)
        cout << L.list[i] << ' ';
    cout << endl;
}

bool FindList(List &L, ElemType &item) {
    for (int i = 0; i < L.size; i++)
        if (L.list[i] == item) {
            item = L.list[i];
            return true;
        }
    return false;
}

bool UpdateList(List &L, const ElemType &item) {
    for (int i = 0; i < L.size; i++)
        if (L.list[i] == item) {
            L.list[i] = item;    //进行更新赋值操作
            return true;
        }
    return false;
}

bool InsertList(List &L, ElemType item, int pos) {
    if (pos < -1 || pos > L.size + 1) {
        cout << "pos值无效!" << endl;
        return false;
    }
    int i;
    if (pos == 0) {
        for (i = 0; i < L.size; i++) {
            if (item < L.list[i])
                break;
        }
        pos = i + 1;
    } else if (pos == -1) {
        pos = L.size + 1;
    }
    if (L.size == L.MaxSize) {
        int k = sizeof(ElemType);
        L.list = (ElemType *) realloc(L.list, 2 * L.MaxSize * k);
        if (L.list == NULL) {
            cout << "动态可分配的存储空间用完，退出运行!" << endl;
            exit(1);
        }
        L.MaxSize = 2 * L.MaxSize;
    }
    for (i = L.size - 1; i >= pos - 1; i--)
        L.list[i + 1] = L.list[i];
    L.list[pos - 1] = item;
    L.size++;
    return true;
}

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
            if (item == L.list[i])
                break;
        }

        if (i == L.size)
            return false;
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
        int k = sizeof(ElemType);
        L.list = (ElemType *) realloc(L.list, L.MaxSize * k / 2);
        L.MaxSize = L.MaxSize / 2;
    }
    return true;
}

void SortList(List &L) {
    int i, j;
    ElemType x;
    for (i = 1; i < L.size; i++) {
        x = L.list[i];
        for (j = i - 1; j >= 0; j--)
            if (x < L.list[j])
                L.list[j + 1] = L.list[j];
            else
                break;
        L.list[j + 1] = x;
    }
}


