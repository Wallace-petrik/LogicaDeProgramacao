#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tam 3

void digitacaoValoresNoVetor(int *vetor);
void imprimirSomatorio(int *vetor);
float calcularMedia(int *vetor);
float calcularDesvioPadrao(int *vet);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int vet[tam] = {1,10,100};

    //digitacaoValoresNoVetor(vet);
    //calcularMedia(vet);
    //printf("\nA média é = %.2f",calcularMedia(vet));
    printf("\nDesvio padrão: %.2f",calcularDesvioPadrao(vet));
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

float calcularMedia(int *vetor){
    float media = 0, somatorio;
    for(int i = 0; i < tam; i++){
        somatorio += vetor[i];
    }
    media = (float)somatorio/tam;
    return media;
}

float calcularDesvioPadrao(int *vet){

    float media = calcularMedia(vet);
    float variancia = 0;
    float desvioPadrao = 0;

    for(int i = 0; i < tam; i++){
        if(media>=vet[i]){
            variancia += (media-vet[i])*(media-vet[i]);
        }else{
            variancia += (vet[i]-media)*(vet[i]-media);
        }
    }
    variancia = variancia/tam;
    desvioPadrao = sqrt(variancia);
    return desvioPadrao;
}


