#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int ant = 1;
    int atual = 1;
    int prox = 0;
    int cont = 0;

    do{

        printf("%d\n",ant);
        prox = ant + atual;
        ant = atual;
        atual = prox;
        cont++;

    }while(cont<15);

    return 0;
}
