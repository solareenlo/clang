/*
 * 関数のプロトタイプ宣言の定義
 */
#include <stdio.h>
#include "showResult.h"

extern int ans;

void showAnswer() {
  printf("%d\n", ans);
}
