/*
 * deep copy: オリジナルのデータを別のメモリにコピーして，そのコピーしたアドレスを参照するコピー方法
 * shallow copy: オリジナルのアドレスをそのまま参照するコピー方法
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXBUFLEN 10

// queue 内の item
typedef struct listitem {
  struct listitem *next; // 次のデータへのポインタ
  struct listitem *prev; // 前のデータへのポインタ
  char* data;            // 格納するデータ
} LISTITEM;

// header
typedef struct {
  struct listitem *first; // queue 内の先頭データへのポインタ
  struct listitem *last;  // queue 内の最後データへのポインタ
} LISTHDR;

LISTHDR original;     // original queue
LISTHDR deep_copy;    // deep copy of queue
LISTHDR shallow_copy; // shallow copy of queue

void enqueue(LISTHDR *queue, LISTITEM *item); // queue の最後にデータを追加する
LISTITEM *dequeue(LISTHDR *queue);            // queue の一番初めからデータを削除する
int queue_length(LISTHDR *queue);             // queue 内のデータ数を返す

int main(void) {
  LISTITEM *temp, *temp1;
  char* pdata;
  int i;

  // 空の queue を作成
  // まずは head 内のポインタは自分自身を指し示す
  original.first = (LISTITEM*)&original;
  original.last = (LISTITEM*)&original;
  deep_copy.first = (LISTITEM*)&deep_copy;
  deep_copy.last = (LISTITEM*)&deep_copy;
  shallow_copy.first = (LISTITEM*)&shallow_copy;
  shallow_copy.last = (LISTITEM*)&shallow_copy;

  // STEP1: original queue を作成する
  for(i=0; i<3; i++) {
    temp = malloc(sizeof(LISTITEM));          // 新しい queue item を作成する
    temp->data = (char*)malloc(MAXBUFLEN);    // set the item's data to some memory
    snprintf(temp->data, MAXBUFLEN, "%u", i); // and set it to the character string of the index
    enqueue(&original, temp);                 // and put it in the queue
  }

  // NOTE: this shows how to iterate over a queue explicitly
  printf("the length of the original queue is %d\n", queue_length(&original));
  temp = original.first;                  // get the first item in the queue
  do {
    printf("data in original queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;                    // move to next item
  } while (temp->next != original.first); // continue until we've been through the entire queue


  // STEP2: deep copy を作成する
  temp = original.first; // get the first item in the queue
  do {
    temp1 = (LISTITEM*)malloc(sizeof(LISTITEM)); // allocate memory for a new queue item
    memcpy(temp1, temp, sizeof(LISTITEM));       // make a copy
    pdata = (char*)malloc(MAXBUFLEN);            // allocate memory for new data
    memcpy(pdata, temp->data, MAXBUFLEN);        // and copy it from the old data
    temp1->data = pdata;                         // set the item's payload to the new data
    enqueue(&deep_copy, temp1);                  // add to the 'copy' queue
    temp = temp->next;                           // move to next item
  } while (temp->next != original.first);        // continue until we've been through the entire queue

  // 作成した deep copy を表示する
  printf("the length of the deep copy queue is %d\n", queue_length(&deep_copy));
  temp = deep_copy.first;                  // get the first item in the queue
  do {
    printf("data in deep copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;                     // move to next item
  } while (temp->next != deep_copy.first); // continue until we've been through the entire queue

  // STEP3: shallow copy を作成する
  // NOTE: the difference between 'deep' and 'shallow' is that the payload or data item is NOT copied
  // so the original and the copy queue items point to the same data
  temp = original.first; // get the first item in the queue
  do {
    temp1 = (LISTITEM*)malloc(sizeof(LISTITEM)); // allocate memory for a new queue item
    memcpy(temp1, temp, sizeof(LISTITEM));       // make a copy
    enqueue(&shallow_copy, temp1);               // add to the shallow 'copy' queue
    temp = temp->next;                           // move to next item
  } while (temp->next != original.first);        // continue until we've been through the entire queue

  // 作成した shallow copy を表示する
  printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
  temp = shallow_copy.first; // get the first item in the queue
  do {
    printf("data in shallow copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;                        // move to next item
  } while (temp->next != shallow_copy.first); // continue until we've been through the entire queue

  // STEP4: original queue のメモリを開放する
  do {                         // keep going until the queue is empty
    temp = dequeue(&original); // if the queue is empty we will get NULL returned
    if (temp != NULL) {
      // NOTE: freeing 'temp' does NOT free all the allocated data
      // BOTH the list item and the payload must be freed
      // also, the free calls MUST be done in the correct order
      free(temp->data);        // call 'free' to tidy up the string data
      free(temp);              // call 'free' to tidy up the queue item itself
    }
  } while (temp != NULL);


  // STEP5: shallow copy と deep copy を表示する
  printf("\nafter deleting the original queue ...\n");
  printf("the length of the deep copy queue is %d\n", queue_length(&deep_copy));
  temp = deep_copy.first; // get the first item in the queue
  do {
    printf("data in deep copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;                     // move to next item
  } while (temp->next != deep_copy.first); // continue until we've been through the entire queue

  // DISASTER!!!! - the shallow queue contains references to 'freed memory - now probably junk
  printf("the length of the shallow copy queue is %d\n", queue_length(&shallow_copy));
  temp = shallow_copy.first; // get the first item in the queue
  do {
    printf("data in shallow copy queue is '%s' at address %p\n", temp->data, temp->data);
    temp = temp->next;                        // move to next item
  } while (temp->next != shallow_copy.first); // continue until we've been through the entire queue

  return 0;
}

// queue の最後にデータを追加する
void enqueue(LISTHDR *queue, LISTITEM *item) {
  LISTITEM *temp;

  temp = queue->last;             // queue の最後のデータを確保する
  queue->last = item;             // queue の最後にデータを追加する
  item->prev = temp;              // 古い方の最後のデータを item の prev にリンクする
  item->next = (LISTITEM*)queue;  // 新しい item の前方リンクを設定する
  temp->next = item;              // 古い最後の item の新しいリンクを前方リンクに設定する
}

// queue の一番初めからデータを取り出す
// 戻り値はデータ
// データがない場合は NULL を返す
LISTITEM *dequeue(LISTHDR *queue) {
  LISTITEM *temp;

  temp = queue->first; // 'first' item を取得
  if(temp == (LISTITEM*)queue) { // queue の先頭が自分自身を参照している場合は，
    temp = NULL;                 // queue の中身は空ということ．
  }
  else {
    queue->first = temp->next;             // queue の先頭は次のデータを参照する
    queue->first->prev = (LISTITEM*)queue; // 次のデータの prev は queue 自身を参照する
  }
  return temp;
}

// queue 内のデータ数を返す
int queue_length(LISTHDR* queue) {
  LISTITEM *temp;
  int length;

  temp = queue->first; // queue の最初のデータを取得する
  length = 0; // queue の長さを初期化
  do {
    // 空の queue を確認するか queue 内を確認する
    if(temp == (LISTITEM*)queue) {
      temp = NULL; // queue の先頭が queue 自身なら do ... while 文を終了する
      break;
    }
    temp = temp->next; // queue 内の次のデータを取得する
    length = length + 1;
  } while (temp != NULL);

  return length;
}

/* Output is here
 * the length of the original queue is 3
 * data in original queue is '0' at address 0x7fd9c44017a0
 * data in original queue is '1' at address 0x7fd9c44017d0
 * data in original queue is '2' at address 0x7fd9c4401800
 * the length of the deep copy queue is 3
 * data in deep copy queue is '0' at address 0x7fd9c4401830
 * data in deep copy queue is '1' at address 0x7fd9c4401860
 * data in deep copy queue is '2' at address 0x7fd9c4401890
 * the length of the shallow copy queue is 3
 * data in shallow copy queue is '0' at address 0x7fd9c44017a0
 * data in shallow copy queue is '1' at address 0x7fd9c44017d0
 * data in shallow copy queue is '2' at address 0x7fd9c4401800
 *
 * after deleting the original queue ...
 * the length of the deep copy queue is 3
 * data in deep copy queue is '0' at address 0x7fd9c4401830
 * data in deep copy queue is '1' at address 0x7fd9c4401860
 * data in deep copy queue is '2' at address 0x7fd9c4401890
 * the length of the shallow copy queue is 3
 * data in shallow copy queue is '' at address 0x7fd9c44017a0
 * data in shallow copy queue is '' at address 0x7fd9c44017d0
 * data in shallow copy queue is '' at address 0x7fd9c4401800
 */
