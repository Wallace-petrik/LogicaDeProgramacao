#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularValorAbsoluto(int numero);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero;
    int numeroAbsoluto = 0;

    printf("Calcular modulo\nDigite um número  inteiro qualquer positivo ou negativo: ");
        scanf("%d",&numero);

    numeroAbsoluto = calcularValorAbsoluto(numero);

    printf("Valor absoluto = %d",numeroAbsoluto);
    return 0;
}

int calcularValorAbsoluto(int numero){
    if(numero<0){
        return -numero;
    }
        return numero;
}
