//
// Created by DaiZhe on 2018/6/1.
//

#ifndef DSCOURSE_CH5_2_H
#define DSCOURSE_CH5_2_H
//1. 初始化一个图邻接表的算法
void InitAdjoin(adjlist GL) {
    for (int i = 0; i < MaxVertexNum; i++) {
        GL[i] = NULL;
    }
}

//2. 根据一个图的边集生成其邻接表的算法
void CreateAdjoin(adjlist GL, int n, char *s, int k1, int k2) {
    // k1=0无向图，k1!=0有向图
    // k2=0无权图，k2!=0有权图
    istrstream sin(s);
    char c1, c2, c3;
    int i, j;
    WeightType w;
    edgenode *p;
    sin >> c1;
    if (k2 == 0) {
        do {
            sin >> c1 >> i >> c2 >> j >> c3;
            p = new edgenode;
            p->adjvex = j;
            p->weight = 1;
            p->next = GL[i];
            GL[i] = p;
            if (k1 == 0) {
                p = new edgenode;
                p->adjvex = i;
                p->weight = 1;
                p->next = GL[j];
                GL[j] = p;
            }
            sin >> c1;
        } while (c1 == ',');
    } else {
        do {
            sin >> c1 >> i >> c2 >> j >> c3 >> w;
            p = new edgenode;
            p->adjvex = j;
            p->weight = w;
            p->next = GL[i];
            GL[i] = p;
            if (k1 == 0) {
                p = new edgenode;
                p->adjvex = i;
                p->weight = w;
                p->next = GL[j];
                GL[j] = p;
            }
            sin >> c1;
        } while (c1 == ',');
    }
}

//3. 把邻接表表示的图用顶点集和边集的形式输出的算法
void PrintAdjoin(adjlist GL, int n, int k1, int k2) {
    // k1=0无向图，k1!=0有向图
    // k2=0无权图，k2!=0有权图
    int i, j;
    edgenode *p;
    cout << "V={";
    for (i = 0; i < n - 1; i++)
        cout << i << ',';
    cout << n - 1 << '}' << endl;
    cout << "E={";
    for (i = 0; i < n; i++) {
        if (k2 == 0) {
            p = GL[i];
            while (p) {
                j = p->adjvex;
                if (k1 == 0) {
                    if (i < j) cout << '(' << i << ',' << j << ')' << ',';
                } else
                    cout << '<' << i << ',' << j << '>' << ',';
                p = p->next;
            }
        } else {
            p = GL[i];
            while (p) {
                j = p->adjvex;
                if (k1 == 0) {
                    if (i < j) cout << '(' << i << ',' << j << ')' << p->weight << ',';
                } else
                    cout << '<' << i << ',' << j << '>' << p->weight << ',';
                p = p->next;
            }
        }
    }
    cout << '}' << endl;
}
#endif //DSCOURSE_CH5_2_H
