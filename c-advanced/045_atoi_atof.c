/*
 * 文字列から数値への置換
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char s1[] = "100";
  char s2[] = "1.23";
  int i;
  double d;

  i = atoi(s1);
  d = atof(s2);

  printf("i=%d, d=%f\n", i, d);

  return 0;
}

/* Output is here.
 * i=100, d=1.230000
 */
