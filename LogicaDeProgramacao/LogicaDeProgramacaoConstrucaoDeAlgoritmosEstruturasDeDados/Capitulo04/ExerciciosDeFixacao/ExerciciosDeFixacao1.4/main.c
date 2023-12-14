#include <stdio.h>
#include <locale.h>
#define tam 5

int main(){
    setlocale(LC_ALL,"");

    int vet[tam];
    int menor;

    for(int i = 0; i < tam ; i++){

        printf("Entre um número: ");
            scanf("%d",&vet[i]);

    }

    for(int i = 0; i < tam - 1; i++){ //Selection sort
        menor = i;
        for(int j = i+1; j < tam; j++){
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

    for(int i = 0; i < tam; i++){
        printf("[%d] ",vet[i]);
    }
    return 0;
}
