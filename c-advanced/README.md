# 発展内容

## math.h を使うときのコンパイル方法
```bash
gcc xxx.c -lm
```
と後ろに `-lm` を追加する。

## ポインタ
### ポインタのポインタの書き方
```c
** p;
```

### ポインタのポインタの利点
- ポインタの状態のチェックなどといったコードを関数内でできることから、ソースコードの中に同じようなコードを何度も書く必要が無いという点。

## 関数ポインタ
### 関数ポインタの書式
```c
型名 (*変数名)(引数)
```
- 037_fuction_pointer2.c を参照のこと。

### 引数内での関数ポインタの書式
```c
型名 (*)(引数)
```
- 037_function_pointer3.c を参照のこと。

### 引数内での関数ポインタを使用する利点
- 関数ポインタは、関数内で呼び出す関数を動的に変更する時に非常に便利。
- 037_function_pointer3.c を参照のこと。

## 構造体と共用体の違い
- 構造体は複数の変数をひとまとめにしたもの。
    - それぞれの変数をメンバーという。
- 共用体は複数あるメンバーのうち、同時に使うことができるのはどれか一つだけ。
    - ここが構造体と共用体の違い。
- 共用体のメモリサイズは、メンバーの中のもっとも大きいものと等しくなっている。
- 共用体を使う理由はメモリの節約。

## 値渡しとポインタ渡しの違い
- 値渡しはコピーを渡す。
    - ので、渡し元のデータは書き換えられない。
- ポインタ渡しはそのデータのアドレスを渡す。
    - ので、渡し元のデータも書き換えられる。

## fopen() 関数のモード

| モード    | 機能                                                         | ファイルが存在しないとき |
|:----------|:-------------------------------------------------------------|:-------------------------|
| r         | テキストデータの読み込み                                     | エラーになる             |
| w         | テキストデータの書き込み                                     | ファイルを新規作成する   |
| a         | テキストデータへの追加書き込み                               | ファイルを新規作成する   |
| r+        | テキストデータを更新モードで開く（書き込み・読み込み共に可） | エラーになる             |
| w+        | テキストデータを更新モードで開く（書き込み・読み込み共に可） | ファイルを新規作成する   |
| a+        | テキストデータを更新モードで開く（書き込み・読み込み共に可） | ファイルを新規作成する   |
| rb        | バイナリデータの読み込み                                     | エラーになる             |
| wb        | バイナリデータの書き込み                                     | ファイルを新規作成する   |
| ab        | バイナリデータへの追加書き込み                               | ファイルを新規作成する   |
| rb+ / r+b | バイナリデータを更新モードで開く（書き込み・読み込み共に可） | エラーになる             |
| wb+ / w+b | バイナリデータを更新モードで開く（書き込み・読み込み共に可） | ファイルを新規作成する   |
| ab+ / a+b | バイナリデータを更新モードで開く（書き込み・読み込み共に可） | ファイルを新規作成する   |