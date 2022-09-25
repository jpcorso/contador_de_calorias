#include <stdio.h>
#include <stdlib.h>

// insere biblioteca
#include "contador_calorias.h"

// insere arvore avl
avl *insereArvore(avl *arvore, tipoInfo info)
{
    if (arvore == NULL)
    {
        arvore = (avl *)malloc(sizeof(avl));
        arvore->info = info;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (info < arvore->info)
        arvore->esquerda = InsereArvore(arvore->esquerda, info);
    else if (info > arvore->info)
        arvore->direita = InsereArvore(arvore->direita, info);

    // vai adicionando a altura toda vez que percorre
    arvore->altura = maisAltura(altura(arvore->esquerda), altura(arvore->direita)) + 1;

    // verifica se precisa rebalancear a árvore
    arvore = balancear(arvore);

    return arvore;
}

// balanceia a arvore avl com as devidas rotacoes
avl *balancear(avl *arvore)
{
    short fb = fatorBalanceamento(arvore);

    // rotação à esquerda
    if (fb < -1 && fatorBalanceamento(arvore->direita) <= 0)
    {
        arvore = rotacaoEsquerda(arvore);
    }
    // rotação à direita
    else if (fb > 1 && fatorBalanceamento(arvore->esquerda) >= 0)
    {
        arvore = rotacaoDireita(arvore);
    }
    // rotação dupla à esquerda
    else if (fb < -1 && fatorBalanceamento(arvore->esquerda) < 0)
    {
        arvore = rotacaoDuplaEsquerda(arvore);
    }
    // rotação dupla à direita
    else if (fb < -1 && fatorBalanceamento(arvore->direita) > 0)
    {
        arvore = rotacaoDuplaDireita(arvore);
    }

    return arvore;
}

void leArquivo(char arquivo[], char alimentos, int calorias)
{
    char *colocaCalorias[50];
    FILE *arqCalorias;
    avl *ponteiroArquivos;

    printf("Nome do arquivo com a tabela de calorias: \n");
    scanf("%s", arquivo);

    arqCalorias = fopen(arquivo, "r");

    if (arqCalorias != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    while (EOF != fscanf(arqCalorias, "%s^%d\n", &ponteiroArquivos->alimentos[50], &ponteiroArquivos->calorias))
    {

        printf("%s, %d", ponteiroArquivos->alimentos[50], ponteiroArquivos->calorias);
    }
}

// essa função insere os dados na avl
void insereArquivo(avl *arvore)
{
}

// calcula a altura da arvore para depois ver se é avl
int altura(avl *arvore)
{
    int alturaEsquerda, alturaDireita;
    if (arvore == NULL)
        return 0;
    else
    {
        alturaEsquerda = altura(arvore->esquerda);
        alturaDireita = altura(arvore->direita);
        if (alturaEsquerda > alturaDireita)
        {
            return (1 + alturaEsquerda);
        }
        else
        {
            return (1 + alturaDireita);
        }
    }
}

// essa funcao diz qual dos lados é maior para recalcular a altura
int maisAltura(avl *esquerda, avl *direita)
{
    if (esquerda > direita)
        return esquerda;
    else if (direita > esquerda)
        return direita;
}

// essa funcao diz qual dos lados é menor para recalcular a altura
int menosAltura(avl *esquerda, avl *direita)
{
    if (esquerda < direita)
        return esquerda;
    else if (direita < esquerda)
        return direita;
}

int fatorBalanceamento(avl *arvore)
{

    arvore->fb = (altura(arvore->esquerda) - altura(arvore->direita));
    return arvore->fb;
}

/*ROTAÇÕES*/
avl *rotacaoEsquerda(avl *arvore)
{
    avl *ponteiroAuxiliar;

    ponteiroAuxiliar = arvore->direita;
    arvore->direita = ponteiroAuxiliar->esquerda;
    ponteiroAuxiliar->esquerda = arvore;
    arvore->fb = 0;
    arvore = ponteiroAuxiliar;

    return arvore;
}

avl *rotacaoDireita(avl *arvore)
{
    avl *ponteiroAuxiliar;

    ponteiroAuxiliar = arvore->esquerda;
    arvore->esquerda = ponteiroAuxiliar->direita;
    ponteiroAuxiliar->direita = arvore;
    arvore->fb = 0;
    arvore = ponteiroAuxiliar;

    return arvore;
}

avl *rotacaoDuplaEsquerda(avl *arvore)
{
    avl *ponteiroAuxiliar1, *ponteiroAuxiliar2;

    ponteiroAuxiliar1 = arvore->direita;
    ponteiroAuxiliar2 = ponteiroAuxiliar1->esquerda;
    ponteiroAuxiliar1->esquerda = ponteiroAuxiliar2->direita;
    ponteiroAuxiliar2->direita = ponteiroAuxiliar1;
    arvore->direita = ponteiroAuxiliar2->esquerda;
    ponteiroAuxiliar2->esquerda = arvore;

    // recalcula o fb
    if (ponteiroAuxiliar2->fb == -1)
        arvore->fb = 1;
    else
        arvore->fb = 0;
    if (ponteiroAuxiliar2->fb == 1)
        ponteiroAuxiliar1->fb = -1;
    else
        ponteiroAuxiliar1->fb = 0;
    arvore = ponteiroAuxiliar2;

    return arvore;
}

avl *rotacaoDuplaDireita(avl *arvore)
{
    avl *ponteiroAuxiliar1, *ponteiroAuxiliar2;

    ponteiroAuxiliar1 = arvore->esquerda;
    ponteiroAuxiliar2 = ponteiroAuxiliar1->direita;
    ponteiroAuxiliar1->direita = ponteiroAuxiliar2->esquerda;
    ponteiroAuxiliar2->esquerda = ponteiroAuxiliar1;
    arvore->esquerda = ponteiroAuxiliar2->direita;
    ponteiroAuxiliar2->direita = arvore;

    // recalcula o fb
    if (ponteiroAuxiliar2->fb == 1)
        arvore->fb = -1;
    else
        arvore->fb = 0;
    if (ponteiroAuxiliar2->fb == -1)
        ponteiroAuxiliar1->fb = 1;
    else
        ponteiroAuxiliar1->fb = 0;
    arvore = ponteiroAuxiliar2;

    return arvore;
}
