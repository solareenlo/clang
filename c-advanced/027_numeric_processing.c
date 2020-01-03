/*
 * 数値処理
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int main(void) {
  int a, b;
  int angle;
  double rad;
  int n=-1;
  double d1=-2.1, d2=3.0;
  unsigned char i = 0xf; // 00001111
  unsigned char j = 0xff; // 11111111

  srand((unsigned) time(NULL));
  a = rand() % 10 + 1;
  b = rand() % 10 + 1;
  printf("%d+%d=%d\n", a, b, a+b);

  printf("角度を度数法で入力してください(0~360)：");
  scanf("%d", &angle);
  rad = PI * (double)angle / 180.0;
  printf("sin(%d)=%f\n", angle, sin(rad));
  printf("cos(%d)=%f\n", angle, cos(rad));
  printf("tan(%d)=%f\n", angle, tan(rad));
  /* Output is here.
   * 10+10=20
   * 角度を度数法で入力してください(0~360)：180
   * sin(180)=0.001593
   * cos(180)=-0.999999
   * tan(180)=-0.001593
   */

  printf("%dの絶対値は%d\n", n, abs(n));
  printf("%fの絶対値は%f\n", d1, fabs(d1));
  printf("%fの2乗は%f\n", d2, pow(d2, 2));
  printf("%fの平方根は%f\n", d2, sqrt(d2));
  /* Output is here.
   * -1の絶対値は1
   * -2.100000の絶対値は2.100000
   * 3.000000の2乗は9.000000
   * 3.000000の平方根は1.732051
   */

  printf("%x << 1 = %x\n", i, i<<1);
  printf("%x >> 1 = %x\n", i, i>>1);
  printf("%x | %x = %x\n", i, j, i|j);
  printf("%x & %x = %x\n", i, j, i&j);
  printf("~%x = %x\n", i, (unsigned char)~i);
  /* Output is here.
   * f << 1 = 1e // 1ビット左シフト：00001111 -> 00011110 = 0x1e0
   * f >> 1 = 7  // 1ビット右シフト：00001111 -> 00000111 = 0x7
   * f | ff = ff // OR 演算子：00001111 or 11111111 = 11111111 = 0xff
   * f & ff = f  // AND 演算子：00001111 and 11111111 = 00001111 = 0xf
   * ~f = f0     // NOT 演算子：00001111 -> 11110000 = 0xf0
   */

  return 0;
}
