/*
 * 構造体のポインタ
 */
#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[256];
  int age;
} student_data;

void setData(student_data*, int, char*, int);
void showData(student_data*);

int main(void) {
  student_data data[3];
  int i;
  int id[] = {1, 2, 3};
  char name[][256] = {"Taro", "Hanako", "Mike"};
  int age[] = {20, 21, 22};

  for(i=0; i<3; i++)
    setData(&data[i], id[i], name[i], age[i]);

  for(i=0; i<3; i++)
    showData(&data[i]);

  return 0;
}

void setData(student_data* data, int id, char* name, int age) {
  data->id = id;
  strcpy(data->name, name);
  data->age = age;
}

void showData(student_data* data) {
  printf("番号：%d, 名前：%s, 年齢：%d\n", data->id, data->name, data->age);
}

/* Output is here.
 * 番号：1, 名前：Taro, 年齢：20
 * 番号：2, 名前：Hanako, 年齢：21
 * 番号：3, 名前：Mike, 年齢：22
*/
