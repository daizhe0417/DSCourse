//
// Created by DaiZhe on 2018/6/1.
//

#ifndef DSCOURSE_CH5_1_H
#define DSCOURSE_CH5_1_H

//1. 图的邻接矩阵存储的初始化算法
void InitMatrix(adjmatrix GA, int k) {
    //k=0为无权图，k=1为有权图
    int i, j;
    for (i = 0; i < MaxVertexNum; i++) {
        for (j = 0; j < MaxVertexNum; j++) {
            if (i == j) {
                GA[i][j] = 0;
            } else if (k) {
                GA[i][j] = MaxValue;
            } else {
                GA[i][j] = 0;
            }
        }
    }
}

//2. 根据一个图的边集生成图的邻接矩阵的算法
void CreateMatrix(adjmatrix GA, int n, char *s, int k1, int k2) {
    // k1=0无向图，k1!=0有向图
    // k2=0无权图，k2!=0有权图
    istrstream sin(s);
    cout << "输入的边集为：" << s << endl;
    cout << "开始创建" << endl;
    char c1, c2, c3;
    int i, j;
    WeightType w;
    sin >> c1;
    if (k1 == 0 && k2 == 0)
        do {
            sin >> c1 >> i >> c2 >> j >> c3;
            GA[i][j] = GA[j][i] = 1;
            sin >> c1;
            if (c1 == '}') break;
        } while (1);
    else if (k1 == 0 && k2 != 0)
        do {
            sin >> c1 >> i >> c2 >> j >> c3 >> w;
            GA[i][j] = GA[j][i] = w;
            sin >> c1;
            if (c1 == '}') break;
        } while (1);
    else if (k1 != 0 && k2 == 0)
        do {
            sin >> c1 >> i >> c2 >> j >> c3;
            GA[i][j] = 1;
            sin >> c1;
            if (c1 == '}') break;
        } while (1);
    else if (k1 != 0 && k2 != 0)
        do {
            sin >> c1 >> i >> c2 >> j >> c3 >> w;
            GA[i][j] = w;
            sin >> c1;
            if (c1 == '}') break;
        } while (1);
}

//3. 根据图的邻接矩阵输出图的二元组表示（顶点集和边集）的算法
void PrintMatrix(adjmatrix GA, int n, int k1, int k2) {
    // k1=0无向图，k1!=0有向图
    // k2=0无权图，k2!=0有权图
    int i, j;
    cout << "V={";
    for (i = 0; i < n - 1; i++) cout << i << ',';
    cout << n - 1 << '}' << endl;
    cout << "E={";
    if (k2 == 0) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (GA[i][j] == 1)
                    if (k1 == 0) {
                        if (i < j) cout << '(' << i << ',' << j << ')' << ',';
                    } else
                        cout << '<' << i << ',' << j << '>' << ',';
    } else {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (GA[i][j] != 0 && GA[i][j] != MaxValue)
                    if (k1 == 0) {
                        if (i < j) cout << '(' << i << ',' << j << ')' << GA[i][j] << ',';
                    } else
                        cout << '<' << i << ',' << j << '>' << GA[i][j] << ',';
    }
    cout << '}' << endl;
}

void PrintMatrix(adjmatrix GA, vexlist vx, int n, int k1, int k2) {
    // k1=0无向图，k1!=0有向图
    // k2=0无权图，k2!=0有权图
    int i, j;
    cout << "V={";
    for (i = 0; i < n - 1; i++) cout << vx[i] << ',';
    cout << n - 1 << '}' << endl;
    cout << "E={";
    if (k2 == 0) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (GA[i][j] == 1)
                    if (k1 == 0) {
                        if (i < j) cout << '(' << i << ',' << j << ')' << ',';
                    } else
                        cout << '<' << i << ',' << j << '>' << ',';
    } else {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (GA[i][j] != 0 && GA[i][j] != MaxValue)
                    if (k1 == 0) {
                        if (i < j) cout << '(' << i << ',' << j << ')' << GA[i][j] << ',';
                    } else
                        cout << '<' << i << ',' << j << '>' << GA[i][j] << ',';
    }
    cout << '}' << endl;
}

#endif //DSCOURSE_CH5_1_H
