#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;
    int i = 0;

    printf("Digite um número qualquer para calcular sua tabuada: ");
        scanf("%d",&numero);

    do{

        printf("%d * %d = %d\n",numero, i, numero * i);
        i++;

    }while(i<=10);

    return 0;
}
