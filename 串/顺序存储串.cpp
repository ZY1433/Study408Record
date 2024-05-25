#include<stdio.h>
#include<stdlib.h>

#define MaxLen 255

typedef struct { //定义定长顺序存储串
  char ch[MaxLen];
  int length;
}SString;

bool SubString(SString &Sub, SString S, int pos, int len){ 
  // 用Sub返回S中从pos开始的长度为len的子串
  if(pos + len -1 > S.length){ //子串越界
    return false;
  }
  for (int i = pos; i < pos + len; i++){
    Sub.ch[i-pos+1] = S.ch[i]; 
  }
  Sub.length = len;
  return true;
}

int StrCompare(SString S, SString T){// 若S>T则返回>0,反之则<0,完全相等返回0
  for (int i = 1; i <= S.length && i <= T.length; i++){
    if(S.ch != T.ch){
      return S.length - T.length;
    }
  }
  return S.length - T.length;
}

int Index(SString S, SString T){
  SString sub;
  int len1 = S.length;
  int len2 = T.length;
  for (int i = 1; i < len1 - len2 + 1; i++){
    SubString(sub,S,i,len2);
    if(StrCompare(sub,T) == 0){
      return i;
    } 
  }
  return 0;
}