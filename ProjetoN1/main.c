#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"


int main() {

    //Criar o vetor de arquivos para não precisar chamar a função para ler 1 por 1, e facilitar a leitura dos arquivos
    char *vetorArquivos[] = {
    "teste_TRE-AC.csv",
    "teste_TRE-AL.csv",
    "teste_TRE-AP.csv",
    "teste_TRE-AM.csv",
    "teste_TRE-BA.csv",
    "teste_TRE-CE.csv",
    "teste_TRE-DF.csv",
    "teste_TRE-ES.csv",
    "teste_TRE-GO.csv",
    "teste_TRE-MA.csv",
    "teste_TRE-MT.csv",
    "teste_TRE-MS.csv",
    "teste_TRE-MG.csv",
    "teste_TRE-PA.csv",
    "teste_TRE-PB.csv",
    "teste_TRE-PR.csv",
    "teste_TRE-PE.csv",
    "teste_TRE-PI.csv",
    "teste_TRE-RJ.csv",
    "teste_TRE-RN.csv",
    "teste_TRE-RS.csv",
    "teste_TRE-RO.csv",
    "teste_TRE-RR.csv",
    "teste_TRE-SC.csv",
    "teste_TRE-SP.csv",
    "teste_TRE-SE.csv",
    "teste_TRE-TO.csv",
    NULL
    };

    system("cls");


    Dados *dados = juntar_dados(vetorArquivos, 1);
    Resumo *resumo = resumir_dados("dados_finais.csv");
    buscarMunicipio();


    return 0;
}