#include <stdio.h>

int main(void) {
  int num;

  printf("整数値を入力してください：");
  scanf("%d", &num);

  if(num < 50) {
    printf("整数値は50未満です。\n");
  } else {
    printf("整数値は50以上です。\n");
  }

  return 0;
}

/* Output is here.
 * 整数値を入力してください：10
 * 整数値は50未満です。
 * 整数値を入力してください：100
 * 整数値は50以上です。
 * 整数値を入力してください：50
 * 整数値は50以上です。
*/
