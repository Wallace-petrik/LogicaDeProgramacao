#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int numero,resto;
    int unidade, dezena,centena;

    printf("\nEntre com um número maior que 99: ");
        scanf("%d",&numero);

    resto = numero;


    centena = resto/100;
    resto = resto%100;
    dezena = resto/10;
    resto = resto%10;

    printf("\n O valor invertido é = %d%d%d",resto,dezena,centena);

    return 0;
}
