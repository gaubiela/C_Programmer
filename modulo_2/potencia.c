#include <stdio.h>

void potencia(int a, int b) {
  int x = 0;
  for (int i = 0; i < b; i++) {
    x = a*a;
  }
  printf("%d^%d = %d", a, b, x);
}

int main() {
  int num1 = 2;
  int num2 = 0;

  potencia(num1, num2);
}