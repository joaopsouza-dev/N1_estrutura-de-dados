#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"

int main() {

    char *vetorArquivos[] = {
        "teste_TRE-AC.csv","teste_TRE-AL.csv","teste_TRE-AP.csv",
        "teste_TRE-AM.csv","teste_TRE-BA.csv","teste_TRE-CE.csv",
        "teste_TRE-DF.csv","teste_TRE-ES.csv","teste_TRE-GO.csv",
        "teste_TRE-MA.csv","teste_TRE-MT.csv","teste_TRE-MS.csv",
        "teste_TRE-MG.csv","teste_TRE-PA.csv","teste_TRE-PB.csv",
        "teste_TRE-PR.csv","teste_TRE-PE.csv","teste_TRE-PI.csv",
        "teste_TRE-RJ.csv","teste_TRE-RN.csv","teste_TRE-RS.csv",
        "teste_TRE-RO.csv","teste_TRE-RR.csv","teste_TRE-SC.csv",
        "teste_TRE-SP.csv","teste_TRE-SE.csv","teste_TRE-TO.csv",
        NULL
    };

    int opcao;

    // 🔥 CONCATENAÇÃO OBRIGATÓRIA (sempre roda ao iniciar)
    printf("Concatenando arquivos...\n");
    juntar_dados(vetorArquivos, 1);
    printf("Arquivos concatenados com sucesso!\n");

    // MENU
    do {
        printf("\n=====================================\n");
        printf("              MENU\n");
        printf("=====================================\n");
        printf("1 - Gerar resumo\n");
        printf("2 - Buscar municipio\n");
        printf("0 - Sair\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch(opcao) {

            case 1:
                printf("\nGerando resumo...\n");
                resumir_dados("dados_finais.csv");
                break;

            case 2:
                printf("\nBuscar municipio...\n");
                buscarMunicipio();
                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}