#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    const float pi = 3.14;
    float raio,area;

    printf("\nEntre com a raio para calcular a área do círculo: ");
        scanf("%f",&raio);

    area = pi*raio*raio;

    printf("\nÁrea do círculo é = %.2f\n",area);

    return 0;
}
