/*
 * pointer 自身にもアドレスがある．
 * pointer が持っている値は誰かのアドレスです．
 */
#include <stdio.h>

int main(int argc, char ** argv) {
  char str1[] = "Taro";
  char *str2 = "Yamada";

  printf("%p, %p, %s\n", &str1, str1, str1);
  printf("%p, %p, %s\n", &str2, str2, str2);

  str2 = str1;
  printf("%p, %p, %c\n", &str2, str2, *str2);

  return 0;
}
/* Output is here.
 * 0x7ffee7244a3b, 0x7ffee7244a3b, Taro
 * 0x7ffee7244a30, 0x1089bbf97, Yamada
 * 0x7ffee7244a30, 0x7ffee7244a3b, T
*/
