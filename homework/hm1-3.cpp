//
// Created by DaiZhe on 2019/3/24.
//
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// 2 字符串逆序
void inversion(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        int from = i;
        int to = str.length() - 1 - i;
        char tmp = str[from];
        str[from] = str[to];
        str[to] = tmp;
    }
    cout << "交换结果:" << str << endl;
}

// 6 二维数组中查找最大元素的下标
void findmax(int *a, int m, int n) {
    int maxValue = *a, maxM = 0, maxN = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(a + i * n + j) > maxValue) {
                maxValue = *(a + i * n + j);
                maxM = i;
                maxN = j;
                break;
            }
        }
    }
    cout << "最大值:" << maxValue << "\t位置:(" << maxM << "," << maxN << ")" << endl;
}

int main() {
    inversion("abc");
    inversion("abcd");

    int a[4][3] = {{2, 5, 6},
                   {3, 6, 8},
                   {8, 4, 2},
                   {6, 3, 2}};
    findmax((int *) a, 4, 3);
}