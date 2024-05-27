#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
//该方法只能存储无向图

typedef struct ENode{ //定义边
  int i; //边的其中一个节点
  int j; //另一个节点
  ENode *ilink; //i能到的下一个节点
  ENode *jlink; //j能到的下一个节点
}ENode;

typedef struct VNode{ //定义顶点节点
  char data; //节点数据
  ENode *firstedge; //该节点指相邻的第一个节点
}V;


typedef struct { //定义顺序表的结构体
  char VNode[MaxVertexNum]; //所有的顶点
  int VexNum, EdgeNum; //当前的顶点数和边数
}ALGraph;
