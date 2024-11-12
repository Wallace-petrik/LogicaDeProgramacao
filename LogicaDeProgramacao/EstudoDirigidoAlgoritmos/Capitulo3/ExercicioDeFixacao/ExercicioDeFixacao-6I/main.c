#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

        float valorA, valorB;
        float soma, subtracao, divisao, multiplicacao;

        printf("Digite dois núemros: ");
            scanf("%f%f",&valorA,&valorB);

        soma = valorA + valorB;
        subtracao = valorA - valorB;
        divisao = valorA / valorB;
        multiplicacao = valorA * valorB;

        printf(" %.2f + %.2f = %.2f\n",valorA,valorB,soma);
        printf(" %.2f - %.2f = %.2f\n",valorA,valorB,subtracao);
        printf(" %.2f / %.2f = %.2f\n",valorA,valorB,divisao);
        printf(" %.2f +* %.2f = %.2f\n",valorA,valorB,multiplicacao);
    return 0;
}
