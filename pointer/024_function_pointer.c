/*
 * function pointer の宣言方法
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*PFI)(int); // ここで関数ポインタの型を宣言

int square(int a);

int main(void) {
  PFI test; // これが function pointer
  /* int (*test)(int); */
  char input[50];
  int value;
  int result;

  // test ポインタに square 関数のエントリポイントを格納
  test = square;

  printf("累乗する整数の値を入力してください ... ");
  value = atoi(gets(input));
  result = test(value);
  printf("累乗した値: %d\n", result);

  return 0;
}

int square(int a) {
  return a*a;
}

/* Output is here
 * 累乗する整数の値を入力してください ... 12
 * 累乗した値: 144
 */
