#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int vetor[10];
    int matriz[3][10];

    for(int j = 0; j < 10; j++){
         printf("Entre com o valor da vetor[%d]: ",j+1);
            scanf("%d",&vetor[j]);
    }

    for(int j = 0; j < 10; j++){
         matriz[0][j] = vetor[j] + 5;
    }

    for(int j = 0; j < 10; j++){
         matriz[2][j] = pow(vetor[j],2);
    }

    for(int i = 0; i < 10; i++){
        int j = 1;
        int fat = 1;
        while(j<=vetor[j]){
            fat *= j;
            j++;
        }
        matriz[1][i] = fat;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            printf("[%3.d]",matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
