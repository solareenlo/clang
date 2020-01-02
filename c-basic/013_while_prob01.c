#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int i, num;
  srand((unsigned)time(NULL));
  num = rand() % 10 + 1;

  printf("%d", num);
  while (i < num) {
    printf("■ ");
    i++;
  }
  printf("\n");

  return 0;
}

/* Output is here.
 * 1■
 * 8■ ■ ■ ■ ■ ■ ■ ■
 * 2■ ■
*/
