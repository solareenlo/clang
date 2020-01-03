/*
 * 変数のアドレス
 */
#include <stdio.h>

int main(void) {
  int a = 100;
  double b = 1.1;
  float c = 12.3f;
  char d = 'a';

  printf("aの値は%d, 大きさは%ldbyte, アドレスは0x%p\n", a, sizeof(int), &a);
  printf("bの値は%f, 大きさは%ldbyte, アドレスは0x%p\n", b, sizeof(double), &b);
  printf("cの値は%f, 大きさは%ldyte, アドレスは0x%p\n", c, sizeof(float), &c);
  printf("dの値は%c, 大きさは%ldyte, アドレスは0x%p\n", d, sizeof(char), &d);
  /* %ld は倍精度整数を10進で出力する */
  /* %p はアドレスを16進数8桁で表示する */

  return 0;
}

/* Output is here.
 * aの値は100, 大きさは4byte, アドレスは0x0x7ffd4865b108
 * bの値は1.100000, 大きさは8byte, アドレスは0x0x7ffd4865b110
 * cの値は12.300000, 大きさは4yte, アドレスは0x0x7ffd4865b10c
 * dの値はa, 大きさは1yte, アドレスは0x0x7ffd4865b107
*/
