#include <stdio.h>
#include <stdlib.h>

// insere biblioteca
#include "contador_calorias.h"


pNodoA* InsereArvore(pNodoA *a, tipoinfo ch){
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esquerda = NULL;
         a->direita = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}
