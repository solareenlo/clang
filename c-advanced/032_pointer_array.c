/*
 * ポインタと配列
 */
#include <stdio.h>

#define SIZE 5

int main(void) {
  int a1[SIZE];
  char a2[SIZE];
  int i;
  int* p1 = NULL;
  char* p2 = NULL;

  for(i=0; i<SIZE; i++) {
    a1[i] = i;
    a2[i] = 'A'+i;
  }
  p1 = &a1[0];
  p2 = &a2[0];

  for(i=0; i<SIZE; i++) {
    printf("a1[%d]=%d, *(p1+%d)=%d, ", i, a1[i], i, *(p1+i));
    printf("a2[%d]=%c, *(p2+%d)=%c\n", i, a2[i], i, *(p2+i));
  }

  return 0;
}

/* Output is here.
 * a1[0]=0, *(p1+0)=0, a2[0]=A, *(p2+0)=A
 * a1[1]=1, *(p1+1)=1, a2[1]=B, *(p2+1)=B
 * a1[2]=2, *(p1+2)=2, a2[2]=C, *(p2+2)=C
 * a1[3]=3, *(p1+3)=3, a2[3]=D, *(p2+3)=D
 * a1[4]=4, *(p1+4)=4, a2[4]=E, *(p2+4)=E
*/
