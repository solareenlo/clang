/*
 * 少し高度なファイル分割
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT 10 // 学生数
#define LENGTH 50 // 学生の名前の長さ
#define MESSAGE_LENGTH 256 // メッセージの長さ

enum ERROR { // エラーメッセージ
  MESSAGE_OK,
  MESSAGE_ERROR
};

typedef struct { // 学生のデータの型
  int id;
  char name[LENGTH];
} student;

int num = 0; // DB の学生数
student student_database[MAX_STUDENT]; // 学生のDB
int Error;
void initDatabase(); // DB の初期化
int add(int, char*); // DB へのデータ登録
student* get(int); // 学生のデータ取得
void showStudentData(student*); // 学生データ表示
void showError(); // エラー表示

int main(void) {
  int i;
  char names[][LENGTH] = {"Taro1", "Taro2", "Taro3", "Taro4"};
  int ids[] = {1, 2, 3, 3};
  initDatabase();
  for(i=0; i<4; i++) {
    add(ids[i], names[i]);
    printf("登録：%d, %s\n", ids[i], names[i]);
    showError();
  }
  for(i=0; i<3; i++)
    showStudentData(get(i+1));

  return 0;
}

void initDatabase() { // DB の初期化
  int i;
  for(i=0; i<MAX_STUDENT; i++) {
    student_database[i].id = -1; // 学生 ID の初期化
    strcpy(student_database[i].name, ""); // 学生名の初期化
  }
  Error = MESSAGE_OK; // エラーメッセージの初期化
  num = 0; // 登録学生数の初期化
}

int add(int id, char* name) { // DB への登録
  if(get(id) == NULL && num < MAX_STUDENT) { // 登録済みであれば登録しない
    student_database[num].id = id;
    strcpy(student_database[num].name, name);
    num++;
    Error = MESSAGE_OK;
    return 1; // 登録できれば1を返す
  }
  Error = MESSAGE_ERROR;
  return 0; // 登録できなければ0を返す
}

student* get(int id) { // 学生データ取得
  int i;
  for(i=0; i<num; i++)
    if(student_database[i].id == id) // 該当 ID が見つかったら、
      return &student_database[i];   // ポインタを返す
  return NULL;
}

void showStudentData(student* data) { // 学生データ表示
  if(data != NULL)
    printf("番号：%d, 名前：%s\n", data->id, data->name);
  else
    printf("データが登録されていません\n");
}

void showError() { // エラー表示
  switch(Error) {
  case MESSAGE_OK:
    printf("OK\n");
    break;
  case MESSAGE_ERROR:
    printf("ERROR\n");
    break;
  }
}

/* Output is here.
 * 登録：1, Taro1
 * OK
 * 登録：2, Taro2
 * OK
 * 登録：3, Taro3
 * OK
 * 登録：3, Taro4
 * ERROR
 * 番号：1, 名前：Taro1
 * 番号：2, 名前：Taro2
 * 番号：3, 名前：Taro3
*/
