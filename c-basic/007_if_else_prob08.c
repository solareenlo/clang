#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  int num;
  srand((unsigned)time(NULL));
  num = rand() % 10 + 1;

  if(num == 1) {
    printf("乱数：%d\n", num);
    printf("乱数は1です\n");
  } else {
    printf("乱数：%d\n", num);
    printf("乱数は1ではありません\n");
  }

  return 0;
}

/* Outpu is here.
 * 乱数：9
 * 乱数は1ではありません
 * 乱数：1
 * 乱数は1です
*/
