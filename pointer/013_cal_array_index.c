/*
 * ポインターを使っていろんな型の配列を操作してみる
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int a[COUNT];
float b[COUNT];
double c[COUNT];
long long int d[COUNT];
short int e[COUNT];
long int f[COUNT];

int main(int argc, char **argv) {
  int *pa;
  float *pb;
  double *pc;
  long long int *pd;
  short int *pe;
  long int *pf;
  int i;

  // それぞれの型サイズの確認
  printf("int のサイズ: %ldバイト\n", sizeof(int));
  printf("float のサイズ: %ldバイト\n", sizeof(float));
  printf("double のサイズ: %ldバイト\n", sizeof(double));
  printf("long long int のサイズ: %ldバイト\n", sizeof(long long int));
  printf("short int のサイズ: %ldバイト\n", sizeof(short int));
  printf("long int のサイズ: %ldバイト\n", sizeof(long int));

  // ポインターの初期化
  pa = a;
  pb = b;
  pc = c;
  pd = d;
  pe = e;
  pf = f;

  // それぞれの型の配列の初期化
  for(i=0; i<COUNT; i++) {
    a[i] = i;
    b[i] = (float)i;
    c[i] = (double)i;
    d[i] = i;
    e[i] = i;
    f[i] = i;
  }

  // ポインターを操作する
  pa += 1;
  pb += 1;
  pc += 1;
  pd += 1;
  pe += 1;
  pf += 1;

  printf("a のアドレス: %p, pa の値: %p, pa が指し示す値: %d\n", a, pa, *pa);
  printf("b のアドレス: %p, pb の値: %p, pb が指し示す値: %f\n", b, pb, *pb);
  printf("c のアドレス: %p, pc の値: %p, pc が指し示す値: %lf\n", c, pc, *pc);
  printf("d のアドレス: %p, pd の値: %p, pd が指し示す値: %lld\n", d, pd, *pd);
  printf("e のアドレス: %p, pe の値: %p, pe が指し示す値: %d\n", e, pe, *pe);
  printf("f のアドレス: %p, pf の値: %p, pf が指し示す値: %ld\n", f, pf, *pf);

  return 0;
}

/* Output is here.
 * int のサイズ: 4バイト
 * float のサイズ: 4バイト
 * double のサイズ: 8バイト
 * long long int のサイズ: 8バイト
 * short int のサイズ: 2バイト
 * long int のサイズ: 8バイト
 * a のアドレス: 0x10baf4010, pa の値: 0x10baf4014, pa が指し示す値: 1
 * b のアドレス: 0x10baf4020, pb の値: 0x10baf4024, pb が指し示す値: 1.000000
 * c のアドレス: 0x10baf4030, pc の値: 0x10baf4038, pc が指し示す値: 1.000000
 * d のアドレス: 0x10baf4050, pd の値: 0x10baf4058, pd が指し示す値: 1
 * e のアドレス: 0x10baf4070, pe の値: 0x10baf4072, pe が指し示す値: 1
 * f のアドレス: 0x10baf4080, pf の値: 0x10baf4088, pf が指し示す値: 1
 */
