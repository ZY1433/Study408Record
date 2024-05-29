#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100

typedef struct { //定义邻接矩阵的图
  char Vex[MaxVertexNum];
  bool Edge[MaxVertexNum][MaxVertexNum]; //存带权图时改成int类型，对应位置记录权值，其余位置记为无穷
  int VexNum, EdgeNum; //当前的顶点数和边数
}MGraph;

bool Adjacent(MGraph G, int x, int y){ // 判断是否存在边(x,y)或<x,y>
  if(G.Edge[x][y] != 0){
    return true;
  }
  return false;
}