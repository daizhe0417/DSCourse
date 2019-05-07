//
// Created by DaiZhe on 2018/5/14.
// 迷宫问题递归求解
//

#include<iostream>

using namespace std;

// 出口坐标
const int m = 6, n = 8;
// 迷宫矩阵
int maze[m + 2][n + 2] =
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
         {1, 0, 0, 1, 1, 0, 1, 0, 1, 1},
         {1, 1, 0, 0, 1, 1, 0, 0, 0, 1},
         {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
         {1, 1, 1, 0, 1, 1, 0, 0, 0, 1},
         {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
         {1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// 探索过程记录
int mark[m + 2][n + 2];

// 探索方向
int moveddd[4][2] =
        {{0,  1},
         {1,  0},
         {0,  -1},
         {-1, 0}};

// 递归方法探索迷宫
bool SeekPath(int x, int y) {
    cout << "x=" << x << ",y=" << y << endl;
    int i;
    int g, h;
    if ((x == m) && (y == n)) return true;
    for (i = 0; i < 4; i++) {
        g = x + moveddd[i][0];
        h = y + moveddd[i][1];
        cout << "g=" << g << ",h=" << h << endl;
        if ((maze[g][h] == 0) && (mark[g][h] == 0)) {
            mark[g][h] = 1;
            if (SeekPath(g, h)) {
                cout << "(" << g << "," << h << "), ";
                return true;
            }
        }
    }
    return false;
}

int main() {
    int i, j;
    //for(i=0;i<m+2;i++)
    //	for(j=0;j<n+2;j++)
    //		cin>>maze[i][j];
    //cout<<"asdfadfasd"<<endl;
    for (i = 0; i < m + 2; i++)
        for (j = 0; j < n + 2; j++)
            mark[i][j] = 0;
    mark[1][1] = 1;
    if (SeekPath(1, 1))
        cout << "(" << 1 << "," << 1 << ")" << endl;
    else cout << "此迷宫无通路!" << endl;
    return 0;
}
