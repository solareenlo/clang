/*
 * 構造体
 */
#include <stdio.h>
#include <string.h>

struct student {
  int id;
  char name[256];
  int age;
};

int main(void) {
  struct student data;

  data.id = 1;
  strcpy(data.name, "Taro Yamada");
  data.age = 20;

  printf("番号：%d, 氏名：%s, 年齢：%d\n", data.id, data.name, data.age);

  return 0;
}

/* Output is here.
 * 番号：1, 氏名：Taro Yamada, 年齢：20
 */
