#include <stdio.h>
#include <locale.h>
#define tan 4
int main(){
    setlocale(LC_ALL,"");

    int vet[tam][tam][tam] = {
    {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    },
    {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}
    },
    {
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 3, 3},
        {3, 3, 3, 3}
    },
    {
        {4, 4, 4, 4},
        {4, 4, 4, 4},
        {4, 4, 4, 4},
        {4, 4, 4, 4}
    }};
    int vetAux[tam][tam];

    printf("\nEntre com os dados!\n\n");

    /*for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            for(int k = 0; k < tam; k++){

                printf("\nEntre com os dados VET[%d][%d][%d]:",i+1,j+1,k+1);
                scanf("%d",&vet[i][j][k]);

            }
        }
    }*/

     for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            for(int k = 0; k < tam; k++){

               printf("[%d] ",vet[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){

            vetAux[i][j] = vet[0][i][j];

        }
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            for(int k = 0; k < tam - 1; k++){

                vet[k][i][j] = vet[k+1][i][j];

            }
        }
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){

            vet[tam-1][i][j] = vetAux[i][j];

        }
    }
    printf("Resposta\n\n");
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            for(int k = 0; k < tam; k++){

               printf("[%d] ",vet[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
