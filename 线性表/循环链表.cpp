#include<stdio.h>
#include<stdlib.h>

#define ElmeType int

typedef struct LNode {
  ElmeType data;
  struct LNode *next;
} LNode, *LinkList;

typedef struct DNode {
  ElmeType data;
  struct DNode *next;
  struct DNode *prior;
} DNode, *DLinkList;

bool InitList(LinkList &L) { //循环单链表初始化
  L = (LinkList)malloc(sizeof(LNode));
  if(L == NULL){
    return false;
  };
  L->next = L;
  return true;
}

bool Empty(LinkList L) { //带头节点循环单链表判断是否为空
  return(L->next == L);
}
bool isTail(LinkList L, LNode *p) { //带头节点循环单链表判断是否为表尾
  return(p->next == L);
}


bool InitDList(DLinkList &L) { //循环双链表初始化
  L = (DLinkList)malloc(sizeof(DNode));
  if(L == NULL){
    return false;
  };
  L->next = L;
  L->prior = L;
  return true;
}

bool DEmpty(DLinkList L) { //带头节点循环双链表判断是否为空
  return(L->next == L);
}
bool DisTail(DLinkList L, DNode *p) { //带头节点循环双链表判断是否为表尾
  return(p->next == L);
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
  p->next->prior = s;
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
    return false;
  p->next = q->next;
  q->next->prior = p;
  free(q);
  return true;

}

int main() {
  DLinkList L;
  
}