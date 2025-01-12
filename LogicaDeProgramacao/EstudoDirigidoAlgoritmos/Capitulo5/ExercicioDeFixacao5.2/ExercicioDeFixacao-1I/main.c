#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int cont = 0;
    int soma = 0;

    do{
        cont += 2;
        soma += cont;
    }while(cont<500);

    printf("Resultado: %d",soma);

    return 0;
}
