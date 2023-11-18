#include "salvar_ranking.h"

void ordenarArquivo(FILE *file) {
    fseek(file, 0, SEEK_SET);

    int numLinhas = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            numLinhas++;
        }
    }

    fseek(file, 0, SEEK_SET);  

    char **dados = malloc(numLinhas * sizeof(char *));
    for (int i = 0; i < numLinhas; i++) {
        dados[i] = malloc(50 * sizeof(char));
        fgets(dados[i], 50, file);
    }

    for (int i = 0; i < numLinhas - 1; i++) {
        int maxIndex = i;
      for (int j = i + 1; j < numLinhas; j++) {
          int score1, score2;
          sscanf(dados[maxIndex], "%*s - %d", &score1);
          sscanf(dados[j], "%*s - %d", &score2);

          if (score2 > score1) {  
              maxIndex = j;
          }
      }

      if (maxIndex != i) {
          char *temp = dados[i];
          dados[i] = dados[maxIndex];
          dados[maxIndex] = temp;
      }
    }

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < numLinhas; i++) {
        fputs(dados[i], file);
    }

    for (int i = 0; i < numLinhas; i++) {
        free(dados[i]);
    }
    free(dados);
}
