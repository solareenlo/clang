/*
 * 051_main_long.c を分割したバージョン
 */
#include <stdio.h>
#include "051_studentDatabase.h"
#include "051_dataOutput.h"

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
