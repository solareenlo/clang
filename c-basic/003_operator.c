#include <stdio.h>
/*
 * 演算子を用いた計算
 */
int main(void) {
  // 四則演算
  printf("%d + %d = %d\n", 3, 2, 3+2);
  printf("%d - %d = %d\n", 3, 2, 3-2);
  printf("%d * %d = %d\n", 3, 2, 3*2);
  printf("%d / %d = %d 余り %d\n", 3, 2, 3/2, 3%2);
  return(0);
}
