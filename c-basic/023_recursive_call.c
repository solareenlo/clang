/*
 * 再帰呼び出し
 */
#include <stdio.h>

void recursive(int);

int main(void) {
  recursive(1);
  return 0;
}

void recursive(int a) {
  printf("a=%d\n", a);
  if(a < 5)
    recursive(a+1);
}

/* Output is here.
 * a=1
 * a=2
 * a=3
 * a=4
 * a=5
*/
