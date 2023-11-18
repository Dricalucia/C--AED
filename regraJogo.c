#include <stdio.h>

void aguardarEnter() {
    printf("\n\nTecle Enter para continuar...\n");
    getchar();
    while (getchar() != '\n');
}

void regraJogo() {
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

        printf("Instruções do Jogo:Decifre o Código \n\n");
        printf("Bem-vindo ao emocionante desafio de inteligência 'Decifre o Código'! Este é um emocionante desafio projetado para exercitar sua mente e testar sua habilidade de decifrar códigos secretos.\n");
  printf("No DECIFRE O CODIGO, seu objetivo é decifrar um código gerado aleatoriamente pelo computador. \n");
        printf("\nAqui estão as regras:\n\n");

        printf("Geração do Código:\n");
        printf("- Um código será gerado aleatoriamente, consistindo em uma sequência de dígitos numéricos.\n");
        printf("- O comprimento do código dependerá do nível escolhido: Fácil (4 dígitos), Médio (5 dígitos), Difícil (6 dígitos).\n\n");

        printf("Tentativas:\n");
        printf("- Você terá várias tentativas para decifrar o código secreto.\n");
        printf("- A cada tentativa, você deverá inserir uma sequência de dígitos correspondente ao código.\n\n");

        printf("Respostas:\n");
        printf("- Após cada tentativa, receberá uma resposta indicando o quão próximo está de decifrar o código.\n");
        printf("  'O' significa que um dígito está correto e na posição correta.\n");
        printf("  'Q' significa que um dígito está correto, mas na posição errada.\n");
        printf("  'N' significa que um dígito está incorreto.\n\n");

        printf("Fim do Jogo:\n");
        printf("- O jogo termina quando você decifra completamente o código, obtendo todos os 'O's na resposta.\n");
        printf("- Será exibido o número de tentativas realizadas e seu score baseado no nível escolhido.\n\n");

        printf("Pontuação:\n");
        printf("- Seu score é calculado com base no número de tentativas e no nível escolhido.\n");
        printf("- Quanto menos tentativas, maior será o seu score.\n\n");

        printf("Salvando o Score:\n");
        printf("- Seu score será salvo automaticamente num ranking de acordo com o nível escolhido.\n");
        printf("\nDesafie a si mesmo e veja se consegue superar os melhores jogadores!\n\n");

        printf("Boa sorte, e que a sua esperteza vença o código secreto!\n");

      aguardarEnter(); // Aguarda o usuário teclar Enter
    }