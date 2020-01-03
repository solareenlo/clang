/*
 * ポインタ
 */
#include <stdio.h>

void show(int, int, int);

int main(void) {
  int a = 100;
  int b = 200;
  int* p = NULL; // 整数型のポインタ p を初期化

  p = &a;
  show(a, b, *p);
  *p = 300;
  show(a, b, *p);
  p = &b;
  show(a, b, *p);
  *p = 400;
  show(a, b, *p);

  return 0;
}

void show(int a, int b, int c) {
  printf("a=%d, b=%d, c=%d\n", a, b, c);
}

/* Output is here.
 * a=100, b=200, c=100
 * a=300, b=200, c=300
 * a=300, b=200, c=200
 * a=300, b=400, c=400
*/
