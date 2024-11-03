#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float prestacao, valor, taxa, tempo;

    printf("Entre com os dados para efetuar o calculo.\n");
    printf("Valor:");
        scanf("%f",&valor);
    printf("Taxa:");
        scanf("%f",&taxa);
    printf("Tempo:");
        scanf("%f",&tempo);

    prestacao = valor + (valor * (taxa / 100) *tempo);

    printf("Valor da prestação em atraso é %.2f",prestacao);

    return 0;
}
