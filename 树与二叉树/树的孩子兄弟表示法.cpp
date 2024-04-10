#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct CSNode{//树的节点
  ElmeType data;
  struct CSNode *firstChild;//第一个孩子
  struct CSNode *nextSibling;//右兄弟
}CSNode, *CSTree;
/*
  找孩子方便，要想方便找双亲，需要加一个双亲指针
  最后存出来是一棵二叉树的形式，森林也会被存成一棵二叉树
  （森林里每棵树根节点视为兄弟）
*/
void visit(CSNode *node){//访问节点
  printf("%d\n",node->data);
}

void ProOrder(CSNode *t){//树的先根遍历
  if(t == NULL){
    return;
  }
  visit(t);//访问当前节点
  ProOrder(t->firstChild);//找左孩子
  ProOrder(t->nextSibling);//由于相当于是二叉树，所以孩子找完找兄弟
}

void PostOrder(CSNode *t){//树的后根遍历
  if(t == NULL){
    return;
  }
  ProOrder(t->firstChild);//先把所有左孩子找到
  visit(t);//访问当前节点
  ProOrder(t->nextSibling);
  //由于相当于是二叉树，所以孩子找完了，根节点又没有右子树，
  //所以就该找兄弟了
}

typedef struct LinkQNode{//链式队列节点
  CSNode *data;//存树的指针
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
int EnQueue(LinkQueue Q, CSNode *T){//入队

	LinkQNode* tempNode;//声明一个临时结点
	
	tempNode = (LinkQNode*)malloc(sizeof(LinkQNode));
	tempNode->data = T;
	tempNode->next = NULL;
	Q->rear->next = tempNode;
	Q->rear = tempNode;		
	return true;
}
CSNode* DeQueue(LinkQueue Q, CSNode *t){//出队
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

void LevelOrder(CSTree T){//层次遍历
  LinkQueue Q;
  initLinkQueue(Q);
  CSNode *p;
  EnQueue(Q,T);
  while(!QEmpty(Q)){
    DeQueue(Q,p);
    visit(p);
    if(p->firstChild != NULL){
      EnQueue(Q,p->firstChild);
      p = p->firstChild;
    }
    while(p->nextSibling != NULL){
      EnQueue(Q,p->nextSibling);
    }
  }
}