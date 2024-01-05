#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#define tam 5

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int matriz[tam][tam];

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    printf("\nMatriz antes das trocas\n\n");

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < tam; i++){
        matriz[1][i] = matriz[1][i] + matriz[4][i];
        matriz[4][i] = matriz[1][i] - matriz[4][i];
        matriz[1][i] = matriz[1][i] - matriz[4][i];

        matriz[0][i] = matriz[0][i] + matriz[3][i];
        matriz[3][i] = matriz[0][i] - matriz[3][i];
        matriz[0][i] = matriz[0][i] - matriz[3][i];

        matriz[1][i] = matriz[1][i] + matriz[4][i];
        matriz[4][i] = matriz[1][i] - matriz[4][i];
        matriz[1][i] = matriz[1][i] - matriz[4][i];

        if(i+i != 4){
            matriz[i][i] = matriz[i][i] + matriz[4-i][i];
            matriz[4-i][i] = matriz[i][i] - matriz[4-i][i];
            matriz[i][i] = matriz[i][i] - matriz[4-i][i];
        }

    }

    printf("\nMatriz depos das trocas\n\n");

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
