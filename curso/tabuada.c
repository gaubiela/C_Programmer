#include <stdio.h>

int main() {

  int num = 0;
  scanf("%d", &num);

  int vet[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < 11; i++) {
    int multi = num*i;
    printf("%d x %d = %d\n", num, i, multi);
  }
}