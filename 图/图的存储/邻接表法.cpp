#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100

typedef struct ENode{ //定义边
  int adjvex; //指向哪一个节点
  ENode *next; //指向的下一个边的指针
}ENode;

typedef struct VNode{ //定义顶点节点
  char data; //节点数据
  ENode *first; //该节点指向的第一个节点
  
}V;


typedef struct { //定义邻接表的图
  VNode vertex[MaxVertexNum]; //所有的顶点
  int VexNum, EdgeNum; //当前的顶点数和边数
}ALGraph;

bool Adjacent(ALGraph G, int x, int y){ // 判断是否存在边(x,y)或<x,y>
  ENode *p = G.vertex[x].first;
  while (p != NULL){
    if(p->adjvex == y){
      return true;
    } else{
      p = p->next;
    }
  }
  return false;
}