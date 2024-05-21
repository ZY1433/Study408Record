#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
#define ElmeType int

typedef struct { //定义顺序队列的结构体
  int front,rear;
  ElmeType data[MaxSize];
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
  if((Q.rear + 1)%MaxSize == Q.front){//判断队是否满，这样会牺牲一个空间不存数据
    return false;//满了就报错
  }
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize ;
  return true;
}

bool DeQueue(SqQueue &Q, ElmeType &e){ // 出队
  if(QueueEmpty(Q)){
    return false;
  }
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

bool GetHead(SqQueue &Q, ElmeType &e){ // 读队头
  if(QueueEmpty(Q)){
    return false;
  }
  e = Q.data[Q.front];
  return true;
}

int GetSize(SqQueue &Q){
  return (Q.rear - Q.front +MaxSize) % MaxSize;
}


