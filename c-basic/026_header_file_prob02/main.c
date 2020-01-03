#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "randLib.h"

int main(void) {
  int i, n;
  int start, end, num;
  init_rand();

  printf("2つの整数値の間の乱数を表示します\n");
  printf("始まりの整数値を入力してください\n");
  scanf("%d", &start);
  printf("終わりの整数値を入力してください\n");
  scanf("%d", &end);
  printf("何個表示するかを入力してください\n");
  scanf("%d", &num);
  for(i=0; i<num; i++) {
    n = getRand(start, end);
    printf("乱数：%d\n", n);
  }

  return 0;
}
