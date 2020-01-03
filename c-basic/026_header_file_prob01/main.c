#include <stdio.h>
#include "calc.h"

int main(void) {
  int n1, n2;
  int r1, r2;

  printf("整数値を2つ入力してください\n");
  printf("n1=");
  scanf("%d", &n1);
  printf("n2=");
  scanf("%d", &n2);
  r1 = div(n1, n2);
  r2 = mod(n1, n2);
  printf("%d/%d=%d余り%d\n", n1, n2, r1, r2);

  return 0;
}

/* Output is here.
 * n1=10
 * n2=3
 * 10/3=3余り1
*/
