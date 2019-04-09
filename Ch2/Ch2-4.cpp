//
// Created by DaiZhe on 2018/4/20.
//

#include<iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

// 单链表结点
struct LNode {
    ElemType data;
    LNode *next;
};

// 双链表结点
struct DNode {
    ElemType data;
    DNode *pre;
    DNode *next;
};


////////////////////////////////////////////////////////////////////////////
//线性表的单链表存储函数声明部分
void InitList(LNode *&HL);                              //1. 初始化单链表
void ClearList(LNode *&HL);

int LenthList(LNode *HL);

bool EmptyList(LNode *HL);

ElemType GetList(LNode *HL, int pos);

void TraverseList(LNode *HL);

bool FindList(LNode *HL, ElemType &item);

bool UpdateList(LNode *HL, const ElemType &item);

bool InsertList(LNode *&HL, ElemType item, int pos);

bool Insert(LNode *&HL, ElemType item, int pos);

bool DeleteList(LNode *&HL, ElemType &item, int pos);//从L删除元素
void SortList(LNode *&HL);

void Sort(LNode *&HL);
//线性表的单链表存储函数声明部分
////////////////////////////////////////////////////////////////////////////

int main() {
    ///////////////////////函数中使用到的变量定义/////////////////////////////
    //LNode *p, *q, *p1;
    //int len;//用来接收用函数返回的单链表长度
    //int pos;//指定位置
    //ElemType kkk;
    //bool is_empty, is_find, is_update, is_insert, is_delete;
    //ElemType pos_data;//用来接收从单链表返回的某结点的值
    /////////////////////////////////////////////////////////////////////////
    //
    //InitList(p);//初始化单链表p
    //p1 = p = new LNode;
    //int MaxSize;
    //cout << "请输入单链表长度：";
    //cin >> MaxSize;
    //cout << "您输入的单链表长度为：" << MaxSize << endl;
    //cout << "请依次输入结点值：" << endl;
    //for (int i = 1; i <= MaxSize; i++) {
    //    q = new LNode;
    //    cout << "请输入第" << i << "个结点：";
    //    cin >> q->data;
    //    p->next = q;
    //    p = q;
    //}
    //p->next = NULL;
    //p = p1->next;
    //
    //
    ////ClearList(p);//清空单链表
    ////cout<<p<<" "<<p->data<<endl;
    //
    //len = LenthList(p);//返回单链表长度
    //cout << "单链表长度为：" << len << endl;
    //
    //is_empty = EmptyList(p);//判断单链表是否为空
    //if (is_empty == 0)
    //    cout << "单链表非空！" << endl;
    //else
    //    cout << "单链表为空！" << endl;
    //
    //
    //cout << "请输入指定位置，以返回结点值：";
    //cin >> pos;
    //cout << endl;
    //pos_data = GetList(p, pos);//返回指定位置的结点的值
    //cout << "单链表第" << pos << "个结点值为：" << pos_data << endl;
    //
    //TraverseList(p);//遍历单链表
    //
    //cout << "请输入指定元素，以判断单链表中是否存在该值结点：";
    //cin >> kkk;
    //cout << endl;
    //is_find = FindList(p, kkk);//从单链表中查找指定的元素是否存在
    //if (is_find == 0)
    //    cout << "单链表不存在该值结点！" << endl;
    //else
    //    cout << "单链表存在该值结点！" << endl;
    //
    //cout << "请输入要插入的元素：";
    //cin >> kkk;
    //cout << endl;
    //cout << "请输入要插入的位置：";
    //cin >> pos;
    //cout << endl;
    //is_insert = InsertList(p, kkk, pos);//向单链表的指定位置插入结点
    //if (is_insert == 0)
    //    cout << "插入结点失败！" << endl;
    //else
    //    cout << "插入结点成功！" << endl;
    //TraverseList(p);
    //
    ////is_delete=DeleteList(p,kkk,3);//从L删除元素
    ////TraverseList(p);
    //
    //SortList(p);//单链表从小到大排序
    //TraverseList(p);
    LNode *p = NULL;
    InitList(p);
    cout << "第一次插入元素" << endl;
    //InsertList(p, 1, 10);
    TraverseList(p);
    cout << "第二次插入元素" << endl;
    InsertList(p, 3, 0);
    TraverseList(p);
    cout << "第三次插入元素" << endl;
    Insert(p, 9, 1);
    Insert(p, 6, -1);
    TraverseList(p);
    cout << "第四次插入元素" << endl;
    Insert(p, 7, -1);
    TraverseList(p);
    cout << "第五次插入元素" << endl;
    Insert(p, 5, 12);
    TraverseList(p);
    Sort(p);
    TraverseList(p);
    Insert(p, 2, 0);
    TraverseList(p);
    Insert(p, 1, 0);
    TraverseList(p);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
//线性表的单链表存储函数定义部分


//1. 初始化单链表
void InitList(LNode *&HL) {
    // 直接将HL赋值为NULL，可能导致内存泄露
    // 当HL指向一个已经存在的链表时，HL=NULL将导致链表的元素成为无法访问也未释放的内存碎片
    if (HL != NULL) {
        cout << "线性表已存在，不再重复初始化，如要清空线性表，请调用ClearList()方法" << endl;
        return;
    }
    HL = NULL;
}

//2.  删除单链表中的所有结点，使之成为一个空表
void ClearList(LNode *&HL) {
    LNode *currP;
    LNode *nextP;
    currP = HL;
    while (currP != NULL) {
        nextP = currP->next;
        delete currP;
        currP = nextP;
    }
    HL = NULL;
}

//3.  得到单链表的长度
int LenthList(LNode *HL) {
    int i = 0;
    while (HL != NULL) {
        i++;
        HL = HL->next;
    }
    return i;
}

//4.  检查单链表是否为空
bool EmptyList(LNode *HL) {
    return HL == NULL;
}

//5. 得到单链表中第pos个结点中的元素
ElemType GetList(LNode *HL, int pos) {
    if (HL == NULL) {
        cerr << "链表HL为空" << endl;
        exit(1);
    }
    if (pos < 1) {              //pos值有错，退出运行
        cerr << "pos超出范围!" << endl;
        exit(1);
    }
    int i = 0;                  //统计已遍历的结点数，i初值为0
    while (HL != NULL) {        //遍历到第pos个结点或表为空时止
        i++;
        if (i == pos) {
            break;
        }
        HL = HL->next;
    }
    if (HL != NULL) {             //返回结点值
        return HL->data;
    } else {
        cerr << "pos超出范围!" << endl;
        exit(1);
    }
}

//6. 遍历一个单链表
void TraverseList(LNode *HL) {
    while (HL != NULL) {        //从表头开始依次输出每个结点的值
        cout << HL->data << " ";
        HL = HL->next;
    }
    cout << endl;
}

//7. 从单链表中查找具有给定值的第一个元素
bool FindList(LNode *HL, ElemType &item) {
    while (HL != NULL) {
        if (HL->data == item) { //查找成功由item带回完整值
            item = HL->data;
            return true;
        } else {
            HL = HL->next;      //HL指向后继结点
        }
    }
    return false;
}

//8. 更新单链表中具有给定值的第一个元素
bool UpdateList(LNode *HL, const ElemType &item) {
    while (HL != NULL) {        //遍历链表，查找元素
        if (HL->data == item) {
            break;
        } else {
            HL = HL->next;
        }
    }
    if (HL == NULL) {
        return false;           //没有找到要更新的元素，返回假
    } else {                    //更新元素
        HL->data = item;
        return true;
    }
}

// 插入结点操作
bool Insert(LNode *&HL, ElemType item, int pos) {
    if (pos < -1) {
        cout << "pos值无效!" << endl;
        return false;
    }
    //为item元素建立新结点
    LNode *newElem;
    newElem = new LNode;
    newElem->data = item;
    newElem->next = NULL;

    LNode *cp = HL;

    if (pos == 0) {
        while (cp && cp->next) {
            if (cp->data > newElem->data || cp->next->data > newElem->data) {
                break;
            }
            cp = cp->next;
        }
    } else if (pos == -1) {
        while (cp && cp->next) {
            cp = cp->next;
        }
    } else {
        int i = 0;
        while (cp && (i < pos - 1)) {
            i++;
            cp = cp->next;
        }
        if (cp == NULL && i < pos - 1) {
            cout << "插入元素" << item << "时pos" << pos << "超出范围" << endl;
            return false;
        }
    }
    // 头指针为NULL，链表为空，头指针直接指向新结点
    if (HL == NULL) {
        HL = newElem;
        return true;
    }
    newElem->next = cp->next;
    cp->next = newElem;
    return true;
}

//9. 向单链表中按给定条件插入一个元素
bool InsertList(LNode *&HL, ElemType item, int pos) {
    //pos值小于-1返回假
    if (pos < -1) {
        cout << "pos值无效!" << endl;
        return false;
    }
    //为item元素建立新结点
    LNode *newptr;
    newptr = new LNode;
    newptr->data = item;
    //寻找新结点的插入位置
    LNode *cp = HL;    //用cp指向当前结点(即待查结点),初始指向表头
    LNode *ap = NULL;  //用ap(ahead pointer)指向cp的前驱结点,初始为空
    if (pos == 0) {     //按值寻找插入位置
        while (cp != NULL) {
            if (item < cp->data) { //找到新元素插入位置,退出循环
                break;
            } else {       //ap和cp指针均后移，实现顺序向后比较
                ap = cp;
                cp = cp->next;
            }
        }
    } else if (pos == -1) {   //查找表尾位置
        while (cp != NULL) {
            ap = cp;
            cp = cp->next;
        }
    } else {             //按序号pos的值寻找插入位置
        int i = 0;
        while (cp != NULL) {
            i++;
            if (i == pos) break;  //找到新元素插入位置,退出循环
            else {             //ap和cp指针均后移，实现顺序向后比较
                ap = cp;
                cp = cp->next;
            }
        }
        if (cp == NULL && pos > i + 1) {
            cout << "pos值超出单链表长度加1!" << endl;
            return false;
        }
    }
    //完成新结点插入操作
    if (ap == NULL) {  //把新结点插入到表头
        newptr->next = HL;
        HL = newptr;
    } else {
        //把新结点插入到非表头位置，即插入到ap和cp结点之间
        newptr->next = cp;  //cp指针也可能为空，此时为表尾
        ap->next = newptr;
    }
    return true;
}

//10. 从单链表中删除符合给定条件的第一个元素
bool DeleteList(LNode *&HL, ElemType &item, int pos)//从L删除元素
{
    //单链表为空，无法删除，返回假
    if (HL == NULL) {
        cerr << "单链表为空，删除操作无效!" << endl;
        return false;
    }
    //pos值小于-1返回假
    if (pos < -1) {
        cout << "pos值无效!" << endl;
        return false;
    }
    //寻找被删除的元素结点
    LNode *cp = HL;    //用cp指向当前结点(即待查结点),初始指表头
    LNode *ap = NULL;  //用ap(ahead pointer)指向cp的前驱结点,初始为空
    if (pos == 0) {  //按值查找被删除结点
        while (cp != NULL) {
            if (item == cp->data) break;  //找到被删除结点cp,退出循环
            else {       //ap和cp指针均后移，实现顺序向后比较
                ap = cp;
                cp = cp->next;
            }
        }
        if (cp == NULL) {
            cout << "单链表中没有相应的结点可删除!" << endl;
            return false;
        }
    } else if (pos == -1)          //查找表尾结点
        while (cp->next != NULL) {
            ap = cp;
            cp = cp->next;
        }
    else {                    //按序号查找结点位置
        int i = 0;
        while (cp != NULL) {
            i++;
            if (i == pos) break;  //找到被删除结点cp,退出循环
            else {             //ap和cp指针均后移，实现顺序向后比较
                ap = cp;
                cp = cp->next;
            }
        }
        if (cp == NULL) {
            cout << "pos值无效!" << endl;
            return false;
        }
    }
    //删除cp所指向的结点
    if (ap == NULL) HL = HL->next;   //删除表头结点
    else ap->next = cp->next;     //删除非表头结点，也可以是表尾结点
    //收回被删除结点的存储空间
    delete cp;
    //删除成功返回真
    return true;
}

void Sort(LNode *&HL) {
    LNode *SL = NULL;
    InitList(SL);
    LNode *cp = HL;
    while (cp) {
        Insert(SL, cp->data, 0);
        cp = cp->next;
    }
    ClearList(HL);
    HL = SL;
}

//11.  对单链表进行数据排序
void SortList(LNode *&HL) {
    //建立一个反映排序结果的新单链表并初始化为空
    LNode *SL;
    InitList(SL);
    //从待排序的HL单链表中依次取出每个结点，按值插入到新单链表中
    LNode *r = HL;//r指向待取出排序的一个结点，初始为HL表头结点
    while (r != NULL) {
        //为新插入的r结点在SL中顺序查找出插入位置
        LNode *t = r->next;     //t指向r的后继结点
        LNode *cp = SL;         //用cp初始指向SL单链表的表头
        LNode *ap = NULL;       //用ap指向cp的前驱结点，初始为空
        while (cp != NULL) {
            if (r->data < cp->data) break;//找到被插入点，退出循环
            else {                      //ap和cp指针均后移，实现顺序向后比较
                ap = cp;
                cp = cp->next;
            }
        }
        //实现插入操作
        if (ap == NULL) {               //把r结点插入到表头
            r->next = SL;
            SL = r;
        } else {                     //把r结点插入ap和cp结点之间
            r->next = cp;           //cp可能为空，则r成为SL的表尾
            ap->next = r;
        }
        //使r指向原单链表的下一个结点
        r = t;
    }
    //由引用参数带回新单链表的表头指针
    HL = SL;
}

//线性表的单链表存储函数定义部分
//////////////////////////////////////////////////////////////////////////////
//12.  对单链表进行数据排序
void SortList2(LNode *&HL) {
    //建立一个反映排序结果的新单链表并初始化为空
    LNode *SL;
    InitList(SL);
    //从待排序的HL单链表中依次取出每个结点，按值插入到新单链表中
    LNode *r = HL;//r指向待取出排序的一个结点，初始为HL表头结点
    while (r != NULL) {
        InsertList(SL, r->data, 0);
        r = r->next;
    }
    delete HL;
    //由引用参数带回新单链表的表头指针
    HL = SL;
}
