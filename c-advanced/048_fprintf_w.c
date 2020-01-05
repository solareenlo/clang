/*
 * ファイルへの書き込み
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(void) {
  FILE *file; // フィアルポインタ
  char pathname[SIZE]; // 書き込むファイルへのパス

  getcwd(pathname, SIZE); // カレントディレクトリへのパスを取得する
  strcat(pathname, "/047_sample.txt");
  printf("%s\n", pathname);

  file = fopen(pathname, "w");
  if(file == NULL) {
    printf("ファイルが開けません\n");
    exit(1);
  }

  fprintf(file, "Hello World.\r\n");
  fprintf(file, "ABC\r\n");
  fclose(file);

  return 0;
}

/*
 * Output is here.
 * 047_sample.txt に
 * Hello World.
 * ABC
 * と書き込まれる
 */
