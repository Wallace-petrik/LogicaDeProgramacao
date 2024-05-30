#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcularSomatorioDeFibonacci(int quantidadeDeTermos, int *somarotio);

int main(){
    setlocale(LC_ALL ,"Portuguese");

    int quantidadeDeTermos;
    int somarotio = 0;

    printf("\nEntre com a quantidade de termos:");
        scanf("%d",&quantidadeDeTermos);

    calcularSomatorioDeFibonacci(quantidadeDeTermos,&somarotio);

    printf("\nO somatório dos N primeiros termos da série de Fibonacci é %d\n",somarotio);
    return 0;
}

void calcularSomatorioDeFibonacci(int quantidadeDeTermos, int *somarotio){
    int antertior = 0;
    int atual = 1;
    int proximo = 0;
    for(int i = 1; i <= quantidadeDeTermos; i++){
        proximo = antertior+atual;
        antertior = atual;
        atual = proximo;
        *somarotio += antertior;
    }
}

