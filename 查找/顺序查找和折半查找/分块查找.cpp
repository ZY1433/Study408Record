#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
#define ElemType int

typedef struct { //定义顺序表的结构体
  ElemType* data;
  int length;
}SeqList;

void InitList(SeqList &L) { //初始化顺序表
  L.data = (ElemType*)malloc(MaxSize * sizeof(ElemType));
  L.length = 0;
}

typedef struct { //定义索引表的结构体
  ElemType maxValue;
  int low;
  int high;
}Index;

Index index[MaxSize];

int Block_Search(SeqList S, Index Idx[], ElemType key){ //假设是递增的顺序表
  int low = 0;
  int high = MaxSize - 1;//对索引表进行二分查找
  
  while(low <= high){
    int mid = (low + high)/2;
    if(Idx[mid].maxValue == key){//找到了就返回
      low = mid;//便于和其它情况相同
      break;
    } else if(Idx[mid].maxValue > key){//如果比要找的值大了
      high = mid - 1;//让最大值移动到mid左边
    } else{//小了
      low = mid + 1;//让最小值移动到mid右边
    }
  }
  int p = Idx[low].low;//要找的值可能所在区间的第一个下标
  int q = Idx[low].high;//结束下标
  for (int i = p; i <= q; i++){
    if(S.data[i] == key){
      return i;//找到就返回
    }
  }
  
  return -1;//没找到
  
}