/*
 * 関数のプロトタイプ宣言2
 */
#include <stdio.h>

int max(int, int);
void show(int);
void line();

int main(void) {
  int n1=2, n2=3;
  line();
  show(n1);
  show(n2);
  printf("2つの数値のうち、大きい方は、%dです\n", max(n1, n2));
  line();

  return 0;
}

int max(int a, int b) {
  if(a>b)
    return a;
  return b;
}

void show(int n) {
  printf("数値：%d\n", n);
  return;
}

void line(){
  printf("*********\n");
}

/* Output is here.
 * *********
 * 数値：2
 * 数値：3
 * 2つの数値のうち、大きい方は、3です
 * *********
*/
