//
// Created by DaiZhe on 2018/5/10.
//

#include<iostream>

using namespace std;

void Hanoi(int n, int a, int b, int c) {
    //当只有一个盘子时，直接由a移到c
    if (n == 1)
        cout << a << "→" << c << endl;
    else {
        //把上面的n-1个盘子经c移到b
        Hanoi(n - 1, a, c, b);
        //把第n个盘子由a移到c
        cout << a << "→" << c << endl;
        //把b上的n-1个盘子经a移到c
        Hanoi(n - 1, b, a, c);
    }
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    Hanoi(n, a, b, c);
}