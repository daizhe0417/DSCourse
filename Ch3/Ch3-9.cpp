//
// Created by DaiZhe on 2018/5/14.
//
#include <iostream>
#include <stdlib.h>
#include<ctime>
using namespace std;

//定义sitem结构类型，用来存储在迷宫中位置。
struct sitem {
    int i;//行标
    int j;//列标
};

typedef sitem ElemType;

//定义Stack栈，用来存储走过的路径，栈中数据类型为上面所定义的sitem结构类型
struct Stack {
    sitem *stack;
    int top;
    int MaxSize;
};

/////////////栈的基本操作///////////////
void InitStack(Stack &S);

void Push(Stack &S, ElemType item);

ElemType Pop(Stack &S);

ElemType Peek(Stack &S);

bool EmptyStack(Stack &S);

void ClearStack(Stack &S);
///////////////////////////////////////

void TIMEDELAY()             //时间延迟函数，这样动态实现时才可以看清
{
    clock_t time;
    time = 500 + clock();
    while (time > clock());
}

const int m = 6, n = 8;
int info = 0;
//以下为系统默认矩阵maze和输出矩阵kkk
int d_maze[
        m + 2][n + 2] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 0, 0, 1, 1, 0, 1, 0, 1, 1},
                         {1, 1, 0, 0, 1, 1, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                         {1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
//int d_kkk[m+2][n+2]={{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,1,0,1,0,1,1},{1,1,0,0,1,1,0,0,0,1},{1,0,0,0,0,0,0,1,1,1},{1,1,1,0,1,1,0,0,0,1},{1,0,0,0,0,0,1,0,1,1},{1,1,0,1,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};

int mark[m + 2][n + 2];//用来标识当前位置是否走过
int moveddd[4][2] = {{0,  1},
                  {1,  0},
                  {0,  -1},
                  {-1, 0}}; //顺时针移动方向

//////////////主函数定义//////////////////////
int main() {
    int maze[m + 2][n + 2];
    int kkk[m + 2][n + 2];
    srand((unsigned int) time((time_t *) NULL));
    int user;
    rev:
    system("cls");//清屏
    system("clear");
    if (info == 1)
        cout << "输入错误！请重新输入！" << endl;
    cout << "★★★★★★★★★★★★★★" << endl;
    cout << "★                        ★" << endl;
    cout << "★     1.使用默认迷宫     ★" << endl;
    cout << "★     2.使用随机迷宫     ★" << endl;
    cout << "★                        ★" << endl;
    cout << "★★★★★★★★★★★★★★" << endl;

    cout << "请输入选项:";
    cin >> user;
    if (user == 1) {
        for (int kk1 = 0; kk1 < m + 2; kk1++)
            for (int kk2 = 0; kk2 < n + 2; kk2++) {
                maze[kk1][kk2] = d_maze[kk1][kk2];
                kkk[kk1][kk2] = d_maze[kk1][kk2];
            }
    } else if (user == 2) {
        for (int kk1 = 0; kk1 < m + 2; kk1++) //先将maze和kkk全赋值为1，即全看做为不可通路
            for (int kk2 = 0; kk2 < n + 2; kk2++) {
                maze[kk1][kk2] = 1;
                kkk[kk1][kk2] = 1;
            }
        for (int q1 = 1; q1 <= 6; q1++)//将除了四周之外的每个位置随机赋值为0或1
            for (int q2 = 1; q2 <= 8; q2++) {
                maze[q1][q2] = rand() % 2;
                kkk[q1][q2] = maze[q1][q2];
            }
        if (maze[1][1] == 1) {   //避免出现入口为墙的情况
            maze[1][1] = 0;
            kkk[1][1] = 0;
        }
    } else {
        info = 1;//如果输入的不是1或2则将info赋值为1，标识输入错误
        goto rev;//跳转
    }

    system("cls");//清屏
    system("clear");
    // 输出迷宫初始状态
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            int code = maze[i][j];
            if (code == 1)
                cout << "●";
            else
                cout << "○";
        }
        cout << endl;
    }
    if (user == 1)
        cout << "以上为默认迷宫" << endl;
    else
        cout << "以上为随机迷宫" << endl;

    int start;
    isstart:
    cout << "如果要开始迷宫演示，请输入1！" << endl;
    cout << "如果要重新生成迷宫，请输入2！" << endl;
    cin >> start;
    if (start == 2)
        goto rev;

    //给mark数组赋初值为0
    for (int k1 = 0; k1 < m + 2; k1++)
        for (int k2 = 0; k2 < n + 2; k2++)
            mark[k1][k2] = 0;

    Stack path;//定义path栈用来保存走过的路径
    InitStack(path);
    mark[1][1] = 1;
    kkk[1][1] = 2;
    sitem item;
    item.i = 1;
    item.j = 1;
    Push(path, item);//把出发点压入栈

    int x = 1;//用来表示当前位置行标
    int y = 1;//用来表示当前位置列标
    int g, h;//用来表示下一个位置行标、列标

    while ((x != m) || (y != n)) {
        int direct = 0;//探路的初始方向为右
        while (direct < 4)//顺时针探路
        {
            int stop = 0;//用来表示此方向是否为通路
            g = x + moveddd[direct][0];
            h = y + moveddd[direct][1]; //按照方向下探一步
            if ((maze[g][h] == 0) && (mark[g][h] == 0)) {
                mark[g][h] = 1;
                kkk[g][h] = 2;//用来标识此位置已经访问过，输出时用☆表示
                item.i = g;
                item.j = h;
                Push(path, item);

                ////////输出迷宫当前探路状态//////
                TIMEDELAY();//设置时间间隔，避免刷屏太快
                system("cls");
                system("clear");
                for (int t1 = 0; t1 < 8; t1++) {
                    for (int t2 = 0; t2 < 10; t2++) {
                        int code = kkk[t1][t2];
                        if (code == 1)
                            cout << "●";
                        else if (code == 0)
                            cout << "○";
                        else if (code == 2)
                            cout << "☆";
                        else
                            cout << "♀";
                    }
                    cout << endl;
                }
                ////////输出迷宫当前探路状态//////

                stop = 1;
            }
            if (stop == 1)
                break;
            else
                direct++;
        }
        x = g;
        y = h;

        if (direct == 4) {
            sitem old, topitem;
            old = Pop(path);
            int xx, yy;
            xx = old.i;
            yy = old.j;
            kkk[xx][yy] = 3;////用来标识此位置已经访问过，且因向下无法走通而回车一步，输出时用♀表示

            ////////输出迷宫当前探路状态//////
            TIMEDELAY();//设置时间间隔，避免刷屏太快
            system("cls");
            system("clear");
            for (int tt1 = 0; tt1 < 8; tt1++) {
                for (int tt2 = 0; tt2 < 10; tt2++) {
                    int code = kkk[tt1][tt2];
                    if (code == 1)
                        cout << "●";
                    else if (code == 0)
                        cout << "○";
                    else if (code == 2)
                        cout << "☆";
                    else
                        cout << "♀";
                }
                cout << endl;
            }
            ////////输出迷宫当前探路状态//////
            topitem = Peek(path);
            x = topitem.i;
            y = topitem.j;

        }
    }
    cout << "成功找到通路！" << endl;
}

///////////////////////栈的操作函数///////////////////////////
//1. 初始化栈
void InitStack(Stack &S) {
    //初始设置栈空间大小为10
    S.MaxSize = 100;
    //动态存储空间分配
    S.stack = new ElemType[S.MaxSize];
    if (!S.stack) {
        cerr << "动态存储分配失败！" << endl;
        exit(1);
    }
    //初始置栈为空
    S.top = -1;
}

//2. 元素item进栈，即插入到栈顶
void Push(Stack &S, ElemType item) {
    //若栈空间用完则自动扩大2倍空间，原有栈内容不变
    if (S.top == S.MaxSize - 1) {
        int k = sizeof(ElemType);  //计算每个元素存储空间的长度
        S.stack = (ElemType *) realloc(S.stack, 2 * S.MaxSize * k);
        S.MaxSize = 2 * S.MaxSize;   //把栈空间大小修改为新的长度
    }
    //栈顶指针后移一个位置
    S.top++;
    //将新元素插入到栈顶
    S.stack[S.top] = item;
}

//3. 删除栈顶元素并返回
ElemType Pop(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "栈空，退出运行!" << endl;
        exit(1);
    }
    //栈顶指针减1表示退栈
    S.top--;
    //返回原栈顶元素的值
    return S.stack[S.top + 1];
}

//4. 读取栈顶元素的值
ElemType Peek(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "寻找通路失败!" << endl;
        exit(1);
    }
    //返回栈顶元素的值
    return S.stack[S.top];
}

//5. 判断栈是否为空
bool EmptyStack(Stack &S) {
    return S.top == -1;
}

//6. 清除栈中的所有元素并释放动态存储空间
void ClearStack(Stack &S) {
    if (S.stack) {
        delete[]S.stack;
        S.stack = 0;
    }
    S.top = -1;
    S.MaxSize = 0;
}
///////////////////////////////////////////////////