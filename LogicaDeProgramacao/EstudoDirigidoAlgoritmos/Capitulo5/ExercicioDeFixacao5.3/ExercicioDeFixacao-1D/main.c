#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;

    printf("Entre com um número qualquer para calcular a tabuada: ");
        scanf("%d",&numero);

    for(int i = 0; i <= 10; i++){

        printf("%2.1d + %2.1d = %2.1d \t",numero,i,numero+i);
        printf("%2.1d - %2.1d = %2.1d \t",numero,i,numero-i);
        printf("%2.1d * %2.1d = %2.1d \t\n",numero,i,numero*i);

    }
    return 0;
}
