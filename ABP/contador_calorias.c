#include <stdio.h>
#include <stdlib.h>

// insere biblioteca
#include "contador_calorias.h"


/*void leArquivos(char arquivo[], char alimentos, int calorias)
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


}*/

// insere arvore abp
abp *insereArvore(abp *arvore, char chave)
{
    if (arvore == NULL)
    {
        arvore = (abp *)malloc(sizeof(abp));
        arvore->info = chave;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (chave < arvore->info)
        arvore->esquerda = InsereArvore(arvore->esquerda, chave);
    else if (chave > arvore->info)
        arvore->direita = InsereArvore(arvore->direita, chave);
    return arvore;
}

//busca alimento na arvore

abp* consultaABP(abp *arvore, char chave) {
    while (arvore != NULL){
        if (arvore->info == chave )
            return arvore; //achou retorna o ponteiro para o nó
        else
            if (arvore->info > chave)
                arvore = arvore->esquerda;
            else
                arvore = arvore->direita;
    }
    return NULL; //não achou, retorna null
}

// calcula numero de nodos (precisa? da pra só fazer um contador na inserção?)

int qtd_nodos(abp *arvore){
    if(arvore == NULL)
        return 0;
    else 
        return 1 + qtd_nodos(arvore->esquerda) + qtd_nodos(arvore->direita);
}


// calcula altura da arvore

int altura(abp *arvore){
    if(arvore == NULL){
        return -1;
    }
    else{
        int esquerda = altura(arvore->esquerda);
        int direita = altura(arvore->direita);
        if(esquerda > direita)
            return esquerda + 1;
        else
            return direita + 1;
    }
}

// calcula o numero de comparacoes
abp* nro_comparacoes(abp *arvore, char *chave){
    while (arvore!=NULL){
        comp++;
            if (!strcmp(arvore->info,chave)){
                comp++;
                return arvore;
            }
            else {
                comp++;
                if (strcmp(arvore->info,chave)>0)
                    arvore = arvore->esquerda;
                else
                    arvore = arvore->direita;
                }
            }
     return NULL;
}

