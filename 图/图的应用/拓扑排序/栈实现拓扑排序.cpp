#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define ElmeType int

//栈
typedef struct { //定义顺序栈的结构体
  int top;
  ElmeType data[MaxVertexNum];
}SqStack;

void InitStack(SqStack &S) { //初始化顺序栈
  S.top = -1;
}

bool StackEmpty(SqStack S){ //判断栈是否空
  if(S.top == -1){
    return true;
  }
  return false;
}

bool Push( SqStack &S, ElmeType e){//入栈
  if(S.top < MaxVertexNum-1){//判断栈是否满
    S.top ++;
    S.data[S.top] = e;
    return true;
  }
  return false;
}

bool Pop(SqStack &S, ElmeType &e){//出栈
  if(StackEmpty(S)){
    return false;
  }
  e = S.data[S.top];
  S.top --;
  return true;
}


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

bool TopologicalSort(ALGraph G){
  SqStack S;
  InitStack(S);
  int indegree[G.VexNum];
  int print[G.VexNum];

  for (int i = 0; i < G.VexNum; i++){
    for (ENode *p = G.vertex[i].first; p != NULL; p = p->next){
      indegree[p->adjvex] ++; //指向顶点的入度+1
    }
  }
  for (int i = 0; i < G.VexNum; i++){
    if(indegree[i] == 0){
      Push(S,i);//度为0的点入栈；
    }
  }
  int cnt = 0;
  while(!StackEmpty(S)){//栈不空
    int e;
    Pop(S,e);
    for (ENode *p = G.vertex[e].first; p != NULL; p = p->next){
      indegree[p->adjvex] --; //指向顶点的入度-1
      if(indegree[p->adjvex] == 0){
        Push(S,p->adjvex);
      }
    }
    print[cnt++] = e;
  }

  if(cnt == G.VexNum){
    return true;//成功
  }
  return false;//说明有回路

}