cmake_minimum_required(VERSION 3.9)
project(DSCourse)

set(CMAKE_CXX_STANDARD 11)

add_executable(DSCourse main.cpp)

###################################
############# 第一章 ###############
###################################
# 计算机程序的基本逻辑结构
add_executable(Ch1-1 Ch1/Ch1-1.cpp expr/aa.cpp homework/hm2-4.cpp)
# 抽象数据类型——矩阵
add_executable(Ch1-2 Ch1/Ch1-2.cpp)
# 抽象数据类型——矩阵——面向对象实现
add_executable(Ch1-3 Ch1/Ch1-3.cpp)
# 算法实例——求n个元素中的最大值
add_executable(Ch1-4 Ch1/Ch1-4.cpp)
# 时间复杂度——累加求和
add_executable(Ch1-5 Ch1/Ch1-5.cpp)
# 时间复杂度——矩阵相加
add_executable(Ch1-6 Ch1/Ch1-6.cpp)
# 时间复杂度——简单选择排序
add_executable(Ch1-7 Ch1/Ch1-7.cpp)

###################################
############# 第二章 ###############
###################################
# 线性表的顺序存储——面向过程实现
add_executable(Ch2-1 Ch2/Ch2-1.cpp)
# 线性表的顺序存储——面向对象实现
add_executable(Ch2-2 Ch2/Ch2-2.cpp)
# 线性表的链接存储——面向过程实现
add_executable(Ch2-3 Ch2/Ch2-3.cpp)
# 线性表的链接存储——面向对象实现-带头指针
add_executable(Ch2-4 Ch2/Ch2-4.cpp)

###################################
############# 第三章 ###############
###################################
# 栈的顺序存储
add_executable(Ch3-1 Ch3/Ch3-1.cpp)
# 栈的链接存储
add_executable(Ch3-2 Ch3/Ch3-2.cpp)
# 栈的应用——键盘输出逆序输出
add_executable(Ch3-3 Ch3/Ch3-3.cpp)
# 栈的应用——语法检查
add_executable(Ch3-4 Ch3/Ch3-4.cpp)
# 栈的应用——运算表达式求值
add_executable(Ch3-5 Ch3/Ch3-5.cpp)
# 栈与递归——递归方法计算阶乘
add_executable(Ch3-6 Ch3/Ch3-6.cpp)
# 栈与递归——汉诺塔
add_executable(Ch3-7 Ch3/Ch3-7.cpp)
# 栈与递归——迷宫问题递归解法
add_executable(Ch3-8 Ch3/Ch3-8.cpp)
# 栈与递归——迷宫问题非递归解法
add_executable(Ch3-9 Ch3/Ch3-9.cpp)


###################################
############# 第四章 ###############
###################################
# 二叉树-链接存储
add_executable(Ch4-1 Ch4/Ch4-1.cpp)
# 二叉搜索树
add_executable(Ch4-2 Ch4/Ch4-2.cpp)
# 堆
add_executable(Ch4-3 Ch4/Ch4-3.cpp)
# 哈夫曼树
add_executable(Ch4-4 Ch4/Ch4-4.cpp)

###################################
############## 作业 ################
###################################
add_executable(hm2-4 homework/hm2-4.cpp)