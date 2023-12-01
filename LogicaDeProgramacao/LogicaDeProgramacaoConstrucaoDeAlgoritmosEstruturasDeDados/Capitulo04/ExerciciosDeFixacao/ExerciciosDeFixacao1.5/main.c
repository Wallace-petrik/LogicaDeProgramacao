#include <stdio.h>
#include <locale.h>


int main(){
    setlocale(LC_ALL,"");

    int tan = 5;
    int tamanho = tan;
    int vet[tan];
    int continuar;

    for(int i = 0; i < tan ; i++){

        printf("Entre um número: ");
            scanf("%d",&vet[i]);

    }

    do{//Bubble Sort
        continuar = 0;
        for(int i = 0; i < tan-1; i++){
            if(vet[i] > vet[i+1]){
                vet[i] = vet[i] + vet[i+1];
                vet[i+1] = vet[i] - vet[i+1];
                vet[i] = vet[i] - vet[i+1];
                continuar = i;
             }
        }
        tan--;
    }while(continuar != 0);

    printf("\n");

    for(int i = 0; i < tamanho; i++){
        printf("[%d] ",vet[i]);
    }
    return 0;
}
