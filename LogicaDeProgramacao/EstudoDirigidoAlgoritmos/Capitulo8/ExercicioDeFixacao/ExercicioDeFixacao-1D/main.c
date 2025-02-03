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
         matriz[1][j] = pow(vetor[j],2);
    }

    return 0;
}
