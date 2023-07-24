#include <stdbool.h>

typedef struct {
  int size; // num[0]〜num[size-1] までにリトルエンディアンで符号なし整数が格納される
  unsigned char num[];
} huge_int; // マイナスの整数は表せない
// size == 0 の場合は値がゼロであると見なす。size < 0 の引数を下記関数群に渡すとエラーになる。
// 上記の整数型に値を設定する手順はhugeint.cのfrom_uchar()を参考にして欲しい

/*
  数値例
  許される huge_int zero = { 0 }; 
  許されない huge_int one = {1, {1} };
  許されない huge_int huge258 = {2, {2, 1 }};  == 2 + 256 * 1 == 258
*/


// 以下のhuge_int *ポインタを返す関数群はすべてmalloc()で確保したメモリ領域へのポインタを返すため、
// 使わなくなった後に返り値のポインタをfree()しないとメモリリークでサニタイザに怒られる
unsigned long long to_ulonglong(const huge_int *x); // 普通の整数型に変換する
huge_int *from_uchar(unsigned char uc); // 普通のunsigned charからhuge_int型に変換する
huge_int *huge_add(const huge_int *a, const huge_int *b); // 足し算
huge_int *huge_subtract(const huge_int *a, const huge_int *b); // 引き算。結果が負ならNULLを返す
huge_int *huge_multiply(const huge_int *a, const huge_int *b); // 掛け算

// 以下は割り算の剰余と商を格納するためのデータ型である
typedef struct {
  huge_int *q; // 割り算の商 (quotient)
  huge_int *r; // 割り算の剰余 (remainder)
} huge_pair;

//以下はaをbで割った商と剰余を返す
huge_pair huge_divide(const huge_int *a, const huge_int *b);

// ゼロか否か？
bool is_zero(const huge_int *a);

//上記の関数群の使い方は素数を1000個探して表示する sieve.c を読んで参考にして欲しい
