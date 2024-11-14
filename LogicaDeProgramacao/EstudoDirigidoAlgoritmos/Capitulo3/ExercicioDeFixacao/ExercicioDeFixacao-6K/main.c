#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int temperaturaEmCelsius;
    float temperaturaEmFahrenheit;

    printf("Digite uma temperatura em Graus Celsius: ");
        scanf("%d",&temperaturaEmCelsius);

    temperaturaEmFahrenheit =(( 9 * temperaturaEmCelsius + 160)/5);

    printf("A temperatura em Fahrenheit é %.2f",temperaturaEmFahrenheit);

    return 0;
}
