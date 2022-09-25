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
    int calorias;
    char alimentos[50];
    int fb;
    tipoInfo info;
    tipoInfo altura;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
};
typedef struct ARVORE avl;

avl *insereArvore(avl *arvore, tipoInfo info);