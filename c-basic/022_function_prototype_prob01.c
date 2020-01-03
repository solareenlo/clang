#include <stdio.h>

int add(int, int);
int sub(int, int);

int main(void) {
  int a, b;
  int result;

  printf("2つの整数値を入力してください\n");
  printf("a=");
  scanf("%d", &a);
  printf("b=");
  scanf("%d", &b);

  result = add(a, b);
  printf("%d+%d=%d\n", a, b, result);

  result = sub(a, b);
  printf("%d-%d=%d\n", a, b, result);

  return 0;
}

int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

/* Output is here.
 * 2つの整数値を入力してください
 * a=10
 * b=4
 * 10+4=14
 * 10-4=6
*/
