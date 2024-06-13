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
bool nowVisited[MaxVertexNum];//记录每轮访问情况

void DFSTraverse(ALGraph G){//dfs前初始化，以及调用dfs
  for (int i = 0; i < G.VexNum; i++){//初始化
    visited[i] = false;
    nowVisited[i] = false;
  }
  for (int i = 0; i < G.VexNum; i++){//调用dfs
    if(!visited[i]){
      DFS(G,i);
    }
  }  
}

void DFS(ALGraph G, int i){//dfs
  visited[i] = true;//先让该点置为已访问
  nowVisited[i] = true;//记录本轮访问情况
  for (ENode *p = G.vertex[i].first; p != NULL; p = p->next){//找到它的下一个顶点
    if(nowVisited[p->adjvex]){//遍历到本轮已访问的节点，说明有回路
      printf("出现回路 ");
      exit(0);
    }
    if(!visited[p->adjvex]){//若下一个没访问
      DFS(G,p->adjvex);//递归
    }
  }
  nowVisited[i] = false;//该节点本轮访问结束，置为false
  printf("%d ",i);
}