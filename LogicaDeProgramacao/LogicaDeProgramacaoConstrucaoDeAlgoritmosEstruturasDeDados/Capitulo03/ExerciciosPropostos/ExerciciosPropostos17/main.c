#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int ant = 0, atual = 1, prox;

    printf("\nENtre com os dois primeiros termos da série de Fibonacci: ");
        scanf("%d%d",&ant,&atual);


    for(int i = 1 ; i <= 20 ; i++){

        printf("\n%dº %d",i,ant);

        prox = ant+atual;
        ant = atual;
        atual = prox;

    }

    return 0;
}
