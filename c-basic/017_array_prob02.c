#include <stdio.h>

int main(void) {
  int i;
  double d[4] = {1.2, -1.3, 5.2, 4.8};

  for(i=0; i<4; i++)
    printf("d[%d]=%.2f ", i, d[i]);
  printf("\n");

  return 0;
}

/* Output is here.
 * d[0]=1.20 d[1]=-1.30 d[2]=5.20 d[3]=4.80
 */
