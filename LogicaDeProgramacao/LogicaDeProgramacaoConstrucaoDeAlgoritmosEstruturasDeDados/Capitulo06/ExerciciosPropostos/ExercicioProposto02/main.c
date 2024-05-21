#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int primeiroNumero;
    int segundoNumero;
    int restoDaDivisao;
    printf("Entre com dois números");
    printf("\nDividendo: ");
        scanf("%d",&primeiroNumero);
    printf("Divisor: ");
        scanf("%d",&segundoNumero);

    restoDaDivisao = calularRestoDaDivisao(primeiroNumero,segundoNumero);

    printf("\nO resto divisão é %d\n",restoDaDivisao);

    return 0;
}

int calularRestoDaDivisao(int dividendo, int divisor){

    int resto;

    if(dividendo<divisor){

        resto = dividendo;
        return resto;

    }

    while(dividendo>=divisor){

        dividendo -=divisor;
        resto = dividendo;
    }

    return resto;
}
