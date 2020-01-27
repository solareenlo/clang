/*
 * stack (データを後入れ後出し)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int a;
  double b;
} DATA;

DATA *bottm;
DATA *end;
DATA *current;

#define SIZE 5

int push(DATA*);
void stackPrint(int);
DATA* pop();

int main(void) {
  int i;
  DATA data, *pdata;

  bottm = (DATA*)malloc(SIZE * sizeof(DATA));
  end = bottm + SIZE;
  current = bottm;

  for(i=0; ; i++) {
    data.a = i;
    data.b = i * 3.0;
    if(!push(&data))
      break;
    printf("push %2d: ", data.a);
    stackPrint(data.a);
  }

  printf("底のデータ: %d, %.2f\n", bottm->a, bottm->b);
  pdata = bottm + SIZE-1;
  printf("最後のデータ: %d, %.2f\n", pdata->a, pdata->b);

  do {
    pdata = pop();
    if(pdata != NULL) {
      printf("ポップしたデータ: %d, %.2f\n", pdata->a, pdata->b);
      printf("pop %2d: ", pdata->a);
      stackPrint(pdata->a);
    }
  } while(pdata != NULL);

  free(bottm);

  return 0;
}

int push(DATA* data) {
  int ok;

  if(current == end) {
    ok = 0;
  } else {
    memcpy(current, data, sizeof(DATA));
    current = current + 1;
    ok = 1;
  }
  return ok;
}

DATA* pop() {
  DATA* data;

  if(current == bottm) {
    data = NULL;
  } else {
    current = current - 1;
    data = current;
  }
  return data;
}

void stackPrint(int num) {
  int i;

  printf("stack [");
  for(i=0; i<num; i++) {
    printf("%3d", i);
  }
  printf("]\n");
}

/* Output is here.
 * push  0: stack []
 * push  1: stack [  0]
 * push  2: stack [  0  1]
 * push  3: stack [  0  1  2]
 * push  4: stack [  0  1  2  3]
 * 底のデータ: 0, 0.00
 * 最後のデータ: 4, 12.00
 * ポップしたデータ: 4, 12.00
 * pop  4: stack [  0  1  2  3]
 * ポップしたデータ: 3, 9.00
 * pop  3: stack [  0  1  2]
 * ポップしたデータ: 2, 6.00
 * pop  2: stack [  0  1]
 * ポップしたデータ: 1, 3.00
 * pop  1: stack [  0]
 * ポップしたデータ: 0, 0.00
 * pop  0: stack []
 */
