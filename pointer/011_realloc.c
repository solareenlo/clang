/*
 * realloc で malloc の動的メモリ確保をリサイズする．
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *s;
  int i;

  i = sizeof("hello");

  s = (char*)malloc(i);
  if(s == NULL) {
    printf("malloc failed\n");
    exit(0);
  }
  // hello 分までしかメモリが確保されていないので，world は s にコピーされない．
  strncpy(s, "hello world", i);
  printf("s: %s\n", s);

  s = realloc(s, 12);
  if(s == NULL) {
    printf("realloc failed\n");
    exit(0);
  }
  strncpy(s, "hello", i);
  strcat(s, " world");
  printf("s: %s\n", s);

  return 0;
}

/* Output is here.
 * s: hello
 * s: hello world
 */
