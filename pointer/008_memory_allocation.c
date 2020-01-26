/*
 * メモリのアロケーション（割当て）
 */
#include <stdio.h>
#include <string.h>
/* #include <malloc.h> */
#include <stdlib.h> // macOS で malloc を使うときはこちらを使う．

#define MAXSTRLEN 50

char *string_function(char *astring) {
  char *s;

  s = (char*)malloc(MAXSTRLEN);
  if(s == NULL) { // エラー処理
    printf("malloc failed\n");
    exit(0);
  }
  strcat(s, "Hello ");
  strcat(s, astring);
  strcat(s, "\n");

  return s;
}

int main(int argc, char **argv) {
  printf("%s", string_function("Taro"));

  return 0;
}

/* Output is here.
 * Hello Taro
 */
