/*
 * ファイル分割
 */
#include <stdio.h>
#include "calc.h"

int main(void) {
  double d1;
  double a=1.0, b=2.0;

  d1 = avg(a, b);
  printf("%fと%fの平均値は%fです\n", a, b, d1);

  return 0;
}

/* Output is here.
 * 1.000000と2.000000の平均値は1.500000です
 */
