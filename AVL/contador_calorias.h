#include <stdio.h>
#include <stdlib.h>
// arquivo.h AVL

// estrutura da árvore
/************************************/
// estrutura da árvore
/************************************/
typedef int tipoInfo;

struct ARVORE
{
    tipoInfo info;
    tipoInfo nivel;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
};
typedef struct ARVORE avl;

struct ARQUIVO
{
    int calorias;
    char alimentos[50];
};
typedef struct ARQUIVO dados;

avl *insereArvore(avl *arvore, tipoInfo info);