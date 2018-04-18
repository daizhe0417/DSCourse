#include <iostream>

using namespace std;
//
// 抽象数据类型——矩
//
struct RECtnagle {
    float length;
    float width;
};

void initRectangle(RECtnagle &r, float len, float wid);

float Circumference(RECtnagle &r);

float Area(RECtnagle &r);

int main() {
    RECtnagle a;
    float length, width;
    cout << "please input length and width of a rectangle:" << endl;
    cin >> length >> width;
    initRectangle(a, length, width);
    cout << "Circumference of this rectangle is " << Circumference(a) << endl;
    cout << "Area of this rectangle is " << Area(a) << endl;
    return 0;
}

void initRectangle(RECtnagle &r, float len, float wid) {
    r.length = len;
    r.width = wid;
}

float Circumference(RECtnagle &r) {
    return (r.length + r.width) * 2;
}

float Area(RECtnagle &r) {
    return r.length * r.width;
}