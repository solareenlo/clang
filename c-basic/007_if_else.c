/*
 * if, else
 */
#include <stdio.h>

int main(void) {
  int a;

  printf("数値を入力：");
  scanf("%d", &a);

  if(a >= 0) {
    printf("入力した数値は、正の整数です。\n");
  } else {
    printf("入力した数値は、負の整数です。\n");
  }

  return 0;
}

/* Output is here.
 * 数値を入力：0
 * 入力した数値は、正の整数です。
 * 数値を入力：10
 * 入力した数値は、正の整数です。
 * 数値を入力：-10
 * 入力した数値は、負の整数です。
*/
