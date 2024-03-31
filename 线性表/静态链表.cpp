#include<stdio.h>
#include<stdlib.h>

#define ElmeType int
#define MAXSIZE 10

typedef struct Node {
  ElmeType data;
  int  next;
} SLinkList[MAXSIZE];
//用数组的方式实现链表