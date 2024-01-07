#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define tam 10

void imprimeMatriz(int matrizP[tam][tam]);

int main(){
    setlocale(LC_ALL,"");

    srand(time(NULL));

    int matriz[tam][tam],matrizAux[tam][tam];

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    printf("MATRIZ NORMAL\n\n");
    imprimeMatriz(matriz);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matrizAux[i][j] = matriz[i][j];
        }
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = matrizAux[j][i];
        }
    }

    printf("\nMATRIZ 90º\n\n");
    imprimeMatriz(matriz);
    return 0;
}

void imprimeMatriz(int matrizP[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]",matrizP[i][j]);
        }
        printf("\n");
    }
}
