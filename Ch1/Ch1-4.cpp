#include <iostream>

using namespace std;
//
// 算法实例——求n个元素中的最大值
//

int main() {
    int i, max, a[10];
    cout << "input 10 numbers:" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    max = a[0];
    for (int i = 1; i < 10; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    cout << "max number is " << max << endl;
    return 0;
}