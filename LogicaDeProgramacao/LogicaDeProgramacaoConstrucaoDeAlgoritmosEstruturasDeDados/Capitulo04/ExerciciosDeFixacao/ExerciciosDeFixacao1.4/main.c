#include <stdio.h>
#include <locale.h>
#define tan 5

int main(){
    setlocale(LC_ALL,"");

    int vet[tan];
    int menor;

    for(int i = 0; i < tan ; i++){

        printf("Entre um número: ");
            scanf("%d",&vet[i]);

    }

    for(int i = 0; i < tan - 1; i++){ //Selection sort
        menor = i;
        for(int j = i+1; j < tan; j++){
            if(vet[j]<vet[menor]){
                menor = j;
            }
        }
        if(i != menor){
            vet[i] = vet[i] + vet[menor];
            vet[menor] = vet[i] - vet[menor];
            vet[i] = vet[i] - vet[menor];
        }
    }

    printf("\n");

    for(int i = 0; i < tan; i++){
        printf("[%d] ",vet[i]);
    }
    return 0;
}
