#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

void digitacaoValoresNoVetor(int *vetor);
void imprimirSomatorio(int *vetor);
void imprimirMedia(int *vetor);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int vet[tam] = {1,10,100};

    //digitacaoValoresNoVetor(vet);
    //imprimirSomatorio(vet);
    imprimirMedia(vet);
    return 0;
}

void digitacaoValoresNoVetor(int *vetor){

    printf("Digite os valores: ");

    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor[i]);
    }

}

void imprimirSomatorio(int *vetor){
    int somatorio = 0;
    for(int i = 0; i < tam; i++){
        somatorio += vetor[i];
    }
    printf("\nO somatório dos itens do vetor é = %d",somatorio);
}

void imprimirMedia(int *vetor){
    float media = 0, somatorio;
    for(int i = 0; i < tam; i++){
        somatorio += vetor[i];
    }
    media = somatorio/tam;
    printf("\nA média é = %2.f",media);
}



