/*
 * ポインタとしての変数配列
 */
#include <stdio.h>

int main(void) {
  double d[3] = {1.1, 2.2, 3.3};
  double *p1 = NULL, *p2 = NULL;
  int i;

  p1 = d;
  p2 = d;

  for(i=0; i<3; i++) {
    printf("%f %f %f\n", *(d+i), p1[i], *p2);
    p2++;
  }

  return 0;
}

/* Output is here.
 * 1.100000 1.100000 1.100000
 * 2.200000 2.200000 2.200000
 * 3.300000 3.300000 3.300000
*/
