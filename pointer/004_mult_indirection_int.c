/*
 * ポインタのポインタを使って，ポインタのアドレスを表示
 */
#include <stdio.h>

#define LENGTH 3

int data[LENGTH];

int main(int argc, char **argv) {
  int *pi;
  int **ppi;
  int i;

  printf("複数の間接参照の例\n");

  // int 型配列の初期化
  for(i=0; i<LENGTH; i++) {
    data[i] = i;
  }

  pi = data;
  ppi = &pi;

  for(i=0; i<LENGTH; i++) {
    printf("array address is %p\n", data);
    printf("item pointed to by pi is %d\n", *pi);
    printf("item pointed to by double indirection of ppi is %d\n", **ppi);
    printf("The address of pi is %p and the value of ppi is %p\n", &pi, ppi);
    printf("The value of pi is %p and it points to %d\n\n", pi, *pi);
    pi += 1;
  }

  return 0;
}

/* Output is here.
 * array address is 0x10877c010
 * item pointed to by pi is 0
 * item pointed to by double indirection of ppi is 0
 * The address of pi is 0x7ffee7485a38 and the value of ppi is 0x7ffee7485a38
 * The value of pi is 0x10877c010 and it points to 0
 *
 * array address is 0x10877c010
 * item pointed to by pi is 1
 * item pointed to by double indirection of ppi is 1
 * The address of pi is 0x7ffee7485a38 and the value of ppi is 0x7ffee7485a38
 * The value of pi is 0x10877c014 and it points to 1
 *
 * array address is 0x10877c010
 * item pointed to by pi is 2
 * item pointed to by double indirection of ppi is 2
 * The address of pi is 0x7ffee7485a38 and the value of ppi is 0x7ffee7485a38
 * The value of pi is 0x10877c018 and it points to 2
 */
