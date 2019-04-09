//
// Created by DaiZhe on 2018/6/1.
//
#include<iostream>
#include <strstream>

using namespace std;

typedef int VertexType;

const int MaxVertexNum = 100;                       // 图的最大顶点数
const int MaxEdgeNum = 9900;                        // 图的最大边数
typedef int WeightType;                             // 权值的通用类型声明
const WeightType MaxValue = 100000;                 // 特定权值，要大于所有有效权值之和
typedef VertexType vexlist[MaxVertexNum];           // 一维数组，存储顶点信息
typedef int adjmatrix[MaxVertexNum][MaxVertexNum];  // 二维数组，邻接矩阵


typedef VertexType vexlist[MaxVertexNum];
//定义vexlist为存储顶点信息的数组类型
typedef int adjmatrix[MaxVertexNum][MaxVertexNum];
//定义adjmatrix为存储邻接矩阵的数组类型

struct edgenode{
    int adjvex;
    WeightType weight;
    edgenode* next;
};
typedef edgenode* adjlist[MaxVertexNum];

#include "Ch5-1.h"
#include "Ch5-2.h"
#include "Ch5-4.h"

int main()
{
    //-------------遍历-------------
    int i,n,k1,k2;
    cout<<"输入待处理图的顶点数:";
    cin>>n;
    cout<<"输入图的有无向和有无权选择(0为无，非0为有):";
    cin>>k1>>k2;
    bool *visited=new bool[n];
    adjmatrix ga;
    InitMatrix(ga,k2);
    cout<<"输入图的边集:";
    char *a=new char[100];
    //cin>>a;
    //a="{(0,1),(0,2),(0,3),(1,4),(1,5),(1,6),(2,6),(4,5)}";
    a="{(0,1),(0,2),(1,2),(3,4),(5,5)}";
    CreateMatrix(ga,n,a,k1,k2);
    cout<<"按图的邻接矩阵得到的深度优先遍历序列:"<<endl;
    for(i=0;i<n;i++) {
        visited[i] = false;
        dfsMatrix(ga, i, n, visited);
    }
    cout<<endl;
    cout<<"按图的邻接矩阵得到的广度优先遍历序列:"<<endl;
    for(i=0;i<n;i++)
        visited[i]=false;
    bfsMatrix(ga,0,n,visited);
    cout<<endl;
    PrintMatrix(ga,n,k1,k2);
    cout<<"-----------------以下为邻接表存储结构----------------------"<<endl;
    adjlist gl;
    InitAdjoin(gl);
    char *b=new char[100];

    int m=9,t1=1,t2=0;//有向无权图，使用b数组
    b="((0,1),(0,2),(1,0),(1,3),(1,4),(1,5),(2,5),(2,6),(3,7),(4,7),(5,8),(6,8))";
    //int m=7,t1=0,t2=0;//无向无权图，使用a数组
    //b="((0,1),(0,2),(0,3),(1,4),(1,5),(1,6),(2,6),(4,5))";

    CreateAdjoin(gl,m,b,t1,t2);
    cout<<"按图的邻接表得到的深度优先遍历序列:"<<endl;
    for(i=0;i<m;i++)
        visited[i]=false;
    dfsAdjoin(gl,0,m,visited);
    cout<<endl;
    cout<<"按图的邻接表得到的广度优先遍历序列:"<<endl;
    for(i=0;i<m;i++)
        visited[i]=false;
    bfsAdjoin(gl,0,m,visited);
    cout<<endl;
    PrintAdjoin(gl,m,t1,t2);
    //-------------遍历-------------
    //-------------------以下为最短路径部分--------------------
/*
	int n=9,k1=1,k2=0;//有向无权图，使用b数组
	adjmatrix ga;
	InitMatrix(ga,k2);
	char *a=new char[100];
	a="((0,1),(0,2),(1,0),(1,3),(1,4),(1,5),(2,5),(2,6),(3,7),(4,7),(5,8),(6,8))";
	CreateMatrix(ga,n,a,k1,k2);
	int dist[10];
	edgenode* path[10];
	Dijkstra(ga,dist,path,0,n);
*/
}