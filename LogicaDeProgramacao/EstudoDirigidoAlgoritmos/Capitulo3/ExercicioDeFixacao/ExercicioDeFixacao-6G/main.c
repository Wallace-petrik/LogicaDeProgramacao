#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int valorA, valorB;
    int adcao, subtracao, multiplicacao;

    printf("Entre com dois valores: ");
        scanf("%d%d",&valorA,&valorB);

    adcao = valorA + valorB;
    subtracao = valorA - valorB;
    multiplicacao = valorA * valorA;

    printf("\t\n%d + %d = %d",valorA,valorB,adcao);
    printf("\t\n%d - %d = %d",valorA,valorB,subtracao);
    printf("\t\n%d * %d = %d\n",valorA,valorB,multiplicacao);

    return 0;
}
