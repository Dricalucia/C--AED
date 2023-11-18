#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "salvar_ranking.h"

typedef struct Node { 
    int digito;
    struct Node *next;
} Node;

typedef struct RespostaNode {
    char resposta; // 'O' para OK, 'Q' para Quase, 'N' para NOK
    struct RespostaNode *next;
} RespostaNode;

void liberarListaEncadeada(Node *lista) {
    while (lista != NULL) {
        Node *temp = lista;
          lista = lista->next;
        free(temp);
    }
}

void gerarCodigo(Node **codigo, int tamCodigo) {
    srand(time(NULL));

    /* Se a lista estiver vazia, insira o primeiro nó */
    if (*codigo == NULL) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->digito = rand() % 10;
        newNode->next = NULL;
        *codigo = newNode;
        //printf("%d", newNode->digito);
    }

    /* Encontrar o último nó na lista */
    Node *ultimo = *codigo;
    while (ultimo->next != NULL) {
        ultimo = ultimo->next;
    }

    /* Adicionar novos nós ao final da lista */
    for (int i = 1; i < tamCodigo; i++) {
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->digito = rand() % 10;
        newNode->next = NULL;
        ultimo->next = newNode;
        ultimo = newNode;
        //printf("%d", newNode->digito);
    }

    printf("\n");
}

/* imprimir resposta a cada tentativa */
void imprimirRespostas(RespostaNode *respostas) {
    while (respostas != NULL) {
        printf("%c ", respostas->resposta);
        respostas = respostas->next;    
    }
    printf("\n");
}

/* Limpar lista encadeada resposta */
void liberarRespostas(RespostaNode **respostas) {
    while (*respostas != NULL) {
        RespostaNode *temp = *respostas;
        *respostas = (*respostas)->next;
        free(temp); 
    }
}

int checkCodigo(Node *codigo, int decifraCodigo[], RespostaNode **respostas, int tamCodigo) {
    int todasCorretas = 1;
    int marcado[10] = {0};
    printf("Validação resposta: ");

    for (int i = 0; i < tamCodigo; i++) {
        RespostaNode *newResposta = (RespostaNode*) malloc(sizeof(RespostaNode));
        newResposta->next = NULL;

        Node *tempCodigo = codigo;
        int posicaoCodigo = 0;
        int encontrou = 0;
        

        while (tempCodigo != NULL) {
          //printf("i = %d | posicao = %d | codigo = %d | decifra = %d \n", i, posicaoCodigo,tempCodigo->digito, decifraCodigo[i]);
            if (decifraCodigo[i] == tempCodigo->digito) {
                if (posicaoCodigo == i) {
                    //if (newResposta->resposta != 'O') {
                        newResposta->resposta = 'O';
                        encontrou = 1;
                        marcado[decifraCodigo[i]] = 1;
                        break;
                    //}
                } else {
                  if (marcado[decifraCodigo[i]] == 0) {
                      //if (newResposta->resposta != 'O') {
                        newResposta->resposta = 'Q';
                        encontrou = 1;
                        todasCorretas = 0;
                        marcado[decifraCodigo[i]] = 1;
                        break;
                      //}
                  } else if (posicaoCodigo == i && decifraCodigo[i] == tempCodigo->digito) {
                      newResposta->resposta = 'O';
                      encontrou = 1;
                      break;
                    } else { 
                    newResposta->resposta = 'Q';
                    todasCorretas = 0;
                    encontrou = 1;
                    //marcado[decifraCodigo[i]] = 1;
                    //break;
                  } 
                }
            }
            tempCodigo = tempCodigo->next;
            posicaoCodigo++;
        } 
  
        if (!encontrou) {  
            newResposta->resposta = 'N';
        }


        if (*respostas == NULL){
            *respostas = newResposta;
        } else {
            RespostaNode *tempResposta = *respostas;
            while (tempResposta->next != NULL) {
                tempResposta = tempResposta->next;
            }
            tempResposta->next = newResposta;
        }  
    }
  imprimirRespostas(*respostas);
  
  todasCorretas = 1;
  
  RespostaNode *tempResposta = *respostas;
    while (tempResposta != NULL){
      if (tempResposta->resposta != 'O'){
        todasCorretas = 0;
      }
      tempResposta = tempResposta->next;
    }
    
    liberarRespostas(respostas);
    if (todasCorretas) {
        
        return 1; 
    } else {
        return 0;
    }
}


int mainJogo() {
    int tentativa = 0;
    char nomeJogador[20];
    int nivelJogo = 0, tamCodigo = 0;
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

    printf("Bem-vindo ao jogo: Decifre o código!\n\n");
    printf("Digite o seu nome: ");
    scanf("%s", nomeJogador);
    printf("\nEscolha o nível do jogo: 1-Facil, 2-Médio, 3-Dificil: ");
    scanf("%d", &nivelJogo);

    switch (nivelJogo) {
        case 1:
            tamCodigo = 4;
            break;
        case 2:
              tamCodigo = 5;
            break;
        case 3:
              tamCodigo = 6;
            break;
        default:
            printf("Nível inválido. O jogo será configurado como fácil (4 dígitos).\n");
              tamCodigo = 4;
    }

    int *decifraCodigo = (int*) malloc (tamCodigo * sizeof(int));
    if (decifraCodigo == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    Node *codigo = NULL;
    gerarCodigo(&codigo, tamCodigo);

    RespostaNode *respostas = NULL;

  while (1) {
          tentativa++;
          printf("Tentativa %d - Digite uma senha de %d dígitos: ", tentativa, tamCodigo);
          for (int i = 0; i < tamCodigo; i++) {
              scanf("%1d", &decifraCodigo[i]);
          }


    if (checkCodigo(codigo, decifraCodigo, &respostas, tamCodigo) == 1) {
        printf("Parabéns, %s!!! \nVocê decifrou o código com %d tentativas.\n", nomeJogador, tentativa);      
        int score = (nivelJogo * 100) / tentativa;
        printf("\nO seu score foi de %d pontos\n", score);
        sleep(3);

        /* Salvar resultado no arquivo */
        char nomeArquivo[20];
        switch (nivelJogo) {
        case 1:
            strcpy(nomeArquivo, "facil.txt");
            break;
        case 2:
            strcpy(nomeArquivo, "medio.txt");
            break;
        case 3:
            strcpy(nomeArquivo, "dificil.txt");
            break;
        default:
            printf("Erro ao determinar o nome do arquivo.\n");
            break;
        }

        FILE *file = fopen(nomeArquivo, "a");
      if (file != NULL) {
          fprintf(file, "%s - %d\n", nomeJogador, score);
          fclose(file);
          file = fopen(nomeArquivo, "r+"); 
          if (file != NULL) {
              ordenarArquivo(file);
              fclose(file);
          } 
          else {
              printf("Erro ao reabrir o arquivo para ordenação.\n");
          }
      } 
      else {
          printf("Erro ao salvar o resultado.\n");
      }
        break;
    }
      }
      liberarListaEncadeada(codigo);
      liberarListaEncadeada(respostas);
      free(decifraCodigo);
      return 0;
  }