/*
 * if のネスト
 */
#include <stdio.h>

int main(void) {
  int dice;
  printf("1から6の数値を入力してください：");
  scanf("%d", &dice);
  if(1 <= dice && dice <= 6) {
    if(dice % 2 == 0) {
      printf("偶数です。\n");
    } else {
      printf("奇数です。\n");
    }
  } else {
    printf("範囲外の数値です。\n");
  }

  return 0;
}

/* Output is here.
 * 1から6の数値を入力してください：4
 * 偶数です。
 * 1から6の数値を入力してください：1
 * 奇数です。
 * 1から6の数値を入力してください：0
 * 範囲外の数値です。
*/
