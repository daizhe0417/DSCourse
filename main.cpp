#include <iostream>

int main() {

    int a[10];

    a[0]=12;
    std::cout << a[0] << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

typedef int ElemType;

struct LNote{
    ElemType data;
    LNote* next;
};

ADT RECtangle is
        Data:
float length,width;
Operations:
void InitRectangle(struct Rectangle& r,float,len,float wid);
float Circumference(struct Rectangle& r);
float Area(struct Rectangle& r);
end RECtangle
