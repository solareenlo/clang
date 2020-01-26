/*
 * 間接参照とプログラムの引数
 */
#include <stdio.h>

int main(int argc, char **argv) {
  int i;

  for(i=0; i<argc; i++) {
    printf("arg %d is %s\n", i, argv[i]);
  }
  printf("\n");

  for(i=0; i<argc; i++) {
    printf("arg %d is %s\n", i, *argv);
    argv += 1;
  }

  return 0;
}

/* Output is here.
 * > gcc 006_cmmandline_args.c
 * > ./a.out test one two
 * arg 0 is ./a.out
 * arg 1 is test
 * arg 2 is one
 * arg 3 is two
 *
 * arg 0 is ./a.out
 * arg 1 is test
 * arg 2 is one
 * arg 3 is two
*/
