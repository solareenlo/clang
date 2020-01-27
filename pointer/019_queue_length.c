/*
 * queue のデータ数を確認する
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

int main() {
  LISTITEM *temp;
  int i;

  // 空の queue を作成
  // まずは head 内のポインタは自分自身を指し示す
  head.first = (LISTITEM*)&head;
  head.last = (LISTITEM*)&head;

  printf("初めの queue の長さ: %d\n", queue_length(&head));
  for(i=0; i<3; i++) {  // queue を作成する
    temp = malloc(sizeof(LISTITEM)); // malloc で動的にメモリ確保
    temp->data = i; // データを格納
    enqueue(&head, temp); // queue 内にデータを格納する
  }
  printf("初期化後の queue の長さ: %d\n\n", queue_length(&head));

  // queue 内を確認する
  do { // queue が空になるまで取り出す
    printf("queue の長さ: %d\n", queue_length(&head));
    temp = dequeue(&head); // queue が空になると NULL が返ってくる
    if (temp != NULL) {
      printf("dequeue されたデータ: %d (address of struct: %p)\n", temp->data, temp);
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
LISTITEM* dequeue(LISTHDR *queue) {
  LISTITEM *temp;

  temp = queue->first; // 'first' item を取得
  if(temp == (LISTITEM*)queue) { // queue の先頭が自分自身を参照している場合は，
    temp = NULL;                 // queue の中身は空ということ．
  }
  else {
    queue->first = temp->next; // queue の先頭は2番目のデータを参照する
    queue->first->prev = (LISTITEM*)queue;
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
      temp = NULL; // queue の最初が queue 自身なら do ... while 文を終了する
      break;
    }
    temp = temp->next; // queue 内の次のデータを取得する
    length = length + 1;
  } while (temp != NULL);

  return length;
}
