#include <stdio.h>
#include <stdlib.h>

// insere biblioteca
#include "contador_calorias.h"

// insere arvore abp
abp *insereArvore(abp *arvore, tipoInfo info)
{
    if (arvore == NULL)
    {
        arvore = (abp *)malloc(sizeof(abp));
        arvore->info = info;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (info < arvore->info)
        arvore->esquerda = InsereArvore(arvore->esquerda, info);
    else if (info > arvore->info)
        arvore->direita = InsereArvore(arvore->direita, info);
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

    if(arqCalorias != NULL){
        printf("Arquivo lido com sucesso!\n");
    }
    else{
        printf("Erro ao carregar o arquivo!\n");
    }

    while(EOF != fscanf(arqCalorias, "%s%d\n", &pontArquivos->alimentos[50], &pontArquivos->calorias))
    {
        printf("%s, %d", pontArquivos->alimentos[50], pontArquivos->calorias);  
    }



}