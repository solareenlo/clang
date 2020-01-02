/*
 * 関数
 */
#include <stdio.h>

double avg(double l, double m) {
  double r = (l+m) / 2.0;
  return r;
}

int main(void) {
  double d1, d2, d3;
  double a=1.2, b=3.4, c=5.6;

  d1 = avg(a, b);
  d2 = avg(4.1, 9.8);
  d3 = avg(c, 4.4);
  printf("d1=%f, d2=%f, d3=%f\n", d1, d2, d3);

  return 0;
}

/* Output is here.
 * d1=2.300000, d2=6.950000, d3=5.000000
 */
