#include <stdio.h>
#include <stdlib.h>
// arquivo.h ABP

// estrutura da árvore
/************************************/
typedef int tipoInfo;

struct ARVORE
{
    tipoInfo info;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
};
typedef struct ARVORE abp;

struct ARQUIVO
{
    int calorias;
    char alimentos[50];
};
typedef struct ARQUIVO dados;

abp *insereArvore(abp *arvore, tipoInfo info);