/*
 * ファイル分割
 */
#include <stdio.h>
#include "calc.h"
#include "showResult.h"

int main(void) {
  int a=1, b=2;

  printf("%d+%d= ", a, b);
  add(a, b);
  showAnswer();

  printf("%d-%d= ", a, b);
  sub(a, b);
  showAnswer();

  return 0;
}

/* Output is here.
 * 1+2= 3
 * 1-2= -1
*/
