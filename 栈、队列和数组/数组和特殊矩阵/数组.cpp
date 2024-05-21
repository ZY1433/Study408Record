/*
  这个主要就是让手算地址
  一维数组地址：
  LOC(a[i]) = LOC(a[0]) + i*sizeof(ElemType);

  二维数组地址(共N行M列)
  行优先：
  LOC(a[i][j]) = LOC(a[0][0]) + (i*N + j)*sizeof(ElemType);
  列优先：
  LOC(a[i][j]) = LOC(a[0][0]) + (j*N + i)*sizeof(ElemType);
*/