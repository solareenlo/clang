/*
 * 文字列操作
 * strcpy: 文字列コピー
 * strcat: 文字列結合
 * strlen: 文字列の長さ
 */
#include <stdio.h>
#include <string.h>

int main(void) {
  char s[10];
  int len;

  strcpy(s, "abc"); // 文字列コピー
  printf("s=%s\n", s);

  strcat(s, "def"); // 文字列結合
  printf("s=%s\n", s);

  len = strlen(s); //文字列の長さ
  printf("文字列の長さ：%d\n", len);

  return 0;
}

/*
 * s=abc
 * s=abcdef
 * 文字列の長さ：6
*/
