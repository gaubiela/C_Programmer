#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

// variáveis globais
char palavrasecreta[20];
char chutes[26];
int chutes_dados = 0;

void abertura() {
  printf("/****************/\n");
  printf("/* Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void chuta() {
  char chute;
  scanf(" %c", &chute);

  chutes[chutes_dados] = chute;
  chutes_dados++;
}

void desenha_forca() {

  for (int i = 0; i < strlen(palavrasecreta); i++) {

    int achou = jachutou(palavrasecreta[i]);

    if (achou) {
      printf("%c ", palavrasecreta[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

int jachutou(char letra) {
  int achou = 0;
  for (int j = 0; j < chutes_dados; j++) {
    if (chutes[j] == letra) {
      achou = 1;
      break;
    }
  }
  return achou;
}

void adiciona_palavra() {
  char quer;

  printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
  scanf(" %c", &quer);

  if (quer == 'S') {
    char novapalavra[20];

    printf("Qual palavra? ");
    scanf("%s", novapalavra);

    FILE *f;

    f = fopen("palavras.txt", "r+");
    if (f == 0) {
      printf("Banco de dados de palavras não disponível\n\n");
      exit(1);
    }

    int qtd;
    fscanf(f, "%d", &qtd);
    qtd++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novapalavra);

    fclose(f);
  }
}

void escolhe_palavra() {

  FILE *f;

  f = fopen("palavras.txt", "r");
  if (f == 0) {
    printf("Banco de dados de palavras não disponível\n\n");
    exit(1);
  }

  int qtddepalavras;
  fscanf(f, "%d", &qtddepalavras);

  srand(time(0));
  int random = rand() % qtddepalavras;

  for (int i = 0; i <= random; i++) {
    fscanf(f, "%s", palavrasecreta);
  }

  fclose(f);
}

int ganhou() {

  for (int i = 0; i < strlen(palavrasecreta); i++) {
    if (!jachutou(palavrasecreta[i])) {
      return 0;
    }
  }
  return 1;
}

int enforcou() {
  int erros = 0;
  for (int i = 0; i < chutes_dados; i++) {
    int existe = 0;
    for (int j = 0; j < strlen(palavrasecreta); j++) {
      if (chutes[i] == palavrasecreta[j]) {
        existe = 1;
        break;
      }
    }
    if (!existe)
      erros++;
  }
  return erros >= 5;
}

int main() {

  abertura();
  escolhe_palavra();

  do {

    desenha_forca();
    chuta();

  } while (!ganhou() && !enforcou());

  adiciona_palavra();
}