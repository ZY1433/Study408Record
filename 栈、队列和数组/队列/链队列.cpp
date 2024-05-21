#include<stdio.h>
#include<stdlib.h>

#define ElmeType int

typedef struct LNode {//队列节点
  ElmeType data;
  struct LNode* next;
} LNode;

typedef struct LinkQueue { //链式队列
  LNode *rear, *front;
} LinkQueue;

bool InitQueue(LinkQueue &Q) { //带头节点初始化
  Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
  if(Q.front == NULL){
    return false;
  };
  Q.front->next = NULL;
  return true;
}

bool Empty(LinkQueue Q) { //带头节点判断是否为空
  return(Q.front->next == NULL);
}

bool EnQueue(LinkQueue &Q, ElmeType e){//带头节点入队
  LNode *p = (LNode *)malloc(sizeof(LNode));
  p->data = e;
  p->next = NULL;//因为它是新队尾，所以要把它next置空
  Q.rear->next = p;//把新节点插入队尾之后
  Q.rear = p;//重新指向队尾
  return true;
}

bool DeQueue(LinkQueue &Q, ElmeType &e){ // 带头节点出队
  if(Empty(Q)){
    return false;
  }
  LNode *p = Q.front->next;
  e = p->data;
  Q.front->next = p->next;
  if(p == Q.rear){
    Q.rear = Q.front;
  }
  free(p); // 记得释放空间
  return true;
}


// bool InitQueue(LinkQueue &Q) { //不带头节点初始化
//   Q.front = Q.rear = NULL;
//   return true;
// }

// bool Empty(LinkQueue Q) { //不带头节点判断是否为空
//   return(Q.front == NULL);
// }

// bool EnQueue(LinkQueue &Q, ElmeType e){//不带头节点入队
//   LNode *p = (LNode *)malloc(sizeof(LNode));
//   p->data = e;
//   p->next = NULL;//因为它是新队尾，所以要把它next置空
//   if(Q.front == NULL){//如果队为空，把队头队尾都指向新节点
//     Q.front = p;
//     Q.rear = p;
//   } else{ // 不为空时，队头不动，要在队尾后面插入新节点
//     Q.rear->next = p;//把新节点插入队尾之后
//     Q.rear = p;//重新指向队尾
//   }
//   return true;
// }

// bool DeQueue(LinkQueue &Q, ElmeType &e){ // 不带头节点出队
//   if(Empty(Q)){
//     return false;
//   }
//   LNode *p = Q.front;
//   e = p->data;
//   Q.front = p->next;
//   if(p == Q.rear){
//     Q.rear = Q.front;
//   }
//   free(p); // 记得释放空间
//   return true;
// }
 