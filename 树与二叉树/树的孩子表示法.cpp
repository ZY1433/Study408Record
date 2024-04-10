#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct CTNode{
  int child;//孩子在数组的位置
  struct CTNode *next;//链表指针,下个孩子
}CTNode;

typedef struct CTBox{
  ElmeType data;
  CTNode *firstChild;//第一个孩子
}CTBox;

typedef struct CTree{
  CTBox nodes[MAXSIZE];
  int n;//节点数
  int r;//根的位置
}CTree;

void visit(CTBox node){//访问节点
  printf("%d\n",node.data);
}

void ProOrder(CTree tree, int index){
  //初始的时候index传入的是根节点的下标
  if(index < 0 || index > tree.n){
    return;
  }
  visit(tree.nodes[index]);//访问

  CTNode *child = tree.nodes[index].firstChild;
  //找到当前位置的第一个孩子节点
  while (child != NULL){//如果有孩子节点
    ProOrder(tree,child->child);
    //对那个孩子节点的下标处进行先根遍历
    child = child->next;//继续找它的下一个孩子
  }
}