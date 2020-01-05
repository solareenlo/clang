#include <string.h>
#include "051_studentDatabase.h"

#define MESSAGE_LENGTH 256

static int num = 0; // DB に登録されている学生数
static student student_database[MAX_STUDENT]; // 学生の DB
int Error = MESSAGE_OK; // エラーメッセージ

void initDatabase() { // DB の初期化
  int i;
  for(i=0; i<MAX_STUDENT; i++) {
    student_database[i].id = -1;
    strcpy(student_database[i].name, "");
  }
  Error = MESSAGE_OK; // エラーメッセージのクリア
  num = 0; // 登録済み学生の数を0に初期化
}

int add(int id, char* name) { // DB への登録
  if(get(id)==NULL && num<MAX_STUDENT) { // 登録済みだと登録しない
    student_database[num].id = id;
    strcpy(student_database[num].name, name);
    num++;
    Error = MESSAGE_OK;
    return 1; // 登録できたら1を返す
  }
  Error = MESSAGE_ERROR;
  return 0; // 登録できなければ0を返す
}

student* get(int id) { // データの取得
  int i;
  for(i=0; i<num; i++) {
    if(student_database[i].id == id)
      return &student_database[i];
  }
  return NULL;
}
