#include<iostream>
#include "../common/Student.cpp"

using namespace std;
#define MAX_SIZE 10

// 定义通用类型ElemType为学生类
typedef Student ElemType;

/**
 * 顺序存储的线性表类
 */
class List {
public:
    ElemType *list = NULL;
    int size = 0;
    int MaxSize = MAX_SIZE;
    // 排序状态：0未排序，1升序，-1倒序
    int sortType = 0;
public:
    /*
     * 构造方法
     */
    List() {
        cout << "List()构造方法" << endl;
        new(this)List(MAX_SIZE);
    }

    // 重载初始化线性表方法，用指定长度len创建数组
    List(int len) {
        // 如果线性表不为空，则不再重复初始化
        if (this->list != NULL) {
            cout << "线性表已存在，不再重复初始化，如要清空线性表，请调用ClearList()方法" << endl;
            return;
        }
        cout << "开始初始化线性表......" << endl;
        //初始定义数组长度为10，以后可增减
        this->MaxSize = len;
        //动态存储空间分配
        this->list = new ElemType[this->MaxSize];
        if (this->list == NULL) {
            cout << "动态可分配的存储空间用完，退出运行!" << endl;
            exit(1);
        }
        //置线性表长度为0，即为空表
        this->size = 0;
    }

    // 2. 清空线性表
    void ClearList() {
        // 释放空间
        if (this->list != NULL) {
            delete[]this->list;
            this->list = NULL;
        }
        //置线性表长度为0，即为空表
        this->size = 0;
    }

    // 3. 返回L的长度
    int get_size() {
        return this->size;
    }

    // 4. 判断L是否为空
    bool IsEmpty() {
        return this->size == 0;
    }

    // 5. 返回L中第pos个元素的值
    ElemType GetElem(int pos) {
        if (pos < 1 || pos > this->size)    //若pos越界则退出程序
        {
            cerr << "pos 越界了!" << endl;
            exit(1);
        }
        return this->list[pos - 1];    //返回第pos个元素的值
    }

    // 6. 遍历输出L中的所有元素
    void TraverseList() {
        for (int i = 0; i < this->size; i++)
            cout << this->list[i] << '\t';
        cout << endl;
    }

    // 7. 从L中查找并返回元素
    bool Find(ElemType &item) {
        for (int i = 0; i < this->size; i++)
            if (this->list[i] == item) {
                // 通过实参item返回找到的元素
                item = this->list[i];
                // 返回值表示是否找到指定元素
                return true;
            }
        return false;
    }

    // 8. 修改L中元素
    bool UpdateList(const ElemType &item) {
        for (int i = 0; i < this->size; i++)
            if (this->list[i] == item) {
                this->list[i] = item;    //进行更新赋值操作
                return true;
            }
        return false;
    }

    // 9. 向L插入元素，默认向表尾插入
    bool Insert(ElemType item) {
        return Insert(item, -1);
    }

    // 9. 向L插入元素
    // pos值：-1表尾，0有序，1~MaxSize+1第pos个位置（下标是pos-1）
    bool Insert(ElemType item, int pos) {
        if (pos < -1 || pos > this->size + 1) {
            cout << "pos值无效!" << endl;
            return false;
        }
        int i;
        // 重新计算要插入元素的位置pos
        // 当pos==0时，按排序插入，找到第一个比item大的元素，插入到这个位置的前面
        if (pos == 0) {
            // 判断表的排序状态，未排序时默认升序排列，倒序时倒置线性表
            if (this->sortType == 0) {
                SortList();
            } else if (this->sortType == -1) {
                ReverseList();
            }
            // 查找插入位置
            for (i = 0; i < this->size; i++) {
                if (item < this->list[i]) {
                    break;
                }
            }
            pos = i + 1;
            // 当pos==-1，插入位置是表尾
        } else if (pos == -1) {
            pos = this->size + 1;
        }
        // 空间已达最大时，扩展空间为原来的2倍
        if (this->size == this->MaxSize) {
            int k = sizeof(ElemType);
            this->list = (ElemType *) realloc(this->list, 2 * this->MaxSize * k);
            if (this->list == NULL) {
                cout << "动态可分配的存储空间用完，退出运行!" << endl;
                exit(1);
            }
            this->MaxSize = 2 * this->MaxSize;
        }
        // 插入位置之后的所有元素，向后移动1位
        for (i = this->size - 1; i >= pos - 1; i--)
            this->list[i + 1] = this->list[i];
        // 插入元素
        this->list[pos - 1] = item;
        // 增加线性表长度
        this->size++;
        return true;
    }

    // 10. 从L删除元素
    bool Delete(ElemType &item, int pos) {
        if (this->size == 0) {
            cout << "线性表为空，删除无效!" << endl;
            return false;
        }
        if (pos < -1 || pos > this->size) {
            cout << "pos值无效!" << endl;
            return false;
        }
        int i;
        if (pos == 0) {
            for (i = 0; i < this->size; i++) {
                if (item == this->list[i])
                    break;
            }

            if (i == this->size)
                return false;
            pos = i + 1;
        } else if (pos == -1) {
            pos = this->size;
        }
        item = this->list[pos - 1];
        for (i = pos; i < this->size; i++) {
            this->list[i - 1] = this->list[i];
        }
        this->size--;
        if (float(this->size) / this->MaxSize < 0.4 && this->MaxSize > 10) {
            //if (float(this->size) / this->MaxSize < 0.4 && this->MaxSize > "2？"0) {
            int k = sizeof(ElemType);
            this->list = (ElemType *) realloc(this->list, this->MaxSize * k / 2);
            this->MaxSize = this->MaxSize / 2;
        }
        return true;
    }

    // 11. 对L中的所有元素重新按给定条件排序
    void SortList() {
        int i, j;
        ElemType x;
        for (i = 1; i < this->size; i++) {
            x = this->list[i];
            for (j = i - 1; j >= 0; j--) {
                if (x < this->list[j]) {
                    this->list[j + 1] = this->list[j];
                } else {
                    break;
                }
            }
            this->list[j + 1] = x;
        }
    }

    // 12. 线性表倒置（翻转）
    void ReverseList() {
        for (int i = 0; i < this->size / 2; ++i) {
            ElemType tmp = this->list[this->MaxSize - 1 - i];
            this->list[this->MaxSize - 1 - i] = this->list[i];
            this->list[i] = tmp;
        }
    }

};

int main() {
    List l;
    Student s1(1, "zhangsan");
    Student s2(2, "lisi");
    l.Insert(s1);
    l.Insert(s2);
    l.TraverseList();
    // 通过学号查询对象
    Student s3(2);
    cout << "位置：" << l.Find(s3) << "内容：" << s3 << endl;
    // 更新数据
    Student s4(3);
    l.Insert(s4);
    l.TraverseList();
    Student s5(3,"wangwu");
    l.UpdateList(s5);
    l.TraverseList();
}
