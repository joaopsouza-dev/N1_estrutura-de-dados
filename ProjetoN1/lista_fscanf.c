// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

// #include "lista.h"



// Dados * juntar_dados(char *vetorArquivos[], bool primeiroArquivo) {

//     FILE *saida;
    
//     if(primeiroArquivo) {
//         saida = fopen("dados_finais.csv", "w");
//     } else {
//         saida = fopen("dados_finais.csv", "a");
//     }
    
//     if (saida == NULL) {
//         printf("Erro ao abrir o arquivo de saída.\n");
//         exit(1);
//     }
    
//     Dados *dados = (Dados *)malloc(sizeof(Dados) * 60000); // Aloca memória para 60.000 registros
//     if (dados == NULL) {
//         printf("Erro ao alocar memória para os dados.\n");
//         exit(1);
//     }

//     int j = 0; // Índice para o array de dados

//     for(int i = 0; vetorArquivos[i] != NULL; i++) {
        

//         ///////////////////////////////////////////////////////// ABRINDO O ARQUIVO PARA LEITURA

//         FILE *fp = fopen(vetorArquivos[i], "r");
//         if (fp == NULL) {
//             printf("Erro ao abrir o arquivo.\n");
//             exit(1);
//         }
//         printf("Arquivo %s aberto com sucesso.\n", vetorArquivos[i]);
        
//         if (i > 0) {
//             char buffer[TAMANHO];
//             fgets(buffer, sizeof(buffer), fp);
//         }
        
//         //////////////////////////////////////////////////////// ALOCANDO MEMÓRIA PARA OS DADOS
        
        
//         while (fscanf(fp, "\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",%d,"
//                             "\"%[^\"]\",\"%[^\"]\",\"%[^\"]\","
//                             "%d,%d,%d,%d,%d,"
//                             "%[^,],"
//                             "%d,%d,%d,"
//                             "%[^,],"
//                             "%d,%d,%d,%d,"
//                             "%[^,],"
//                             "%d,%d,%d,"
//                             "%[^,],"
//                             "%d,%d,%d,"
//                             "%[^,]\n",
            
//             dados[j].sigla_tribunal,
//             dados[j].procedimento,
//             dados[j].ramo_justica,
//             dados[j].sigla_grau,
//             dados[j].uf_oj,
//             dados[j].municipio_oj,

//             &dados[j].id_ultimo_oj,

//             dados[j].nome,
//             dados[j].mesano_cnm1,
//             dados[j].mesano_sent,

//             &dados[j].casos_novos_2026,
//             &dados[j].julgados_2026,
//             &dados[j].prim_sent2026,
//             &dados[j].suspensos_2026,
//             &dados[j].dessobrestados_2026,

//             dados[j].cumprimento_meta1,

//             &dados[j].distm2_a,
//             &dados[j].julgm2_a,
//             &dados[j].suspm2_a,

//             dados[j].cumprimento_meta2a,

//             &dados[j].distm2_ant,
//             &dados[j].julgm2_ant,
//             &dados[j].suspm2_ant,
//             &dados[j].desom2_ant,

//             dados[j].cumprimento_meta2ant,

//             &dados[j].distm4_a,
//             &dados[j].julgm4_a,
//             &dados[j].suspm4_a,

//             dados[j].cumprimento_meta4a,

//             &dados[j].distm4_b,
//             &dados[j].julgm4_b,
//             &dados[j].suspm4_b,

//             dados[j].cumprimento_meta4b

//             ) == 33) { 

//                 fprintf(saida,
//                     "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%d,"
//                     "\"%s\",\"%s\",\"%s\","
//                     "%d,%d,%d,%d,%d,"
//                     "%s,"
//                     "%d,%d,%d,"
//                     "%s,"
//                     "%d,%d,%d,%d,"
//                     "%s,"
//                     "%d,%d,%d,"
//                     "%s,"
//                     "%d,%d,%d,"
//                     "%s\n",

//                     dados[j].sigla_tribunal,
//                     dados[j].procedimento,
//                     dados[j].ramo_justica,
//                     dados[j].sigla_grau,
//                     dados[j].uf_oj,
//                     dados[j].municipio_oj,

//                     dados[j].id_ultimo_oj,

//                     dados[j].nome,
//                     dados[j].mesano_cnm1,
//                     dados[j].mesano_sent,

//                     dados[j].casos_novos_2026,
//                     dados[j].julgados_2026,
//                     dados[j].prim_sent2026,
//                     dados[j].suspensos_2026,
//                     dados[j].dessobrestados_2026,

//                     dados[j].cumprimento_meta1,

//                     dados[j].distm2_a,
//                     dados[j].julgm2_a,
//                     dados[j].suspm2_a,

//                     dados[j].cumprimento_meta2a,

//                     dados[j].distm2_ant,
//                     dados[j].julgm2_ant,
//                     dados[j].suspm2_ant,
//                     dados[j].desom2_ant,

//                     dados[j].cumprimento_meta2ant,

//                     dados[j].distm4_a,
//                     dados[j].julgm4_a,
//                     dados[j].suspm4_a,

//                     dados[j].cumprimento_meta4a,

//                     dados[j].distm4_b,
//                     dados[j].julgm4_b,
//                     dados[j].suspm4_b,

//                     dados[j].cumprimento_meta4b
//                 );
//                 j++; // Incrementa o índice para o próximo registro

//             }

//             fclose(fp);
//     }
    
//     fclose(saida);
//     return dados;
    
// } 

    
