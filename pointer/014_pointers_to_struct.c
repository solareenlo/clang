/*
 * 構造体のサイズはデータの並びによって，
 * 確保するバイトサイズが変わってくる．
 *
 * int, int, double, long long int の並びの構造体は
 * int: 4byte + int; 4byte = 8byte
 * double: 8byte = 8byte
 * lont long int: 8byte = 8byte
 * で，8byte * 3 = 24byte になる．
 *
 * int, double, int, long long int の並びの構造体は
 * int: 4byte + \n: 1byte + \n: 1byte + \n: 1byte + \n: 1byte = 8byte
 * double: 8byte = 8byte
 * int: 4byte + \n: 1byte + \n: 1byte + \n: 1byte + \n: 1byte = 8byte
 * long long int: 8byte = 8byte
 * で，8byte * 4 = 32 byte になる．
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int a;
  double b;
  int c;
  long long int d;
} MYSTRUCT;

#define COUNT 3

int main(void) {
  MYSTRUCT *p, *q;
  void *v; // int 型で構造体のデータを1つ1つ確認するためのgeneric pointer
  int i;

  printf("MYSTRUCT のサイズ: %ldバイト\n", sizeof(MYSTRUCT));

  p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));

  // 構造体の初期化
  for(i=0; i<COUNT; i++) {
    p[i].a = i;
    p[i].b = 100.0 + i;
    p[i].c = i * 2;
    p[i].d = 333 + i;
  }

  for(i=0; i<COUNT; i++) {
    q = p + i;
    printf("構造体[%d] のアドレス: %p\n", i, q);
    printf("構造体[%d] の値: a: %d, b: %lf, c: %d, d: %lld\n", i, q->a, q->b, q->c, q->d);
    printf("アドレス: a: %p, b: %p, c: %p, d: %p\n", &q->a, &q->b, &q->c, &q->d);
  }

  // 3番目の構造体の中身を int 型で1つ1つ確かめている
  // 構造体の中身の int 型データの後ろがきちんと 0 でパディングされているのが分かる
  v = p + 2;
  for(i=0; i<sizeof(MYSTRUCT)/sizeof(int); i++) {
    printf("v[%d]=%d\n", i, ((int*)v)[i]);
  }

  return 0;
}

/* Output is here.
 * MYSTRUCT のサイズ: 32バイト
 * 構造体[0] のアドレス: 0x7f7f08401730
 * 構造体[0] の値: a: 0, b: 100.000000, c: 0, d: 333
 * アドレス: a: 0x7f7f08401730, b: 0x7f7f08401738, c: 0x7f7f08401740, d: 0x7f7f08401748
 * 構造体[1] のアドレス: 0x7f7f08401750
 * 構造体[1] の値: a: 1, b: 101.000000, c: 2, d: 334
 * アドレス: a: 0x7f7f08401750, b: 0x7f7f08401758, c: 0x7f7f08401760, d: 0x7f7f08401768
 * 構造体[2] のアドレス: 0x7f7f08401770
 * 構造体[2] の値: a: 2, b: 102.000000, c: 4, d: 335
 * アドレス: a: 0x7f7f08401770, b: 0x7f7f08401778, c: 0x7f7f08401780, d: 0x7f7f08401788
 * v[0]=2
 * v[1]=0
 * v[2]=0
 * v[3]=1079607296
 * v[4]=4
 * v[5]=0
 * v[6]=335
 * v[7]=0
 */
