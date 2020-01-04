/*
 * 関数の引数として関数ポインタを渡す
 */
#include <stdio.h>

// 関数ポインタを引数としてとる関数
// 引数内での関数ポインタの書式
// 型名 (*)(引数)
// 関数ポインタは、呼び出す関数を動的に変更する時に非常に便利
void funcp(int (*)(int), int n);

// 関数ポインタに用いる関数
int dbl(int);
int hlf(int);

int main(void) {
  funcp(dbl, 10);
  funcp(hlf, 10);

  return 0;
}

// 関数ポインタの書式
// 型名 (*変数名)(引数)
void funcp(int (*f)(int), int n) {
  printf("引数：%d, 結果：%d\n", n, f(n));
}

int dbl(int n) {
  return n * 2;
}

int hlf(int n) {
  return n / 2;
}

/* Output is here.
 * 引数：10, 結果：20
 * 引数：10, 結果：5
*/
