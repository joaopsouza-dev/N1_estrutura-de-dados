#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dados.h"

Dados * juntar_dados(char *vetorArquivos[], bool primeiroArquivo) {

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
        

        FILE *saida;

        // usa o parâmetro para decidir o modo de abertura
        if (primeiroArquivo) {
            saida = fopen("dados_finais.csv", "w");
        } else {
            saida = fopen("dados_finais.csv", "a");
        }

        if (saida == NULL) {
            printf("Erro ao abrir o arquivo de saída.\n");
            fclose(fp);
            exit(1);
        }

        char linha[TAMANHO];

        // ignora o cabeçalho a partir do segundo arquivo
        if (!primeiroArquivo) {
            fgets(linha, sizeof(linha), fp);
        }

        // copia linha por linha
        while (fgets(linha, sizeof(linha), fp) != NULL) {
            fprintf(saida, "%s", linha);
        }

        fclose(fp);
        fclose(saida);

        // depois do primeiro, sempre será append
        primeiroArquivo = false;
    }
    
    return dados;
}




// função para ler o arquivo 'dados_finais.csv' e calcular as metas para cada tribunal, e salvar os resultados em um novo arquivo 'resumo_dados.csv'
Resumo *resumir_dados(char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");

    if (fp == NULL)
    {
        printf("Erro ao ler o arquivo.\n");
        exit(1);
    }

    char linha[TAMANHO];

    // pular cabeçalho
    fgets(linha, sizeof(linha), fp);

    FILE *saida = fopen("resumo_dados.csv", "w");

    if (saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    // ERRO 1: utilização do malloc, resultava no acumulo de lixo na memoria
    // CORREÇÃO 1: calloc no lugar de malloc
    // malloc apenas reserva memória, sem limpar — ela chega cheia de lixo.
    // calloc reserva E zera tudo, garantindo que todos os acumuladores
    // comecem em 0 antes de qualquer soma.
    Resumo *resumo = (Resumo *)calloc(60000, sizeof(Resumo));

    if (resumo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    int qtd = 0;


    // Declaração das variaveis locais, que será armazenado todos os valores necessarios para as operações
    char sigla_tribunal[TAMANHO];

    int casos_novos, julgados, suspensos, dessobrestados;
    int distm2_a, julgm2_a, suspm2_a;
    int distm2_ant, julgm2_ant, suspm2_ant, desom2_ant;
    int distm4_a, julgm4_a, suspm4_a;
    int distm4_b, julgm4_b, suspm4_b;

    while (fgets(linha, sizeof(linha), fp))
    {
        int indice = -1;

        // Solução 2: sscanf expandido para ler todos os 18 campos necessários.
        // O CSV tem campos string entre aspas duplas e campos int sem aspas.
        // %*[^,] ignora um campo inteiro (qualquer conteúdo até a próxima vírgula).
        // O padrão "\"%63[^\"]\"" lê um campo entre aspas duplas.
        //
        // Mapeamento das colunas (base 1):
        //  1  sigla_tribunal       <- lido
        //  2  procedimento         <- ignorado
        //  3  ramo_justica         <- ignorado
        //  4  sigla_grau           <- ignorado
        //  5  uf_oj                <- ignorado
        //  6  municipio_oj         <- ignorado
        //  7  id_ultimo_oj         <- ignorado (%*d, sem aspas)
        //  8  nome                 <- ignorado
        //  9  mesano_cnm1          <- ignorado
        // 10  mesano_sent          <- ignorado
        // 11  casos_novos_2026     <- lido
        // 12  julgados_2026        <- lido
        // 13  prim_sent2026        <- ignorado
        // 14  suspensos_2026       <- lido
        // 15  dessobrestados_2026  <- lido
        // 16  cumprimento_meta1    <- ignorado (string: "Inf", "NA"...)
        // 17  distm2_a             <- lido
        // 18  julgm2_a             <- lido
        // 19  suspm2_a             <- lido
        // 20  cumprimento_meta2a   <- ignorado (string com decimal)
        // 21  distm2_ant           <- lido
        // 22  julgm2_ant           <- lido
        // 23  suspm2_ant           <- lido
        // 24  desom2_ant           <- lido
        // 25  cumprimento_meta2ant <- ignorado
        // 26  distm4_a             <- lido
        // 27  julgm4_a             <- lido
        // 28  suspm4_a             <- lido
        // 29  cumprimento_meta4a   <- ignorado
        // 30  distm4_b             <- lido
        // 31  julgm4_b             <- lido
        // 32  suspm4_b             <- lido
        // 33  cumprimento_meta4b   <- ignorado
        if (sscanf(linha,
                   "\"%63[^\"]\",%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*d,"
                   "%*[^,],%*[^,],%*[^,],"
                   "%d,%d,%*d,%d,%d,%*[^,],"
                   "%d,%d,%d,%*[^,],"
                   "%d,%d,%d,%d,%*[^,],"
                   "%d,%d,%d,%*[^,],"
                   "%d,%d,%d",
                   sigla_tribunal,
                   &casos_novos, &julgados, &suspensos, &dessobrestados,
                   &distm2_a,   &julgm2_a,   &suspm2_a,
                   &distm2_ant, &julgm2_ant, &suspm2_ant, &desom2_ant,
                   &distm4_a,   &julgm4_a,   &suspm4_a,
                   &distm4_b,   &julgm4_b,   &suspm4_b) != 18)
        {
            continue; // pula linha inválida
        }

        // procurar tribunal já existente no vetor resumo
        for (int i = 0; i < qtd; i++)
        {
            if (strcmp(resumo[i].sigla_tribunal, sigla_tribunal) == 0)
            {
                indice = i;
                break;
            }
        }

        // tribunal novo: inicializa a entrada
        if (indice == -1)
        {
            strcpy(resumo[qtd].sigla_tribunal, sigla_tribunal);
            indice = qtd;
            qtd++;
        }

        // acumula os valores para Meta1
        resumo[indice].total_julgados       += julgados;
        resumo[indice].soma_julgados        += julgados;
        resumo[indice].soma_casos_novos     += casos_novos;
        resumo[indice].soma_dessobrestados  += dessobrestados;
        resumo[indice].soma_suspensos       += suspensos;

        // acumula os valores para Meta2A
        resumo[indice].soma_distm2_a   += distm2_a;
        resumo[indice].soma_julgm2_a   += julgm2_a;
        resumo[indice].soma_suspm2_a   += suspm2_a;

        // acumula os valores para Meta2Ant
        resumo[indice].soma_distm2_ant += distm2_ant;
        resumo[indice].soma_julgm2_ant += julgm2_ant;
        resumo[indice].soma_suspm2_ant += suspm2_ant;
        resumo[indice].soma_desom2_ant += desom2_ant;

        // acumula os valores para Meta4A
        resumo[indice].soma_distm4_a   += distm4_a;
        resumo[indice].soma_julgm4_a   += julgm4_a;
        resumo[indice].soma_suspm4_a   += suspm4_a;

        // acumula os valores para Meta4B
        resumo[indice].soma_distm4_b   += distm4_b;
        resumo[indice].soma_julgm4_b   += julgm4_b;
        resumo[indice].soma_suspm4_b   += suspm4_b;
    }

    // calcular as cinco metas para cada tribunal
    for (int i = 0; i < qtd; i++)
    {
        float den;

        // Meta1 = julgados / (casos_novos + dessobrestados + suspensos) * 100
        den = (float)(resumo[i].soma_casos_novos
                    + resumo[i].soma_dessobrestados
                    + resumo[i].soma_suspensos);
        resumo[i].meta1 = (den != 0.0) ?
            ((float)resumo[i].soma_julgados / den) * 100.0 : 0.0;

        // Meta2A = julgm2_a / (distm2_a + suspm2_a) * (1000/7)
        den = (float)(resumo[i].soma_distm2_a + resumo[i].soma_suspm2_a);
        resumo[i].meta2A = (den != 0.0) ?
            ((float)resumo[i].soma_julgm2_a / den) * (1000.0 / 7.0) : 0.0;

        // Meta2Ant = julgm2_ant / (distm2_ant + suspm2_ant + desom2_ant) * 100
        den = (float)(resumo[i].soma_distm2_ant
                    + resumo[i].soma_suspm2_ant
                    + resumo[i].soma_desom2_ant);
        resumo[i].meta2Ant = (den != 0.0) ?
            ((float)resumo[i].soma_julgm2_ant / den) * 100.0 : 0.0;

        // Meta4A = julgm4_a / (distm4_a + suspm4_a) * 100
        den = (float)(resumo[i].soma_distm4_a + resumo[i].soma_suspm4_a);
        resumo[i].meta4A = (den != 0.0) ?
            ((float)resumo[i].soma_julgm4_a / den) * 100.0 : 0.0;

        // Meta4B = julgm4_b / (distm4_b + suspm4_b) * 100
        den = (float)(resumo[i].soma_distm4_b + resumo[i].soma_suspm4_b);
        resumo[i].meta4B = (den != 0.0) ?
            ((float)resumo[i].soma_julgm4_b / den) * 100.0 : 0.0;
    }

    
    fprintf(saida, "sigla_tribunal,total_julgados_2026,Meta1,Meta2A,Meta2Ant,Meta4A,Meta4B\n");

    for (int i = 0; i < qtd; i++)
    {
        fprintf(saida, "%s,%lld,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                resumo[i].sigla_tribunal,
                resumo[i].total_julgados,
                resumo[i].meta1,
                resumo[i].meta2A,
                resumo[i].meta2Ant,
                resumo[i].meta4A,
                resumo[i].meta4B);
    }

    fclose(fp);
    fclose(saida);
    printf("\n\n=================================================\n");
    printf("Arquivo resumo_dados.csv foi criado com sucesso!\n");
    printf("=================================================\n\n");


    return resumo;
}



void buscarMunicipio() { // 3° função a ser implementada
    
    char municipio[100];

    FILE *fp = fopen("dados_finais.csv", "r"); // Abre o arquivo para leitura
    if(fp == NULL) {
        printf("Erro ao abrir o arquivo de dados finais.\n");
        exit(1);
    }

    printf("Digite o Municipio/Cidade que voce deseja buscar (letras maiusculas e sem acento): ");
    fgets(municipio, sizeof(municipio), stdin);

    // remover \n, porque se não quando formos comparar, o nome do município do CSV não vai bater com o nome digitado, já que o fgets inclui o \n no final da string
    municipio[strcspn(municipio, "\n")] = '\0';
    
    
    char nomeArquivo[200];
    strcpy(nomeArquivo, municipio);
    
    // substituir espaços por underlines, porque no CSV os municípios estão com underlines, então se o usuário digitar "São Paulo", a gente vai transformar em "São_Paulo" pra comparar com o CSV
    int a = 0;
    while (nomeArquivo[a] != '\0') {
        if (nomeArquivo[a] == ' ') {
            nomeArquivo[a] = '_';
        }
        a++;
    }

    // aqui eu pego o nome do município digitado e crio o nome do arquivo de saída, que vai ser o nome do município + .csv, para salvar os resultados da busca
    strcat(nomeArquivo, ".csv");

    FILE *saida = fopen(nomeArquivo, "w");
    if (saida == NULL) {
        printf("Erro ao criar arquivo de saída\n");
        fclose(fp);
        exit(1);
    }

    char linha[TAM_LINHA];

    // copiar o cabeçalho para o arquivo de saída
    if (fscanf(fp, "%[^\n]\n", linha) == 1) {
        fprintf(saida, "%s\n", linha);
    }

    // percorrer o arquivo linha por linha pra achar o município digitado
    while (fgets(linha, sizeof(linha), fp)) {

        char municipioCSV[100];

        int i = 0, j = 0;
        int aspas = 0;
        int dentroCampo = 0; // "interruptor" para indicar se estamos dentro do campo do município e parar de ler quando chegar na 12° aspas

        while (linha[i] != '\0') {

            // como quero pegar o município, que é o 6° campo, ele vai estar entre a 11° e a 12° aspas, então quando eu chegar na 11° aspas, eu começo a copiar os caracteres para o municipioCSV, e quando chegar na 12° aspas, eu paro de copiar
            if (linha[i] == '"') {
                aspas++;

                if (aspas == 11) {
                    dentroCampo = 1;
                    j = 0;
                    i++;
                    continue;
                }

                if (aspas == 12) {
                    municipioCSV[j] = '\0';
                    break;
                }
            }

            if (dentroCampo) {
                municipioCSV[j++] = linha[i];
            }

            i++;
        }

        // usando strcmp para comparar o município do CSV com o município digitado, se for igual, salva a linha no arquivo de saída
        if (strcmp(municipioCSV, municipio) == 0) {
            fprintf(saida, "%s", linha);
        }
    }

    fclose(fp);
    fclose(saida);

    printf("Arquivo %s foi criado\n", nomeArquivo);
}