/*
 * switch
 */
#include <stdio.h>

int main(void) {
  int num;

  printf("1から3の数値を入力してください：");
  scanf("%d", &num);

  switch(num) {
    case 1:
      printf("one\n");
      break;
    case 2:
      printf("two\n");
      break;
    case 3:
      printf("three\n");
      break;
    default:
      printf("不適切な数値です。\n");
      break;
  }

  return 0;
}

/* Output is here.
 * 1から3の数値を入力してください：1
 * one
 * 1から3の数値を入力してください：2
 * two
 * 1から3の数値を入力してください：3
 * three
 * 1から3の数値を入力してください：0
 * 不適切な数値です。
*/
