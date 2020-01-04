/*
 * 構造体配列
 */
#include <stdio.h>
#include <string.h>

struct student {
  int id;
  char name[256];
  int age;
};

// 構造体の名前を typedef で定義する
typedef struct student student_data;

int main(void) {
  int i;

  student_data data[] = {
    {1, "Taro", 20},
    {2, "Hana", 21},
    {3, "Mike", 22}
  };

  for(i=0; i<3; i++)
    printf("番号：%d, 名前：%s, 年齢：%d\n", data[i].id, data[i].name, data[i].age);

  return 0;
}

/* Output is here.
 * 番号：1, 名前：Taro, 年齢：20
 * 番号：2, 名前：Hana, 年齢：21
 * 番号：3, 名前：Mike, 年齢：22
*/
