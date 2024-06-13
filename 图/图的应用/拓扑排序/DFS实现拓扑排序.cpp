#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define ElmeType int

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

bool visited[MaxVertexNum];//判断是否访问
int time = 0;//记录每个节点的访问时间
int visitTime[MaxVertexNum];

void DFSTraverse(ALGraph G){//dfs前初始化，以及调用dfs
  for (int i = 0; i < G.VexNum; i++){//初始化
    visited[i] = false;
    visitTime[i] = 0;
  }
  for (int i = 0; i < G.VexNum; i++){//调用dfs
    if(!visited[i]){
      DFS(G,i);
    }
  }
  //最后要按时间从大到小排序实现拓扑排序
}

void DFS(ALGraph G, int i){//dfs
  visited[i] = true;//先让该点置为已访问
  for (ENode *p = G.vertex[i].first; p != NULL; p = p->next){//找到它的下一个顶点
    if(!visited[p->adjvex]){//若下一个没访问
      DFS(G,p->adjvex);//递归
    }
  }
  time = time+1;
  visitTime[i] = time;//按访问时间倒序排列就是拓扑排序
}