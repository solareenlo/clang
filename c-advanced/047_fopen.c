/*
 * ファイルの読み込み
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
  FILE *file;
  char pathname[256];

  getcwd(pathname, 256); // カレントディレクトリへのパスを取得する
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
