/*
 * NULL ポインタへのアクセス
 */
#include <stdio.h>

int main(void) {
  int* p = NULL; // ポインタを NULL で初期化
  *p =1; // アドレスを指定しないまま値を代入すると実行時にエラーになる
  return 0;
}
