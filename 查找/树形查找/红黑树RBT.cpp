#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

typedef struct RBTNode {//红黑树节点
  ElmeType data;//数据
  bool color;//颜色 false代表黑，true代表红 
  struct RBTNode *lchild, *rchild;
  struct RBTNode *parent; //父节点
}RBTNode, *RBTree;

void LeftDyeing(RBTree f){ //左旋染色操作
  //f是新插入节点的爷节点
  RBTree p = f->parent;//p为f的父节点
  RBTree c = f->rchild;//c为f的右孩子，因为只有右孩子需要左旋

  f->rchild = c->lchild;//f的右孩子指向改为c的左孩子
  if(c->lchild != NULL){//当c的左孩子不空
    c->lchild->parent = f;//让它的父指针指向f
  }
  c->lchild = f; //c的左孩子指向f
  f->parent = c;//此时让f的父指针指向c
  if(p != NULL){//p不为空，也就是原来f不是根
    if (p->lchild == f) {//判断f是左孩子还是右孩子
      p->lchild = c;
    } else {
      p->rchild = c;//让f原来父节点指向c
    }
    c->parent = p;//让c的父指针指向原来f的父指针
  }
  c->color = !c->color;
  f->color = !f->color;//对c和f染色
}

void RightDyeing(RBTree f){// 右旋操作染色操作
  //f是新插入节点的爷节点
  RBTree p = f->parent;//p为f的父节点
  RBTree c = f->lchild;//c为f的左孩子，因为只有左孩子需要右旋

  f->lchild = c->rchild;
  if(c->rchild != NULL){
    c->rchild->parent = f;
  }
  c->rchild = f;
  f->parent = c;

  if(p!= NULL){
    if(p->lchild = f){
      p->lchild = c;
    } else{
      p->rchild = c;
    }
    c->parent = p;
  }
  c->color = !c->color;//染色
  f->color = !f->color;//染色
}

void LeftRightDyeing(RBTree f){ //LR操作
  //f是新插入节点的爷节点
  RBTree p = f->parent;//p为f的父节点
  RBTree c = f->lchild;//c为f的左孩子，因为是LR
  RBTree gc = c->rchild;//gc为c的右孩子，也就是f的孙子

  //gc和c进行左旋
  c->rchild = gc->lchild;//c的右孩子指向gc的左孩子
  if(gc->lchild != NULL){
    gc->lchild->parent = c;//不空，让其父指针指向c
  }
  gc->lchild = c;//孙子的左孩子指向c
  c->parent = gc;//c的父指向gc
  f->lchild = gc;//f的左孩子指向gc
  gc->parent = f;//gc的父先指向f

  //现在的gc再和f进行右旋
  f->lchild = gc->rchild;//爷的左指向孙的右
  if(gc->rchild != NULL){//孙右不为空
    gc->rchild->parent = f;//孙的父改为爷
  }
  gc->rchild = f;//孙的右孩子改为爷
  f->parent = gc;//爷的父改为孙

  if(p != NULL){//若原来爷的父不空
    if(p->lchild = f){//看原来爷是左孩子还是右孩子
      p->lchild = gc;//让它指到孙
    } else{
      p->rchild = gc;
    }
    gc->parent = p;//让孙的父改为爷的父
  }

  //染色
  gc->color = !gc->color;
  f->color = !f->color;//爷孙染色
}

void RightLeftDyeing(RBTree f){ //RL操作
  //f是新插入节点的爷节点
  RBTree p = f->parent;//p为f的父节点
  RBTree c = f->rchild;//c为f的右孩子，因为这是RL
  RBTree gc = c->lchild;//gc为c的左孩子，也就是f的孙子

  //gc和c进行右旋
  c->lchild = gc->rchild;//c的左孩子指向gc的右孩子
  if(gc->rchild != NULL){
    gc->rchild->parent = c;//不空，让其父指针指向c
  }
  gc->rchild = c;//孙子的右孩子指向c
  c->parent = gc;//c的父指向gc
  f->rchild = gc;//f的右孩子指向gc
  gc->parent = f;//gc的父先指向f

  //现在的gc再和f进行左旋
  f->rchild = gc->lchild;//爷的右指向孙的左
  if(gc->lchild != NULL){//孙左不为空
    gc->rchild->parent = f;//孙的父改为爷
  }
  gc->lchild = f;//孙的左孩子改为爷
  f->parent = gc;//爷的父改为孙

  if(p != NULL){//若原来爷的父不空
    if(p->lchild = f){//看原来爷是左孩子还是右孩子
      p->lchild = gc;//让它指到孙
    } else{
      p->rchild = gc;
    }
    gc->parent = p;//让孙的父改为爷的父
  }

  //染色
  gc->color = !gc->color;
  f->color = !f->color;//爷孙染色
}

//插入
/*
  红黑树的插入和AVL树有点像
  先是按照排序树的方式找到新加的数应当在的位置
  将其置为红色
  判断

  若它是根节点，则置为黑即可

  若其父节点是黑色，无需任何调整

  若其父也是红色，则判断叔叔(父亲兄弟)的颜色
    若叔叔是黑色，判断新插入节点和其爷节点的位置关系
      分为RR,LL,LR,RL四种情况，与AVL树操作类似
      前两者分别对其父进行左旋、右旋，结束后对其父和爷节点颜色取反
      后两者分别对它进行先左再右旋 和 先右再左旋，注意这种情况对它和它爷染色

    若它叔也是红色
      将其父和叔都改为黑色，把它爷当作新的节点，染红，对爷重复进行上述所有判断操作
      直至所有节点均正常
*/

//删除
/*
  与二叉排序树类似，分为三种情况
  1.没有孩子，直接删除
  2.只有左子树或者只有右子树，直接用子树替代它
  3.左右子树都有，找到它的直接前驱或者后继替换它，然后转换成
  删除它的直接前驱或者后继，最后转换为前两种情况

  在删除后，红黑树的性质可能被破环，所以要进行调整
  由于第3种会转换成前两种，所以只用考虑前两种

  对于2.只有左子树或者只有右子树，由于红黑树的性质

  两个红违反性质，不可行
  一个黑节点若只包含一边包含黑节点的子树，则含子树那边会大于无子树那边，不可行
  红节点后只包含一边包含黑节点子树的情况同理不可行
  所以只可能存在
    被删的为黑色节点，且其只有一个红色的左孩子或者红色的右孩子节点这种情况
  所以只需要红色节点补上被删节点，且染成黑色即可

  对于没有孩子的情况：
    若删除的是红节点，则不会破坏性质，不需要调整

    （先引入双黑节点概念被删除的黑节点需先置为双黑节点
    到双黑节点被消除，删除才算结束）

    若删除的是黑节点，先将其置为双黑节点，然后观察它的兄弟节点
    (此时先标记被删除节点的父节点为p,兄弟节点为s,兄弟的一个孩子节点为r)
      若其兄弟是黑色节点
        观察它兄弟的孩子节点
          若存在红色孩子
          
            然后根据r对于p的位置分为4种情况：LL，RR，LR，RL
            这时和AVL树相似，就是多了一步染色
              对于前两种情况(LL,RR)
                需要让r的颜色变为s的颜色，s变为p的颜色，p变黑，
                再分别进行右旋或左旋
              对后两种情况(LR,RL)
                需要让r的颜色变为p的颜色,p变黑
                再进行 左右旋 或 右左旋即可
            旋转过后，性质就已恢复，可将双黑变为单黑，结束

          若兄弟没有红孩子
            让兄弟变红，然后双黑节点上移到父节点
              当双黑节点上移过程中遇到红色节点，将该节点转换成黑节点，双黑消除
              双黑节点到根节点，不用修改，双黑消除

            若仍双黑存在，则判断双黑的兄弟节点是否符合其它条件，
            直至双黑消除，删除完毕
        
      若兄弟是红色节点
        先让兄弟和父亲变色(兄变黑，父变红)
        然后朝双黑节点旋转，双黑节点保持存在
        根据新的情况继续判断双黑节点新的兄弟符合的条件，
        直至双黑消除

  至此，所有红黑树的删除情况解析完毕。     

            

*/