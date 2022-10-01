#ifndef CONTADOR_CALORIAS_H
#define CONTADOR_CALORIAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// arquivo.h AVL

// estrutura dos dados
/************************************/
typedef struct dados
{
    int caloriasDiarias;
    int calorias;
    char alimentos[50];
} dados;
/************************************/

// estrutura da árvore
/************************************/
struct ARVORE
{
    int fb;
    dados dados;
    int altura;
    struct ARVORE *esquerda;
    struct ARVORE *direita;
};
typedef struct ARVORE avl;
/************************************/

/*--------------TRATA ARVORE--------------*/
void desenha(avl *arvore, int nivel);
int qtd_nodos(avl *arvore);
avl *insereArvore(avl *arvore, dados info, int *ok, int *rotacao);
avl *Caso1(avl *arvore, int *ok, int *rotacao);
avl *Caso2(avl *arvore, int *ok, int *rotacao);
int fatorBalanceamento(avl *arvore);
avl *consultaAVL(avl *arvore, char alimentosDia[50], int *comparacoes);
/*--------------TRATA ARVORE--------------*/

/*--------------ROTAÇÕES--------------*/
avl *rotacaoEsquerda(avl *arvore);
avl *rotacaoDireita(avl *arvore);
avl *rotacaoDuplaEsquerda(avl *arvore);
avl *rotacaoDuplaDireita(avl *arvore);
/*--------------ROTAÇÕES--------------*/

#endif