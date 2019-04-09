//
// Created by DaiZhe on 2018/6/1.
//

#ifndef DSCOURSE_CH5_3_H
#define DSCOURSE_CH5_3_H
//1. 边集数组中的元素类型和边集数组类型定义
// 边集数组的元素类型
struct edge{
    int fromvex;            // 起点域
    int endvex;             // 终点域
    WeightType weight;      // 权值域
};
// 边集数组
typedef edge edgeset[MaxEdgeNum];


//2. 初始化图的边集数组的算法
void InitArray(edgeset GE)
{
    for(int i=0;i<MaxEdgeNum;i++){
        GE[i].fromvex=GE[i].endvex=-1;
        GE[i].weight=MaxValue;
    }
}

//3. 根据图的边集生成图的边集数组的算法
void CreateArray(edgeset GE,int n,char* s,int k)
{
    istrstream sin(s);
    char c1,c2,c3;
    int i,j,c=0;
    WeightType w;
    sin>>c1;
    if(k==0){
        do{
            sin>>c1>>i>>c2>>j>>c3;
            GE[c].fromvex=i;
            GE[c].endvex=j;
            GE[c].weight=1;
            c++;
            sin>>c1;
        }while(c1==',');
    }
    else{
        do{
            sin>>c1>>i>>c2>>j>>c3>>w;
            GE[c].fromvex=i;
            GE[c].endvex=j;
            GE[c].weight=w;
            c++;
            sin>>c1;
        }while(c1==',');
    }
}
//4. 根据图的边集数组表示输出图的二元组表示的算法
void PrintArray(edgeset GE,int n,int k1,int k2)
{
    int i;
    cout<<"V={";
    for(i=0;i<n-1;i++) cout<<i<<',';
    cout<<n-1<<'}'<<endl;
    cout<<"E={";
    i=-1;
    while(GE[++i].fromvex!=-1){
        if(k2==0){
            if(k1==0)
                cout<<'('<<GE[i].fromvex<<','<<GE[i].endvex<<')'<<',';
            else
                cout<<'<'<<GE[i].fromvex<<','<<GE[i].endvex<<'>'<<',';
        }
        else{
            if(k1==0){
                cout<<'('<<GE[i].fromvex<<','<<GE[i].endvex;
                cout<<')'<<GE[i].weight<<',';
            }
            else{
                cout<<'<'<<GE[i].fromvex<<','<<GE[i].endvex;
                cout<<'>'<<GE[i].weight<<',';
            }
        }
    }
    cout<<')'<<endl;
}
#endif //DSCOURSE_CH5_3_H
