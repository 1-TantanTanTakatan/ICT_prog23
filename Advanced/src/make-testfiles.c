#define _CRT_SECURE_NO_WARNINGS 1 // Visual Studioでprintf使うための呪い
#include <stdio.h>
#include <errno.h>

int main(void)
{
  FILE *fp;
  errno=0;
  if ((fp = fopen("empty.bin", "wb")) == NULL) {
    perror("fopen(empty.bin)");
    return 1;
  }
  fclose(fp);
  
  errno=0;
  if ((fp = fopen("zero.bin", "wb")) == NULL) {
    perror("zero.bin");
    return 1;
  }
  fputc(0, fp);
  fclose(fp);

  errno=0;
  if ((fp = fopen("zerozero.bin", "wb")) == NULL) {
    perror("zerozero.bin");
    return 1;
  }
  fputc(0, fp);
  fputc(0, fp);
  fclose(fp);

  return 0;
}
