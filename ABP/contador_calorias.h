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

typedef struct str_alimentos{
        int calorias;
        char alimentos[100];
}str_alimentos;


abp *insereArvore(abp *arvore, char chave);

abp* consultaABP(abp *arvore, char chave);

int qtd_nodos(abp *arvore);

int altura(abp *arvore);

abp* nro_comparacoes(abp *arvore, char *chave);