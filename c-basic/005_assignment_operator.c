/*
 * 代入演算子
 */
#include <stdio.h>

int main(void) {
  int a1=10, b1=10, c1=10, d1=10;
  int a2=10, b2=10, c2=10, d2=10;

  a1 = a1 + 1;
  b1 = b1 - 1;
  c1 = c1 * 2;
  d1 = d1 / 2;

  // 代入演算子を用いて計算
  a2 += 1;
  b2 -= 1;
  c2 *= 2;
  d2 /= 2;

  printf("a1=%d, b1=%d, c1=%d, d1=%d\n", a1, b1, c1, d1);
  printf("a2=%d, b2=%d, c2=%d, d2=%d\n", a2, b2, c2, d2);

  return 0;
}

/* Output is here.
 * a1=11, b1=9, c1=20, d1=5
 * a2=11, b2=9, c2=20, d2=5
*/
