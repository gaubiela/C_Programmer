#include <stdio.h>
#include <string.h>

void soma(int numeros[10]) {
  int somatorio = 0;
  for (int i = 0; i < 10; i++) {
    somatorio += numeros[i];
  }
  printf("%d", somatorio);  
}

int main() {
  int num[10] = {1, 2, 3};

  soma(num);
}