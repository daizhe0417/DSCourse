#include <iostream>

#define MAX_N 10
using namespace std;
//
// Created by DaiZhe on 2018/3/24.
// 时间复杂度——简单选择排序
//

void SelectSort(int b[], int n) {
    int i, j, k, x;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i; j < n; j++) {
            if (b[j] < b[k]) {
                k = j;
            }
        }
        x = b[i];
        b[i] = b[k];
        b[k] = x;
    }
}

int main() {
    int a[MAX_N] = {3, 8, 5, 7, 2, 9, 4, 10, 6, 1};
    SelectSort(a, MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        cout << "a[" << i << "]=" << a[i] << " , ";
    }
    return 0;
}