#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lista.h"

Dados * juntar_dados(char *vetorArquivos[], bool primeiroArquivo) {

    FILE *saida = fopen("dados_finais.csv", "w"); // sempre começa do zero
    
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }
    
    Dados *dados = (Dados *)malloc(sizeof(Dados) * 60000); 
    if (dados == NULL) {
        printf("Erro ao alocar memória para os dados.\n");
        exit(1);
    }

    int j = 0;

    for(int i = 0; vetorArquivos[i] != NULL; i++) {

        FILE *fp = fopen(vetorArquivos[i], "r");
        if (fp == NULL) {
            printf("Erro ao abrir o arquivo: %s\n", vetorArquivos[i]);
            exit(1);
        }

        printf("Arquivo %s aberto com sucesso.\n", vetorArquivos[i]);

        char linha[TAMANHO];

        // ignora o cabeçalho a partir do segundo arquivo
        if (i > 0) {
            fgets(linha, sizeof(linha), fp);
        }

        // copia linha por linha
        while (fgets(linha, sizeof(linha), fp) != NULL) {
            fprintf(saida, "%s", linha);
        }

        fclose(fp);
    }
    
    fclose(saida);
    return dados;
}