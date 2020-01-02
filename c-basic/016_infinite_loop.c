/*
 * 無限ループ
 */
#include <stdio.h>

int main(void) {
  int num;

  printf("負の値で、ループから抜けます\n");

  while(1) {
    printf("数値を入力：");
    scanf("%d", &num);
    if(num < 0)
      break;
  }
  printf("end\n");

  return 0;
}

/* Output is here.
 * 負の値で、ループから抜けます
 * 数値を入力：10
 * 数値を入力：20
 * 数値を入力：1
 * 数値を入力：0
 * 数値を入力：-10
 * end
*/
