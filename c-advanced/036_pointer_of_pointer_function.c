/*
 * 関数の引数にポインタのポインタを使用する
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int createMemory(char**, int);
void freeMemory(char**);

int main(void) {
  char* s = NULL;

  createMemory(&s, 255);
  strcpy(s, "Hello World\n");
  printf("%s", s);
  freeMemory(&s);

  return 0;
}

/*
 * メモリの生成や消去を関数内で行う場合は
 * 関数へポインタのポインタを渡すことになる
*/
int createMemory(char** m, int size) {
  if(*m == NULL) {
    *m = (char*)malloc(sizeof(char)*size);
    if(*m == 0) //メモリが生成できなければエラー
      return -1;
    return 0;
  }
  return 0;
}

void freeMemory(char** m) {
  if(m != 0)
    free(*m);
}

/* Output is here.
 * Hello World
 */
