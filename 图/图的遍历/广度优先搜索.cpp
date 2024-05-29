#include<stdio.h>
#include<stdlib.h>

#define ElmeType int
#define MaxVertexNum 100
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

void ALG_visit(VNode v){ //邻接表的访问函数，读出节点数据
  printf("%c",v.data);
}

void ALG_BFS(ALGraph G) { //基于邻接表的广搜
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
  }
  SqQueue Q;
  InitQueue(Q); // 初始化队列

  for (int i = 0; i < G.VexNum; i++){ //遍历节点
    if(!visited[i]){ //遇到未访问节点
      EnQueue(Q,i); //入队
      visited[i] = true; //设成已经访问
    }
    while (!QueueEmpty(Q)){ // 当队列非空 循环
      int e;
      DeQueue(Q,e); //队头出队
      ALG_visit(G.vertex[e]); //访问出队元素
      if(G.vertex[e].first != NULL){ //当出队元素有相接的节点时
        e = G.vertex[e].first->adjvex; // 指向这一节点
      }
      if(!visited[e]){ //若这一节点未访问
        EnQueue(Q,e); //入队
        visited[e] = true; //设置成已访问
      }
    }
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

void MG_BFS(MGraph G) { //基于邻接矩阵的广搜
  for (int i = 0; i < G.VexNum; i++){ //初始化访问判断数组
    visited[i] = false;
  }
  SqQueue Q;
  InitQueue(Q);//初始化队列
  for (int i = 0; i < G.VexNum; i++){ //对每个联通分量遍历
    if(!visited[i]){//判断是否访问节点
      EnQueue(Q,i); //入队
      visited[i] = true; //设为已访问
    }
    while (!QueueEmpty(Q)){ //队不空
      int t;
      DeQueue(Q,t); //出队头
      MG_visit(G.Vex[t]); //访问队头
      for (int j = 0; j < G.VexNum; j++){ //遍历队头可到达的节点
        if(G.Edge[i][j] != 0 && !visited[j]){ //找到相连且未访问的节点
          EnQueue(Q,j); //将其入队
          visited[j] = true; //设为已访问
        }
      }
    }
    
  }
}