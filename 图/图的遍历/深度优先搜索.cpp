#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100

bool visited[MaxVertexNum]; //判断是否访问

typedef struct ENode{ //定义邻接表的边
  int adjvex; //指向哪一个节点
  ENode *next; //指向的下一个边的指针
}ENode;

typedef struct VNode{ //定义邻接表的顶点节点
  char data; //节点数据
  ENode *first; //该节点指向的第一个节点
  
}V;

typedef struct { //定义邻接表的图
  VNode vertex[MaxVertexNum]; //所有的顶点
  int VexNum, EdgeNum; //当前的顶点数和边数
}ALGraph;

void ALG_visit(VNode v){ //邻接表的访问函数，读出节点数据
  printf("%c",v.data);
}

void ALG_DFSTraverse(ALGraph G){
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
  }

  for (int i = 0; i < G.VexNum; i++){
    if(!visited[i]){
      ALG_DFS(G,i); //调用深搜
    }
  }
}

void ALG_DFS(ALGraph G, int i) { //基于邻接表的深搜
  
  ALG_visit(G.vertex[i]); // 访问节点
  visited[i] = true; // 设置已访问
  ENode* p = G.vertex[i].first; //找到该节点的下一个节点
  while(p != NULL){ //节点存在 循环
    int t = G.vertex[i].first->adjvex; //节点位置
    if(!visited[t]){ //若是未访问节点
      ALG_DFS(G,t); //递归
    }
    p = p->next; // 递归结束，访问下一个节点
  }
}


typedef struct { //定义邻接矩阵的图
  char Vex[MaxVertexNum];
  int Edge[MaxVertexNum][MaxVertexNum]; //带权图时
  int VexNum, EdgeNum; //当前的顶点数和边数
}MGraph;

void MG_visit(char e){ //邻接矩阵的访问函数，输出节点数据
  printf("%c",e);
}

void MG_DFSTraverse(MGraph G){
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
  }

  for (int i = 0; i < G.VexNum; i++){
    if(!visited[i]){
      MG_DFS(G,i); //调用深搜
    }
  }
}

void MG_DFS(MGraph G, int i) { //基于邻接矩阵的深搜
  MG_visit(G.Vex[i]); // 访问节点
  visited[i] = true; // 设置已访问
  for (int j = 0; j < G.VexNum; j++){ //遍历其相邻的节点
    if(G.Edge[i][j] != 0 && !visited[j]){ //若存在且未访问
      MG_DFS(G,j); //递归
    }
  }
  
}