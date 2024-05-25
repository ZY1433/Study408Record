#include<stdio.h>
#include<stdlib.h>

#define MaxLen 255

typedef struct { //定义定长顺序存储串
  char ch[MaxLen];
  int length;
}SString;

void get_next(int next[],SString T){
  int j = 1, k = 0;//j指的是后缀的末尾，k指向的是前缀的末尾
  next[1] = 0;//由于第一个没有前缀也没后缀，让它指向0
  while (j < T.length){
    if(k == 0 || T.ch[j] == T.ch[k]){//当前缀末尾为0或者前缀和后缀末尾相同时
      j ++;
      k ++;//两个位置均往后加一个
      next[j] = k;//现在的j指的是当前的位置，k是前缀的后一个

      //也可以下面这样写
      // next[j+1] = k+1;
      // j ++;
      // k ++;
    } else{//当有前缀，且前缀和后缀末尾不相同
      k = next[k];//前缀末尾改成前缀这个子串的前缀
    }
  }
  
}

void get_nextval(int nextval[],SString T){
  int j = 1, k = 0;//j指的是后缀的末尾，k指向的是前缀的末尾
  nextval[1] = 0;//由于第一个没有前缀也没后缀，让它指向0
  while (j < T.length){
    if(k == 0 || T.ch[j] == T.ch[k]){//当前缀末尾为0或者前缀和后缀末尾相同时
      j ++;
      k ++;//两个位置均往后加一个
      if(T.ch[j] == T.ch[k]){ //若当前位置与前缀后一个相同时，匹配必定失败
        nextval[j] = nextval[k]; //让其指向前缀后一个位置的前缀后一
      } else{ //不相同时和之前一样
        nextval[j] = k;//现在的j指的是当前的位置，k是前缀的后一个
      }
    } else{//当有前缀，且前缀和后缀末尾不相同
      k = nextval[k];//前缀末尾改成前缀这个子串的前缀
    }
  }
  
}

int Index_KMP(SString S, SString T, int next[]){
  int i = 1, j = 1;
  while (i <= S.length && j <= T.length){
    if(j==0 || S.ch[i] == T.ch[j]){
      i++;
      j++;
    } else{
      j = next[j];
    }
  }
  if(j > T.length){
    return i - T.length;
  }
  return 0;
}

int main(){//简单测试
  SString S,T;
  char s[] = {'a','b','c','d','a','s','d'};
  char t[] = {'b','c','d'};
  S.length = 7;
  T.length = 3;
  for(int i = 1; i <= S.length; i ++){
    S.ch[i] = s[i-1];
  }
  for(int i = 1; i <= T.length; i ++){
    T.ch[i] = t[i-1];
  }
  
  int next[10];
  get_nextval(next,T);
  printf("%d\n",Index_KMP(S,T,next));
  // for(int i = 1; i <= 5; i ++){
  //   printf("%d\n",next[i]);
  // }
}
