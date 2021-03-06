/*
 * データを2つの構造体のポインタを使って，リスト構造で格納し，
 * データを先入れ先出し(queue)と，先入れ後出し(stack)を行う．
 * データの先出し(queue)と後出し(stack)はそれぞれコメントアウトしながら入れ替えて使う．
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  struct list *next; // 次のデータへのポインタ
  struct list *prev; // 前のデータへのポインタ
  int data; // 格納するデータ
} LIST;

typedef struct {
  struct list *first; // queue の先頭データへのポインタ
  struct list *last; // queue の最後データへのポインタ
} HEADER;

HEADER head; // これが queue

void enqueue(LIST *ima, HEADER *head); // doubly linked list で構造体をリスト化
LIST *dequeue(HEADER *head); // データ先出し用の関数
LIST *aoqueue(HEADER *head); // データ後出し用の関数

int main(void) {
  int i;
  LIST *ima;

  head.first = (LIST*)&head; // 一番初めの構造体データのアドレスが格納され，取り出しの時に上書きされる
  head.last = (LIST*)&head; // 一番最後の構造体データのアドレスが格納され，取り出しの時に上書きされる

  // ima 構造体にデータを先入れ
  /* printf("構造体にデータを先入れ\n"); */
  for(i=0; i<3; i++) {
    ima = malloc(sizeof(LIST));
    ima->data = i; // データを格納
    enqueue(ima, &head); // doubly linked list で構造体をリスト化
    /* printf("前: %p, 今: %p, 次: %p, データ: %d\n", ima->prev, ima, ima->next, ima->data); */
  }

  printf("first item = %d\n", head.first->data);
  printf("last item = %d\n", head.last->data);

  printf("普通の方法でデータを降順に出力\n");
  while(ima != (LIST*)&head) {
    printf("前: %p, 今: %p, 次: %p, データ: %d\n", ima->prev, ima, ima->next, ima->data);
    ima = ima->prev;
  }

  printf("普通の方法でデータを昇順に出力\n");
  ima = head.first;
  while(ima != (LIST*)&head) {
    printf("前: %p, 今: %p, 次: %p, データ: %d\n", ima->prev, ima, ima->next, ima->data);
    ima = ima->next;
  }

  // ima 構造体からデータを先出し
  printf("Queue を使って構造体からデータを先出し\n");
  do {
    ima = dequeue(&head);
    if(ima != NULL) {
      printf("前:%p, 今:%p, 次:%p, データ:%d\n", ima->prev, ima, ima->next, ima->data);
      free(ima);
    }
  } while(ima != NULL);

  // ima 構造体からデータを後出し
  /* printf("Queue を使って構造体からデータを後出し\n"); */
  /* do { */
  /*   ima = aoqueue(&head); */
  /*   if(ima != NULL) { */
  /*     printf("前: %p, 今: %p, 次: %p, データ: %d\n", ima->prev, ima, ima->next, ima->data); */
  /*     free(ima); */
  /*   } */
  /* } while(ima != NULL); */

  return 0;
}

// データ先出し用の関数
// 戻り値はデータ
// データがない場合は NULL を返す
LIST *dequeue(HEADER *head) {
  LIST *temp; // 飛び石用の構造体ポインタ生成

  temp = head->first;
  if(temp == (LIST*)head) { // queue の先頭が自分自身を参照している場合は，
    temp = NULL;            // queue の中身は空ということ．
  } else {
    head->first = temp->next; // queue の先頭は next データを参照する
    head->first->prev = (LIST*)head; // queue の次のデータの preve データは queue 自身を参照する
  }
  return temp;
}

// データ後出し用の関数
// 戻り値はデータ
// データがない場合は NULL を返す
LIST *aoqueue(HEADER *head) {
  LIST *temp; // 飛び石用の構造体ポインタ生成

  temp = head->last;
  if(temp == (LIST*)head) { // queue の最後が自分自身を参照している場合は，
    temp = NULL;            // queue の中身は空ということ．
  } else {
    head->last = temp->prev; // queue の最後が1つ前のデータを参照する
    head->last->next = (LIST*)head; // 1つ前のデータの次のデータは head を参照する
  }
  return temp;
}

// 構造体データを double linked list でリスト化
void enqueue(LIST *ima, HEADER *head) {
  LIST *temp; // 飛び石用の構造体ポインタ生成

  // 以下の部分の理解には同じディレクトリにある img ディレクトリ内の 016_doubly_linked_list.png を参照のこと
  temp = head->last; // temp に1つ前の構造体のアドレスを代入
  head->last = ima; // 今のアドレスを代入して，次の構造体が参照できる用に，
  ima->prev = temp; // 今の prev に1つ前の構造体のアドレスを代入
  ima->next = (LIST*)head; // 今の next に head のアドレスを代入して初期化
  temp->next = ima; // 1つ前の構造体の next に今のアドレスを代入
}

/* Output is here.
 * first item = 0
 * last item = 2
 * 普通の方法でデータを降順に出力
 * 前: 0x7fdc5f401760, 今: 0x7fdc5f401780, 次: 0x10f55a020, データ: 2
 * 前: 0x7fdc5f401740, 今: 0x7fdc5f401760, 次: 0x7fdc5f401780, データ: 1
 * 前: 0x10f55a020, 今: 0x7fdc5f401740, 次: 0x7fdc5f401760, データ: 0
 * 普通の方法でデータを昇順に出力
 * 前: 0x10f55a020, 今: 0x7fdc5f401740, 次: 0x7fdc5f401760, データ: 0
 * 前: 0x7fdc5f401740, 今: 0x7fdc5f401760, 次: 0x7fdc5f401780, データ: 1
 * 前: 0x7fdc5f401760, 今: 0x7fdc5f401780, 次: 0x10f55a020, データ: 2
 * Queue を使って構造体からデータを先出し
 * 前:0x10f55a020, 今:0x7fdc5f401740, 次:0x7fdc5f401760, データ:0
 * 前:0x10f55a020, 今:0x7fdc5f401760, 次:0x7fdc5f401780, データ:1
 * 前:0x10f55a020, 今:0x7fdc5f401780, 次:0x10f55a020, データ:2
 */
