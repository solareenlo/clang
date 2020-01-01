#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int num;
  srand((unsigned)time(NULL));
  num = rand() % 10 + 1;
  printf("数値：%d\n", num);
  if(num >= 5)
    printf("5以上です\n");
  else
    printf("5未満です\n");
  return 0;
}

/* Output is here.
 * 数値：9
 * 5以上です
 * 数値：6
 * 5以上です
 * 数値：6
 * 5以上です
 * 数値：2
 * 5未満です
*/
