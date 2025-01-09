#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int soma = 0;
    int contador = 0;

    do{
        contador++;
        soma += contador;
    }while(contador<5);
    printf("Resp: %d\n",soma);
    return 0;
}
