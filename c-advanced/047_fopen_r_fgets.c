/*
 * ファイルの読み込み
 * 1行ずつ
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(void) {
  FILE *file; // フィアルポインタ
  char pathname[SIZE]; // 読み込むファイルへのパス
  char line[SIZE]; // 読み込むファイルを格納する配列
  line[0] = '\0'; // 初期化

  getcwd(pathname, 256); // カレントディレクトリへのパスを取得する
  strcat(pathname, "/047_sample.txt");
  printf("%s\n", pathname);

  file = fopen(pathname, "r");
  if(file == NULL) {
    printf("ファイルが開きません\n");
    exit(1);
  }

  // fgets はテキストファイルを1行ずつ読み込む関数
  // fgets(文字列ポインタ、文字列サイズ、ファイルポインタ)
  while(fgets(line, SIZE, file) != NULL) {
    printf("%s", line);
  }

  fclose(file);

  return 0;
}
