/*
 * グローバル変数
 */
#include <stdio.h>

int global = 100;
void func1(double, int);
void func2();

int main(void) {
  double a = 1.0;
  int b = 1;

  printf("************\n");
  printf("main中\n");
  printf("global=%d\n", global);
  printf("a=%f b=%d\n", a, b);
  printf("************\n");
  func1(3.14, 10);
  func2();

  return 0;
}

void func1(double a, int b) {
  printf("func1中\n");
  printf("global=%d\n", global);
  printf("a=%f b=%d\n", a, b);
  printf("************\n");
}

void func2() {
  double a=1.1;
  int b=2;
  printf("func2中\n");
  printf("global=%d\n", global);
  printf("a=%f b=%d\n", a, b);
  printf("************\n");
}

/* Output is here.
 * ************
 * main中
 * global=100
 * a=1.000000 b=1
 * ************
 * func1中
 * global=100
 * a=3.140000 b=10
 * ************
 * func2中
 * global=100
 * a=1.100000 b=2
 * ************
*/
