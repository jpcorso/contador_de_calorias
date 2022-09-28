// Trabalho final de estrutura de dados **contador de calorias**

// João Pedro Licks Corso - 00337569
// Júlia Mombach da Silva - 00281023

/*Essa aplicação recebe um arquivo texto contendo os
alimentos ingeridos por um paciente e uma tabela de alimentos e suas calorias. A
tabela de calorias deverá ficar armazenada em uma árvore. */

#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]){

    abp *arvore = NULL;
    abp *aux = NULL;
    abp dados;

    if((argc < 2) || strlen(argv[1]) < 3){
        fprintf(stderr, "Informe o nome do arquivo a ser lido, nome deve possuir ao menos 3 caracteres\n");
        return 1;
    }
    FILE* arq = fopen(argv[1], "r");
    if(arq == NULL){
        fprintf(stderr, "Arquivo %s nao existe\n", argv[1]);
    }

    while(fscanf(arq, "%s, %d", )







   




    return 0;
}