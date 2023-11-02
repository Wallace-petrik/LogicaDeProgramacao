#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int ant = 1 , atual = 1, prox = 0;

    for(int i = 1; i <= 20; i++){

        printf("\n %dº = %d",i,ant);

        prox = ant + atual;
        ant = atual;
        atual = prox;
    }

    return 0;
}
