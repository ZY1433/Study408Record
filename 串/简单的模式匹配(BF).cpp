#include<stdio.h>
#include<stdlib.h>

#define MaxLen 255

typedef struct { //定义定长顺序存储串
  char ch[MaxLen];
  int length;
}SString;

// int Index(SString S, SString T){
//   int len1 = S.length;
//   int len2 = T.length;
//   for (int i = 1; i <= len1 - len2; i++){
//   	bool flag = true;
//     for (int j = 1; j <= len2; j++){
//       if(S.ch[i+j-1] != T.ch[j]){
//       	flag = false;
//         break;
//       }
//     }
//     if(flag)
//     	return i;
//   }
//   return 0;
// }

int Index(SString S, SString T){
  int i = 1;
  int j = 1;
  
  while (i <= S.length && j <= T.length){
    if(S.ch[i] == T.ch[j]){
      i++;
      j++;
    } else{
      i = i-j+2;
      j = 1;
    }
  }
  if(j > T.length){
    return i-j+1;
  } else{
    return 0;
  }
  
}

int main(){//简单测试
  SString S,T;
  char s[] = {'a','b','c','d','a','s','d'};
  char t[] = {'d','a','s'};
  for(int i = 1; i <= 7; i ++){
    S.ch[i] = s[i-1];
  }
  for(int i = 1; i <= 3; i ++){
    T.ch[i] = t[i-1];
  }
  S.length = 7;
  T.length = 3;
  printf("%d\n",Index(S,T));
}
