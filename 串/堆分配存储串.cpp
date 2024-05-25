#include<stdio.h>
#include<stdlib.h>

#define InitLen 255

typedef struct { //定义堆分配的存储串
  char *ch;//串的基地址
  int length;
}HString;

void InitString(HString &S) { //初始化顺序表
  S.ch = (char*)malloc(InitLen * sizeof(char));
  S.length = 0;
}