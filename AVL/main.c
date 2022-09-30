// Trabalho final de estrutura de dados **contador de calorias**

// João Pedro Licks Corso - 00337569
// Júlia Mombach Silva - XXXXXXXX

/*Essa aplicação recebe um arquivo texto contendo os
alimentos ingeridos por um paciente e uma tabela de alimentos e suas calorias. A
tabela de calorias deverá ficar armazenada em uma árvore. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// insere biblioteca
#include "contador_calorias.h"

int main(void)
{
    // declarações
    // ponteiros arvore
    avl *arvore = NULL;
    avl *auxiliar = NULL;
    // dados
    dados info;
    char alimentosDia[50];
    int gramas;
    int ok;
    int caloriasConsumidas;
    int comparacoes = 0;
    int rotacao = 0;
    // arquivos
    FILE *arqCalorias;
    FILE *arqConsumo;
    FILE *arqSaida;

    // le arquivo para colocar na arvore
    arqCalorias = fopen("1000Shuffled.csv", "r");

    if (arqCalorias != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    while (fscanf(arqCalorias, "%[^;];%d/n", info.alimentos, &info.calorias) == 2)
    {
        arvore = insereArvore(arvore, info, &ok, &rotacao);
    }

    fclose(arqCalorias);

    // aquivo que le arquivo de consumo diario
    arqConsumo = fopen("day1.csv", "r");

    if (arqConsumo != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    // arquivo que escreve na saida
    arqSaida = fopen("calorias_consumidas.txt", "w");

    while (fscanf(arqConsumo, "%[^;];%d/n", alimentosDia, &gramas) == 2)
    {
        // printf("%s", alimentosDia);
        auxiliar = consultaAVL(arvore, alimentosDia, &comparacoes);
        printf("%d", auxiliar->dados.calorias);
        //  saida(arvore, info, auxiliar, gramas, arqSaida);
        //caloriasConsumidas = ((auxiliar->dados.calorias * gramas) / 100);
        //info.caloriasDiarias += caloriasConsumidas;

        // fprintf(arqSaida, "%dg de %s (%d calorias por 100g) = %d calorias\n", gramas, aalimentosDia, auxiliar->dados.calorias, caloriasConsumidas);
    }

        //fprintf(arqSaida, "\nTotal de %d calorias consumidas no dia.\n", info.caloriasDiarias);

    int quantos = qtd_nodos(arvore);

    // fprintf(arqSaida, "\nTotal de %d calorias consumidas no dia.\n", caloriasDiarias);

    fprintf(arqSaida, "\n\n======== ESTATISTICAS AVL ============\n");

    fprintf(arqSaida, "Numero de nodos: %d\n", quantos);

    fprintf(arqSaida, "Altura: %d\n", arvore->altura);

    fprintf(arqSaida, "Rotacoes: %d\n", rotacao);

    fprintf(arqSaida, "Comparacoes: %d\n", comparacoes);

    fclose(arqConsumo);
    fclose(arqSaida);

    return 0;
}
