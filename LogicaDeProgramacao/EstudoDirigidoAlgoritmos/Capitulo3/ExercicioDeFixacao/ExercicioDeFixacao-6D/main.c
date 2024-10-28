#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(){

    float raio = 0;
    float altura = 0;
    float volume = 0;

    const float PI = 3.14159;

    printf("\n\t\tVolume do cilindro");

    printf("\nDigite o raio do cilindro: ");
        scanf("%f",&raio);
    printf("\nDigite a altura do cilindro: ");
        scanf("%f",&altura);

    volume = PI * pow(raio,2) * altura;

    printf("\nO volume do cilindro é igual: %.2f",volume);
    return 0;
}
