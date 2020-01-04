/*
 * 数値から文字列への変換
 */
#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[256], s2[256];
  int a = 10, b = 20;

  sprintf(s1, "%d", a);
  sprintf(s2, "%d", b);

  puts(s1);
  puts(s2);
  puts("Hello");

  return 0;
}

/* Output is here.
 * 10
 * 20
 * Hello
*/
