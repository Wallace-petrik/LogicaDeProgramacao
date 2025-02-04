#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetorA[tam], vetorB[tam];
    int matriz[2][tam];

    for(int i = 0; i < tam; i++){
        printf("Entre com o %dº do vetor A: ",i+1);
            scanf("%d",&vetorA[i]);
    }
    printf("\n");
    for(int i = 0; i < tam; i++){
        printf("Entre com o %dº do vetor B: ",i+1);
            scanf("%d",&vetorB[i]);
    }
    printf("\n");
    for(int i = 0; i < tam; i++){
        matriz[0][i]=vetorA[i]*2;
        matriz[1][i]=vetorB[i]-5;
    }

    printf("\nVetor A\n");
    for(int i = 0; i < tam; i++){
        printf("[%d]",vetorA[i]);
    }

    printf("\n\nVetor B\n");
    for(int i = 0; i < tam; i++){
        printf("[%d]",vetorB[i]);
    }

    printf("\n\nMatriz C\n");
    for(int i = 0; i < tam; i++){
        printf("[%d] [%d]\n",matriz[0][i],matriz[1][i]);
    }
    return 0;
}
