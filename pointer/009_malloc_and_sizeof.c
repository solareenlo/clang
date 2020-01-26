/*
 * sizeof でデータのサイズを取得して，
 * malloc でそのデータサイズ分だけデータを確保する．
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *s;
  int stringsize;
  int i;

  stringsize = sizeof("hello");
  printf("'hello' のサイズ：%d\n", stringsize);

  s = (char*)malloc(stringsize);
  if(s == NULL) { // エラー処理
    printf("malloc failed\n");
    exit(0);
  }

  strncpy(s, "hello", stringsize);
  printf("s: %s\n", s);
  s[0] = 'c';
  printf("s: %s\n", s);

  for(i=0; i<stringsize; i++)
    printf("%c ", s[i]);
  printf("\n");

  free(s);

  return 0;
}

/* Output is here.
 * 'hello' のサイズ：6
 * s: hello
 * s: cello
 * c e l l o
 */
