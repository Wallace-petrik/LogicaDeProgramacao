#include <stdio.h>
#include <locale.h>
#define L 5
#define C 3

int main(){

    setlocale(LC_ALL,"");

    int matA[L][C];
    int matB[L][C];
    int matC[L][C];

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            printf("Entre com o calor da Matriz A[%d][%d]: ",i+1, j+1);
                scanf("%d",&matA[i][j]);
        }
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            printf("Entre com o calor da Matriz B[%d][%d]: ",i+1, j+1);
                scanf("%d",&matB[i][j]);
        }
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            matC[i][j]=matA[i][j]+matB[i][j];
        }
    }
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            printf("%d\t",matC[i][j]);
        }
        printf("\n");
    }
    return 0;
}
