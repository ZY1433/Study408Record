#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct BiTNode {
  ElmeType data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree InitBiTList(ElmeType e) { 
  BiTree root = NULL;
  root = (BiTree)malloc(sizeof(BiTNode));
  root->data = e;
  root->lchild = NULL;
  root->rchild = NULL;
}

bool InsertNextBiTNode(BiTNode* t, ElmeType e, bool left) {// 在t左边或右边插入e
  BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
  p->data = e;
  p->lchild = NULL;
  p->rchild = NULL;

  if(left){
    if(t->lchild == NULL){
      t->lchild = p;
      return true;
    }
    return false;
  }
  if(t->rchild == NULL){
      t->rchild = p;
      return true;
    }
  return false;
}

void visit(BiTNode *T){//访问节点
  printf("%d\n",T->data);
}
void ProOrder(BiTree T) {//递归先序遍历
  if(T == NULL){
    return;
  }
  visit(T);
  ProOrder(T->lchild);
  ProOrder(T->rchild);
}
void InOrder(BiTree T) {//递归中序遍历
  if(T == NULL){
    return;
  }
  ProOrder(T->lchild);
  visit(T);
  ProOrder(T->rchild);
}
void PostOrder(BiTree T) {//递归后序遍历
  if(T == NULL){
    return;
  }
  ProOrder(T->lchild);
  ProOrder(T->rchild);
  visit(T);
}
int TreeDepth(BiTree T) { //求树的深度
  if(T == NULL){
    return 0;
  }
  int l = TreeDepth(T->lchild);
  int r = TreeDepth(T->rchild);
  return l > r ? l+1 : r+1;
}

typedef struct LinkQNode{//链式队列节点
  BiTNode *data;//存树的指针
  struct LinkQNode *next;
}LinkQNode;
typedef struct LinkQueue{//链式队列
	LinkQNode* front;//队头指针 相当于LinkQNode *front 
	LinkQNode* rear;//队尾指针	
}*LinkQueue;
bool initLinkQueue(LinkQueue Q){//初始化队列函数
	Q->front  = (LinkQNode*)malloc(sizeof(LinkQNode));
	Q->rear = Q->front;
	if(!Q->front)return false;
        //成功
	Q->front->next = NULL;
	return true;
}
int EnQueue(LinkQueue Q, BiTNode *T){//入队

	LinkQNode* tempNode;//声明一个临时结点
	
	tempNode = (LinkQNode*)malloc(sizeof(LinkQNode));
	tempNode->data = T;
	tempNode->next = NULL;
	Q->rear->next = tempNode;
	Q->rear = tempNode;		
	return true;
}
BiTNode* DeQueue(LinkQueue Q, BiTNode *t){//出队
	//若队列为空
	if(Q->front==Q->rear) {
		return NULL;  
	}
	//若队列不空，则让队列头部元素出队 
	LinkQNode* p = Q->front->next;
	Q->front->next = p->next; 
	//如果只有一个元素，该元素出队后，就让尾指针和头指针指向相同，相当于重置链队列
	if(Q->rear==p) Q->rear = Q->front; 
	//如果不止一个元素，就不用重置尾指针位置 
  t = p->data;
	free(p);
	return t;
} 
bool QEmpty(LinkQueue Q){
  if(Q->front==Q->rear) {
		return false;  
	}
  return true;
}

void LevelOrder(BiTree T){//层次遍历
  LinkQueue Q;
  initLinkQueue(Q);
  BiTNode *p;
  EnQueue(Q,T);
  while(!QEmpty(Q)){
    DeQueue(Q,p);
    visit(p);
    if(T->lchild != NULL){
      EnQueue(Q,T->lchild);
    }
    if(T->rchild != NULL){
      EnQueue(Q,T->rchild);
    }
  }
}