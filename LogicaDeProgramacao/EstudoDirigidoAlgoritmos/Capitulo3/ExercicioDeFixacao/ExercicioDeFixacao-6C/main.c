#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int fahrenheit = 0;
    float celsius = 0;

    printf("\n\n\t\t\Fahrenheit para Celsius");
    printf("\n\nDigite a temperatura em Farenheit: ");
        scanf("%d",&fahrenheit);

    celsius = ((fahrenheit - 32) * 5) / 9;

    printf("\n\%d Fahrenheit é equivalente a %.2f em Celsius",fahrenheit,celsius);

    return 0;
}
