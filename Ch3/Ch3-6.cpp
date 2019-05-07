//
// Created by DaiZhe on 2018/5/10.
//

#include<iostream>

using namespace std;

long f(int n) {
    cout << "f"<<n << endl;
    if (n == 0) {
        return 1;
    } else {
        int fn_1 = f(n - 1);
        cout << "f" << n - 1 << "=" << fn_1 << endl;
        return n * fn_1;
    }
}

int main() {
    int n = 5;
    int result = f(n);
    cout << n << "!=" << result << endl;
    return 0;
}