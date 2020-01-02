#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int i;
  int data[10];

  srand((unsigned)time(NULL));
  for(i=0; i<10; i++) {
    data[i] = rand() % 10 + 1;
    printf("%d ", data[i]);
  }
  printf("\n");

  printf("奇数：");
  i=0;
  while(i<10) {
    if(data[i]%2 == 1)
      printf("%d ", data[i]);
    i++;
  }
  printf("\n");

  printf("偶数：");
  i=0;
  while(i<10) {
    if(data[i]%2 == 0)
      printf("%d ", data[i]);
    i++;
  }
  printf("\n");

  return 0;
}

/* Output is here.
 * 8 2 4 1 10 10 8 3 10 3
 * 奇数：1 3 3
 * 偶数：8 2 4 10 10 8 10
*/
