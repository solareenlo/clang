/*
 * ファイルの読み込み
 * 1文字ずつ
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(void) {
  FILE *file; // ファイルポインタ
  char pathname[SIZE]; // ファイルへのパス
  int c; // 読み込む文字のコード

  // カレントディレクトリの 047_sample.txt へのパスを取得&表示
  getcwd(pathname, SIZE);
  strcat(pathname, "/047_sample.txt");
  printf("%s\n", pathname);

  file = fopen(pathname, "r");
  if(file == NULL) {
    printf("ファイルが開けません\n");
    exit(1);
  }

  // fgetc を用いて、1文字ずつテキストデータを読み込む
  // fgets(ファイルポインタ)
  while((c=fgetc(file)) != EOF) {
    printf("%c", (char)c);
  }

  fclose(file);

  return 0;
}
