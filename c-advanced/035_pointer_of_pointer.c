/*
 * ポインタのポインタ
 */
#include <stdio.h>

#define SIZE 3

int main(void) {
  char* s[SIZE] = {"Taro", "Jiro", "Hanako"};
  char** pps = NULL;
  int i;

  for(i=0; i<SIZE; i++)
    printf("%s\n", s[i]);

  pps = s;
  for(i=0; i<SIZE; i++) {
    printf("%s\n", *pps);
    pps++;
  }

  return 0;
}

/* Output is here.
 * Taro
 * Jiro
 * Hanako
 * Taro
 * Jiro
 * Hanako
*/
