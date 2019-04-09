#include <iostream>

using namespace std;

//
// 时间复杂度--累加求和
//

// 累加求和函数
int sum(int b[], int n) {
    int i, s = 0;
    for (i = 0; i < n; i++) {
        s += b[i];
    }
    return s;
}

// 求1~n的和——方法一
int sum1(int n) {
    int r = 0;
    for (int i = 1; i <= n; ++i) {
        r += i;
    }
    return r;
}

// 求1~n的和——方法二
int sum2(int n) {
    int r = 0;
    r = n * (n + 1) / 2;
    return r;
}

int main() {
    clock_t start,end;
    start = clock();
    sum1(1000000);
    end=clock();
    cout << "方法一用时："<<((end-start)) << endl;

    start = clock();
    sum2(1000000);
    end=clock();
    cout << "方法二用时："<<((end-start)) << endl;
    return 0;
}