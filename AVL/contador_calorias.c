// insere biblioteca
#include "contador_calorias.h"

int qtd_nodos(avl *arvore)
{
    if (arvore == NULL)
        return 0;
    else
        return 1 + qtd_nodos(arvore->esquerda) + qtd_nodos(arvore->direita);
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

// insere arvore avl
avl *insereArvore(avl *arvore, dados info)
{
    if (arvore == NULL)
    {
        arvore = (avl *)malloc(sizeof(avl));
        arvore->dados = info;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        arvore->altura = 0;
        return arvore;
    }
    else if (strcmp(info.alimentos, arvore->dados.alimentos) < 0)
        arvore->esquerda = insereArvore(arvore->esquerda, info);
    else if (strcmp(info.alimentos, arvore->dados.alimentos) > 0)
        arvore->direita = insereArvore(arvore->direita, info);

    // vai adicionando a altura toda vez que percorre
    arvore->altura = altura(arvore) + 1;

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

int fatorBalanceamento(avl *arvore)
{
    arvore->fb = (altura(arvore->esquerda) - altura(arvore->direita));
    return 1;
}

void leArquivo(avl *arvore, dados info, FILE *arqCalorias)
{
    char arquivo[50];
    char alimentos[50];
    int calorias;

    // printf("Nome do arquivo com a tabela de calorias: ");
    // scanf("%s", arquivo);

    arqCalorias = fopen("1000Shuffled.csv", "r");

    if (arqCalorias != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    while (fscanf(arqCalorias, "%[^;];%d/n", info.alimentos, &info.calorias) == 2)
    {
        arvore = insereArvore(arvore, info);
    }

    fclose(arqCalorias);
}

avl *consultaAVL(avl *arvore, char alimentosDia[50])
{
    int comparaAlimentos;
    
    

    while (arvore != NULL)
    {
        comparaAlimentos = strcmp(alimentosDia, arvore->dados.alimentos);

        if (comparaAlimentos == 0)
        {
            return arvore;
        }
        else if (comparaAlimentos > 0)
        {
            return consultaAVL(arvore->direita, alimentosDia);
        }
        else if (comparaAlimentos < 0)
        {
            return consultaAVL(arvore->esquerda, alimentosDia);
        }
    }


    return NULL;
}

void leConsumo(avl *arvore, dados info, FILE *arqConsumo, FILE *arqSaida)
{
    char consumo[50];
    char alimentosDia[50];
    int gramas;
    avl *auxiliar;

    // printf("Nome do arquivo com o consumo diário: ");
    // scanf("%s", consumo);

    arqConsumo = fopen("day1.csv", "r");

    if (arqConsumo != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
        printf("em pleno 2022 ponteiros porra");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    while (fscanf(arqConsumo, "%[^;];%d/n", alimentosDia, &gramas) == 2)
    {
        auxiliar = consultaAVL(arvore, alimentosDia);
        //saida(arvore, info, auxiliar, gramas, arqSaida);
    }

    fclose(arqConsumo);
}

/*void saida(avl *arvore, dados info, avl *auxiliar, int gramas, FILE *arqSaida)
{

    char nomeSaida[50];
    int caloriasConsumidas;
    int consulta;

    arqSaida = fopen("calorias_consumidas.txt", "w");

    caloriasConsumidas = ((arvore->dados.calorias * gramas) / 100);
    info.caloriasDiarias += caloriasConsumidas;

    fprintf(arqSaida, "%dg de %s (%d calorias por 100g) = %d calorias", gramas, arvore->dados.alimentos, auxiliar->dados.calorias, caloriasConsumidas);

    fclose(arqSaida);
}

void estatisticas(dados info, FILE *arqSaida)
{

    arqSaida = fopen("calorias_consumidas.txt", "w");

    fprintf(arqSaida, "Total de %d calorias consumidas no dia.", info.caloriasDiarias);
    fclose(arqSaida);
}*/

/*ROTAÇÕES*/

avl *rotacaoEsquerda(avl *arvore)
{
    avl *auxiliar;

    auxiliar = arvore->direita;
    arvore->direita = auxiliar->esquerda;
    auxiliar->esquerda = arvore;
    arvore->fb = 0;
    arvore = auxiliar;

    return arvore;
}

avl *rotacaoDireita(avl *arvore)
{
    avl *auxiliar;

    auxiliar = arvore->esquerda;
    arvore->esquerda = auxiliar->direita;
    auxiliar->direita = arvore;
    arvore->fb = 0;
    arvore = auxiliar;

    return arvore;
}

avl *rotacaoDuplaEsquerda(avl *arvore)
{
    avl *auxiliar1, *auxiliar2;

    auxiliar1 = arvore->direita;
    auxiliar2 = auxiliar1->esquerda;
    auxiliar1->esquerda = auxiliar2->direita;
    auxiliar2->direita = auxiliar1;
    arvore->direita = auxiliar2->esquerda;
    auxiliar2->esquerda = arvore;

    // recalcula o fb
    if (auxiliar2->fb == -1)
        arvore->fb = 1;
    else
        arvore->fb = 0;
    if (auxiliar2->fb == 1)
        auxiliar1->fb = -1;
    else
        auxiliar1->fb = 0;
    arvore = auxiliar2;

    return arvore;
}

avl *rotacaoDuplaDireita(avl *arvore)
{
    avl *auxiliar1, *auxiliar2;

    auxiliar1 = arvore->esquerda;
    auxiliar2 = auxiliar1->direita;
    auxiliar1->direita = auxiliar2->esquerda;
    auxiliar2->esquerda = auxiliar1;
    arvore->esquerda = auxiliar2->direita;
    auxiliar2->direita = arvore;

    // recalcula o fb
    if (auxiliar2->fb == 1)
        arvore->fb = -1;
    else
        arvore->fb = 0;
    if (auxiliar2->fb == -1)
        auxiliar1->fb = 1;
    else
        auxiliar1->fb = 0;
    arvore = auxiliar2;

    return arvore;
}
