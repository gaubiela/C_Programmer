#include <stdio.h>

void soma(int *num, int a, int b) { (*num) = a + b; }

int main() {

  int a = 2, b = 2;
  int x = 0;

  soma(&x, a, b);
  printf("%d", x);
}