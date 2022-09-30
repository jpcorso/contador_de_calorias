// Trabalho final de estrutura de dados **contador de calorias**

// João Pedro Licks Corso - 00337569
// Júlia Mombach Silva - XXXXXXXX

/*Essa aplicação recebe um arquivo texto contendo os
alimentos ingeridos por um paciente e uma tabela de alimentos e suas calorias. A
tabela de calorias deverá ficar armazenada em uma árvore. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//insere biblioteca
#include "contador_calorias.h"

int main(void)
{   
    //declarações
    //arvore
    avl *arvore = NULL;
    avl *aux = NULL;
    avl *auxiliar = NULL;
    //dados
    dados info;
    char alimentosDia[50];
    int gramas;
    //arquivos
    FILE *arqCalorias;
    FILE *arqConsumo;
    FILE *arqSaida;

    leArquivo(arvore, info, arqCalorias);
    leConsumo(arvore, info, arqConsumo, arqSaida);
    int quantos = qtd_nodos(arvore);
    printf("NODOS %d", quantos);

    //saida(arvore, info, auxiliar, gramas, arqSaida);
    //estatisticas(info, arqSaida);

    return 0;
}
