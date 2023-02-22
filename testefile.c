#include <stdio.h>

int main() {

  FILE *leitura;

  leitura = fopen("teste.txt", "r");
  if (leitura == 0) {
    printf("Banco de dados de palavras não disponível\n\n");
    exit(1);
  }

  printf("%s", leitura);
}