#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int matrizA[7], matrizB[7];
    int matrizC[2][7];

    for(int i = 0; i < 7; i++){
        printf("Entre com o %dº elemento da matriz A: ",i+1);
            scanf("%d",&matrizA[i]);
    }

    for(int i = 0; i < 7; i++){
        printf("Entre com o %dº elemento da matriz B: ",i+1);
            scanf("%d",&matrizB[i]);
    }

    for(int i = 0; i < 7; i++){
        matrizC[0][i] = matrizA[i];
        matrizC[1][i] = matrizB[i];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 7; j++){
            printf("[%d] ",matrizC[i][i]);
        }
        printf("\n");
    }
    return 0;
}
