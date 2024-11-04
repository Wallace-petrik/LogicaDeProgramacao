#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL,"");

    int valor;
    int resultado;

    printf("Entre com um número inteiro: ");
        scanf("%d",&valor);

    resultado = (int)pow(valor, 2);

    printf("%d² = %d",valor,resultado);

    return 0;
}
