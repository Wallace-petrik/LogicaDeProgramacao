#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define max 5

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int matriz[max][max];
    int colunas[max] = {0,0,0,0,0},linhas[max] = {0,0,0,0,0};
    int somaOddNumbers = 0;

    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            matriz[i][j] = rand()%10;

            if(matriz[i][j]%2!=0){
                somaOddNumbers += matriz[i][j];
            }
            linhas[i] = linhas[i]+matriz[i][j];

        }
    }

    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            colunas[i] += matriz[j][i];
        }
    }

    printf("\nSoma dos números impares : %d\n",somaOddNumbers);
    printf("\nSoma de cada uma das %d colunos.\n",max);

    for(int i = 0; i < max; i++){
        printf("COluna %d = %d\n",i+1,colunas[i]);
    }

    printf("\nSoma de cada uma das %d linhas.\n",max);
    for(int i = 0; i < max; i++){
        printf("Linha %d = %d\n",i+1,linhas[i]);
    }
    return 0;
}
