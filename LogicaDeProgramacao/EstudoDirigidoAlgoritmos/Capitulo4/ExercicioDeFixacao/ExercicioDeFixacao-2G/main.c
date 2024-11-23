#include <stdio.h>

int main() {
    int valor, maior, menor;

    printf("Digite o valor 1: ");
    scanf("%d", &valor);

    maior = menor = valor;

    printf("Digite o valor 2: ");
    scanf("%d", &valor);
    if (valor > maior) maior = valor;
    if (valor < menor) menor = valor;

    printf("Digite o valor 3: ");
    scanf("%d", &valor);
    if (valor > maior) maior = valor;
    if (valor < menor) menor = valor;

    printf("Digite o valor 4: ");
    scanf("%d", &valor);
    if (valor > maior) maior = valor;
    if (valor < menor) menor = valor;

    printf("Digite o valor 5: ");
    scanf("%d", &valor);
    if (valor > maior) maior = valor;
    if (valor < menor) menor = valor;

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
