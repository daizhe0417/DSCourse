//
// Created by DaiZhe on 2019/3/24.
//
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

// 1
int Prime(int n) {
    int i = 2;
    int x = (int) sqrt(n);
    while (i <= x) {
        cout << "i=" << i << ",x=" << x << endl;
        if (n % i == 0)break;
        i++;
    }
    if (i > x) return 1;
    else return 0;
}

// 2


// 4
int fun(int n) {
    int i = 1, s = 1;
    while (s < n) {
        s += ++i;
        cout << "s=" << s << ",i=" << i << endl;
    }
    return i;
}

// 5
//void UseFile(ifstream &inp, int c[10]) {
//    int i;
//    for (i = 0; i < 10; i++) {
//        c[i] = 0;
//    }
//    int x;
//    while (inp >> x) {
//        i = x % 10;
//        c[i]++;
//    }
//}

// 6
void mtable(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cout << i << "*" << j << "=" << setw(2) << i * j << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << Prime(7) << endl;
    cout << Prime(6) << endl;

    cout << fun(2) << endl;
    cout << fun(3) << endl;
    cout << fun(4) << endl;

    mtable(9);
}