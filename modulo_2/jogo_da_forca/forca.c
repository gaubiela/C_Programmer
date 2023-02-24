#include "forca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_dados = 0;

void abertura() {
  printf("/****************/\n");
  printf("/ Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void desenha_forca() {

  int erros = chutes_errados();

  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
         (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
         (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
  printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
         (erros >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");

  for (int i = 0; i < strlen(palavrasecreta); i++) {

    if (ja_chutou(palavrasecreta[i])) {
      printf("%c ", palavrasecreta[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

void chuta() {
  char chute;
  printf("Fale uma letra: ");
  scanf(" %c", &chute);

  if (letra_existe(chute)) {
    printf("Voce acertou: a palavra tem a letra %c\n\n", chute);
  } else {
    printf("\nVoce errou: a palavra NAO tem a letra %c\n\n", chute);
  }

  chutes[chutes_dados] = chute;
  chutes_dados++;
}

int enforcou() { return chutes_errados() >= 5; }



void escolhepalavra() {
  FILE *f;

  f = fopen("palavras.txt", "r");
  if (f == 0) {
    printf("Banco de dados de palavras nao disponível\n\n");
    exit(1);
  }

  int qtddepalavras;
  fscanf(f, "%d", &qtddepalavras);

  srand(time(0));
  int randomico = rand() % qtddepalavras;

  for (int i = 0; i <= randomico; i++) {
    fscanf(f, "%s", palavrasecreta);
  }

  fclose(f);
}

void adiciona_palavra() {
  char quer;

  printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
  scanf(" %c", &quer);

  if (quer == 'S') {
    char novapalavra[TAMANHO_PALAVRA];

    printf("Digite a nova palavra, em letras maiúsculas: ");
    scanf("%s", novapalavra);

    FILE *f;

    f = fopen("palavras.txt", "r+");
    if (f == 0) {
      printf("Banco de dados de palavras nAo disponível\n\n");
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

int letra_existe(char letra) {

  for (int j = 0; j < strlen(palavrasecreta); j++) {
    if (letra == palavrasecreta[j]) {
      return 1;
    }
  }

  return 0;
}

int chutes_errados() {
  int erros = 0;

  for (int i = 0; i < chutes_dados; i++) {

    if (!letra_existe(chutes[i])) {
      erros++;
    }
  }

  return erros;
}

int ganhou() {
  for (int i = 0; i < strlen(palavrasecreta); i++) {
    if (!ja_chutou(palavrasecreta[i])) {
      return 0;
    }
  }

  return 1;
}

int ja_chutou(char letra) {
  int achou = 0;
  for (int j = 0; j < chutes_dados; j++) {
    if (chutes[j] == letra) {
      achou = 1;
      break;
    }
  }

  return achou;
}

int main() {

  abertura();
  escolhepalavra();

  do {

    desenha_forca();
    chuta();

  } while (!ganhou() && !enforcou());

  if (ganhou()) {
    printf("        :"
           ";                    \n");
    printf("        |:`.`.__..__.'.';|                    \n");
    printf("        || :-"
           "-; ||                    \n");
    printf("        :;              :;                    \n");
    printf("        /  .==.    .==.  \\                   \n");
    printf("        :      _.--._      ;                  \n");
    printf("        ; .--.' `--' `.--. :                  \n");
    printf("      :   __;`      ':__    ;                 \n");
    printf("      ;  '  '-._:;_.-'  '   :                 \n");
    printf("      '.       `--'       .'                  \n");
    printf("        ."
           ".                  \n");
    printf("      .'     "
           "------"
           "     `.                \n");
    printf("    /`-                    -'\\               \n");
    printf("    /`-                      -'\\             \n");
    printf("  :`-   .'              `.   -';              \n");
    printf("  ;    /                  \\    :             \n");
    printf("  :    :    VOCE GANHOU!    ;    ;            \n");
    printf("  ;    ;                    :    :            \n");
    printf("  ':_:.'                    '.;_;'            \n");
    printf("    :_                      _;                \n");
    printf("    ; "
           " :`-.     _.._    \n");
    printf("    :_          ()          _;    --::__. `.  \n");
    printf("      \"-                  - /`._           : \n");
    printf("    .-"
           "-.  "
           "--..____.'  \n");
    printf("    /         .__  __.         \\             \n");
    printf("   : / ,       / "
           " \\       . \\ ;           \n");
    printf("    "
           "      "
           "              \n");

  } else {
    printf("          (___)           \n");
    printf("   ____                   \n");
    printf(" _\\___ \\  |\\_/|        \n");
    printf("\\     \\ \\/ x x \\ ___  \n");
    printf(" \\__   \\ \\ =^= //|||\\ \n");
    printf("  |===  \\/____)_)||||    \n");
    printf("  \\______|    | |||||    \n");
    printf("      _/_|  | | =====     \n");
    printf("     (_/  \\_)_)          \n");
    printf("  _________________       \n");
    printf(" (    VOCE FOI    _)      \n");
    printf("  (__ ENFORCADO!  )       \n");
    printf("    (___    _____)        \n");
    printf("        '--'              \n\n");
    printf("A palavra era **%s**\n\n", palavrasecreta);
  }
  adiciona_palavra();
}
