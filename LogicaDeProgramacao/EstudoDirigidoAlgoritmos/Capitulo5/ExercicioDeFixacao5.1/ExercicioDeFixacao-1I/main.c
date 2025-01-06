#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int base = 0;
    int expoente = 0;
    int contador = 0;
    int potencia = 1;

    printf("\nEntre com o valor da base: ");
        scanf("%d",&base);
    printf("\nEntre com o valor do expoente: ");
        scanf("%d",&expoente);

    while(contador++<expoente){

        potencia *= base;

    }

    printf("Resultado = %d",potencia);
    return 0;
}
