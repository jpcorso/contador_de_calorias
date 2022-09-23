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
    return arvore;
}