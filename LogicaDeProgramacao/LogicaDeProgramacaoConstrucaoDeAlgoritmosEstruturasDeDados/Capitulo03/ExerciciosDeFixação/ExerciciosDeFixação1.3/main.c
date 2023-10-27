#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL,"");

    const float pi = 3.14159;

    int raio;
    float volume;

    printf("\nCalcular volume de uma esfera");
    printf("\nEntre com o Raio da esfera: ");
        scanf("%d",&raio);

    volume = (4*pi*pow(raio,3))/3;

    printf("\nO VOLUME da esfera em metros³ é = %.1f",volume);

    return 0;
}
