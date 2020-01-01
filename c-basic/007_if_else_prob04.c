#include <stdio.h>

int main(void) {
  int num;

  printf("数値を入力してください：");
  scanf("%d", &num);

  if(num <= 10 || 90 <= num)
    printf("10以下か90以上です\n");

  return 0;
}

/* Output is here.
 * 数値を入力してください：10
 * 10以下か90以上です
 * 数値を入力してください：0
 * 10以下か90以上です
 * 数値を入力してください：50
 * 数値を入力してください：100
 * 10以下か90以上です
*/
