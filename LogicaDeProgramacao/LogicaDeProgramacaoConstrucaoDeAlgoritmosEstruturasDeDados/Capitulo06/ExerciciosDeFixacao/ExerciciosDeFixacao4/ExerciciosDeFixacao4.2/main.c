#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int informaQuantidadeDeDigitos(int numero);

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;
    int numeroInvertido = 0;
    int divisor = 0;

    printf("Digite um número inteiro qualquer: ");
        scanf("%d",&numero);

    divisor = calcularDivisor(numero);
    numeroInvertido = inverterNumero(numero,divisor);

    printf("O número invertido é %d",numeroInvertido);

    return 0;
}

int calcularDivisor(int numero){
    int divisor = 1;

    while(numero>0.0){

        divisor *=10;
        numero *= 0.1;

    }
    divisor /=10;
    return divisor;
}

int inverterNumero(int numero, int divisor){

    int resto  = 0;
    int numeroInvertido = 0;
    int resposta = 0;

    for(int i = divisor, j = 1; i >= 1; i/=10, j*=10){

        numeroInvertido = numero/i;
        resto = numero%i;

        numeroInvertido *= j;

        numero = resto;
        resposta += numeroInvertido;
    }

    return resposta;
}
