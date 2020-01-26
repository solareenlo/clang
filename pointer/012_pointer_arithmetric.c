/*
 * pointer の算術
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int main(int argc, char **argv) {
  int *p;
  int a[COUNT];
  int i;

  printf("int のサイズ：%ld byte\n", sizeof(int));

  for(i=0; i<COUNT; i++) {
    a[i] = i;
    printf("a[%d] = %d\n", i, a[i]);
  }

  p = a;
  printf("a のアドレス: %p, p の値: %p, p が指し示す値: %d.\n", a, p, *p);
  p = p + 1;
  printf("a のアドレス: %p, p の値: %p, p が指し示す値: %d.\n", a, p, *p);
  p = p + 2;
  printf("a のアドレス: %p, p の値: %p, p が指し示す値: %d.\n", a, p, *p);
  p = p + 1; // ここで初期化されていないメモリにアクセスしている．
  printf("a のアドレス: %p, p の値: %p, p が指し示す値: %d.\n", a, p, *p);

  return 0;
}

/* Output is here.
 * int のサイズ：4 byte
 * a[0] = 0
 * a[1] = 1
 * a[2] = 2
 * a[3] = 3
 * a のアドレス: 0x7ffee17aea30, p の値: 0x7ffee17aea30, p が指し示す値: 0.
 * a のアドレス: 0x7ffee17aea30, p の値: 0x7ffee17aea34, p が指し示す値: 1.
 * a のアドレス: 0x7ffee17aea30, p の値: 0x7ffee17aea3c, p が指し示す値: 3.
 * a のアドレス: 0x7ffee17aea30, p の値: 0x7ffee17aea40, p が指し示す値: -512038296.
 */
