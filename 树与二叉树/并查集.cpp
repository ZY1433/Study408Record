#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ElmeType int
#define MAXSIZE 100

int UFSets[MAXSIZE];

void Initial(int s[]){//初始化
  for (size_t i = 0; i < MAXSIZE; i++){
    s[i] = -1;
  }
}

// int Find(int s[], int x){//找到x的根节点
//   while (s[x] >= 0){
//     x = s[x];
//   }
//   return x;
// }

// void Union(int s[], int r1, int r2){//合并两棵树 此时find的时间复杂度为O(n),将n个元素合并的总时间复杂度为O(n^2)
//   if(r1 == r2){
//     return;
//   }
//   s[r2] = r1;
// }

void Union(int s[], int r1, int r2){//优化后的版本，这时每个根节点的绝对值代表其有几个节点 此时find的时间复杂度为O(log(n)) 此时总时间复杂度为O(nlog(n))
  if(r1 == r2){
    return;
  }
  if(s[r1] > s[r2]){//当r2的节点比r1多(因为是绝对值，所以大的反而节点少)
    s[r2] += s[r1];//给r2加上r1的节点数
    s[r1] = r2;//r1的根节点设置为r2
  } else{
    s[r1] += s[r2];
    s[r2] = r1;
  }
}

int Find(int s[], int x){//路径压缩  时间复杂度O(a(n)),a(n)是个增长很慢的函数，大多数情况下a(n)<=4 此时总时间复杂度为O(a(n)n)
  if (s[x] < 0){//如果是根节点，说明找到了
    return x;//返回
  } else{ //如果不是根节点，则递归
    s[x] = Find(s, s[x]);//且把结果传回来，更新路径上的每个节点的根
    return s[x];
  }
  
}