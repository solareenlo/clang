/*
 * queue 内の途中の item を削除する
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
LISTITEM *remove_at(LISTHDR *queue, int position); // position からのデータを削除する

int main() {
  LISTITEM *temp;
  int requested_index;
  char input[50];
  int i;

  // 空の queue を作成
  // まずは head 内のポインタは自分自身を指し示す
  head.first = (LISTITEM*)&head;
  head.last = (LISTITEM*)&head;

  for(i=0; i<5; i++) {               // queue を作成する
    temp = malloc(sizeof(LISTITEM)); // malloc で動的に queue の1つの item 分を確保する
    temp->data = i;                  // データを格納する
    enqueue(&head, temp);            // temp を queue 内に配置する
  }

    // setbuf(stdout, NULL); // NOTE: If you are using an IDE such as CodeLite and nothing is initially shown
                             // in its Terminal you may need to uncomment this to turn off buffering

  printf("the length of the queue is %d\n", queue_length(&head));
  // ユーザーが入力したインデックスを削除する
  printf("enter the index of the queue entry ... ");
  requested_index = atoi(gets(input));
//  do {              // keep going ...
    temp = remove_at(&head, requested_index); // remove できない場合は NULL が返ってくる
    if(temp != NULL) {
      printf("OK: data removed at %d is %d\n", requested_index, temp->data);
      free(temp);
    }
    else {
      printf("ERROR: cannot remove at %d\n", requested_index);
    }
//  } while (temp != NULL);

  // 削除した結果を表示する
  printf("the length of the queue is %d\n", queue_length(&head));
  do {                     // queue が空になるまで続ける
    temp = dequeue(&head); // queue が空の場合は NULL が返ってくる
    if (temp != NULL) {
      printf("data is %d\n", temp->data);
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

// this removes an item from 'position' in a queue - returns the item or NULL if the position does not exist
// NOTE: this uses a similar queue iteration technique to that used in 'queue_length'
// position から item を削除する
LISTITEM *remove_at(LISTHDR *queue, int position) {
  LISTITEM *temp;
  int i;

  // 注：この例では負の位置を扱いませんが、逆のポインターを position として使用することを示すために負の位置を使用できます
  if(position < 0) {
    return NULL;
  }

  temp = queue->first; // queue の先頭の item を取得する
  i = 0;
  do {
    // この if 文で，queue が空かどうかを確認する
    // queue が空なら do ... while 文を終了させる
    if(temp == (LISTITEM*)queue) {
      temp = NULL; // queue の先頭が queue 自身なら do ... while 文を終了する
      break;
    }
    if(i == position) {
      // 以下の2つで自分への参照を飛ばす
      temp->prev->next = temp->next; // [自分の前の item ]の次の参照を，自分の次の item に変更する
      temp->next->prev = temp->prev; // [自分の次の item ]の前の参照を，自分の前の item に変更する
      temp->next = NULL; // 参照を削除
      temp->prev = NULL; // 参照を削除
      break;
    }
    temp = temp->next; // queue 内の次の item を取得する
    i = i + 1;         // 対応するインデックス position をインクリメントする
  } while (temp != NULL);

  return temp;
}
