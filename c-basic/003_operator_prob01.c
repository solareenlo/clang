#include <stdio.h>

int main(void) {
  int a, b;

  printf("a = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);

  printf("aの値 = %d\n", a);
  printf("bの値 = %d\n", b);
  printf("a+b=%d\n", a+b);
  printf("a-b=%d\n", a-b);
  printf("a*b=%d\n", a*b);
  printf("a/b=%d\n", a/b);
  printf("a%%b=%d\n", a%b);

  return 0;
}

/* Output is here.
 * a = 10
 * b = 5
 * aの値 = 10
 * bの値 = 5
 * a+b=15
 * a-b=5
 * a*b=50
 * a/b=2
 * a%b=0
*/
