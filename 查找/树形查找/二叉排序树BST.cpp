#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct BSTNode {//二叉排序树节点
  ElmeType data;
  struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

BSTNode *BST_Search(BSTree T, ElmeType key){//非递归实现搜索
  while(T!=NULL && T->data!=key){
    if(T->data > key){//值比key大
      T = T->lchild;//找它左边
    } else if(T->data < key){//小
      T = T->rchild;//找右边
    }
  }
  return T;
}

BSTNode *BSTSearch(BSTree T, ElmeType key){//递归实现搜索
  if(T == NULL){
    return T;
  }
  if(T->data == key){
    return T;
  }
  if(T->data < key){
    return BSTSearch(T->rchild,key);
  }
  if(T->data > key){
    return BSTSearch(T->lchild,key);
  }
}

bool BST_Insert(BSTree &T, ElmeType key){//非递归实现插入
  while(T!=NULL){
    if(T->data > key){//值比key大
      T = T->lchild;//去它左边
    } else if(T->data < key){//小
      T = T->rchild;//去右边
    } else{ //二叉搜索树不允许值相等的情况，报错
      return false;
    }
  }
  T = (BSTNode *)malloc(sizeof(BSTNode));//新建节点
  T->data = key;
  T->lchild = NULL;
  T->rchild = NULL;
  return true;
}

bool BSTInsert(BSTree &T, ElmeType key){//递归实现插入
  if(T == NULL){
    T = (BSTNode *)malloc(sizeof(BSTNode));//新建节点
    T->data = key;
    T->lchild = NULL;
    T->rchild = NULL;
    return true;
  }
  if(T->data == key){
    return false;
  }
  if(T->data > key){
    return BSTInsert(T->lchild, key);
  }
  if(T->data < key){
    return BSTInsert(T->rchild, key);
  }
}

bool BST_Delete(BSTree &T){//非递归实现删除
  if(T->lchild == NULL && T->rchild == NULL){//是叶子节点，直接删除就行
    T = NULL; 
    return true;
  }
  if(T->lchild != NULL && T->rchild == NULL){//只有左子树
    BSTNode *p = T->lchild;//找到左子树
    T->data = p->data;//让被删的节点数据等于左子树的值
    T->lchild = p->lchild;//让被删的节点的左孩子等于原左子树的左孩子
    T->rchild = p->rchild;//让被删的节点的右孩子等于原左子树的右孩子
    free(p);//释放原左子树节点，相当于删除了原来的T
    return true;
  }
  if(T->lchild == NULL && T->rchild != NULL){//只有右子树
    BSTNode *p = T->rchild;//找到右子树
    T->data = p->data;//让被删的节点数据等于右子树的值
    T->lchild = p->lchild;//让被删的节点的左孩子等于原右子树的左孩子
    T->rchild = p->rchild;//让被删的节点的右孩子等于原右子树的右孩子
    free(p);//释放原右子树节点，相当于删除了原来的T
    return true;
  }
  if(T->lchild != NULL && T->rchild != NULL){//左右子树都有
    BSTNode *p = T->lchild;//找到左子树
    BSTNode *q = T->rchild;//找到右子树

    T->data = q->data;//让被删的节点数据等于右子树的值
    T->lchild = q->lchild;//让被删的节点的左孩子等于原右子树的左孩子
    T->rchild = q->rchild;//让被删的节点的右孩子等于原右子树的右孩子
    //相当于让右子树替换了T

    while(q->lchild != NULL){//然后找到右子树最小的那个节点
      q = q->lchild;//也就是最左下角的节点
    }
    q->lchild = p;//让原右子树的最小节点的左孩子设置为原左子树

    return true;
  }
}

bool BSTDelete(BSTree &T){//递归实现删除
  if(T->lchild == NULL && T->rchild == NULL){//是叶子节点，直接删除就行
    T = NULL; 
    return true;
  }
  if(T->lchild != NULL && T->rchild == NULL){//只有左子树
    BSTNode *p = T->lchild;//找到左子树
    T->data = p->data;//让被删的节点数据等于左子树的值
    T->lchild = p->lchild;//让被删的节点的左孩子等于原左子树的左孩子
    T->rchild = p->rchild;//让被删的节点的右孩子等于原左子树的右孩子
    free(p);//释放原左子树节点，相当于删除了原来的T
    return true;
  }
  if(T->lchild == NULL && T->rchild != NULL){//只有右子树
    BSTNode *p = T->rchild;//找到右子树
    T->data = p->data;//让被删的节点数据等于右子树的值
    T->lchild = p->lchild;//让被删的节点的左孩子等于原右子树的左孩子
    T->rchild = p->rchild;//让被删的节点的右孩子等于原右子树的右孩子
    free(p);//释放原右子树节点，相当于删除了原来的T
    return true;
  }
  if(T->lchild != NULL && T->rchild != NULL){//左右子树都有
    BSTNode *p = T->rchild;//找到右子树
    while(p->lchild != NULL){//找到右子树最小的那个节点
      p = p->lchild;//也就是最左下角的节点
    }
    T->data = p->data;//让被删的节点数据等于右子树的值
    return BST_Delete(p);//递归，相当于按以上规则删除右子树最小的元素
  }
}