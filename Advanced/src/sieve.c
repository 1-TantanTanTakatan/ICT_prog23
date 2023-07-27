#define _CRT_SECURE_NO_WARNINGS 1 // Visual Studioでprintf使うための呪い

// エラトステネスのふるいっぽいプログラム
// https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9
// gcc -O1 -Wall -Wextra -g3 -fsanitize=undefined -fsanitize=address hugeint.c sieve.c -lm などでコンパイルする
// gccの代わりにclangでも良い
// プログラム起動時の引数に何も与えないと1から始めて千個の素数を表示し、引数n （ただしn <= 8）
// を指定するとnバイトのランダムな整数から千個の素数を表示する
// もしプログラムの２つ目の引数があればその個数だけ表示する　例：a.out 3 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include "hugeint.h"

static bool is_prime(const huge_int *x)
{
  huge_int *huge_one = from_uchar(1);

  huge_int *divider = huge_add(huge_one, huge_one);
  huge_pair qr;
  while(to_ulonglong(divider) <= sqrtl(to_ulonglong(x))) {
    qr = huge_divide(x, divider);
    if (qr.q->size == 1 && qr.q->num[0]==1) {
      free(qr.q); free(qr.r);
      break;
    }
    if (qr.r->size == 0) {
      free(qr.q); free(qr.r);
      free(divider); free(huge_one);
      return false;
    }
    free(qr.q); free(qr.r);
    huge_int *tmp = huge_add(huge_one, divider);
    free(divider);
    divider=tmp;
  }
  free(divider); free(huge_one);
  return true;
}
  
static huge_int *huge_random(int nbyte)
{
  huge_int *ret = malloc(nbyte + sizeof(huge_int));
  ret->size=nbyte;
  int i;
  for(i=0; i<nbyte; i++) {
    ret->num[i] = 0xffU & rand();
  }
  return ret;
}

int main(int argc, char **argv)
{
  huge_int *huge_one = from_uchar(1);
  huge_int* next;
  if (argc == 1)  next = from_uchar(1); 
  else next = huge_random(atoi(argv[1]));
  int iteration;
  if (argc >= 3) iteration = atoi(argv[2]);
  else iteration = 1000;
  int i=0;
  while (i < iteration) {
    if (is_prime(next)) {
      printf("%llu\n", to_ulonglong(next));
      i++;
    }
    huge_int *tmp = huge_add(next, huge_one);
    free(next); // これをしないとメモリリークをサニタイザに怒られる
    next = tmp;
  }
  free(next); free(huge_one);  // これをしないとメモリリークをサニタイザに怒られる
  return 0;
}
