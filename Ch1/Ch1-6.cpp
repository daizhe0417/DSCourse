#include <iostream>

#define MS 10
using namespace std;
//
// Created by DaiZhe on 2018/3/24.
// 时间复杂度--矩阵相加
//

void MatrixAdd(int a[MS][MS], int b[MS][MS], int c[MS][MS], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main() {
    int a[MS][MS], b[MS][MS], c[MS][MS];
    int i, j;
    for (i = 0; i < MS; i++) {
        for (j = 0; j < MS; j++) {
            a[i][j] = i + j;
            b[i][j] = i * j;
        }
    }
    MatrixAdd(a, b, c, MS);
    for (i = 0; i < MS; i++) {
        for (j = 0; j < MS; j++) {
            cout << "a[" << i << "][" << j << "]=" << a[i][j] << ",b[" << i << "][" << j << "]=" << b[i][j] << endl;
            cout << "c[" << i << "][" << j << "]=" << c[i][j] << endl;
        }
    }
    return 0;
}