#ifndef CONTADOR_CALORIAS_H
#define CONTADOR_CALORIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "contador_calorias.h"

// estrutura da árvore
/************************************/

typedef struct str_alimento{
        int calorias;
        char alimentos[100];
}str_alimento;

//typedef int tipoInfo;

struct ARVORE
{
    str_alimento info;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
};
typedef struct ARVORE abp;


abp *insereArvore(abp *arvore, str_alimento comida);

abp* consultaABP(abp *arvore, char alimento_dia[100], int *comp);

int qtd_nodos(abp *arvore);

int altura(abp *arvore);

#endif