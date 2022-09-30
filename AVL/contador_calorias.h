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
}dados;
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

/*--------------TRATA ARQUIVOS--------------*/
void leArquivo(avl *arvore, dados info, FILE *arqCalorias);
void leConsumo(avl *arvore, dados info, FILE *arqConsumo, FILE *arqSaida);
void saida(avl *arvore, dados info, avl *auxiliar, int gramas, FILE *arqSaida);
void estatisticas(dados info, FILE *arqSaida);
/*--------------TRATA ARQUIVOS--------------*/


/*--------------TRATA ARVORE--------------*/
int qtd_nodos(avl *arvore);
avl *insereArvore(avl *arvore, dados info);
avl *balancear(avl *arvore);
int fatorBalanceamento(avl *arvore);
avl *consultaAVL(avl *arvore, char alimentosDia[50]);
/*--------------TRATA ARVORE--------------*/


/*--------------ROTAÇÕES--------------*/
avl *rotacaoEsquerda(avl *arvore);
avl *rotacaoDireita(avl *arvore);
avl *rotacaoDuplaEsquerda(avl *arvore);
avl *rotacaoDuplaDireita(avl *arvore);
/*--------------ROTAÇÕES--------------*/

#endif