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
    

    char *comida[50];
    int calorias;
    char *ptr;

    FILE *arquivo;
    arquivo = fopen("day1.csv", "r");

    while(fscanf(fptr, "%[^;];%d\n", comida, &calorias)==2){

        printf("%s  ---  %d\n", S, cal);

    }
    fclose(arquivo);
    return 0;

    


    }







   




    return 0;
}