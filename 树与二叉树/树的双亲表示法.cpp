#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct {//树的节点
  ElmeType data;
  int parent;//双亲的下标
}PTNode;

typedef struct{
  PTNode nodes[MAXSIZE];
  int n;//节点个数
}PTree;