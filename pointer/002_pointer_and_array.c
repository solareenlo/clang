/*
 * 配列のポインタを使って，配列の先頭アドレスを表示
 */
#include <stdio.h>

int main(int argc, char **argv) {
  char str1[] = "Taro Yamada";

  printf("%s %d %p %p %p\n", str1, str1[0], &str1, &str1[0], str1);

  return 0;
}

/* Output is here.
 * Taro Yamada 84 0x7ffee87c8a4c 0x7ffee87c8a4c 0x7ffee87c8a4c
*/
