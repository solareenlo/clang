/*
 * 配列
 */
#include <stdio.h>

int main(void) {
  double d[] = {1.2, 3.4, 5.6};
  double sum, avg;
  int i;

  sum = 0.0;
  for(i=0; i<3; i++) {
    printf("%f ", d[i]);
    sum += d[i];
  }
  printf("\n");

  avg = sum / 3.0;

  printf("合計値：%f\n", sum);
  printf("平均値：%f\n", avg);

  return 0;
}

/* Output is here.
 * 1.200000 3.400000 5.600000
 * 合計値：10.200000
 * 平均値：3.400000
*/
