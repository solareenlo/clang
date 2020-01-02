/*
 * do while
 */
#include <stdio.h>

int main(void) {
  int i = 0;

  do {
    printf("%d ", i);
    i++;
  } while(i < 5);
  printf("\n");

  return 0;
}

/* Output is here.
 * 0 1 2 3 4
 */
