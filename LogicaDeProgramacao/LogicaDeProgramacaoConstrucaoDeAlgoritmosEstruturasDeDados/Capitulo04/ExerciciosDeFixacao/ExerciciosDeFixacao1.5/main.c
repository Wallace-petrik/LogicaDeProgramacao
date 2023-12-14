#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"");

    int tam = 5;
    int tamanho = tam;
    int vet[tam];
    int continuar;

    for(int i = 0; i < tam ; i++){

        printf("Entre um número: ");
            scanf("%d",&vet[i]);

    }

    do{//Bubble Sort
        continuar = 0;
        for(int i = 0; i < tam-1; i++){
            if(vet[i] > vet[i+1]){
                vet[i] = vet[i] + vet[i+1];
                vet[i+1] = vet[i] - vet[i+1];
                vet[i] = vet[i] - vet[i+1];
                continuar = i;
             }
        }
        tam--;
    }while(continuar != 0);

    printf("\n");

    for(int i = 0; i < tamanho; i++){
        printf("[%d] ",vet[i]);
    }
    return 0;
}
