//
// Created by DaiZhe on 2018/5/22.
//
#include<iostream>

using namespace std;

// 通用元素类型声明
typedef int ElemType;

struct BTreeNode {
    ElemType data;      //值域
    BTreeNode *left;    //指向左孩子结点的指针域
    BTreeNode *right;   //指向右孩子结点的指针域
};

//1. 查找算法-递归
bool Find(BTreeNode *BST, ElemType &item) {
    if (BST == NULL) return false;      //查找失败返回假
    else {
        if (item == BST->data) {        //若查找成功则带回元素值并返回真
            item = BST->data;
            return true;
        } else if (item < BST->data)    //向左子树继续查找
            return Find(BST->left, item);
        else                            //向右子树继续查找
            return Find(BST->right, item);
    }
}

//1'.查找算法-非递归
bool Find1(BTreeNode *BST, ElemType &item) {
    while (BST != NULL) {
        if (item == BST->data) {
            item = BST->data;
            return true;
        } else if (item < BST->data) {
            BST = BST->left;
        } else {
            BST = BST->right;
        }
    }
    return false;
}

//2. 更新算法-非递归
bool Update1(BTreeNode *BST, const ElemType &item) {
    while (BST != NULL) {               //循环查找待更新的结点
        if (item == BST->data) {        //进行更新并返回真
            BST->data = item;
            return true;
        } else if (item < BST->data) {   //向左子树查找
            BST = BST->left;
        } else {
            BST = BST->right;           //向右子树查找
        }
    }
    return false;                       //没有待更新的结点，返回假
}

//3. 插入算法-递归
void Insert(BTreeNode *&BST, const ElemType &item) {
    if (BST == NULL) {              //把值为item的新结点链接到已找到的插入位置
        BTreeNode *p = new BTreeNode;
        p->data = item;
        p->left = p->right = NULL;
        BST = p;
    } else if (item < BST->data) {
        Insert(BST->left, item);    //向左子树中插入元素
    } else {
        Insert(BST->right, item);   //向右子树中插入元素
    }
}

//3'.插入算法-非递归
void Insert1(BTreeNode *&BST, const ElemType &item) {
    //为插入新元素寻找插入位置，定义指针t并指向当前待比较的结点，初始
    //指向树根结点，定义指针parent指向t结点的双亲结点，初始为NULL
    BTreeNode *t = BST, *parent = NULL;
    while (t != NULL) {
        parent = t;
        if (item < t->data) t = t->left;
        else t = t->right;
    }
    //建立值为item，左、右指针域为空的新结点
    BTreeNode *p = new BTreeNode;
    p->data = item;
    p->left = p->right = NULL;
    //将新结点插入到二叉搜索树BST中
    if (parent == NULL){
        BST = p;
    }else if (item < parent->data){
        parent->left = p;
    }else{
        parent->right = p;
    }
}

//4. 建立二叉搜索树
void CreateBSTree(BTreeNode *&BST, ElemType a[], int n)
//利用数组中的n个元素建立二叉搜索树的算法
{
    BST = NULL;   //从空树开始建立
    for (int i = 0; i < n; i++)
        Insert(BST, a[i]);
}

//5. 删除算法
bool Delete(BTreeNode *&BST, const ElemType &item) {
    if (BST == NULL) return false;
    if (item < BST->data) return Delete(BST->left, item);
    if (item > BST->data) return Delete(BST->right, item);
    BTreeNode *temp = BST;
    if (BST->left == NULL) {
        BST = BST->right;
        delete temp;
        return true;
    } else if (BST->right == NULL) {
        BST = BST->left;
        delete temp;
        return true;
    } else {
        if (BST->left->right == NULL) {
            BST->data = BST->left->data;
            return Delete(BST->left, BST->left->data);
        } else {
            BTreeNode *p1 = BST, *p2 = BST->left;
            while (p2->right != NULL) {
                p1 = p2;
                p2 = p2->right;
            }
            BST->data = p2->data;
            return Delete(p1->right, p2->data);
        }
    }
}
