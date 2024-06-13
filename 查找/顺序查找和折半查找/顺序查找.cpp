#include<stdio.h>
#include<stdlib.h>

#define InitSize 10
#define ElemType int

typedef struct { //定义顺序表的结构体
  ElemType* data;
  int length;
  int MaxSize;
}SeqList;

void InitList(SeqList &L) { //初始化顺序表
  L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
  L.length = 0;
  L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) { //增加顺序表长度
  int *p = L.data;
  L.data = (ElemType*)malloc(sizeof(ElemType) * (L.MaxSize+len));
  L.MaxSize += len;
  for(int i = 0; i < L.length; i++) {
    L.data[i] = p[i];
  }
  free(p);
}

int Search_seq(SeqList S, ElemType key){
  for (int i = 0; i < S.length; i++){
    if(S.data[i] == key){
      return i;
    }
  }
  return -1;
  
}