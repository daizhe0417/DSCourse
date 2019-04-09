//
// Created by DaiZhe on 2018/6/1.
//

#ifndef DSCOURSE_CH5_4_H
#define DSCOURSE_CH5_4_H

//1.图的深度优先搜索遍历算法（采用邻接矩阵存储结构）
void dfsMatrix(adjmatrix GA, int i, int n, bool *visited) {
    //从初始点vi出发深度优先搜索由邻接矩阵GA表示的图
    cout << i << ' ';               //假定访问顶点vi以输出该顶点的序号代之
    visited[i] = true;              //标记vi已被访问过
    for (int j = 0; j < n; j++) {     //依次搜索vi的每个邻接点
        if (GA[i][j] != 0 && GA[i][j] != MaxValue && !visited[j]) {
            //若vi的一个有效邻接点vj未被访问过，则从vj出发进行递归调用
            dfsMatrix(GA, j, n, visited);
        }
    }
}

//2.图的广度优先搜索遍历算法（采用邻接矩阵存储结构）
void bfsMatrix(adjmatrix GA, int i, int n, bool *visited) {
    //从初始点vi出发广度优先搜索由邻接矩阵GA表示的图
    const int MaxSize = 30;             //定义队列的最大长度
    int q[MaxSize] = {0};               //定义一个队列q，其元素类型应为整型
    int front = 0, rear = 0;            //定义队首和队尾指针
    cout << i << ' ';                   //访问初始点vi
    visited[i] = true;                  //标记初始点vi已访问过
    q[++rear] = i;                      //将已访问过的初始点序号i入队
    while (front != rear) {             //当队列非空时进行循环处理
        front = (front + 1) % MaxSize;
        int k = q[front];               //删除队首元素，第一次执行时k的值为i
        for (int j = 0; j < n; j++) {   //依次搜索vk的每一个可能的邻接点
            if (GA[k][j] != 0 && GA[k][j] != MaxValue && !visited[j]) {
                cout << j << ' ';       //访问一个未被访问过的邻接点vj
                visited[j] = true;      //标记vj已访问过
                rear = (rear + 1) % MaxSize;
                q[rear] = j;            //顶点序号j入队
            }//if end
        }//for end
    }//while end
}//end


//3.图的深度优先搜索遍历算法（采用邻接表存储结构）
void dfsAdjoin(adjlist GL, int i, int n, bool *visited) {
    //从初始点vi出发深度优先搜索由邻接表GL表示的图
    cout << i << ' ';           //假定访问顶点vi以输出该顶点的序号代之
    visited[i] = true;          //标记vi已被访问过
    edgenode *p = GL[i];        //取vi邻接表的表头指针
    while (p != NULL) {         //依次搜索vi的每个邻接点
        int j = p->adjvex;      //j为vi的一个邻接点序号
        if (!visited[j])        //若vj未被访问过，则从vj出发进行递归调用
            dfsAdjoin(GL, j, n, visited);
        p = p->next;            //使p指向vi单链表的下一个边结点
    }
}

//4.图的广度优先搜索遍历算法（采用邻接表存储结构）
void bfsAdjoin(adjlist GL, int i, int n, bool *visited) {
    //从初始点vi出发广度优先搜索由邻接表GL表示的图
    const int MaxSize = 30;     //给出顺序队列的最大长度
    int q[MaxSize] = {0};       //定义一个队列q，其元素类型应为整型
    int front = 0, rear = 0;    //定义队首和队尾指针
    cout << i << ' ';           //访问初始点vi
    visited[i] = true;          //标记初始点vi已访问过
    q[++rear] = i;              //将已访问过的初始点序号i入队
    while (front != rear) {     //当队列非空时进行循环处理
        front = (front + 1) % MaxSize;
        int k = q[front];       //删除队首元素，第一次执行时k的值为i
        edgenode *p = GL[k];    //取vk邻接表的表头指针
        while (p != NULL) {     //依次搜索vk的每一个邻接点
            int j = p->adjvex;  //vj为vk的一个邻接点
            if (!visited[j]) {  //若vj没有被访问过则进行处理
                cout << j << ' ';
                visited[j] = true;
                rear = (rear + 1) % MaxSize;
                q[rear] = j;    //顶点序号j入队
            }
            p = p->next;        //使p指向vk邻接表的下一个边结点
        }// while(p!=NULL) end
    }// while(front!=rear) end
}//end
#endif //DSCOURSE_CH5_4_H
