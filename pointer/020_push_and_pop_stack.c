/*
 * stack 形式のデータを push して pop する
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int a;
  double b;
} DATA;

DATA *base;
DATA *end;
DATA *top;

#define STACKSIZE 5

int push(DATA *data);
DATA *pop();

int main(void) {
  DATA data, *pdata;
  int i;

  base = (DATA*)malloc(STACKSIZE * sizeof(DATA));
  end = base + STACKSIZE;
  top = base;

  // top が end になるまでデータを stack 形式で push する
  for(i=0; ; i++) {
    data.a = i;
    data.b = i * 2.0;
    if(!push(&data)) break;
  }

  printf("first item = %d, %.2lf\n", base->a, base->b);
  pdata = base + 4;
  printf("last item = %d, %.2lf\n", pdata->a, pdata->b);

  // top が base になるまでデータを stack 形式で pop する
  do {
    pdata = pop();
    if(pdata != NULL) printf("data popped is %d, %lf\n", pdata->a, pdata->b);
  } while (pdata != NULL);

  free(base);

  return 0;
}

int push(DATA *data) {
  int ok;

  if(top == end) {
    ok = 0;
  } else {
    // top へ data から sizeof(DATA) 分だけデータをコピーする
    memcpy(top, data, sizeof(DATA));
    top = top + 1;
    ok = 1;
  }

  return ok;
}

DATA *pop() {
  DATA *data;

  if(top == base) {
    data = NULL;
  } else {
    top = top - 1;
    data = top;
  }

  return data;
}

/* Output is here.
 * first item = 0, 0.00
 * last item = 4, 8.00
 * data popped is 4, 8.000000
 * data popped is 3, 6.000000
 * data popped is 2, 4.000000
 * data popped is 1, 2.000000
 * data popped is 0, 0.000000
 */
