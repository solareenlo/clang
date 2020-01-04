/*
 * 関数ポインタ
 */
#include <stdio.h>

void func1();
void func2();

int main(void) {
  // 関数ポインタの書式
  // 型名 (*変数名)(引数)
  void (*fp)() = func1; // 関数ポインタを func1 で初期化
  fp(); // 関数 fp() を実行
  fp = func2;
  fp(); // 関数 fp() を実行

  return 0;
}

void func1() {
  printf("func1\n");
}

void func2() {
  printf("func2\n");
}

/* Output is here.
 * func1
 * func2
*/
