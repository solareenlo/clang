/*
 * for のネスト
 */
#include <stdio.h>

int main(void) {
  int i, j;

  for(i=0; i<2; i++) {
    for(j=0; j<3; j++)
      printf("%d+%d=%d, ", i, j, i+j);
    printf("\n");
  }

  return 0;
}

/* Output is here.
 * 0+0=0, 0+1=1, 0+2=2,
 * 1+0=1, 1+1=2, 1+2=3,
*/
