#include <iostream>

using namespace std;
//
// 抽象数据类型--矩阵--面向对象实现
//

/*
 * 矩形类
 */
class RECtangle {
//  数据
private:
    float length, width;
//  方法
public:
    // 初始化方法
    RECtangle();
    // 初始化方法
    RECtangle(float len, float wid);

    // 计算周长方法
    float Circumference();

    // 计算面积方法
    float Area();

//  getters and setters
public:
    float getLength() const;

    void setLength(float length);

    float getWidth() const;

    void setWidth(float width);
};

RECtangle::RECtangle() {
    this->length = 0;
    this->width = 0;
}

RECtangle::RECtangle(float len, float wid) {
    this->length = len;
    this->width = wid;
}

float RECtangle::Circumference() {
    return (this->length + this->width) * 2;
}

float RECtangle::Area() {
    return this->length * this->width;
}

float RECtangle::getLength() const {
    return length;
}

void RECtangle::setLength(float length) {
    RECtangle::length = length;
}

float RECtangle::getWidth() const {
    return width;
}

void RECtangle::setWidth(float width) {
    RECtangle::width = width;
}

int main() {
    RECtangle a;
    float length, width;
    cout << "please input length and width of a rectangle:" << endl;
    cin >> length >> width;
    a.setLength(length);
    a.setWidth(width);
    cout << "Circumference of this rectangle is " << a.Circumference() << endl;
    cout << "Area of this rectangle is " << a.Area() << endl;
    return 0;
}