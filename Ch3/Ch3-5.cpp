//
// Created by DaiZhe on 2018/5/7.
//

#include<iostream>

#define MAX_SIZE 10

using namespace std;

// 通用元素类型声明
typedef double ElemType;

// 栈的定义
struct Stack {
    ElemType *stack;    // 栈的存储空间
    int top;            // 栈顶下标
    int MaxSize;        // 栈的长度
};

//1. 初始化栈S为空
void InitStack(Stack &S) {
    //初始设置栈空间大小为10
    S.MaxSize = 10;
    //动态存储空间分配
    S.stack = new ElemType[S.MaxSize];
    if (!S.stack) {
        cerr << "动态存储分配失败！" << endl;
        exit(1);
    }
    //初始置栈为空
    S.top = -1;
}

//2. 元素item进栈，即插入到栈顶
void Push(Stack &S, ElemType item) {
    //若栈空间用完则自动扩大2倍空间，原有栈内容不变
    if (S.top == S.MaxSize - 1) {
        int k = sizeof(ElemType);  //计算每个元素存储空间的长度
        S.stack = (ElemType *) realloc(S.stack, 2 * S.MaxSize * k);
        S.MaxSize = 2 * S.MaxSize;   //把栈空间大小修改为新的长度
    }
    //栈顶指针后移一个位置
    S.top++;
    //将新元素插入到栈顶
    S.stack[S.top] = item;
}

//3. 删除栈顶元素并返回
ElemType Pop(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "栈空，退出运行!" << endl;
        exit(1);
    }
    //栈顶指针减1表示退栈
    S.top--;
    //返回原栈顶元素的值
    return S.stack[S.top + 1];
}

//4. 读取栈顶元素的值
ElemType Peek(Stack &S) {
    //若栈空则退出运行
    if (S.top == -1) {
        cerr << "Stack is empty!" << endl;
        exit(1);
    }
    //返回栈顶元素的值
    return S.stack[S.top];
}

//5. 判断栈是否为空
bool EmptyStack(Stack &S) {
    return S.top == -1;
}

//6. 清除栈中的所有元素并释放动态存储空间
void ClearStack(Stack &S) {
    if (S.stack) {
        delete[]S.stack;
        S.stack = 0;
    }
    S.top = -1;
    S.MaxSize = 0;
}

int Precedence(char op);

void Change(char *s1, char *s2);

double Compute(char *str);

int main() {
    char *c = "10 3.5 - 4.3 2.48 + * 5 /";
    cout << "后缀表达式求值结果为：" << Compute(c) << endl;

    char a[30];
    char b[30];
    cout << "请输入一个中缀算术表达式：" << endl;
    cin.getline(a, sizeof(a));
    Change(a, b);
    cout << "对应的后缀表达式为：" << endl;
    cout << b << endl;
    double ans;
    ans = Compute(b);
    cout << "后缀表达式求值结果为：" << ans << endl;
}


////////////////////////////////////
//        后缀表达式求值             //
////////////////////////////////////

//1.  后缀表达式求值
double Compute(char *str)  //计算由str所指字符串的后缀表达式的值
{
    //用S栈存储操作数和中间计算结果，元素类型为double
    Stack S;
    //初始化栈S
    InitStack(S);
    //定义x,y用于保存浮点数，定义i用于扫描后缀表达式
    double x, y;
    int i = 0;
    //扫描后缀表达式中的每个字符，并进行相应处理
    while (str[i]) {
        if (str[i] == ' ')      //扫描到空格字符不做任何处理
        {
            i++;
            continue;
        }
        switch (str[i]) {
            case '+':        //做栈顶两个元素的加法，和赋给x
                x = Pop(S) + Pop(S);
                i++;
                break;
            case '-':        //做栈顶两个元素的减法，差赋给x
                x = Pop(S);    //弹出减数
                x = Pop(S) - x;  //弹出被减数
                i++;
                break;
            case '*':       //做栈顶两个元素的乘法，积赋给x
                x = Pop(S) * Pop(S);
                i++;
                break;
            case '/':       //做栈顶两个元素的除法，商赋给x
                x = Pop(S);    //弹出除数
                if (x != 0.0) x = Pop(S) / x;  //弹出被除数并计算
                else {       //除数为0时终止运行
                    cerr << "Divide by 0!" << endl;
                    exit(1);
                }
                i++;
                break;
            default:  //扫描到的是浮点数字符串，生成对应的浮点数
                x = 0;  //利用x保存扫描到的整数部分的值
                while (str[i] >= 48 && str[i] <= 57) {
                    x = x * 10 + str[i] - 48;
                    i++;
                }
                if (str[i] == '.') {
                    i++;
                    y = 0;      //利用y保存扫描到的小数部分的值
                    double j = 10.0;  //用j作为相应小数位的权值
                    while (str[i] >= 48 && str[i] <= 57) {
                        y = y + (str[i] - 48) / j;
                        i++;
                        j *= 10;
                    }
                    x += y;  //把小数部分合并到整数部分x中
                }
        }
        //把扫描转换后或进行相应运算后得到的一个浮点数压入栈S中
        Push(S, x);
    }  //while end
    //若计算结束后栈为空则中止运行
    if (EmptyStack(S)) {
        cerr << "Stack is empty!" << endl;
        exit(1);
    }
    //若栈中仅有一个元素，则它就是后缀表达式的值，否则为出错
    x = Pop(S);
    if (EmptyStack(S)) return x;
    else {
        cerr << "expression error!" << endl;
        exit(1);
    }
    //释放S栈中动态存储空间
    ClearStack(S);
}


//2.  将中缀算术表达式转换为后缀算术表达式
void Change(char *s1, char *s2)
//将字符串s1中的中缀表达式转换为s2字符串中的后缀表达式
{
    //定义用于暂存运算符的栈R并初始化，该栈的元素类型为char
    Stack R;
    InitStack(R);
    //给栈底放入'@'字符，它具有最低优先级0
    Push(R, '@');
    //定义i,j分别用于扫描s1和指示s2串中待存字符的位置
    int i = 0, j = 0;
    //定义ch保存s1串中扫描到的字符，初值为第一个字符
    char ch = s1[i];
    //依次处理中缀表达式中的每个字符
    while (ch != '\0') {
        //对于空格字符不做任何处理，顺序读取下一个字符
        if (ch == ' ') ch = s1[++i];
            //对于左括号，直接进栈
        else if (ch == '(') {
            Push(R, ch);
            ch = s1[++i];
        }
            //对于右括号，使括号内的仍停留在栈中的运算符依次出栈并写入s2
        else if (ch == ')') {
            while (Peek(R) != '(') s2[j++] = Pop(R);
            Pop(R);       //删除栈顶的左括号
            ch = s1[++i];
        }
            //对于运算符，使暂存栈顶不低于ch优先级的运算符依次出栈并写s2
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            char w = Peek(R);
            while (Precedence(w) >= Precedence(ch)) {    // Precedence(w)函数返回运算符形参的优先级
                s2[j++] = w;
                Pop(R);
                w = Peek(R);
            }
            Push(R, ch);  //把ch运算符写入栈中
            ch = s1[++i];
        }
            //此处必然为数字或小数点字符，否则为中缀表达式错误
        else {
            //若ch不是数字或小数点字符则退出运行
            if ((ch < '0' || ch > '9') && ch != '.') {
                cout << "中缀表达式表示错误!" << endl;
                exit(1);
            }
            //把一个数值中的每一位依次写入到s2串中
            while ((ch >= '0' && ch <= '9') || ch == '.') {
                s2[j++] = ch;
                ch = s1[++i];
            }
            //被放入s2中的每个数值后面接着放入一个空格字符
            s2[j++] = ' ';
        }
    }
    //把暂存在栈中的运算符依次退栈并写入到s2串中
    ch = Pop(R);
    while (ch != '@') {
        if (ch == '(') {
            cerr << "expression error!" << endl;
            exit(1);
        } else {
            s2[j++] = ch;
            ch = Pop(R);
        }
    }
    //在后缀表达式的末尾放入字符串结束符
    s2[j++] = '\0';
}

//求运算符优先级的Precedence函数
int Precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case '@':
        default:
            return 0;
    }
}