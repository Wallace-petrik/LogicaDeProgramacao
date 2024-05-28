#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float arredondaNumero(float numero);

int main(){
    setlocale(LC_ALL,"Portuguese");

    float numero;

    printf("\nArredondamento");
    printf("Entre com número qualquer de ponto flutuante: ");
        scanf("%f",&numero);

    printf("Antes de arredondar %.2f\n",numero);
    numero = arredondaNumero(numero);
    printf("Depois de arredondar %.2f\n",numero);

    return 0;
}

float arredondaNumero(float numero) {
    if (numero > 0) {
        if (numero - (int)numero >= 0.5) {
            return (int)numero + 1;
        } else {
            return (int)numero;
        }
    } else {
        if (numero - (int)numero <= -0.5) {
            return (int)numero - 1;
        } else {
            return (int)numero;
        }
    }
}
