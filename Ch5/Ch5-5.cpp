//
// Created by DaiZhe on 2018/6/4.
// 图的应用：最小生成树
//
#include <iostream>
#include <strstream>

using namespace std;

// 通用元素类型声明
typedef char VertexType;

const int MaxVertexNum = 100;                       // 图的最大顶点数
const int MaxEdgeNum = 9900;                        // 图的最大边数
typedef int WeightType;                             // 权值的通用类型声明
const WeightType MaxValue = 100000;                 // 特定权值，要大于所有有效权值之和
typedef VertexType vexlist[MaxVertexNum];           // 一维数组，存储顶点信息
typedef int adjmatrix[MaxVertexNum][MaxVertexNum];  // 二维数组，邻接矩阵

#include "Ch5-1.h"

#include "Ch5-3.h"

void printCT(edgeset CT) {
    cout << "{";
    for (int i = 0; i < MaxEdgeNum; i++) {
        if (CT[i].fromvex != -1) {
            cout << "(" << CT[i].fromvex << "," << CT[i].endvex << ")" << CT[i].weight << ",";
        }
    }
    cout << "}" << endl;
}

//1.普里姆算法产生图的最小生成树
void Prim(adjmatrix GA, edgeset CT, int n)
//利用普里姆算法从顶点v0出发求出用邻接矩阵GA表示的图的
//最小生成树，最小生成树的边集存于数组CT中
{
    int i, j, k, min, t, m, w;
    //给CT赋初值，对应第0次的LW值
    for (i = 0; i < n - 1; i++) {
        CT[i].fromvex = 0;
        CT[i].endvex = i + 1;
        CT[i].weight = GA[0][i + 1];
    }
    cout << "第" << 0 << "次" << endl;
    printCT(CT);
    //进行n-1循环，每次求出最小生成树中的第k条边
    for (k = 1; k < n; k++) {
        cout << "第" << k << "次" << endl;
        //从CT[k-1]~CT[n-2](即LW)中查找最短边CT[m]
        min = MaxValue;
        m = k - 1;
        for (j = k - 1; j < n - 1; j++)
            if (CT[j].weight < min) {
                min = CT[j].weight;
                m = j;
            }
        cout << "更新前" << endl;
        printCT(CT);
        //把最短边所在下标m对调到第k-1下标位置，这样下一次循环时，就从新的k-1开始就可以了
        edge temp = CT[k - 1];
        CT[k - 1] = CT[m];
        CT[m] = temp;
        cout << "交换后" << endl;
        printCT(CT);
        //把新并入最小生成树T中的顶点序号赋给j
        j = CT[k - 1].endvex;
        //修改LW中的有关边，使T中到T外的每一个顶点各保持
        //一条到目前为止最短的边
        for (i = k; i < n - 1; i++) {
            t = CT[i].endvex;
            w = GA[j][t];
            if (w < CT[i].weight) {
                CT[i].weight = w;
                CT[i].fromvex = j;
            }
        } //内for end
        cout << "更新后" << endl;
        printCT(CT);
    } //外for end
}

void printVars(bool **s, edgeset CT, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "CT:";
    printCT(CT);
}

//2. 克鲁斯卡尔算法
void Kruskal(edgeset GE, edgeset CT, int n)
//求边集数组GE所示图的最小生成树，树中每条边依次存于数组CT中
{
    int i, j;
    //定义具有n*n个元素的动态分配的二维数组s
    bool **s = new bool *[n];
    for (i = 0; i < n; i++) s[i] = new bool[n];
    //初始化s集合，使每一个顶点分属于对应集合
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (i == j) s[i][j] = true;
            else s[i][j] = false;
    }
    //定义相应变量
    int k = 1;      //k表示待获取的最小生成树中的边数，初值为1
    int d = 0;      //d表示GE中待扫描边元素的下标位置，初值为0
    int m1, m2;    //m1和m2分别保存一条边的两个顶点所在集合的序号
    cout << "开始" << endl;
    printVars(s, CT, n);
    //进行n-1次循环，得到最小生成树中的n-1条边
    while (k < n) {
        cout << "第" << k << "次:(" << GE[d].fromvex << "," << GE[d].endvex << ")" << endl;
        printVars(s, CT, n);
        for (i = 0; i < n; i++) {  //求出边GE[d]的两个顶点所在集合的序号m1和m2
            if (s[i][GE[d].fromvex] == true) m1 = i;
            if (s[i][GE[d].endvex] == true) m2 = i;
        }
        cout << "m1=" << m1 << "\tm2=" << m2 << endl;
        if (m1 != m2) {  //若两集合序号不等，则表明GE[d]是生成树中的一条边，
            //应将它加入到数组CT中
            CT[k - 1] = GE[d];
            k++;
            for (j = 0; j < n; j++) {  //合并两个集合，并将另一个置为空集
                s[m1][j] = s[m1][j] || s[m2][j];
                s[m2][j] = false;
            }
        }
        printVars(s, CT, n);
        d++;  //d后移一个位置，以便扫描GE中的下一条边
    }
    //释放为s动态分配的数组空间
    for (i = 0; i < n; i++) delete[]s[i];
    delete[]s;
}


int main() {
    cout << "普里姆算法:" << endl;
    adjmatrix GA;
    vexlist vx;
    InitMatrix(GA, 1);
    char *s = "{(0,1)8,(0,3)5,(1,2)12,(1,3)3,(1,4)10,(2,4)6,(2,5)2,(3,5)7,(3,6)15,(4,5)9}";
    CreateMatrix(GA, 7, s, 0, 1);
    PrintMatrix(GA, 7, 0, 1);

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (GA[i][j] == MaxValue) {
                cout << "N" << "\t";
            } else {
                cout << GA[i][j] << "\t";
            }
        }
        cout << endl;
    }

    edgeset CT;
    InitArray(CT);
    Prim(GA, CT, 7);
    cout << "Prim算法结果：" << endl;
    PrintArray(CT, 7, 0, 0);

    cout << "克鲁斯卡尔算法" << endl;
    edgeset GB;
    InitArray(GB);
    s = "{(0,1)18,(0,4)4,(0,5)23,(1,2)5,(1,3)8,(1,5)12,(2,3)10,(3,4)20,(3,5)15,(4,5)25}";
    CreateArray(GB, 6, s, 1);
    PrintArray(GB, 6, 0, 1);

    InitArray(CT);
    Kruskal(GB, CT, 6);
    cout << "Kruskal算法结果：" << endl;
    PrintArray(CT, 6, 0, 0);

    return 0;
}