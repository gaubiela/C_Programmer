#include <stdio.h>

void potencia(int *resultado, int a, int b) {
  for (int i = 0; i < b; i++) {
    *resultado = *resultado * a;
  }
}

int main() {
  int resultado = 1;
  potencia(&resultado, 10, 5);
  printf("%d", resultado);
}