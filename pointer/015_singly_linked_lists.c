/*
 * ポインタでシングル連結リスト作成
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
  struct listitem *next; // 次の構造体のアドレスを格納する
  int data;
} LISTITEM;

int main(int argc, char **argv) {
  LISTITEM *listhead, *temp;
  int i;

  listhead = NULL;

  // シングル連結リスト作成
  for(i=0; i<3; i++) {
    temp = malloc(sizeof(LISTITEM));
    temp->data = i;
    temp->next = listhead;
    listhead = temp;
  }

  temp = listhead;
  while(temp != NULL) {
    printf("list item: %p, next: %p, data: %d\n", temp, temp->next, temp->data);
    temp = temp->next;
  }

  return 0;
}

/* Output is here.
 * list item: 0x7ff2d5c01750, next: 0x7ff2d5c01740, data: 2
 * list item: 0x7ff2d5c01740, next: 0x7ff2d5c01730, data: 1
 * list item: 0x7ff2d5c01730, next: 0x0, data: 0
 */
