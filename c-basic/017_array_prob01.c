#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int a[6];
  int i, num;

  srand((unsigned)time(NULL));

  // 配列 a に乱数を代入する
  for(i=0; i<6; i++) {
    num = rand() % 10 + 1;
    a[i] = num;
  }

  // 配列 a の値を表示する
  for(i=0; i<6; i++)
    printf("a[%d]=%d ", i, a[i]);

  printf("\n");

  return 0;
}

/* Output is here.
 * a[0]=8 a[1]=6 a[2]=5 a[3]=6 a[4]=7 a[5]=6
 */
