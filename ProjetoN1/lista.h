#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#define TAMANHO 500

/*
"sigla_tribunal","procedimento","ramo_justica","sigla_grau","uf_oj","municipio_oj", ================ CHAR

"id_ultimo_oj", =========== INT 

"nome","mesano_cnm1","mesano_sent", ============= CHAR

"casos_novos_2026","julgados_2026","prim_sent2026","suspensos_2026","dessobrestados_2026","cumprimento_meta1","distm2_a","julgm2_a","suspm2_a","cumprimento_meta2a","distm2_ant","julgm2_ant","suspm2_ant","desom2_ant","cumprimento_meta2ant","distm4_a","julgm4_a","suspm4_a","cumprimento_meta4a","distm4_b","julgm4_b","suspm4_b","cumprimento_meta4b" ================= INT
*/

typedef struct {

    char sigla_tribunal[TAMANHO];
    char procedimento[TAMANHO];
    char ramo_justica[TAMANHO];
    char sigla_grau[TAMANHO];
    char uf_oj[TAMANHO];
    char municipio_oj[TAMANHO];

    int id_ultimo_oj;

    char nome[TAMANHO];
    char mesano_cnm1[TAMANHO];
    char mesano_sent[TAMANHO];

    int casos_novos_2026;
    int julgados_2026;
    int prim_sent2026;
    int suspensos_2026;
    int dessobrestados_2026;
    char cumprimento_meta1[TAMANHO];
    int distm2_a;
    int julgm2_a;
    int suspm2_a;
    char cumprimento_meta2a[TAMANHO];
    int distm2_ant;
    int julgm2_ant;
    int suspm2_ant;
    int desom2_ant;
    char cumprimento_meta2ant[TAMANHO];
    int distm4_a;
    int julgm4_a;
    int suspm4_a;
    char cumprimento_meta4a[TAMANHO];
    int distm4_b;
    int julgm4_b;
    int suspm4_b;
    char cumprimento_meta4b[TAMANHO];

} Dados;

Dados * juntar_dados(char *vetorArquivos[], bool primeiroArquivo);

#endif