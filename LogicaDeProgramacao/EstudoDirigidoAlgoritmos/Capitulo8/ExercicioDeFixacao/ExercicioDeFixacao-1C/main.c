#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int matriz[4][5];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
             printf("Entre com o valor da matriz[%d][%d]: ",i,j);
                scanf("%d",&matriz[i][j]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
             printf("[%2.d]",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
