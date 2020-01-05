#include <stdio.h>
#include "051_dataOutput.h"

extern int Error; // エラーメッセージ

void showStudentData(student* data) { // 学生データの表示
  if(data != NULL)
    printf("番号：%d, 名前：%s\n", data->id, data->name);
  else
    printf("データが登録されていません\n");
}

void showError() { // エラーの表示
  switch(Error) {
  case MESSAGE_OK:
    printf("OK\n");
    break;
  case MESSAGE_ERROR:
    printf("ERROR\n");
    break;
  }
}
