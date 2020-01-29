/*
 * queue の中身を取り出して，別の queue にコピーする
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

LISTHDR src; // 元のデータ
LISTHDR dst; // 'destination' データ

void enqueue(LISTHDR *queue, LISTITEM *item); // queue の最後にデータを追加する
LISTITEM *dequeue(LISTHDR *queue); // queue の一番初めからデータを削除する

int main(void) {
  LISTITEM *temp;
  int i;

  // 空の `source` queue を作成
  src.first = (LISTITEM*)&src;
  src.last = (LISTITEM*)&src;
  // 空の `destination` queue を作成
  dst.first = (LISTITEM*)&dst;
  dst.last = (LISTITEM*)&dst;

  // source queue を作成する
  printf("source queue を作成中...\n");
  for(i=0; i<3; i++) {
    temp = malloc(sizeof(LISTITEM)); // malloc で動的にメモリ確保
    temp->data = i; // データを作成
    enqueue(&src, temp); // source queue 内にデータを格納する
    printf("data is %d\n", temp->data);
  }

  // 'source' queue からデータを削除して，'destination queue にそのコピーを追加する
  printf("destination queue にコピー中...\n");
  do { // 'source' queue が空になるまで繰り返す
    temp = dequeue(&src); // queue が空になると NULL が返ってくる
    if(temp != NULL) {
      printf("data is %d\n", temp->data);
      enqueue(&dst, temp);
    }
  } while (temp != NULL);

  // destination queue 内のデータを取り出す
  printf("destination queue ...\n");
  do { // queue 内が空になるまで繰り返す
    temp = dequeue(&dst); // queue が空になると NULL が返ってくる
    if(temp != NULL) {
      printf("destination data is %d\n", temp->data);
      free(temp); // 動的メモリ解放
    }
  } while (temp != NULL);

  printf("source queue ...\n");
  temp = dequeue(&src);  // queue が空になると NULL が返ってくる
  if(temp == NULL) {
    printf("source queue は空です\n");
  }

  printf("destinaion queue ...\n");
  temp = dequeue(&dst);  // queue が空になると NULL が返ってくる
  if(temp == NULL) {
    printf("destination queue は空です\n");
  }

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
LISTITEM* dequeue(LISTHDR *queue) {
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

/* Output is here
 * source queue を作成中...
 * data is 0
 * data is 1
 * data is 2
 * destination queue にコピー中...
 * data is 0
 * data is 1
 * data is 2
 * destination queue ...
 * destination data is 0
 * destination data is 1
 * destination data is 2
 * source queue ...
 * source queue は空です
 * destinaion queue ...
 * destination queue は空です
 */
