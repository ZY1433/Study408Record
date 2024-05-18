#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50
#define ElmeType int

typedef struct { //定义共享栈的结构体
  int top1;//第一个栈
  int top2;//第二个栈
  ElmeType data[MaxSize];
}SqStack;

void InitStack(SqStack &S) { //初始化顺序栈
  S.top1 = -1;
  S.top2 = MaxSize;
}

bool StackEmpty(SqStack S, int type){ //判断栈是否空,type代表是第几个栈
  if(type == 1){
    if(S.top1 == -1){
      return true;
    }
    return false;
  } else{
    if(S.top2 == MaxSize){
      return true;
    }
    return false;
  }
  
}

bool Push( SqStack &S, ElmeType e, int type){//入栈
  if(type == 1){
    if(S.top1 < S.top2-1){//判断栈是否满
      S.top1 ++;
      S.data[S.top1] = e;
      return true;
    }
    return false;
  } else {
    if(S.top1 >= S.top2-1){//判断栈是否满
      S.top2 --;
      S.data[S.top2] = e;
      return true;
    }
    return false;
  }
  
}

bool Pop(SqStack &S, ElmeType &e, int type){//出栈
  if(type == 1){
    if(StackEmpty(S,1)){
      return false;
    }
    e = S.data[S.top1];
    S.top1 --;
    return true;
  } else{
    if(StackEmpty(S,2)){
      return false;
    }
    e = S.data[S.top2];
    S.top2 ++;
    return true;
  }
  
}

bool GetTop(SqStack &S, ElmeType &e, int type){//读栈顶
  if(type == 1){
    if(StackEmpty(S,1)){
      return false;
    }
    e = S.data[S.top1];
    return true;
  } else{
    if(StackEmpty(S,2)){
      return false;
    }
    e = S.data[S.top2];
    return true;
  }
}

