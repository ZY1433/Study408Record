#include<stdio.h>
#include<stdlib.h>

#define ElmeType int

typedef struct LNode {
  ElmeType data;
  struct LNode* next;
} LNode, *LinkList;

//{ // 不带头节点的操作
// bool InitList(LinkList &L) { //不带头节点初始化
//   L = NULL;
//   return true;
// }

// bool Empty(LinkList L) { //不带头节点判断是否为空
//   return (L == NULL);
// }

// bool ListInsert(LinkList &L, int i, ElmeType e){//不带头结点插入
//   if(i < 1){
//     return false;
//   }
//   if(i == 1) {
//     LNode* s = (LNode*)malloc(sizeof(LNode));
//     s->data = e; //别忘了加数据！！
//     s->next = L;
//     L = s;
//     return true;
//   }
//   int j = 1;
//   LNode* p = L;
//   while (p != NULL && j < i-1){
//     p = p->next;
//     j ++;
//   }
//   if (p == NULL){
//     return false;
//   }
//   LNode* s = (LNode*)malloc(sizeof(LNode));
//   s->data = e;
//   s->next = p->next;
//   p->next = s;
//   return true;
// }
//}

LNode* GetElem(LinkList L, int i) {// 带头结点 按位查找
  if(i < 0) {
    return NULL;
  }
  LNode* p = L;
  int j = 0;
  while (p != NULL && j < i){
    p = p->next;
    j ++;
  }
  return p;
}

bool InitList(LinkList &L) { //带头节点初始化
  L = (LinkList)malloc(sizeof(LNode));
  if(L == NULL){
    return false;
  };
  L->next = NULL;
  return true;
}

bool Empty(LinkList L) { //带头节点判断是否为空
  return(L->next == NULL);
}

bool InsertNextNode(LNode* p, ElmeType e) {// 在p后面插入e
  if(p == NULL) {
    return false;
  }
  LNode* s = (LNode*)malloc(sizeof(LNode));
  if(s == NULL) {
    return false;
  }
  s->data = e; //别忘了加数据！！！！
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListInsert(LinkList &L, int i, ElmeType e){//带头结点在位序i插入
  if(i < 1){
    return false;
  }
  // int j = 0;
  // LNode* p = L;
  // while (p != NULL && j < i-1){
  //   p = p->next;
  //   j ++;
  // }
  LNode* p = GetElem(L,i-1);//找到第i-1个位置
  // if (p == NULL){
  //   return false;
  // }
  // LNode* s = (LNode*)malloc(sizeof(LNode));
  // s->data = e;
  // s->next = p->next;
  // p->next = s;
  // return true;
  return InsertNextNode(p,e);
}

bool InsertPriorNode(LNode*p, LNode* s) { // 在p前面插入s 先插到后面再交换值
  if(s == NULL || p == NULL) {
    return false;
  }
  s->next = p->next;
  p->next = s;
  ElmeType t = s->data;
  s->data = p->data;
  p->data = t;
  return true;
}

bool ListDelete(LinkList &L, int i, ElmeType &e) { // 带头结点删除指定位序的节点
  if(i < 1){
    return false;
  }
  // int j = 0;
  // LNode* p = L;
  // while (p != NULL && j < i-1){
  //   p = p->next;
  //   j ++;
  // }
  LNode* p = GetElem(L,i-1);//找到第i-1个位置
  if(p == NULL || p->next == NULL) {
    return false;
  }
  LNode* q = p->next;
  e = q->data;
  p->next = q->next;
  free(q);
  return true;

}

bool DeleteNode(LNode* p) { //删除指定节点
  if(p == NULL) {
    return false;
  }
  LNode* q = p->next;
  p->data = q->data; // 注意这里，如果p是最后一个的话，q是没有data的，只能从头遍历
  p->next = q->next;
  free(q);
  return true;
}

LNode* LocateElem(LinkList L, ElmeType e) { // 按值查找
  LNode* p = L->next;
  while(p != NULL && p->data != e) {
    p = p->next;
  }
  return p;
}

int Length(LinkList L){ // 求表长
  LNode* p = L->next;
  int len = 0;
  while(p != NULL) {
    p = p->next;
    len ++;
  }
  return len;
}

LinkList List_TailInsert(LinkList &L) { //带头节点的尾插法
  // L = (LinkList)malloc(sizeof(LNode));
  // L->next = NULL;
  InitList(L);
  LNode *s = L;
  LNode *r = L;
  ElmeType e;
  scanf("%d", &e);
  while (e != -1){
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    r->next = s;
    r = r->next; 
    scanf("%d", &e);
  }
  r->next = NULL; //记得把表尾指针置空
  return L;
  
}

LinkList List_HeadInsert(LinkList &L) { //带头节点的头插法
  // L = (LinkList)malloc(sizeof(LNode));
  // L->next = NULL;
  InitList(L);
  LNode *s = L;
  LNode *r = L;
  ElmeType e;
  scanf("%d", &e);
  while (e != -1){
    s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = r->next;
    r->next = s;
    scanf("%d", &e);
  }
  return L;
  
}

void re(LinkList &L) {//逆置单链表
  LNode *h = L->next, *r = L->next;
  for (int i = 0; i < 5; i++){
  	// printf("1%d %d\n", h->data,r->data);
    r = h->next;
    // printf("2%d %d\n", h->data,r->data);
    h->next = r->next;
    // printf("3%d %d\n", h->data,r->data);
    r->next = L->next;
    // printf("4%d %d\n", h->data,r->data);
    L->next = r;
    // printf("5%d %d\n", h->data,r->data);
  }
  h->next = NULL;
  // r->next = NULL;
  // LNode *h = L, *r = L;
  // h = L->next;
  // L->next = NULL;
  // for (int i = 0; i < 5; i++){
  //   r = h->next;
  //   h->next = L->next;
  //   L->next = h;
  //   h = r;
  // }
  // r->next = NULL;
}
int main() {
  LinkList L;
  List_TailInsert(L);
  LNode *p = L->next;
  for (int i = 0; i < 5; i++){
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
  
	p = L->next;
  while (p!=NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}
