#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

// imprime cabeçalho do jogo
printf("\n\n");
printf("      ,.     ,.                      \n");
printf("               /^ \\- -/ ^           \n");
printf("               "   " "   "           \n");
printf("              { <O> _ <O> }          \n");
printf("              ==_ .:Y:. _==          \n");
printf("              .""  `--^--' "".        \n");
printf("            (,~-~."" "" ,~-~.)       \n");
printf("      ------(     )----(     )-----  \n");
printf("            ^-'-'-^    ^-'-'-^       \n");
printf("	   Bem vindo ao jogo de      \n");
printf("	   adivinhacao do gato!      \n");
printf("      _____________________________  \n");
printf("            |"""" /~.^.~\\ """"|      \n");
printf("             ,i-i-i(""(  i-i-i.      \n");
printf("            (o o o ))"")( o o o)     \n");
printf("             \\(_) /(""(  \\ (_)/    \n");
printf("              `--'  \\""\\  `--'     \n");
printf("                     )"")            \n");
printf("                    (""/             \n");
printf("                    `                \n");
printf("\n\n");

  int randomtime = time(0);
  srand(randomtime);

  int randomnum = rand();

  int numerosecreto = randomnum % 100;
  int chute;
  int ganhou = 0;
  int tentativas = 1;
  double pontos = 1000;

  int acertou = 0;

  int nivel;
  printf("Que nivel deseja jogar?\n");
  printf("(1) Facil (2) Medio (3) Dificil\n\n");
  printf("Escolha: ");
  scanf("%d", &nivel);
  printf("\n\n");

  int numerodetentativas;

  switch (nivel) {
  case 1:
    numerodetentativas = 20;
    break;

  case 2:
    numerodetentativas = 15;
    break;

  default:
    numerodetentativas = 6;
    break;
  }

  //   if (nivel == 1) {
  //     numerodetentativas = 20;
  //   } else if (nivel == 2) {
  //     numerodetentativas = 15;
  //   } else {
  //     numerodetentativas = 6;
  //   }

  for (int i = 1; i <= numerodetentativas; i++) {
    printf("Tentativa %d\n", tentativas);
    printf("Qual e o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

    if (chute < 0) {
      printf("Voce nao pode chutar numeros negativos!\n");
      printf("\n");
      continue;
    }

    acertou = (chute == numerosecreto);

    if (acertou) {
      break;
    } else {

      if (chute > numerosecreto) {
        printf("\n");
        printf("Seu chute foi  maior que o numero secreto\n");
        printf("\n");
      }
      if (chute < numerosecreto) {
        printf("\n");
        printf("Seu chute foi menor que o numero secreto\n");
        printf("\n");
      }
    }

    tentativas++;
    double pontosPerdidos = abs(chute - numerosecreto) / (double)2;
    pontos = pontos - pontosPerdidos;
  }

  printf("Fim de jogo!\n");

  if (acertou) {
    printf("\n\n");
    printf("              VOCE GANHOU!                 \n");
    printf("                                           \n");
    printf("     .-o=o-.                               \n");
    printf("           ,  /=o=o=o=\\ .--.              \n");
    printf("         _|\\|=o=O=o=O=|    \\             \n");
    printf("      __.'  a`\\=o=o=o=(`\\   /            \n");
    printf("      '.   a 4/`|.-""'`\\ \\ ;'`)   .---.  \n");
    printf("        \\   .'  /   .--'  |_.'   / .-._)  \n");
    printf("         `)  _.'   /     /`-.__.' /        \n");
    printf("          `'-.____;     /'-.___.-'         \n");
    printf("                   `" "`                   \n");
    printf("                                           \n");
    printf("Voce acertou em %d tentativas\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
  } else {
    printf("\n\n");
    printf("     VOCE PERDEU!      \n");
    printf(" TENTE NOVAMENTE!      \n");    
    printf("       ___             \n");
    printf(",_    '---'    _,      \n");
    printf("\\ `-._|\\_/|_.-' /    \n");
    printf(" |   =)'T'(=   |       \n");
    printf("  \\   /``\\   /       \n");
    printf("   '._\\) (/_.'        \n");
    printf("       | |             \n");
    printf("      /\\ /\\          \n");
    printf("      \\ T /           \n");
    printf("      (/ \\)\\          \n");
    printf("           ))           \n");
    printf("          ((            \n");
    printf("          \\)           \n");
    printf("\n\n");
  }
}