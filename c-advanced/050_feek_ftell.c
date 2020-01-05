/*
 * fseek を用いて1つずつバイナリデータを読み取る
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(void) {
  FILE* file;
  char pathname[SIZE];
  int i, size;
  char* rdata; // 読み取りデータ

  getcwd(pathname, SIZE);
  strcat(pathname, "/049_sample.bin");
  printf("%s\n", pathname);

  file = fopen(pathname, "rb"); // 読み取り専用にファイルを開く
  if(file == NULL) {
    printf("読み取り用ファイルを開くことができません\n");
    exit(1);
  }

  fseek(file, 0, SEEK_END); // ファイルの最後にシークする
  printf("%sは、%ldバイトです\n", pathname, ftell(file));
  size = ftell(file); // ファイルの大きさを取得する
  rdata = (char*)malloc(sizeof(char) * size); // ファイルのサイズだけ、配列を動的に確保する
  fseek(file, 0, SEEK_SET); // ファイルの先頭にシークする
  fread(rdata, sizeof(char), size, file); // データを配列 rdata に格納する
  fclose(file);

  for(i=0; i<size; i++)
    printf("%x ", rdata[i]);
  printf("\n");

  free(rdata);

  return 0;
}

/* Output is here.
 * /clang/c-advanced/049_sample.bin
 * /clang/c-advanced/049_sample.binは、4バイトです
 * 10 1a 1e 1f
 */
