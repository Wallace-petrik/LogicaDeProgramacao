#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

void digitacaoValoresNoVetor(int *vetor);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int vet[tam] = {1,10,100};

    //digitacaoValoresNoVetor(vet);

    return 0;
}

void digitacaoValoresNoVetor(int *vetor){

    printf("Digite os valores: ");

    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor[i]);
    }

}
