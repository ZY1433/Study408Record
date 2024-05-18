#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
#define ElmeType int

typedef struct { //定义顺序栈的结构体
  int top;
  ElmeType data[MaxSize];
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
  if(S.top < MaxSize-1){//判断栈是否满
    S.top ++;
    S.data[S.top] = e;
    return true;
  }
  return false;
}

bool Pop(SqStack &S, ElmeType &e){
  if(StackEmpty(S)){
    return false;
  }
  e = S.data[S.top];
  S.top --;
  return true;
}

bool GetTop(SqStack &S, ElmeType &e){
  if(StackEmpty(S)){
    return false;
  }
  e = S.data[S.top];
  return true;
}

