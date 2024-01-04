#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define tam 10

imprime(int *vet);

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int matriz[tam][tam];
    int vetLinhaMaior[tam],vetLinhaMenor[tam];
    int maior,menor;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j]=rand() % 10;
        }
    }

    for(int i = 0; i < tam; i++){
        maior = matriz[i][0];
        menor = matriz[i][0];
        for(int j = 0; j < tam; j++){
            if(maior<matriz[i][j]){
                maior = matriz[i][j];
            }
            if(menor>matriz[i][j]){
                menor = matriz[i][j];
            }
        }
        vetLinhaMaior[i] = maior;
        vetLinhaMenor[i] = menor;
    }

    printf("\nMaiores números de cada linha.\n\n");
    imprime(vetLinhaMaior);
    printf("\nMenores números de cada linha.\n\n");
    imprime(vetLinhaMenor);
    getchar();
    return 0;
}

imprime(int *vet){
    for(int i = 0; i < tam; i++){
        printf("Linha %2.d = %d\n",i+1,vet[i]);
    }
}
