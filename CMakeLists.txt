cmake_minimum_required(VERSION 3.9)
project(DSCourse)

set(CMAKE_CXX_STANDARD 11)

add_executable(DSCourse main.cpp)

###################################
############# 第一章 ###############
###################################
# 计算机程序的基本逻辑结构
add_executable(Ch1-1 Ch1/Ch1-1.cpp)
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
