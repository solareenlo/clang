#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*PFI)(int); // 関数ポインタの型を定義する

// 使用する4つの関数
int identity(int a);
int square(int a);
int cube(int a);
int fourth(int a);

PFI power[] = { identity, square, cube, fourth };

int main(void) {
  char input[50];
  int value;
  int exponent;
  int result;

  printf("使用する関数の番号を入力してください ... \n");
    printf("[1] identity, [2] square, [3] cube, [4] fourth\n> ");
  exponent = atoi(gets(input));
  // NOTE: the sizeof(PFI) is 4 and the sizeof the 'power' array here is 16
  if (exponent <= 0 || exponent > sizeof(power)/sizeof(PFI)) {
    printf("ERROR: out of range!\n");
  } else {
    printf("整数を入力してください\n> ");
    value = atoi(gets(input));
    // here, I'm indexing into an array of function pointers, selecting the 'power'
    // that the user entered (that, is the 'exponent') and using that function to
    // calculate the 'value' to the power of 'exponent'
    result = power[exponent - 1](value);
    printf("計算結果: %d\n", result);
  }

  return 0;
}

int identity(int a) {
  return a;
}

int square(int a) {
  return a*a;
}

int cube(int a) {
  return a*a*a;
}

int fourth(int a) {
  return a*a*a*a;
}

/* Output is here
 * 使用する関数の番号を入力してください ...
 * [1] identity, [2] square, [3] cube, [4] fourth
 * warning: this program uses gets(), which is unsafe.
 * > 2
 * 整数を入力してください
 * > 3
 * 計算結果: 9
 */
