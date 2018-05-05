//
// Created by DaiZhe on 2018/4/30.
//

#include<iostream>

using namespace std;

/**
 * 学生类-作为线性表表中要存储的元素
 */
class Student {
private:
    int num = 0;        // 学号
    string name = "";   // 姓名
    int sex = 0;        // 性别
    string dept = "";   // 专业
public:
    /*
     * 构造方法
     */
    Student() {
        this->num = 0;
        this->name = "";
    }

    Student(int num) {
        this->num = num;
        this->name = "";
    }

    /*
     * 构造方法
     */
    Student(int num, string name) {
        this->num = num;
        this->name = name;
    }

    Student(const Student &s) {
        this->num = s.num;
        this->name = s.name;
        this->sex = s.sex;
        this->dept = s.dept;
        //cout << "copy constructor" << endl;
    }

    Student(const Student &s, Student &p) {
        p = Student(s);
    }

    // =========== getter、setter ===========
    int getNum() {
        return this->num;
    }

    void setNum(int num) {
        this->num = num;
    }

    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    /*
     * 重载运算符 ==
     */
    bool operator==(const Student &s) {
        if (this->num == s.num) {
            return true;
        }
        return false;
    }

    /*
     * 重载运算符 <
     */
    bool operator<(const Student &s) {
        if (this->num < s.num) {
            return true;
        }
        return false;
    }

    /*
     * 重载运算符 >
     */
    bool operator>(const Student &s) {
        if (this->num > s.num) {
            return true;
        }
        return false;
    }

    /*
     * 重载运算符 =
     */
    void operator=(const Student &s) {
        this->num = s.num;
        this->name = s.name;
        this->sex = s.sex;
        this->dept = s.dept;
    }

    /*
     * 重载运算符 <<
     */
    friend ostream &operator<<(ostream &out, Student &s);
};

/*
 * 重载学生类的运算符 <<
 */
ostream &operator<<(ostream &out, Student &s) {
    out << "学号:" << s.num << "\t姓名:" << s.name;
    return out;
}

//int main(){
//    Student s;
//    cout << s.getAaa() << endl;
//}