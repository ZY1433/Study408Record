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
  if(Q.rear < MaxSize-1){//判断队是否满,会出现假溢出，所以一般采用循环队列
    Q.data[Q.rear] = e;
    Q.rear ++;
    return true;
  }
  return false;
}



