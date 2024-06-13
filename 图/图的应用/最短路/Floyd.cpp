#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define INF 0x3f3f3f3f

typedef struct { //定义邻接矩阵的图
  char Vex[MaxVertexNum];
  int Edge[MaxVertexNum][MaxVertexNum]; //带权图时
  int VexNum, EdgeNum; //当前的顶点数和边数
}MGraph;

int path[MaxVertexNum][MaxVertexNum];
int ans[MaxVertexNum][MaxVertexNum];
void floyd(MGraph G) { //基于邻接矩阵
  for (int i = 0; i < G.VexNum; i++){//初始ans数组为图的初始状态
    for (int j = 0; j < G.VexNum; j++){
      ans[i][j] = G.Edge[i][j];
    }
  }

  for (int k = 0; k < G.VexNum; k++){ //可作为中转的顶点
    for (int i = 0; i < G.VexNum; i++){
      for (int j = 0; j < G.VexNum; j++){
        if(ans[i][j] > ans[i][k] + ans[k][j]){
          path[i][j] = k;
          ans[i][j] = ans[i][k] + ans[k][j];
        }
      }
    }
  }
}

void getPath(int i, int j){//输出中间路径，开始和结尾要先自己输出
  if(path[i][i]==-1) return;//因为开始初始化为-1，这里就可以避免相邻的再次输出 
	getPath(i,path[i][j]);//前半部 
	printf("%d-->",path[i][j]);
	getPath(path[i][j],j);//后半部 
  
}
