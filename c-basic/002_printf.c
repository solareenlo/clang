/*
 * printf
 */
#include <stdio.h>

int main(void) {
  printf("Hello. My name is %s.\n", "Taro");
  printf("%f + %f = %f\n", 1.2, 2.3, 1.2+2.3);

  return(0);
}

/* Output is here.
 * Hello. My name is Taro.
 * 1.200000 + 2.300000 = 3.500000
*/
