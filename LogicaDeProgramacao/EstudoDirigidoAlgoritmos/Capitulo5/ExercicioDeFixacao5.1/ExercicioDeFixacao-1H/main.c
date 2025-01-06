#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = 0;

    int anterior = 1;
    int atual = 1;
    int proximo = 0;

    while(contador++<15){

        printf("%d\n",anterior);
        proximo = anterior+atual;
        anterior = atual;
        atual = proximo;
    }

    return 0;
}
