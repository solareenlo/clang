/*
 * 文字列比較
 * strcmp
 */
#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[256], s2[256];

  printf("2種類の文字列を入力してください\n2つの文字列は同じでも違っても構いません\n");
  printf("s1=");
  scanf("%s", s1);
  printf("s2=");
  scanf("%s", s2);

  if(strcmp(s1, s2)==0)
    printf("s1とs2は同じです\n");
  else
    printf("s1とs2は違います\n");

  return 0;
}

/* Output is here.
 * 2種類の文字列を入力してください
 * 2つの文字列は同じでも違っても構いません
 * s1=abc
 * s2=efg
 * s1とs2は違います
 *
 * 2種類の文字列を入力してください
 * 2つの文字列は同じでも違っても構いません
 * s1=abc
 * s2=abc
 * s1とs2は同じです
*/
