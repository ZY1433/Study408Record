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

int prim(ALGraph G){
  int ans = 0;
  int dist[G.VexNum];//距离
  bool included[G.VexNum];//最小生成树包含的点
  for(int i = 0; i < G.VexNum; i++){
    dist[i] = INF; //初始化为无穷
    included[i] = false;//初始化为未加入
  }

  dist[0] = 0;//假设从第0个点开始，将其距离设为0
  for (int i = 0; i < G.VexNum; i++) {
        int u = -1;//距离第i个点最近的未加入的点的下标
        int min = INF;//最小值先设为无穷大

        for (int j = 0; i < G.VexNum; j++){//遍历所有顶点
          if(!included[j] && dist[j] < min){//未加入 且比最小值小
            u = j;//更新
          }
        }

        if(u == -1){ //若u未变动，说明这不是联通图，返回-1
          return -1;
        }
        included[u] = true;//把最近的未加入的点加入

        for (ENode *p = G.vertex[u].first; p != NULL ; p = p->next){
          //用和这个点相接的未加入的点更新dist
          int v = p->adjvex;
          if(!included[v] && p->weight < dist[v]){
            dist[v] = p->weight;
          }
        }
    }
  return ans;
}

