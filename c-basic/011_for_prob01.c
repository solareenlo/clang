#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int i, num;

  srand((unsigned)time(NULL));
  num = rand() % 10 + 1;
  printf("%d", num);
  for(i=0; i<num; i++)
    printf("■ ");
  printf("\n");

  return 0;
}

/* Output is here.
 * 4■ ■ ■ ■
 * 5■ ■ ■ ■ ■
 * 1■
*/
