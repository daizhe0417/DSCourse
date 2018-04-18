#include <iostream>
using namespace std;

//
// 计算机程序的基本逻辑结构
//
int main() {
    int x = 0;
    int result = 0;

    cout << "input number" << endl;

    // 输入
    cin >> x;

    // 处理
    for (int i = 0; i < 10; i++) {
        result += i;
    }

    // 输出
    cout << "result=" << result << endl;

    return 0;
}
