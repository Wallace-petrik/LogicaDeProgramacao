#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = 0;
    int soma = 0;

    while(contador<500){
        contador +=2;
        soma += contador;
    }
    printf("%d",soma);
    return 0;
}
