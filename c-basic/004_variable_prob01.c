#include <stdio.h>

int main(void) {
  int wide, height, depth;

  printf("直方体の高さ(自然数)：");
  scanf("%d", &height);
  printf("直方体の幅(自然数)：");
  scanf("%d", &wide);
  printf("直方体の奥行き(自然数)：");
  scanf("%d", &depth);
  printf("直方体の体積：%d\n", height*wide*depth);

  return 0;
}

/* Output is here.
 * 直方体の高さ(自然数)：10
 * 直方体の幅(自然数)：2
 * 直方体の奥行き(自然数)：3
 * 直方体の体積：60
*/
