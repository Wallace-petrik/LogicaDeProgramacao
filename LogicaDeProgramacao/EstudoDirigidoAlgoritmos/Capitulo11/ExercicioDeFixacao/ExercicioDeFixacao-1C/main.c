#include <stdio.h>
#include <locale.h>

void calcularPotencia(int b, int e);

int main(){

    setlocale(LC_ALL,"");

    int base = 0;
    int expoente =0;

    printf("Ende com o valor da base: ");
        scanf("%d",&base);
    printf("Ende com o valor da expoente: ");
        scanf("%d",&expoente);

    calcularPotencia(base,expoente);

    return 0;
}

void calcularPotencia(int b, int e){

    int potencia = b;

    for(int i = 1; i < e; i++){
        potencia *= b;
    }
    printf("Potência = %d",potencia);
}
