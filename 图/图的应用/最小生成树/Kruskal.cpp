#include <iostream>
#include <algorithm>

using namespace std;

#define ElmeType int
#define MaxVertexNum 5050

// 并查集
int UFSets[MaxVertexNum];

void Init(){ //初始化并查集
  for (int i = 0; i < MaxVertexNum; i++){
    UFSets[i] = i;
  }
}

int find(int i){ //查询根节点
  if(UFSets[i] == i){
    return i;
  } 
  return UFSets[i] = find(UFSets[i]);
}

void merge(int i, int j){ //合并节点
  UFSets[i] = find(j);
}

typedef struct ENode{ //定义邻接表的边
  int a; //从哪个节点
  int b; //指向哪一个节点
  int weight;
}ENode;


int kruskal(ENode e[], int elen, int vlen){ //传入排好序的所有边的数组,边数，节点数 输出最小权值
  int ans = 0;
  int cnt = 0;
  Init(); // 初始化并查集
  for (int i = 0; i < elen; i++){
    int a = find(e[i].a);
    int b = find(e[i].b);//找到两节点的连通分量
    if(a != b){ //若不相等，则可加入
      ans += e[i].weight;
      merge(a,b);//将其合并
      cnt ++;//边数++
    }
    if(cnt == vlen-1){//边数为节点数-1
      break;//跳出循环
    }
  }
  return ans;
}

bool cmp(ENode x, ENode y)//根据权重排序
{
	return x.weight<y.weight;
}

int main(){
  int n,m;
  scanf("%d %d",&n, &m);
  ENode E[m+5];
  for (int i = 0; i < m; i++){
    int a, b, w;
    scanf("%d %d %d",&a, &b, &w);
    E[i].a = a;
    E[i].b = b;
    E[i].weight = w;
  }
  sort(E,E+m,cmp);

  printf("%d",kruskal(E, m, n));
  system("pause");
}