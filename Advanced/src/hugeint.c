#define _CRT_SECURE_NO_WARNINGS 1 // Visual Studioでprintf使うための呪い
#include "hugeint.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

unsigned long long to_ulonglong(const huge_int *x)
{
  assert(x->size >= 0);
  assert(x->size <= 8);
  //if (x->size > 8) return ULLONG_MAX;
  unsigned long long ull = 0;
  int i;
  for (i=0; i<x->size; i++) {
    ull += (unsigned long long)x->num[i] << (i*CHAR_BIT);
  }
  return ull;
}


huge_int *from_uchar(unsigned char uc)
{
  if (uc > 0) {
    huge_int *r = malloc(sizeof(huge_int)+1);
    r->size=1; r->num[0]=uc;
    return r;
  } else {
    huge_int *r = malloc(sizeof(huge_int));
    r->size=0;
    return r;
  }
}

static int my_min(int x, int y)
{
  if (x<y) return x;
  else return y;
}

static int my_max(int x, int y)
{
  if (x>y) return x;
  else return y;
}

bool is_zero(const huge_int *a)
{
  assert(a->size >= 0);

  if (a->size == 0) return true;

  int i;
  for (i=0; i<a->size; i++)
    if (a->num[i] > 0) return false;
  
  return true;
}
  
huge_int *huge_add(const huge_int *a, const huge_int *b)
{
  assert(a->size >= 0);
  assert(b->size >= 0);
  errno=0;
  huge_int *result = malloc(a->size + b->size + sizeof(huge_int) + 1);
  if (result == NULL) {
    perror("malloc():");
    abort();
  }
  unsigned overflow=0;
  int i;
  for (i=0; i<my_min(a->size, b->size); i++) {
    unsigned two_bytes = overflow + a->num[i] + b->num[i];
    result->num[i] = two_bytes & 0xffU;
    overflow = two_bytes >> CHAR_BIT;
  }

  if (overflow == 0 && a->size == b->size) {
    result -> size = i;
    return result;
  } else if (overflow != 0 && a->size == b->size  ) {
    result -> num[i] = overflow;
    result -> size = 1+i;
    return result;
  }

  const unsigned char *rest;
  if (a->size > b->size) rest = a->num;
  else rest = b->num;
  for(i=my_min(a->size, b->size) ; i<my_max(a->size, b->size); i++) {
    unsigned two_bytes = overflow + rest[i];
    result->num[i] = two_bytes & 0xffU;
    overflow = two_bytes >> CHAR_BIT;
  }
  if (overflow==0) result -> size = i;
  else {
    result -> size = i+1;
    result->num[i]=overflow;
  }
  return result;
}

// 結果が負ならNULLを返す
huge_int *huge_subtract(const huge_int *a, const huge_int *b) // a-b
{
  assert(a->size >= 0);
  assert(b->size >= 0);

  int i;
  for (i = b->size-1; i>=a->size; i--)
    if (b->num[i] > 0) { /* fprintf(stderr, "first NULL\n"); */ return NULL;}

  errno=0;
  huge_int *result = malloc(a->size + sizeof(huge_int));
  if (result == NULL) {
    perror("malloc():");
    abort();
  }
  int underflow=0;
  for (i=0; i<my_min(a->size, b->size); i++) {
    int two_bytes = underflow + a->num[i] - b->num[i];
    result->num[i] = two_bytes & 0xff;
    underflow = two_bytes >> CHAR_BIT;
  }

  if (underflow != 0 && a->size < b->size  ) {
    free(result);
    return NULL;
  }

  for( ; i<a->size; i++) {
    int two_bytes = underflow + a->num[i];
    result->num[i] = two_bytes & 0xff;
    underflow = two_bytes >> CHAR_BIT;
  }
  if (underflow!=0)  {
    free(result);
    return NULL;
  }
  for (i=a->size-1; i>=0 && result->num[i] == 0; i--) ;
  result-> size = 1+i;
  return result;
}

huge_int *huge_multiply(const huge_int *a, const huge_int *b) // Compute a*b
{
  assert(a->size >= 0);
  assert(b->size >= 0);
  
  if (is_zero(a) || is_zero(b)) {
    huge_int *result = malloc(sizeof(huge_int));
    result->size=0;
    return result;
  }
  errno=0;
  huge_int *result = malloc(a->size + b->size + sizeof(huge_int));
  if (result == NULL) {
    perror("malloc():");
    abort();
  }

  result->size=0;
  memset(result->num, 0, a->size + b->size);
  int i,j;
  huge_int *tmp = malloc(a->size + b->size + sizeof(huge_int));
  for(i=0; i<b->size; i++) {
    memset(tmp->num, 0, a->size + b->size);
    tmp->size=0;
    unsigned overflow = 0;
    for(j=0; j<a->size; j++) {
      unsigned two_bytes = overflow + b->num[i] * a->num[j];
      tmp->num[i+j] = two_bytes & 0xffU;
      overflow = two_bytes >> CHAR_BIT;
    }

    if (overflow != 0) {
      tmp->num[i+ j] = overflow;
      tmp->size = i+j+1;
    } else
      tmp->size = i+j;
    huge_int *tmp2 = huge_add(result, tmp);
    free(result);
    result = tmp2;
  }

  free(tmp);
  return result;
}

huge_pair huge_divide(const huge_int *a, const huge_int *b) // Compute a / b and a % b
{
  assert(a->size >= 0);
  assert(b->size >= 0);
  
  if (is_zero(b)) {
    fprintf(stderr, "Division by zero!!\n");
    abort();
  }
  errno=0;
  huge_int *current_remainder = malloc(a->size + sizeof(huge_int));
  memmove(current_remainder, a, a->size + sizeof(huge_int));
  huge_int *current_quotient = malloc(sizeof(huge_int));
  current_quotient->size=0;
  huge_int *multiplier = malloc(a->size + sizeof(huge_int));
  multiplier -> size=a->size;
  int i;
  for (i=a->size-1; i>=0; i--) {
    int j;
    for (j=CHAR_BIT-1; j>=0; j--) {
      memset(multiplier->num, 0, a->size);
      multiplier->size=1+i;
      multiplier->num[i] = 1 << j;
      huge_int *tmp2 = huge_multiply(b, multiplier);
      huge_int *tmp = huge_subtract(current_remainder, tmp2);
      free(tmp2); tmp2=NULL;
      if (tmp != NULL) {
	free(current_remainder);
	current_remainder=tmp;
	tmp2= huge_add(current_quotient, multiplier);
	free(current_quotient);
	current_quotient=tmp2;
      }
    }
  }
  free(multiplier);
  huge_pair r = {current_quotient, current_remainder};
  return r;
}
