#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int n;

  srand((unsigned)time(NULL));
  n = rand() % 6 + 1;
  printf("数値：%d\n", n);
  if(n >= 3)
    printf("数値は3以上です\n");
  else
    printf("数値は3未満です\n");

  return 0;
}

/* Output is here.
 * 数値：6
 * 数値は3以上です
 * 数値：3
 * 数値は3以上です
 * 数値：2
 * 数値は3未満です
*/
