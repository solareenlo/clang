/*
 * ポインタと関数
 */
#include <stdio.h>

void swap(int*, int*);

int main(void) {
  int a = 1, b = 2;

  printf("a=%d, b=%d\n", a, b);
  swap(&a, &b);
  printf("a=%d, b=%d\n", a, b);

  return 0;
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/* Output is here.
 * a=1, b=2
 * a=2, b=1
*/
