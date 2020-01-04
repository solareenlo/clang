/*
 * 共用体
 * 構造体との違い
 * - 複数あるメンバーのうち、同時に使うことができるのはどれか一つだけ
 * - 共用体のメモリサイズは、メンバーの中のもっとも大きいものと等しくなっている
 * - 共用体を使う理由はメモリの節約
 */
#include <stdio.h>
#include <string.h>

union data {
  int n;
  double d;
  char s[16];
};

int main(void) {
  union data d[3];

  d[0].n = 1;
  d[1].d = 3.14;
  strcpy(d[2].s, "hello");

  printf("%d, %f, %s\n", d[0].n, d[1].d, d[2].s);

  return 0;
}

/* Output is here.
 * 1, 3.140000, hello
 */
