#include <stdio.h>

int main() {

  int **matriz;

  int linhas = 5;
  int colunas = 10;

  // alocando espaço para as linhas,
  // que guardam ponteiro de inteiro.
  matriz = malloc(sizeof(int *) * linhas);

  // agora, para cada linha, alocamos
  // espaço para um array com 10 ("colunas") posições.
  for (int i = 0; i < linhas; i++) {
    matriz[i] = malloc(sizeof(int) * colunas);
  }

  // agora podemos usar 'matriz' como uma matriz
  matriz[2][3] = 10;
}