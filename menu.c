#include <stdio.h>
#include <stdlib.h>
#include "MyLibs.h"


int mainMenu(){
  int option = 10;

  while (option != 0) {
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
   


      printf("Digite a opção desejada: \n\n1 - JOGAR \n2 - INSTRUÇÃO DO JOGO \n3 - CLASSIFICAÇÃO \n0 - SAIR JOGO\n");
      printf("\n");
      scanf("%d", &option);

      switch (option) {
          case 1: 
              mainJogo();
              break;
          case 2: 
              regraJogo();
              break;
          case 3: 
              mainRanking();
              break;
          case 0: 
              printf("Obrigada por jogar!");
              system("clear"); // limpar a tela
              return 0;
          default:
              printf("Opção Inválida. Digite novamente: ");
              scanf("%d", &option); 
              getchar();
              break;
      }
  }
  return 0;

}