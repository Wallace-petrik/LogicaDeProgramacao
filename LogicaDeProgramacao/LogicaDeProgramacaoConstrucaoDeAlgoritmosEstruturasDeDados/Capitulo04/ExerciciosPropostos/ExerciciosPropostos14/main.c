#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define tam 10
int main(){
    setlocale(LC_ALL,"");

    srand(time(NULL));
    int matriz[tam][tam];

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    printf("MATRIZ NORMAL\n\n");

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }



    printf("\nMATRIZ 90º\n\n");

     for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("[%d]",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
