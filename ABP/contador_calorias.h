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
    int calorias;
    char alimento[100];
};
typedef struct ARVORE abp;
/*
struct ARQUIVO
{
    int calorias;
    char alimentos[50];
};
typedef struct ARQUIVO dados;
*/

abp *insereArvore(abp *arvore, char chave);

abp* consultaABP(abp *arvore, char chave);

int qtd_nodos(abp *arvore);

int altura(abp *arvore);

abp* nro_comparacoes(abp *arvore, char *chave);