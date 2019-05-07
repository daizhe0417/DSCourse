//
// Created by DaiZhe on 2018/5/21.
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

//1. 初始化二叉树
void InitBTree(BTreeNode *&BT)
//初始化二叉树，即把树根指针置空
{
    BT = NULL;
}

//2. 建立二叉树
void CreateBTree(BTreeNode *&BT, char *a)
//根据字符串a所给出的用广义表表示的二叉树建立对应的存储结构
{
    const int MaxSize = 10;     //栈数组长度要大于等于二叉树的深度减1
    BTreeNode *s[MaxSize];      //s数组作为存储根结点指针的栈使用
    int top = -1;               //top作为栈顶指针，初值为-1，表示空栈
    BT = NULL;                  //把树根指针置为空，即从空树开始
    BTreeNode *p;               //定义p为指向二叉树结点的指针
    int k;                      //用k作为处理结点的左子树和右子树的标记，
    //k=1处理左子树，k=2处理右子树
    int i = 0;                  //用i扫描数组a中存储的二叉树广义表字符串
    while (a[i]) {              //每循环一次处理一个字符，直到扫描到字符串结束符'\0'为止
        switch (a[i]) {
            case ' ':           //对空格不作任何处理
                break;
            case '(':
                if (top == MaxSize - 1) {
                    cout << "栈空间太小，请增加MaxSize的值!" << endl;
                    exit(1);
                }
                top++;
                s[top] = p;
                k = 1;
                break;
            case ')':
                if (top == -1) {
                    cout << "二叉树广义表字符串错!" << endl;
                    exit(1);
                }
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:   //只可能为字符，即结点值
                p = new BTreeNode;
                p->data = a[i];
                p->left = p->right = NULL;
                if (BT == NULL) {
                    BT = p;   //作为根结点插入
                } else {
                    if (k == 1) {
                        s[top]->left = p;       //作为左孩子插入
                    } else {
                        s[top]->right = p;      //作为右孩子插入
                    }
                }
        }  //switch end
        i++;  //为扫描下一个字符修改i值
    }
}

//3.  检查二叉树是否为空
bool EmptyBTree(BTreeNode *BT) {
    return BT == NULL;
}

//4. 求二叉树深度
int DepthBTree(BTreeNode *BT) {      //求由BT指针指向的一棵二叉树的深度
    if (BT == NULL)
        return 0;  //对于空树，返回0并结束递归
    else {
        int dep1 = DepthBTree(BT->left);      //计算左子树的深度
        int dep2 = DepthBTree(BT->right);     //计算右子树的深度
        if (dep1 > dep2)                       //返回树的深度
            return dep1 + 1;
        else
            return dep2 + 1;
    }
}

//5. 从二叉树中查找值为x的结点，若存在则由x带回完整值并返回真，否则返回假
bool FindBTree(BTreeNode *BT, ElemType &x) {
    if (BT == NULL) return false;      //树为空返回假
    else {
        if (BT->data == x) { //树根结点的值等于x则由x带回结点值并返回真
            x = BT->data;
            return true;
        } else {
            //向左子树查找若成功则继续返回真
            if (FindBTree(BT->left, x)) return true;
            //向右子树查找若成功则继续返回真
            if (FindBTree(BT->right, x)) return true;
            //左、右子树查找均失败则返回假
            return false;
        }
    }
}

//6. 输出二叉树
void PrintBTree(BTreeNode *BT) {       //输出二叉树的广义表表示
    if (BT != NULL) {                  //树为空时结束递归，否则执行如下操作
        cout << BT->data;             //输出根结点的值
        if (BT->left != NULL || BT->right != NULL) {
            cout << '(';              //输出左括号
            PrintBTree(BT->left);   //输出左子树
            if (BT->right != NULL)
                cout << ',';    //若右子树不为空则首先输出逗号分隔符
            PrintBTree(BT->right);  //输出右子树
            cout << ')';              //输出右括号
        }
    }
}

//7．清除一棵二叉树，使之变为一棵空树
void ClearBTree(BTreeNode *&BT) {
    if (BT != NULL) {
        ClearBTree(BT->left);           //删除左子树
        ClearBTree(BT->right);          //删除右子树
        delete BT;                      //释放根结点
        BT = NULL;                      //置根指针为空
    }
}

//8.前序遍历算法
void PreOrder(BTreeNode *BT) {
    if (BT != NULL) {
        cout << BT->data << ' ';    //访问根结点
        PreOrder(BT->left);         //前序遍历左子树
        PreOrder(BT->right);        //前序遍历右子树
    }
}

//9.中序遍历算法
void InOrder(BTreeNode *BT) {
    if (BT != NULL) {
        InOrder(BT->left);          //中序遍历左子树
        cout << BT->data << ' ';    //访问根结点
        InOrder(BT->right);         //中序遍历右子树
    }
}

//10.后序遍历算法
void PostOrder(BTreeNode *BT) {
    if (BT != NULL) {
        PostOrder(BT->left);        //后序遍历左子树
        PostOrder(BT->right);       //后序遍历右子树
        cout << BT->data << ' ';    //访问根结点
    }
}

//11.按层遍历算法
//此算法为一个非递归算法，具体描述如下：
void LevelOrder(BTreeNode *BT)              //按层遍历由BT指针所指向的二叉树
{
    const int MaxSize = 30;                 //定义用于存储队列的数组长度
    BTreeNode *q[MaxSize];                  //定义队列所使用的数组空间
    int front = 0, rear = 0;                //定义队首指针和队尾指针，初始为空队
    BTreeNode *p;
    if (BT != NULL) {                       //将树根指针进队
        rear = (rear + 1) % MaxSize;
        q[rear] = BT;
    }
    while (front != rear) {                 //当队列非空时执行循环
        front = (front + 1) % MaxSize;      //使队首指针指向队首元素
        p = q[front];                       //删除队首元素
        cout << p->data << ' ';             //输出队首元素所指结点的值
        if (p->left != NULL) {              //若存在左孩子，则左孩子结点指针进队
            rear = (rear + 1) % MaxSize;
            q[rear] = p->left;
        }
        if (p->right != NULL) {             //若存在右孩子，则右孩子结点指针进队
            rear = (rear + 1) % MaxSize;
            q[rear] = p->right;
        }
    } //while end
}

int main() {
    BTreeNode *bt;
    InitBTree(bt);
    char b[50];
    cout << "输入广义表表示的二叉树字符串：" << endl;
    cin.getline(b, sizeof(b));
    CreateBTree(bt, b);
    PrintBTree(bt);

    cout << "前序遍历：";
    PreOrder(bt);
    cout << endl;

    cout << "中序遍历：";
    InOrder(bt);
    cout << endl;

    cout << "后序遍历：";
    PostOrder(bt);
    cout << endl;

    cout << "按层遍历：";
    LevelOrder(bt);
    cout << endl;

    ElemType x;
    cout << "输入一个待查字符：" << endl;
    cin >> x;
    if (FindBTree(bt, x)) {
        cout << "找到" << x << endl;
    } else {
        cout << "未找到" << endl;
    }

    cout << "深度：";
    cout << DepthBTree(bt) << endl;
    return 0;
}