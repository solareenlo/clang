/*
 * queue 内の任意の場所に item を追加する
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
  struct listitem *next; // 次のデータへのポインタ
  struct listitem *prev; // 前のデータへのポインタ
  int data; // 格納するデータ
} LISTITEM;

typedef struct {
  struct listitem *first; // queue 内の先頭データへのポインタ
  struct listitem *last; // queue 内の最後データへのポインタ
} LISTHDR;

LISTHDR head; // これが queue

void enqueue(LISTHDR *queue, LISTITEM *item); // queue の最後にデータを追加する
LISTITEM *dequeue(LISTHDR *queue); // queue の一番初めからデータを削除する
int queue_length(LISTHDR *queue); // queue 内のデータ数を返す
LISTITEM *add_after(LISTHDR *queue, int position, LISTITEM* item);

int main(void) {
  LISTITEM *temp;
  int requested_index;
  char input[50];
  int i;

  // 空の queue を作成
  // まずは head 内のポインタは自分自身を指し示す
  printf("address of head = %p\n", &head);
  head.first = (LISTITEM*)&head;
  head.last = (LISTITEM*)&head;

  for (i=0; i<3; i++) { // queue を作成する
    temp = malloc(sizeof(LISTITEM)); // malloc で動的に queue の1つの item 分を確保する
    printf("item[%d] のアドレス: %p\n", i, temp);
    temp->data = i; // とりあえすのデータを設定する
    enqueue(&head, temp); // queue 内に配置する
  }

  printf("queue の長さ: %d\n", queue_length(&head));
  // ユーザーが入力した index の item を追加する
  printf("enter the index of the queue entry ... ");
  requested_index = atoi(gets(input));
  temp = malloc(sizeof(LISTITEM));
  printf("追加する item のアドレス: %p\n", temp);
  temp->data = -requested_index; // 入力された index に - の値を付けた数字を data とする
  if(add_after(&head, requested_index, temp) == NULL) { // 追加できない場合は NULL が返ってくる
    printf("cannot add item at %d\n", requested_index);
    free(temp);
  }
  else {
    printf("追加した item: %d\n", requested_index);
  }

  // 昇順に queue の item を表示する
  temp = head.first;
  printf("昇順 ...\n");
  do {
    printf("addr=%p; data=%2d; next=%p; prev=%p;\n", temp, temp->data, temp->next, temp->prev);
    temp = temp->next;
  } while (temp != head.first);

  // 降順 に queue の item を表示する
  printf("降順 ...\n");
  temp = head.last;
  do {
    printf("addr=%p; data=%2d; next=%p; prev=%p;\n", temp, temp->data, temp->next, temp->prev);
    temp = temp->prev;
  } while (temp != head.last);

  // 追加した結果を表示する
  printf("the length of the queue is now %d\n", queue_length(&head));
  do {                     // queue が空になるまで続ける
    temp = dequeue(&head); // queue が空になると NULL が返ってくる
    if (temp != NULL) {
      printf("data in original queue is %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  return 0;
}

// queue の最後にデータを追加する
void enqueue(LISTHDR *queue, LISTITEM *item) {
  LISTITEM *temp;

  temp = queue->last;        // queue の最後のデータを確保する
  queue->last = item;        // queue の最後にデータを追加する
  item->prev = temp;        // 古い方の最後のデータを item の prev にリンクする
  item->next = (LISTITEM*)queue;  // 新しい item の前方リンクを設定する
  temp->next = item;        // 古い最後の item の新しいリンクを前方リンクに設定する
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
    queue->first = temp->next; // queue の先頭は次のデータを参照する
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

// `position` の後に item を追加する
// 戻り値は追加した item
// `position` が無い場合は NULL を返す
// NOTE: this uses a similar queue iteration technique to that used in 'queue_length'
LISTITEM* add_after(LISTHDR *queue, int position, LISTITEM* item) {
  LISTITEM *temp;
  int i;

  // 注: この例では負の位置を扱いませんが，
  // 逆のポインターを position として使用することを示すために負の position を使用できます
  if (position < 0) {
    return NULL;
  }

  temp = queue->first; // 先頭の item を取得
  i = 0;
  do {
    // この if 文で，queue が空かどうかを確認する
    // queue が空なら do ... while 文を終了させる
    if (temp == (LISTITEM*)queue) {
      temp = NULL; // queue の先頭が queue 自身なら do ... while 文を終了する
      break;
    }
    if(i == position) {
      // 以下の4つで item を挿入する
      // 追加するので参照が4つある
      // item が 追加する item
      // temp の後ろに item が追加される
      item->next = temp->next;
      temp->next = item;
      item->prev = temp;
      item->next->prev = item;
      break;
    }
    temp = temp->next; // queue 内の item を参照するため
    i = i + 1;         //  queue 内の item を1つずつ見るために i をインクリメントして position と比較する
  } while (temp != NULL);

  return temp;
}

/* Output is here
 * address of head = 0x103ebf038
 * item[0] のアドレス: 0x7f90f4c01780
 * item[1] のアドレス: 0x7f90f4c017a0
 * item[2] のアドレス: 0x7f90f4c017c0
 * queue の長さ: 3
 * warning: this program uses gets(), which is unsafe.
 * enter the index of the queue entry ... 0
 * 追加する item のアドレス: 0x7f90f4d00000
 * 追加した item: 0
 * 昇順 ...
 * addr=0x7f90f4c01780; data= 0; next=0x7f90f4d00000; prev=0x103ebf038;
 * addr=0x7f90f4d00000; data= 0; next=0x7f90f4c017a0; prev=0x7f90f4c01780;
 * addr=0x7f90f4c017a0; data= 1; next=0x7f90f4c017c0; prev=0x7f90f4d00000;
 * addr=0x7f90f4c017c0; data= 2; next=0x103ebf038; prev=0x7f90f4c017a0;
 * addr=0x103ebf038; data= 0; next=0x7f90f4c01780; prev=0x7f90f4c017c0;
 * 降順 ...
 * addr=0x7f90f4c017c0; data= 2; next=0x103ebf038; prev=0x7f90f4c017a0;
 * addr=0x7f90f4c017a0; data= 1; next=0x7f90f4c017c0; prev=0x7f90f4d00000;
 * addr=0x7f90f4d00000; data= 0; next=0x7f90f4c017a0; prev=0x7f90f4c01780;
 * addr=0x7f90f4c01780; data= 0; next=0x7f90f4d00000; prev=0x103ebf038;
 * addr=0x103ebf038; data= 0; next=0x7f90f4c01780; prev=0x7f90f4c017c0;
 * the length of the queue is now 4
 * data in original queue is 0
 * data in original queue is 0
 * data in original queue is 1
 * data in original queue is 2
 */
