/*
 * 多次元配列
 */
#include <stdio.h>

int main(void) {
  int a[4][3];
  int i, j;

  // 配列に値を代入
  for(j=0; j<3; j++)
    for(i=0; i<4; i++)
      a[i][j] = i+j;

  // 配列の値を表示
  for(j=0; j<3; j++) {
    for(i=0; i<4; i++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  return 0;
}

/* Output is here.
 * 0 1 2 3
 * 1 2 3 4
 * 2 3 4 5
*/
