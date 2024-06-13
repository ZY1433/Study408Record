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

int Binary_Search(SeqList S, ElemType key){ //假设是递增的顺序表
  int low = 0;
  int high = S.length - 1;
  
  while(low <= high){
    int mid = (low + high)/2;
    if(S.data[mid] == key){//找到了就返回
      return mid;
    } else if(S.data[mid] > key){//如果比要找的值大了
      high = mid - 1;//让最大值移动到mid左边
    } else{//小了
      low = mid + 1;//让最小值移动到mid右边
    }
  }
  return -1;//没找到
  
}