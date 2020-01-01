#include <stdio.h>

int main(void) {
  int num;

  printf("整数値を入力してください：");
  scanf("%d", &num);

  if(num == 1) {
    printf("1です。\n");
  } else {
    printf("1ではありません。\n");
  }

  return 0;
}

/* Output is here.
 * 整数値を入力してください：1
 * 1です。
 * 整数値を入力してください：0
 * 1ではありません。
*/
