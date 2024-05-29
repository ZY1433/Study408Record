#include<stdio.h>
#include<stdlib.h>
//该方法只能存储有向图

#define MaxVertexNum 100

typedef struct ENode{ //定义边
  int tailvex; //弧尾节点
  int headvex; //弧头节点
  ENode *hlink; //弧头相同的下一个节点  就是从tailvex出发的下一个节点
  ENode *tlink; //弧尾相同的下一个节点  就是到达headvex的下一个节点
}ENode;

typedef struct VNode{ //定义顶点节点
  char data; //节点数据
  ENode *firsthlink; //该节点指向的第一个弧头相同的下一个节点 其实就是自己出发的一个节点
  ENode *firsttlink; //该节点指向的第一个弧尾相同的下一个节点 其实就是到达自己的一个节点
}V;


typedef struct { //定义十字链表的图
  char VNode[MaxVertexNum]; //所有的顶点
  int VexNum, EdgeNum; //当前的顶点数和边数
}ALGraph;
