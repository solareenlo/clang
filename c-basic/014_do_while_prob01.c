#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int i, num;

  srand((unsigned)time(NULL));
  num = rand() % 10 + 1;

  printf("%d ", num);
  do {
    printf("■ ");
    i++;
  } while(i < num);
  printf("\n");

  return 0;
}

/* Output is here.
 * 4 ■ ■ ■ ■
 * 5 ■ ■ ■ ■ ■
 * 8 ■ ■ ■ ■ ■ ■ ■ ■
*/
