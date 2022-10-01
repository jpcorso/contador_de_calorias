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
#include "biblioteca.h"

int main(int argc, char *argv[])
{
    // declarações
    // ponteiros arvore
    avl *arvore = NULL;
    abp *arvoreABP = NULL;
    avl *auxiliar = NULL;
    abp *auxiliar1 = NULL;
    // dados
    str_alimento comida;
    dados info;
    char alimentosDia[50];
    int gramas;
    int ok;
    int caloriasConsumidas;
    int caloriasDiarias;
    char alimento_dia[50];
    int gramas_dia;
    int comparacoes = 0;
    int rotacao = 0;
    int comp = 0;
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

    while (fscanf(arqCalorias, "%[^;];%d\n", info.alimentos, &info.calorias) == 2)
    {
        arvore = insereArvoreAVL(arvore, info, &ok, &rotacao);
    }

    while (fscanf(arqCalorias, "%[^;];%d\n", comida.alimentos, &comida.calorias) == 2)
    {
        arvoreABP = insereArvoreABP(arvoreABP, comida);
    }

    int quantosAVL = qtd_nodosAVL(arvore);
    int quantosABP = qtd_nodosABP(arvoreABP);
    int altura_ABP = alturaABP(arvoreABP);

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

    while (fscanf(arqConsumo, "%[^;];%d\n", alimentosDia, &gramas) == 2)
    {
        auxiliar = consultaAVL(arvore, alimentosDia, &comparacoes);
        caloriasConsumidas = ((auxiliar->dados.calorias * gramas) / 100);
        caloriasDiarias += caloriasConsumidas;

        fprintf(arqSaida, "%dg de %s (%d calorias por 100g) = %d calorias\n", gramas, alimentosDia, auxiliar->dados.calorias, caloriasConsumidas);
    }

    while (fscanf(arqConsumo, "%[^;];%d\n", alimento_dia, &gramas_dia) == 2)
    {
        auxiliar1 = consultaABP(arvoreABP, alimentosDia, &comp);
    }

    fprintf(arqSaida, "\nTotal de %d calorias consumidas no dia.\n", caloriasDiarias);

    // fprintf(arqSaida, "\nTotal de %d calorias consumidas no dia.\n", caloriasDiarias);

    //****************************************************//
    //--------------------ESTATISTICAS--------------------//
    //****************************************************//

    fprintf(arqSaida, "\n\n======== ESTATISTICAS ABP ============\n");

    fprintf(arqSaida, "Numero de nodos: %d\n", quantosABP);

    fprintf(arqSaida, "Altura: %d\n", altura_ABP);

    fprintf(arqSaida, "Rotacoes: 0\n");

    fprintf(arqSaida, "Comparacoes: %d\n", comp);

    fprintf(arqSaida, "\n\n======== ESTATISTICAS AVL ============\n");

    fprintf(arqSaida, "Numero de nodos: %d\n", quantosAVL);

    fprintf(arqSaida, "Altura: %d\n", arvore->altura);

    fprintf(arqSaida, "Rotacoes: %d\n", rotacao);

    fprintf(arqSaida, "Comparacoes: %d\n", comparacoes);

    fclose(arqConsumo);
    fclose(arqSaida);

    return 0;
}
