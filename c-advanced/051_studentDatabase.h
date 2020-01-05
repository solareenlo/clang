#ifndef _051_STUDENT_DATABASE_H_
#define _051_STUDENT_DATABASE_H_

#define MAX_STUDENT 10 // 登録できる学生の最大数
#define LENGTH 50 // 名前の最大長

enum ERROR { // エラーメッセージ
  MESSAGE_OK,
  MESSAGE_ERROR
};

typedef struct { // 学生データの型
  int id; // 番号
  char name[LENGTH]; // 名前
} student;

void initDatabase(); // DB の初期化
int add(int, char*); // DB への登録
student* get(int); // 学生データの取得

#endif // _051_STUDENT_DATABASE_H_
