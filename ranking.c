#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ranking(char *nomeArquivo, int nivel) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    char nome[50];
    int score;
    char nivelJogo[10];
  
  system("clear"); // limpa a tela
  printf("      ██████╗ ███████╗ ██████╗██╗███████╗██████╗ ███████╗   ██████╗ \n");
  printf("      ██╔══██╗██╔════╝██╔════╝██║██╔════╝██║  ██╗██╔════╝  ██╔═══██╗\n");
  printf("      ██║  ██║█████╗  ██║     ██║███████╗███████║█████╗    ██║   ██║\n");
  printf("      ██║  ██║██╔══╝  ██║     ██║██╔════╝██╔═██╔╝██╔══╝    ██║   ██║\n");
  printf("      ██████╔╝███████╗╚██████╗██║██║     ██║ ╚██║███████╗  ╚██████╔╝\n");
  printf("      ╚═════╝ ╚══════╝ ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═════╝ \n\n");
  printf("       ██████╗ ██████╗ ██████╗ ██╗ ███████╗ ██████╗ \n");
  printf("      ██╔════╝██╔═══██╗██╔══██╗██║██╔═════╝██╔═══██╗\n");
  printf("      ██║     ██║   ██║██║  ██║██║██║  ███╗██║   ██║\n");
  printf("      ██║     ██║   ██║██║  ██║██║██║   ██║██║   ██║\n");
  printf("      ╚██████╗╚██████╔╝██████╔╝██║╚██████╔╝╚██████╔╝\n");
  printf("      ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═════╝  ╚═════╝ \n\n\n");

    if (nivel == 3){
      strcpy(nivelJogo, "Dificil");
    } else if (nivel == 2){
      strcpy(nivelJogo, "Médio");
     } else 
      strcpy(nivelJogo, "Fácil");
      
    printf("********* Ranking - Nível %s *********\n\n", nivelJogo);
    //char linha[100];
    printf("\tUsuário\t\t\t|\tScore\n");
    printf("\t===================================\n");  // Linha de separação
    while(fscanf(arquivo, "%49[^-] - %d\n", nome, &score) == 2){
    //while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("\t%-15s\t|\t%d\n", nome, score);
    }

    fclose(arquivo);

}

int mainRanking() {
  system("clear"); // limpa a tela
  printf("      ██████╗ ███████╗ ██████╗██╗███████╗██████╗ ███████╗   ██████╗ \n");
  printf("      ██╔══██╗██╔════╝██╔════╝██║██╔════╝██║  ██╗██╔════╝  ██╔═══██╗\n");
  printf("      ██║  ██║█████╗  ██║     ██║███████╗███████║█████╗    ██║   ██║\n");
  printf("      ██║  ██║██╔══╝  ██║     ██║██╔════╝██╔═██╔╝██╔══╝    ██║   ██║\n");
  printf("      ██████╔╝███████╗╚██████╗██║██║     ██║ ╚██║███████╗  ╚██████╔╝\n");
  printf("      ╚═════╝ ╚══════╝ ╚═════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═════╝ \n\n");
  printf("       ██████╗ ██████╗ ██████╗ ██╗ ███████╗ ██████╗ \n");
  printf("      ██╔════╝██╔═══██╗██╔══██╗██║██╔═════╝██╔═══██╗\n");
  printf("      ██║     ██║   ██║██║  ██║██║██║  ███╗██║   ██║\n");
  printf("      ██║     ██║   ██║██║  ██║██║██║   ██║██║   ██║\n");
  printf("      ╚██████╗╚██████╔╝██████╔╝██║╚██████╔╝╚██████╔╝\n");
  printf("      ╚══════╝ ╚═════╝ ╚═════╝ ╚═╝ ╚═════╝  ╚═════╝ \n\n\n");


    int nivelJogo;

    printf("\nEscolha o nível do jogo: 1-Fácil, 2-Médio, 3-Difícil: ");
    scanf("%d", &nivelJogo);

    switch (nivelJogo) {
    case 1:
        ranking("facil.txt", nivelJogo);
        break;
    case 2:
        ranking("medio.txt", nivelJogo);
        break;
    case 3:
        ranking("dificil.txt", nivelJogo);
        break;
    default:
        printf("Nível inválido. O jogo será configurado como fácil (4 dígitos).\n");
        ranking("facil.txt", nivelJogo);
    }

    /*
      printf("\nVoltar?\n1-Sim ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        return 0;
    } */
    aguardarEnter(); // Aguarda o usuário teclar Enter
   // return 0;
}
