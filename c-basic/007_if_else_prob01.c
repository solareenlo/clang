#include <stdio.h>

int main(void) {
  int num;

  printf("整数値を入力してください：");
  scanf("%d", &num);

  if(num >= 5) {
    printf("5以上です。\n");
  } else {
    printf("5未満です。\n");
  }

  return 0;
}

/* Output is here.
 * 整数値を入力してください：10
 * 5以上です。
 * 整数値を入力してください：1
 * 5未満です。
*/
