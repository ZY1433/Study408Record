#include<stdio.h>
#include<stdlib.h>

#define InitLen 255

// typedef struct StringNode{ //定义块链存储串
//   char *ch; //存储一个字符
//   StringNode *next; //指向下一个节点
// }StringNode, *String;

//这种方式和普通链表几乎一样，但是存储密度太低，一般采用下面这种

typedef struct StringNode{ //定义块链存储串
  char ch[4]; //存储多个字符
  StringNode *next; //指向下一个节点
}StringNode, *String;
