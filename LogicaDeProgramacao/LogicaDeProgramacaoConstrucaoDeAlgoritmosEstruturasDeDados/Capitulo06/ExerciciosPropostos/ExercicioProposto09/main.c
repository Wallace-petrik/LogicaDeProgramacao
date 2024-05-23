#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularMdc(int numeroA, int numeroB);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numeroA,numeroB;
    int mdc;

    printf("Entre com dois números para calcular o MDC: ");
        scanf("%d%d",&numeroA,&numeroB);

    if(numeroA<numeroB){
        mdc = calcularMdc(numeroA,numeroB);
    }else{
        mdc = calcularMdc(numeroB,numeroA);
    }

    printf("\nO MDC é %d",mdc);
    return 0;
}

int calcularMdc(int numeroA, int numeroB){ //Algoritmo de Euclides

    int resto = numeroA;

    while(resto!=0){

        resto = numeroB%numeroA;
        numeroB = numeroA;
        numeroA = resto;

    }

    return numeroB;
}
