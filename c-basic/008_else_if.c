/*
 * else if
 */
#include <stdio.h>

int main(void) {
  int num;

  printf("1~3の値を入力してください：");
  scanf("%d", &num);

  if(num == 1) {
    printf("one\n");
  } else if(num == 2) {
    printf("two\n");
  } else if(num == 3) {
    printf("three\n");
  } else {
    printf("不適切な値です。\n");
  }

  return 0;
}

/* Output is here.
 * 1~3の値を入力してください：0
 * 不適切な値です。
 * 1~3の値を入力してください：1
 * one
 * 1~3の値を入力してください：2
 * two
 * 1~3の値を入力してください：3
 * three
*/
