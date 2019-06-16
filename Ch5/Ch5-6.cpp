//
// Created by DaiZhe on 2018/6/7.
// 图的应用：最短路径
//

#include <iostream>
#include <strstream>

using namespace std;

typedef int VertexType;
typedef int WeightType;

const int MaxVertexNum = 100;                       // 图的最大顶点数
const int MaxEdgeNum = 9900;                        // 图的最大边数
typedef int WeightType;                             // 权值的通用类型声明
const WeightType MaxValue = 100000;                 // 特定权值，要大于所有有效权值之和
typedef VertexType vexlist[MaxVertexNum];           // 一维数组，存储顶点信息
typedef int adjmatrix[MaxVertexNum][MaxVertexNum];  // 二维数组，邻接矩阵

struct edgenode {
    int adjvex;
    WeightType weight;
    edgenode *next;
};

#include"Ch5-1.h"

// 更新最短路径链表
void PATH(edgenode *path[], int m, int j) {
    edgenode *p, *q, *s;
    // 清空原来的到顶点j的路径链表
    p = path[j];
    while (p != NULL) {
        path[j] = p->next;
        delete p;
        p = path[j];
    }
    // 顶点j的路径链表更新为到顶点m的路径链表，加上顶点m到顶点j的路径
    p = path[m];
    while (p != NULL) {
        q = new edgenode;
        q->adjvex = p->adjvex;
        if (path[j] == NULL) path[j] = q;
        else s->next = q;
        s = q;
        p = p->next;
    }
    q = new edgenode;
    q->adjvex = j;
    q->next = NULL;
    s->next = q;
}
//从顶点i到顶点j的路径中添加顶点k
void PATH_2(edgenode *path[10][10], int i, int j, int k) {
    edgenode *p, *q;
    p = path[i][j];

    q = new edgenode;
    q->adjvex = k;
    q->next = NULL;

    if (p == NULL)
        path[i][j] = q;
    else {
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
void Dijkstra(adjmatrix GA, int dist[], edgenode *path[], int i, int n)
//利用狄克斯特拉算法求图GA中从顶点i到其余每个顶点间的
//最短距离和最短路径，它们分别被存于数组dist和path中
{
    int j, k, w, m;
    //定义作为集合使用的动态数组s
    bool *s = new bool[n];
    //分别给s,dist和path数组赋初值
    for (j = 0; j < n; j++) {
        if (j == i) s[j] = true; else s[j] = false;
        dist[j] = GA[i][j];
        if (dist[j] < MaxValue && j != i) {
            edgenode *p1 = new edgenode;
            edgenode *p2 = new edgenode;
            p1->adjvex = i;
            p2->adjvex = j;
            p2->next = NULL;
            p1->next = p2;
            path[j] = p1;
        } else{
            path[j] = NULL;
        }
    }
    //共进行n-2次循环，每次求出从源点i到终点m的最短路径及长度
    for (k = 1; k <= n - 2; k++) {
        //求出第k个终点m
        w = MaxValue;
        m = i;
        // 求不在s中的边的权重的最小值
        for (j = 0; j < n; j++)
            if (s[j] == false && dist[j] < w) {
                w = dist[j];
                m = j;
            }
        // 若找到最小权重的边,则把顶点m并入集合S中,
        // 否则退出循环,因为剩余的顶点,其最短路径长度均为MaxValue,无需再计算下去
        if (m != i) s[m] = true;
        else break;
        //对s元素为false的对应dist和path中的元素作必要修改
        for (j = 0; j < n; j++)
            if (s[j] == false && dist[m] + GA[m][j] < dist[j]) {
                dist[j] = dist[m] + GA[m][j];
                // 更新最短路径链表
                // 其中，将顶点i到顶点j的最短路径更新为
                // 顶点i到顶点m的最短路径加上顶点m到顶点j的路径
                PATH(path, m, j);
            }
    }
}

void Floyd(adjmatrix GA, adjmatrix A, int n, edgenode *path_2[10][10])
//利用Floyd算法求GA表示的图中每对顶点之间的最短长度
//对应保存在二维数组A中
{
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = GA[i][j];
    cout << "OK" << endl;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                if (i == k || j == k || i == j) continue;
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    //cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                    PATH_2(path_2, i, j, k);
                }
            }
}


int main() {
    int n = 5, k1 = 1, k2 = 1;
    adjmatrix ga1;
    InitMatrix(ga1, k2);
    char *a = new char[100];
    a = "{(0,1)3,(0,4)30,(1,2)25,(1,3)8,(2,4)10,(3,0)20,(3,2)4,(3,4)12,(4,0)5}";
    CreateMatrix(ga1, n, a, k1, k2);

    int dist[10];
    edgenode *path[10];
    Dijkstra(ga1, dist, path, 0, n);
    //输出Dijkstra算法得到的从0到其它顶点的最短路径
    for (int i = 1; i < n; i++) {
        cout << dist[i] << endl;
        edgenode *p = path[i];
        cout << "从0到" << i << "的最短路径为:";
        while (p != NULL) {
            cout << p->adjvex << ",";
            p = p->next;
        }
        cout << endl;
    }

    //------------Flored算法调用------------------------------
    int m = 4;
    adjmatrix ga2;
    InitMatrix(ga2, k2);
    char *b = new char[100];
    b = "{(0,1)1,(0,3)4,(1,2)9,(1,3)2,(2,0)3,(2,3)8,(3,2)6}";
    CreateMatrix(ga2, m, b, k1, k2);

    edgenode *path_2[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            path_2[i][j] = NULL;
    adjmatrix A;
    Floyd(ga2, A, m, path_2);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            cout << path_2[i][j] << " ";
        cout << endl;
    }

    //输出Flord算法得到的每对顶点之间的最短路径
    edgenode *p;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j)
                continue;
            if (A[i][j] == MaxValue)
                cout << "从" << i << "到" << j << "没有路" << endl;
            else {
                if (path_2[i][j] == NULL)
                    cout << "从" << i << "到" << j << "的最短路径长度为:" << A[i][j] << "\t最短路径为:" << i << "->" << j << endl;
                else {
                    cout << "从" << i << "到" << j << "的最短路径长度为:" << A[i][j] << "\t最短路径为:" << i << "->";
                    p = path_2[i][j];
                    while (p != NULL) {
                        cout << p->adjvex << "->";
                        p = p->next;
                    }
                    cout << j << endl;
                }
            }
        }
        cout << endl;
    }
}


