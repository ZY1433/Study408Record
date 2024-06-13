#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define INF 0x3f3f3f3f

typedef struct ENode{ //定义边
  int adjvex; //指向哪一个节点
  int weight;
  ENode *next; //指向的下一个边的指针
}ENode;

typedef struct VNode{ //定义顶点节点
  char data; //节点数据
  ENode *first; //该节点指向的第一个节点
  
}V;


typedef struct ALGraph{ //定义邻接表的图
  VNode vertex[MaxVertexNum]; //所有的顶点
  int VexNum, EdgeNum; //当前的顶点数和边数
}ALGraph;
  int dist[MaxVertexNum];//距离
  int path[MaxVertexNum];//路径
  bool final[MaxVertexNum];//是否确定最短路

bool dijkstra(ALGraph G, int idx){
  for(int i = 0; i < G.VexNum; i++){
    dist[i] = INF; //初始化为无穷
    path[i] = -1; //初始化路径
    final[i] = false;//初始化为未加入
  }

  dist[idx] = 0;//从第idx个点开始，将其距离设为0

  for (int i = 0; i < G.VexNum; i++) {
        int u = -1;//距离第i个点最近的未加入的点的下标
        int min = INF;//最小值先设为无穷大

        for (int j = 0; i < G.VexNum; j++){//遍历所有顶点
          if(!final[j] && dist[j] < min){//未确定最小距离 且比当前最小值小
            u = j;//更新
          }
        }

        if(u == -1){ //若u未变动，说明这不是联通图，已经没有idx能到达的顶点了，结束即可
          break;
        }
        final[u] = true;//这说明u是为确定里距离目标点最近的那个，将其加入

        for (ENode *p = G.vertex[u].first; p != NULL ; p = p->next){
          //用和这个点相接的未加入的点更新dist
          int v = p->adjvex;
          if(!final[v] && p->weight < dist[v]){
            dist[v] = p->weight;
          }
        }
    }
  return true;
}

