/*
 * ポインタ渡しと値渡し
 */
#include <stdio.h>

typedef struct {
  int i;
  double d;
} num_data;

void dealData1(num_data data);
void dealData2(num_data* pData);

int main(void) {
  num_data n1 = {1, 1.2f}, n2 = {1, 1.2f};
  printf("n1のアドレス:0x%p\nn2のアドレス:0x%p\n", &n1, &n2);

  dealData1(n1);
  dealData2(&n2);
  printf("n1.i=%d, n1.d=%f\n", n1.i, n1.d);
  printf("n2.i=%d, n2.d=%f\n", n2.i, n2.d);

  return 0;
}

void dealData1(num_data data) {
  printf("i=%d, d=%f\n", data.i, data.d);
  printf("dealData1に渡ってきたデータのアドレス:0x%p\n", &data);
  data.i = 2;
  data.d = 2.2;
}

void dealData2(num_data* pData) {
  printf("i=%d, d=%f\n", pData->i, pData->d);
  printf("dealData2に渡ってきたデータのアドレス:%p\n", pData);
  pData->i = 2;
  pData->d = 2.2;
}

/* Output is here.
 * n1のアドレス:0x0x7ffcf2f81b80
 * n2のアドレス:0x0x7ffcf2f81b90
 * i=1, d=1.200000
 * dealData1に渡ってきたデータのアドレス:0x0x7ffcf2f81b50
 * i=1, d=1.200000
 * dealData2に渡ってきたデータのアドレス:0x7ffcf2f81b90
 * n1.i=1, n1.d=1.200000
 * n2.i=2, n2.d=2.200000
*/

/* 上記の Output から分かること
 * 値渡しは構造体のコピーを渡している
 * ポインタ渡しは構造体のアドレスを渡している
 * よって、値渡しは渡した先で値を変えても、渡し元の値は変更されない
 * が、ポインタ渡しは渡した先で値を変更すると、渡し元の値も変更される
 */
