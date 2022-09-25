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
    
    arvore->altura = 

    return arvore;
}

void leArquivos(char arquivo[], char alimentos, int calorias)
{
    char *colocaCalorias[50];
    FILE *arqCalorias;
    dados *pontArquivos;

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

    while (EOF != fscanf(arqCalorias, "%s^%d\n", &pontArquivos->alimentos[50], &pontArquivos->calorias))
    {

        printf("%s, %d", pontArquivos->alimentos[50], pontArquivos->calorias);
    }
}

// calcula a altura da arvore para depois ver se é avl
int fatorBalanceamento(avl *arvore)
{
    int alturaEsquerda, alturaDireita;
    if (arvore == NULL)
        return 0;
    else
    {
        alturaEsquerda = fatorBalanceamento(arvore->esquerda);
        alturaDireita = fatorBalanceamento(arvore->direita);
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
