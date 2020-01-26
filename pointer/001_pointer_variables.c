/*
 * ポインタ使ってアドレスを表示
 */
#include <stdio.h>

int main(int argc, char **argv) {
  int num;
  int *numPtr;
  int num2;

  num = 100;
  numPtr = &num;
  num2 = *numPtr;

  printf("num=%d, numPtr=%p, address of num=%p, num2=%d\n", num, numPtr, &num, num2);

  return 0;
}

/* Output is here.
 * num=100, numPtr=0x7ffee599da3c, address of num=0x7ffee599da3c, num2=100
*/
