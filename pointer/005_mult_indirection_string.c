/*
 * ポインタのポインタの簡単な例
 */
#include <stdio.h>

#define LENGTH 3

char* words[LENGTH];

int main(int argc, char **argv) {
  char *pc;
  char **ppc;
  int i;

  printf("文字列におけるマルチ間接参照の例\n");

  words[0] = "zero";
  words[1] = "one";
  words[2] = "two";
  for(i=0; i<LENGTH; i++) {
    printf("%s\n", words[i]);
  }

  printf("Now print the chars in each string...\n");
  ppc = words; // ポインタのポインタである ppc を初期化
  for(i=0; i<LENGTH; i++) {
    ppc = words + i; // 文字列の配列のアドレスを ppc に代入
    pc = *ppc; // ppc の値(文字列の配列のアドレス)をポインタ pc に代入
    while(*pc != 0) { // 文字列の文字を1文字1文字取得する
      printf("%c ", *pc);
      pc += 1; // ポインタ pc を1ずらして次の文字を取得できるようにする
    }
    printf("\n");
  }

  return 0;
}

/* Output is here.
 * 文字列におけるマルチ間接参照の例
 * zero
 * one
 * two
 * Now print the chars in each string...
 * z e r o
 * o n e
 * t w o
*/
