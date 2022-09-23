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

abp *insereArvore(abp *arvore, tipoInfo info);