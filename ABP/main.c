// Trabalho final de estrutura de dados **contador de calorias**

// João Pedro Licks Corso - 00337569
// Júlia Mombach Silva - XXXXXXXX

/*Essa aplicação recebe um arquivo texto contendo os
alimentos ingeridos por um paciente e uma tabela de alimentos e suas calorias. A
tabela de calorias deverá ficar armazenada em uma árvore. */

main(int argc, char *argv[]){

    abp *arvore = NULL;
    abp *aux = NULL;
    abp dados;
    abp *lala=NULL;

    str_alimento comida;

    //char *comida[100];
    //int calorias;
    char *ptr;
    char alimento_dia[100];
    int calorias_dia;
    int calorias_parc;
    int calorias_total=0;
    int quantos;
    int aaltura;
    int comparacoes = 0;

    FILE *arquivo;
    arquivo = fopen("1000Shuffled.csv", "r");

    //INSERE NA ARVORE
    while(fscanf(arquivo, "%[^;];%d\n", comida.alimentos, &comida.calorias)==2){
        arvore = insereArvore(arvore, comida);

        //printf("%s  ---  %d\n", comida.alimentos, comida.calorias);

    }
    fclose(arquivo);

    quantos = qtd_nodos(arvore);
    aaltura = altura(arvore);
    //printf("quantos nodos: %d\n", quantos);


    FILE *arqsaida;
    FILE *arquivo2;
    arquivo2 = fopen("day1.csv", "r");
    arqsaida = fopen("saida.txt", "w");

    while(fscanf(arquivo, "%[^;];%d\n", alimento_dia, &calorias_dia)==2){


        //printf("%s  ---  %d\n", alimento_dia, calorias_dia);
        //printf("%d\n\n", arvore->info.calorias);
        lala = consultaABP(arvore, alimento_dia, &comparacoes);
        //printf("\n%d\n\n", lala->info.calorias);
        calorias_parc = (lala->info.calorias * calorias_dia)/100;
        calorias_total += calorias_parc;
        fprintf(arqsaida, "%d de %s (%d calorias por 100g) = %d calorias\n", calorias_dia, alimento_dia, lala->info.calorias, calorias_parc);
    }
    fprintf(arqsaida, "\nTotal de %d calorias consumidas no dia.\n", calorias_total);

    fprintf(arqsaida, "\n\n======== ESTATISTICAS ABP ============\n");

    fprintf(arqsaida, "Numero de nodos: %d\n", quantos);

    fprintf(arqsaida, "Altura: %d\n", aaltura);

    fprintf(arqsaida, "Rotacoes: 0\n");

    fprintf(arqsaida, "Comparacoes: %d\n", comparacoes);

    fclose(arquivo2);
    fclose(arqsaida);
    return 0;




    }
