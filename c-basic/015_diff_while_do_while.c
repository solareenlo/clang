/*
 * while と do while との違い
 */
#include <stdio.h>

int main(void) {
  int i, num;

  printf("回数を入力：");
  scanf("%d", &num);

  printf("whilde で実行\n");
  i = 0;
  while(i < num) {
    printf("*");
    i++;
  }
  printf("\n");

  printf("do while で実行\n");
  i = 0;
  do {
    printf("*");
    i++;
  } while(i < num);
  printf("\n");

  return 0;
}

/* Output is here.
 * 回数を入力：5
 * whilde で実行
 * *****
 * do while で実行
 * *****
 * 回数を入力：0
 * whilde で実行
 *
 * do while で実行
 * *
*/
