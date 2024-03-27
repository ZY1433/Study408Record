#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

typedef struct { //定义顺序表的结构体
  int* data;
  int length;
  int MaxSize;
}SeqList;

void InitList(SeqList &L) { //初始化顺序表
  L.data = (int*)malloc(InitSize * sizeof(int));
  L.length = 0;
  L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) { //增加顺序表长度
  int *p = L.data;
  L.data = (int*)malloc(sizeof(int) * (L.MaxSize+len));
  L.MaxSize += len;
  for(int i = 0; i < L.length; i++) {
    L.data[i] = p[i];
  }
  free(p);
}

bool ListInster(SeqList &L, int i, int e) { //插入元素 (i是位序)
  if(i > L.length+1 || i < 1){
    return false;
  }
  if(L.length >= L.MaxSize){
    return false;
  }
  for(int j = L.length; j > i-1; j--){
    L.data[j] = L.data[j-1];
  }
  // L.data[i] = e; //写错啦！i是指位序，减一才是下标
  L.data[i-1] = e;
  L.length += 1;
  return true;
}

bool ListDelete(SeqList &L, int i, int &e) { //删除某个，还要把删掉的值传给e
  if(i < 1 || i > L.length){
    return false;
  }
  e = L.data[i-1];
  for (int j = i; j < L.length; j++){
    L.data[j-1] = L.data[j];
  }
  L.length --; //别忘改长度！
  return true;
}

int GetElem(SeqList &L, int i) { //按位查找
  return L.data[i-1];
}

int LocateElem(SeqList &L, int e) { // 按值查找,返回位序
  for(int i = 0; i < L.length; i ++) {
    if(L.data[i] == e) {
      return i+1;
    }
  }
  return 0;
}
int main() {
  SeqList L;
  InitList(L);

  IncreaseSize(L,5);
  printf("成功");
  return 0;
}
// 以下是课后题
#define ElemType int


int Q1(SeqList &L) {
  if(L.length == 0){
    printf("错误");
    return 0;
  }
  ElemType min = L.data[0];
  int idx = 0;
  for(int i = 1; i < L.length; i ++){
    if(L.data[i] < min){
      min = L.data[i];
      idx = i;
    }
  }
  L.data[idx] = L.data[L.length-1];
  L.length --;
  return min;
}