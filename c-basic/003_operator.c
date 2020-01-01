/*
 * 演算子
 */
#include <stdio.h>

int main(void) {
  // 四則演算
  printf("%d + %d = %d\n", 3, 2, 3+2);
  printf("%d - %d = %d\n", 3, 2, 3-2);
  printf("%d * %d = %d\n", 3, 2, 3*2);
  printf("%d / %d = %d 余り %d\n", 3, 2, 3/2, 3%2);

  return(0);
}

/* Output is here.
 * 3 + 2 = 5
 * 3 - 2 = 1
 * 3 * 2 = 6
 * 3 / 2 = 1 余り 1
*/
