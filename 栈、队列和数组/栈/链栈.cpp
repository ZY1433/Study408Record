#include<stdio.h>
#include<stdlib.h>

#define ElmeType int

typedef struct LNode {
  ElmeType data;
  struct LNode* next;
} LNode, *LinkStack;

// { // 不带头节点的操作
bool InitList(LinkStack &L) { //不带头节点初始化
  L = NULL;
  return true;
}

bool Empty(LinkStack L) { //不带头节点判断是否为空
  return (L == NULL);
}

bool Push(LinkStack &L, ElmeType e) { //不带头节点入栈
  if(L == NULL){
    L = (LNode*)malloc(sizeof(LNode));
    L->data = e;
    return true;
  }
  LNode* s = (LNode*)malloc(sizeof(LNode));
  s->data = e;
  s->next = L->next;
  L->next = s;
  return true;
}

bool Pop(LinkStack L, ElmeType &e) { //不带头节点出栈
  if(L == NULL) {
    return false;
  }
  LNode* p = L; 
  e = L->data;
  L = L->next;
  free(p);
  return true;
}

bool GetTop(LinkStack L, ElmeType &e){ // 不带头节点读栈顶
  if(L == NULL) {
    return false;
  }
  e = L->data;
  return true;
}
// }


// bool InitList(LinkStack &L) { //带头节点初始化
//   L = (LinkStack)malloc(sizeof(LNode));
//   if(L == NULL){
//     return false;
//   };
//   L->next = NULL;
//   return true;
// }

// bool Empty(LinkStack L) { //带头节点判断是否为空
//   return(L->next == NULL);
// }

// bool Push(LinkStack &L, ElmeType e) { //带头节点入栈
//   LNode* s = (LNode*)malloc(sizeof(LNode));
//   s->data = e;
//   s->next = L->next;
//   L->next = s;
//   return true;
// }

// bool Pop(LinkStack L, ElmeType &e) { //出栈
//   if(L->next == NULL) {
//     return false;
//   }
//   LNode* q = L->next;
//   e = q->data;
//   L->next = q->next;
//   free(q);
//   return true;
// }

// bool GetTop(LinkStack L, ElmeType &e){ // 读栈顶
//   if(L->next == NULL) {
//     return false;
//   }
//   LNode* q = L->next;
//   e = q->data;
//   return true;
// }




