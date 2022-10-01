#include "contador_calorias.h"


//INSERE OS ELEMENTOS NA ARVORE
abp *insereArvore(abp *arvore, str_alimento comida)
{
    if (arvore == NULL)
    {
        arvore = (abp *)malloc(sizeof(abp));
        arvore->info = comida;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (strcmp(comida.alimentos, arvore->info.alimentos)<0)
        arvore->esquerda = insereArvore(arvore->esquerda, comida);
    else if (strcmp(comida.alimentos, arvore->info.alimentos))
        arvore->direita = insereArvore(arvore->direita, comida);
    return arvore;
}

//PROCURA OS ALIMENTOS CONSUMIDOS PELO PACIENTE NA ARVORE
 abp* consultaABP(abp *arvore, char alimento_dia[100], int *comp){
        //int comparacoes;
        if (arvore==NULL)
            return NULL;
        else{
            (*comp)++;
            if (strcmp(arvore->info.alimentos, alimento_dia)==0){
                //printf("%s - %d", arvore->info.alimentos, arvore->info.calorias);
                return arvore;
            }
            else{
                //printf("%s - %d\n", arvore->info.alimentos, arvore->info.calorias);
                if (strcmp(arvore->info.alimentos, alimento_dia)>0)
                    return consultaABP(arvore->esquerda, alimento_dia, comp);
                else
                    return consultaABP(arvore->direita, alimento_dia, comp);
                }
            }
        }

//CALCULA QUANTOS NODOS TEM NA ARVORE
int qtd_nodos(abp *arvore){
    if(arvore == NULL)
        return 0;
    else
        return 1 + qtd_nodos(arvore->esquerda) + qtd_nodos(arvore->direita);
}

//CALCULA ALTURA DA ARVORE
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