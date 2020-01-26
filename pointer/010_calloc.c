/*
 * malloc と calloc の使い方の違い
 * 両者ともやることは同じ．
 * 動的にメモリを確保する．
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *s;
  int i;
  int *p;

  // malloc は引数は1つだけ．
  // 確保するバイトサイズだけ．
  s = (char*)malloc(1);
  if(s == NULL) { // エラー処理
    printf("malloc failed\n");
    exit(0);
  }
  s[0] = 3;
  s[1] = 2;
  s[2] = 1;
  for(i=0; i<6; i++)
    printf("s[%d]=%d（%p）\n", i, s[i], &s[i]);
  free(s);
  printf("\n");

  // calloc は引数が2つ．
  // 個数とバイトサイズの2つ．
  s = (char*)calloc(6, sizeof(char));
  if(s == NULL) { // エラー処理
    printf("malloc failed\n");
    exit(0);
  }
  for(i=0; i<6; i++)
    printf("s[%d]=%d（%p）\n", i, s[i], &s[i]);
  free(s);
  printf("\n");

  p = (int*)calloc(6, sizeof(int));
  if(p == NULL) { // エラー処理
    printf("malloc failed\n");
    exit(0);
  }
  for(i=0; i<6; i++)
    printf("s[%d]=%d（%p）\n", i, p[i], &p[i]);
  free(p);

  return 0;
}

/* Output is here.
 * s[0]=3（0x7fcf7ec01730）
 * s[1]=2（0x7fcf7ec01731）
 * s[2]=1（0x7fcf7ec01732）
 * s[3]=0（0x7fcf7ec01733）
 * s[4]=0（0x7fcf7ec01734）
 * s[5]=0（0x7fcf7ec01735）
 *
 * s[0]=0（0x7fcf7ec01730）
 * s[1]=0（0x7fcf7ec01731）
 * s[2]=0（0x7fcf7ec01732）
 * s[3]=0（0x7fcf7ec01733）
 * s[4]=0（0x7fcf7ec01734）
 * s[5]=0（0x7fcf7ec01735）
 *
 * s[0]=0（0x7fcf7ec01740）
 * s[1]=0（0x7fcf7ec01744）
 * s[2]=0（0x7fcf7ec01748）
 * s[3]=0（0x7fcf7ec0174c）
 * s[4]=0（0x7fcf7ec01750）
 * s[5]=0（0x7fcf7ec01754）
 */
