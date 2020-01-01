/*
 * キャスト(型変換)
 */
#include <stdio.h>

int main(void) {
  int i1, i2, j1, j2;
  double d1, d2, e1, e2;

  j1 = 10;
  j2 = 10;
  d1 = 10.12;
  d2 = 10.12;
  i1 = d1;
  i2 = (int)d2;
  e1 = j1;
  e2 = (double)j2;

  printf("d1 = %f, d2 = %f\n", d1, d2);
  printf("i1 = %d, i2 = %d\n", i1, i2);
  printf("j1 = %d, j2 = %d\n", j1, j2);
  printf("e1 = %f, e2 = %f\n", e1, e2);

  return 0;
}

/* Output is here.
 * d1 = 10.120000, d2 = 10.120000
 * i1 = 10, i2 = 10
 * j1 = 10, j2 = 10
 * e1 = 10.000000, e2 = 10.000000
*/
