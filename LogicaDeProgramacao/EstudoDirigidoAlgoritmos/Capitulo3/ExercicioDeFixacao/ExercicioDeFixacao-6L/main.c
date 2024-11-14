#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    float medidaEmPes, medidadeEmMetros;

    printf("Entre com uma medida em pés: ");
        scanf("%f",&medidaEmPes);

    medidadeEmMetros = medidaEmPes/3.281;

    printf("A medida em metros é %.2f",medidadeEmMetros);

    return 0;
}
