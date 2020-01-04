/*
 * 引数のある関数ポインタ
 */
#include <stdio.h>

int max(int, int);
int min(int, int);

int main(void) {
  // 関数ポインタの書式
  // 型名 (*変数名)(引数)
  int (*cmp)(int, int) = max; // cmp の初期化
  int a=2, b=3;

  printf("%dと%dのうち、大きい方は%d\n", a, b, cmp(a,b));

  cmp = min;
  printf("%dと%dのうち、小さい方は%d\n", a, b, cmp(a,b));

  return 0;
}

int max(int a, int b) {
  if(a>b) return a;
  return b;
}

int min(int a, int b) {
  if(a<b) return a;
  return b;
}

/* Output is here.
 * 2と3のうち、大きい方は3
 * 2と3のうち、小さい方は2
*/
