/*
 * generic pointer の例
 */
#include <stdio.h>

#define LENGTH 3

int data[LENGTH];
char* words[LENGTH];

int main(int argc, char **argv) {
    void *gp;
    int i;

    printf ("generic pointer の例\n");

    // データの初期化
    for (i=0; i<LENGTH; i++)
      data[i] = i;
    for (i=0; i<LENGTH; i++)
      printf("%d ", data[i]);
    printf("\n");

    words[0] = "zero";
    words[1] = "one";
    words[2] = "two";
    for (i=0; i<LENGTH; i++)
      printf("%s ", words[i]);
    printf("\n");

    gp = data;
    printf("\nint 型配列のアドレス：%p\n", gp);

    for(i=0; i<LENGTH; i++) {
      printf("gp ポインタが指し示す先の値：%d（%p）\n", *(int*)gp, (int*)gp);
      gp = (int*)gp + 1;
    }

    gp = words;
    printf("\n文字列型配列のアドレス：%p\n", gp);

    for(i=0; i<LENGTH; i++) {
      printf("gp ポインタが指し示す先の値：%s（%p）\n", *(char**)gp, (char**)gp);
      gp = (char**)gp + 1;
    }

	return 0;
}

/* Output is here.
 * generic pointer の例
 * 0 1 2
 * zero one two
 *
 * int 型配列のアドレス：0x102f0f010
 * gp ポインタが指し示す先の値：0（0x102f0f010）
 * gp ポインタが指し示す先の値：1（0x102f0f014）
 * gp ポインタが指し示す先の値：2（0x102f0f018）
 *
 * 文字列型配列のアドレス：0x102f0f020
 * gp ポインタが指し示す先の値：zero（0x102f0f020）
 * gp ポインタが指し示す先の値：one（0x102f0f028）
 * gp ポインタが指し示す先の値：two（0x102f0f030）
*/
