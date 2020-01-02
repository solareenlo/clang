/*
 * 関数のプロトタイプ宣言
 * 関数の型を先に宣言したもの。
 */
#include <stdio.h>
double avg(double, double);

int main(void) {
  double d1, d2, d3;
  double a=1.2, b=3.4, c=5.6;
  d1 = avg(a, b);
  d2 = avg(10.0, 2.3);
  d3 = avg(c, 2.2);
  printf("d1=%f, d2=%f, d3=%f\n", d1, d2, d3);

  return 0;
}

double avg(double l, double m) {
  double r = (l+m) / 2.0;
  return r;
}

/* Output is here.
 * d1=2.300000, d2=6.150000, d3=3.900000
 */
