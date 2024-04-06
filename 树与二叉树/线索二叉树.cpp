#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct TreadNode {
  ElmeType data;
  struct TreadNode *lchild, *rchild;
  int ltag, rtag;//当值为1的时候代表左右孩子指向的是线索
}TreadNode, *TreadTree;

TreadTree InitBiTList(ElmeType e) { 
  TreadTree root = NULL;
  root = (TreadTree)malloc(sizeof(TreadNode));
  root->data = e;
  root->lchild = NULL;
  root->rchild = NULL;
  root->ltag = 0;
  root->rtag = 0;
}

bool InsertNextBiTNode(TreadNode* t, ElmeType e, bool left) {//在t左边或右边插入e
  TreadNode *p = (TreadNode*)malloc(sizeof(TreadNode));
  p->data = e;
  p->lchild = NULL;
  p->rchild = NULL;
  p->ltag = 0;
  p->rtag = 0;
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


void visit(TreadNode *T,TreadNode* &pre){//访问节点，看是否可以线索化
  if(T->lchild == NULL){//左孩子是空的
    T->ltag = 1;
    T->lchild = pre;
  }
  if(pre != NULL && pre->rchild == NULL){//pre被更新过，且pre右孩子为空
    T->rtag = 1;
    pre->rchild = T;
  }
  pre = T;//更新pre
}

void InTread(TreadTree T, TreadNode* &pre){//中序遍历并线索化
  if(T != NULL){
    InTread(T->lchild,pre);
    visit(T,pre);
    InTread(T->rchild,pre);
  }
}
void CreateInTread(TreadTree T) {//创建中序线索二叉树
  TreadNode *pre = NULL;
  if(T != NULL){
    InTread(T,pre);
    if(pre->rchild == NULL){
      pre->rtag = 1;//需要再处理一步
    }
  }
}

void PreTread(TreadTree T, TreadNode* &pre){//先序遍历并线索化
  if(T != NULL){
    visit(T,pre);
    if(T->ltag == 0){//防止出现循环
      InTread(T->lchild,pre);
    }
    InTread(T->rchild,pre);
  }
}
void CreatePreTread(TreadTree T) {//创建先序线索二叉树
  TreadNode *pre = NULL;
  if(T != NULL){
    InTread(T,pre);
    if(pre->rchild == NULL){
      pre->rtag = 1;//需要再处理一步
    }
  }
}

void PostTread(TreadTree T, TreadNode* &pre){//后序遍历并线索化
  if(T != NULL){
    InTread(T->lchild,pre);
    InTread(T->rchild,pre);
    visit(T,pre);
  }
}
void CreatePostTread(TreadTree T) {//创建后序线索二叉树
  TreadNode *pre = NULL;
  if(T != NULL){
    InTread(T,pre);
    if(pre->rchild == NULL){
      pre->rtag = 1;//需要再处理一步
    }
  }
}
TreadNode *InFindFirstNode(TreadNode *p){//按中序找到指定节点下第一个访问的节点
  while (p->ltag == 0){
    p = p->lchild;
  }
  return p;
}
TreadNode *InFindLastNode(TreadNode *p){//按中序找到指定节点下最后一个访问的节点
  while (p->ltag == 0){
    p = p->rchild;
  }
  return p;
}
TreadNode *InNextNode(TreadNode *p){//中序线索二叉树找后继
  if(p->rtag == 1){
    return p->rchild;
  }
  if(p->rtag == 0){
    return InFindFirstNode(p->rchild);
  }
}
TreadNode *InpreNode(TreadNode *p){//中序线索二叉树找前驱
  if(p->rtag == 1){
    return p->lchild;
  }
  if(p->rtag == 0){
    return InFindLastNode(p->lchild);
  }
}