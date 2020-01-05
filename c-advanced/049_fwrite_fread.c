/*
 * fwrite と fread を用いたバイナリデータの書き込みと読み取り
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 256

int main(void) {
  FILE *file;
  char pathname[ SIZE ];
  int i;
  char wdata[] = {0x10, 0x1a, 0x1e, 0x1f};
  char rdata[4];

  getcwd(pathname, SIZE);
  strcat(pathname, "/049_sample.bin");
  printf("%s\n", pathname);

  // 書き込み用ファイルを開く
  file = fopen(pathname, "wb");
  if(file == NULL) {
    printf("書き込み用ファイルを開くことができません\n");
    exit(1);
  }
  // fwrite を使用してバイナリデータを書き込む
  // fwrite(データ, データのバイト長, データの数, ファイルポインタ)
  fwrite(wdata, sizeof(char), sizeof(wdata), file);
  fclose(file);

  // 読み込み用ファイルを開く
  file = fopen(pathname, "rb");
  if(file == NULL) {
    printf("読み取り用ファイルを開くことができません\n");
    exit(1);
  }
  // fread を使用してバイナリデータを読み込む
  // fread(データ, データのバイト長, データ数, ファイルポインタ)
  fread(rdata, sizeof(char), sizeof(rdata), file);
  fclose(file);
  for(i=0; i<sizeof(rdata); i++)
    printf("%x ", rdata[i]);
  printf("\n");

  return 0;
}

/* Output is here.
 * 10 1a 1e 1f
 */
