// balanceia a arvore avl com as devidas rotacoes
avl *balancear(avl *arvore)
{
    short fb = 0;
    //short fb = fatorBalanceamento(arvore);

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