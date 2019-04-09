#include <iostream>
using namespace std;
int main() {
    
    int i;
    cout << i << endl;

    int a[10];

    cout << a[10] << endl;

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
