//
// Created by DaiZhe on 2018/5/24.
// 哈夫曼树
//
#include<iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

struct BTreeNode {
    ElemType data;      //值域
    float weight;
    BTreeNode *left;    //指向左孩子结点的指针域
    BTreeNode *right;   //指向右孩子结点的指针域
};

//1. 构造哈夫曼树的算法
BTreeNode *CreateHuffman(ElemType a[], int n)
//根据数组a中n个权值建立一棵哈夫曼树，返回树根指针
{
    BTreeNode **b, *q;
    //动态分配一个由b指向的指针数组
    b = new BTreeNode *[n];
    int i, j;
    //初始化b指针数组，使每个指针元素指向a数组中对应元素的结点
    for (i = 0; i < n; i++) {
        b[i] = new BTreeNode;
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    //进行n-1次循环建立哈夫曼树
    for (i = 1; i < n; i++) {
        //用k1表示森林中具有最小权值的树根结点的下标，
        //用k2表示森林中具有次最小权值的树根结点的下标
        int k1 = -1, k2;
        //让k1初始指向森林中第一棵树，k2初始指向森林中第二棵树
        for (j = 0; j < n; j++) {
            if (b[j] != NULL && k1 == -1) {
                k1 = j;
                continue;
            }
            if (b[j] != NULL) {
                k2 = j;
                break;
            }
        }
        //从当前森林中求出最小权值树和次最小权值树
        for (j = k2; j < n; j++) {
            if (b[j] != NULL) {
                if (b[j]->data < b[k1]->data) {
                    k2 = k1;
                    k1 = j;
                } else if (b[j]->data < b[k2]->data) k2 = j;
            }
        }
        //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
        q = new BTreeNode;
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];
        //将指向新树的指针赋给b指针数组中k1位置，k2位置置为空
        b[k1] = q;
        b[k2] = NULL;
    }
    //删除动态建立的数组b
    delete[]b;
    //返回整个哈夫曼树的树根指针
    return q;
}

//2. 根据哈夫曼树求带权路径长度的算法。
ElemType WeightPathLength(BTreeNode *FBT, int len)
//根据FBT指针所指向的哈夫曼树求出带权路径长度，len初值为0
{
    if (FBT == NULL) return 0;  //空树则返回0
    else {
        //访问到叶子结点时返回该结点的带权路径长度，其中值参len
        //保存当前被访问结点的路径长度
        if (FBT->left == NULL && FBT->right == NULL) {
            return FBT->data * len;
        }
            //访问到非叶子结点时进行递归调用，返回左、右子树的带权
            //路径长度之和，向下深入一层时len值增1
        else {
            return WeightPathLength(FBT->left, len + 1) + WeightPathLength(FBT->right, len + 1);
        }
    }
}

//3. 求哈夫曼树编码的算法。
void HuffManCoding(BTreeNode *FBT, int len)
//根据FBT指针所指向的哈夫曼树输出每个叶子的编码，len初值为0
{
    // static 数组只初始化一次，递归时每层函数访问的都是同一个数组
    static int a[10];//数组的长度要至少等于哈夫曼树的深度减1
    int ccc=10;
    if (FBT != NULL) {
        //访问到叶子结点时输出其保存在数组a中的0和1序列编码
        if (FBT->left == NULL && FBT->right == NULL) {
            cout << "结点权值为" << FBT->data << "的编码：";
            for (int i = 0; i < len; i++) cout << a[i] << ' ';
            cout << endl;
        }
            //访问到非叶子结点时分别向左、右子树进行递归调用，并分别把分支上
            //的0、1编码保存到数组a的对应元素中，向下深入一层时len值增1
        else {
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

void PrintBTree(BTreeNode *BT) {            //输出二叉树的广义表表示
    if (BT != NULL) {                       //树为空时结束递归，否则执行如下操作
        cout << BT->data;                   //输出根结点的值
        if (BT->left != NULL || BT->right != NULL) {
            cout << '(';                    //输出左括号
            PrintBTree(BT->left);           //输出左子树
            if (BT->right != NULL)
                cout << ',';                //若右子树不为空则首先输出逗号分隔符
            PrintBTree(BT->right);          //输出右子树
            cout << ')';                    //输出右括号
        }
    }
}

void ClearBTree(BTreeNode *&BT) {
    if (BT != NULL) {
        ClearBTree(BT->left);           //删除左子树
        ClearBTree(BT->right);          //删除右子树
        delete BT;                      //释放根结点
        BT = NULL;                      //置根指针为空
    }
}

int main() {
    int n, i;
    BTreeNode *fbt = NULL;
    cout << "输入待构造哈夫曼树中带权叶子节点数n:";
    cin >> n;
    ElemType *a = new ElemType[n];
    cout << "输入" << n << "个整数作为权值:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fbt = CreateHuffman(a, n);
    cout << "广义表形式的哈夫曼树：" << endl;
    PrintBTree(fbt);
    cout << endl;
    cout << "哈夫曼树的权：";
    cout << WeightPathLength(fbt, 0) << endl;
    cout << "每个叶子的哈夫曼编码：" << endl;
    HuffManCoding(fbt, 0);
    ClearBTree(fbt);
    return 0;
}