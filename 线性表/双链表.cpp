#include<stdio.h>
#include<stdlib.h>

#define ElmeType int

typedef struct DNode {
  ElmeType data;
  struct DNode *next;
  struct DNode *prior;
} DNode, *DLinkList;

bool InitDList(DLinkList &L) { //带头节点初始化
  L = (DLinkList)malloc(sizeof(DNode));
  if(L == NULL){
    return false;
  };
  L->next = NULL;
  L->prior = NULL;
  return true;
}

bool InsertNextDNode(DNode* p, ElmeType e) {// 在p后面插入e
  if(p == NULL) {
    return false;
  }
  DNode* s = (DNode*)malloc(sizeof(DNode));
  if(s == NULL) {
    return false;
  }
  s->data = e; //别忘了加数据！！！！
  if(p->next != NULL) {
  p->next->prior = s;
  }
  s->next = p->next;
  p->next = s;
  s->prior = p;
  return true;
}

bool ListDelete(DNode* p) { // 删除指定节点的后一个
  if(p == NULL){
    return false;
  }
  DNode *q = p->next;
  if(q == NULL){
    return false;
  }
  p->next = q->next;
  if(q->next != NULL){
    q->next->prior = p;
  }
  free(q);
  return true;

}

int main() {
  DLinkList L;
  
}