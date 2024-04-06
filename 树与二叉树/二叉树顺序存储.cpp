#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

struct TreeNode {
  ElmeType value;
  bool isEmpty;
};
static TreeNode t[MAXSIZE];

bool InitTreeList() { 
  for (size_t i = 1; i < MAXSIZE; i++){
    t[i].isEmpty = true;
  }
  return true;
}
int getLChild(int i){//求左孩子位置
  return 2*i;
}
int getRChild(int i){//求右孩子位置
  return 2*i+1;
}
int getParent(int i){//求父节点位置
  return i/2;
}
int getLevel(int n){ //求树高
  return (int)(log(n)/log(2)) +1;
}
int LCA(int i, int j) {//最近公共祖先
  
  while (i != j){
    if(i > j){
      i /= 2;
    } 
    if(j > i) {
        j /= 2;
    }
  }
  return i;

}

int main() {
  InitTreeList();
  printf("%d",getLevel(10));
}