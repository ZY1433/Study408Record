#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct AVLNode {//平衡二叉树节点
  ElmeType data;//数据
  int balance; //平衡因子(左树高-右树高)
  struct AVLNode *lchild, *rchild;
}AVLNode, *AVLTree;

void Left(AVLTree &gf, AVLTree &f, AVLTree &p, int type){ //左旋操作
  //gf是f的父节点，p是f的右孩子，type为1代表f是gf的右孩子，为0代表是左孩子
  //f是最小不平衡子树
  f->rchild = p->lchild;//f的右孩子指向改为p的左孩子
  p->lchild = f; //p的左孩子指向f
  if(type == 1){
    gf->rchild = p;  //gf指向p
  } else{
    gf->lchild = p;
  }
}

void Right(AVLTree &gf, AVLTree &f, AVLTree &p, int type){// 右旋操作
  //gf是f的父节点，p是f的左孩子，type为1代表f是gf的右孩子，为0代表是左孩子
  //f是最小不平衡子树 
  f->lchild = p->rchild;//f的左孩子指向改为p的右孩子
  p->rchild = f; //p的右孩子指向f
  if(type == 1){
    gf->rchild = p;
  } else{
    gf->lchild = p; //gf指向p
  }
}

void LeftRight(AVLTree &gf, AVLTree &f, AVLTree &p, AVLTree &q, int type){ //LR操作
  //f是最小不平衡子树，gf是f的父节点，p是f的左孩子，q是p的右孩子，
  //type为1代表f是gf的右孩子，为0代表是左孩子
  Left(f,p,q,0);//先对pq进行左旋
  Right(gf,f,p,type);//再对新的fp进行右旋(此时f还是f，但是p已经改为原来的q)
}

void RightLeft(AVLTree &gf, AVLTree &f, AVLTree &p, AVLTree &q, int type){ //RL操作
  //f是最小不平衡子树，gf是f的父节点，p是f的右孩子，q是p的左孩子，
  //type为1代表f是gf的右孩子，为0代表是左孩子
  Right(f,p,q,1);//先对pq进行右旋
  Left(gf,f,p,type);//再对新的fp进行左旋(此时f还是f，但是p已经改为原来的q)
}

//插入
/*
  对于插入，在插入后，在插入路径上寻找最小不平衡子树，
  然后根据插入位置在该最小不平衡子树里的位置进行平衡，分为以下4种：
  LL：插入位置在最小不平衡子树的左子树的左子树
    对最小不平衡子树进行右旋操作即可

  RR：插入位置在最小不平衡子树的右子树的右子树
    对最小不平衡子树进行左旋操作即可

  LR：插入位置在最小不平衡子树的左子树的右子树
    对最小不平衡子树进行LR操作

  RL：插入位置在最小不平衡子树的右子树的左子树
    对最小不平衡子树进行RL操作

  这样就更新为新的平衡二叉树了
*/

//删除
/*
  对于删除，和二叉排序树的删除相同
  分为3种情况，叶子节点直接删除，只有左或右子树的用子树替代原有位置即可
  左右子树都有的，可以用右子树替代原有位置，然后让原左子树成为原右子树最小节点的左子树

  删除后，沿着删除位置向根节点寻找，若找到不平衡子树
  找它的最高的儿子和最高的孙子，记为pq，根据pq位置进行旋转
  先儿子后孙子位置分为4种：
  LL,RR,LR,RL
  分别和插入进行同样操作即可

  在当前不平衡子树平衡完毕后，可能将不平衡向上传递，所以要继续向上寻找
  直到根节点也判断完毕，则所有子树均为平衡二叉树了
  这样就更新为平衡二叉树了
*/