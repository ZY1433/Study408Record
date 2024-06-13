#include<stdio.h>
#include<stdlib.h>

#define ElmeType int
#define MaxVertexNum 100
#define INF 0x3f3f3f3f
//队列
typedef struct { //定义顺序队列的结构体
  int front,rear;
  ElmeType data[MaxVertexNum];
}SqQueue;
void InitQueue(SqQueue &Q) { //初始化顺序队列
  Q.front = Q.rear = 0;
}
bool QueueEmpty(SqQueue Q){ //判断队列是否空
  if(Q.front == Q.rear){
    return true;
  }
  return false;
}
bool EnQueue(SqQueue &Q, ElmeType e){//入队
  if((Q.rear + 1)%MaxVertexNum == Q.front){//判断队是否满，这样会牺牲一个空间不存数据
    return false;//满了就报错
  }
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxVertexNum ;
  return true;
}
bool DeQueue(SqQueue &Q, ElmeType &e){ // 出队
  if(QueueEmpty(Q)){
    return false;
  }
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxVertexNum;
  return true;
}

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

int d[MaxVertexNum];
int path[MaxVertexNum];

void ALG_BFS(ALGraph G, int idx) { //基于邻接表的广搜，判断idx到其它点的最短路
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
    d[i] = INF;  //初始化距离数组
    path[i] = -1;  //初始化路径数组
  }
  d[idx] = 0;
  SqQueue Q;
  InitQueue(Q); // 初始化队列
  EnQueue(Q,idx);//让idx先入队
  visited[idx] = true;//设成已访问
  while (!QueueEmpty(Q)){ // 当队列非空 循环
    int u;
    DeQueue(Q,u); //队头出队

    for(ENode *t = G.vertex[u].first; t != NULL; t = t->next){
      int v = t->adjvex;//新到的节点
      if(!visited[v]){//若没访问过
        EnQueue(Q,v);//入队
        d[v] = d[u] + 1; //距离为原距离+1
        path[v] = u;//记录它是由u到达的
        visited[v] = true;//置为已访问
      }
    }
  }
}


typedef struct { //定义邻接矩阵的图
  char Vex[MaxVertexNum];
  int Edge[MaxVertexNum][MaxVertexNum]; //带权图时
  int VexNum, EdgeNum; //当前的顶点数和边数
}MGraph;


void MG_BFS(MGraph G, int idx) { //基于邻接矩阵的广搜
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
    d[i] = INF;  //初始化距离数组
    path[i] = -1;  //初始化路径数组
  }
  d[idx] = 0;
  SqQueue Q;
  InitQueue(Q);//初始化队列
  EnQueue(Q,idx);
  visited[idx] = true;
  while (!QueueEmpty(Q)){ //队不空
    int t;
    DeQueue(Q,t); //出队头
    for (int j = 0; j < G.VexNum; j++){ //遍历队头可到达的节点
      if(G.Edge[t][j] != 0 && !visited[j]){ //找到与队头相连且未访问的节点
        EnQueue(Q,j); //将其入队
        d[j] = d[t] + 1;
        path[j] = t;
        visited[j] = true; //设为已访问
      }
    }
  }
}