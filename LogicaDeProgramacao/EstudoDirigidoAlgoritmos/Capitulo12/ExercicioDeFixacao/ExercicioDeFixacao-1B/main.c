#include <stdio.h>
#include <locale.h>

int imprimirFibonacci(int n);

int main(){

    setlocale(LC_ALL,"");

    int fibonacci = 0;
    int numero = 0;

    printf("\n Entre com um número para calcular o Fibonacci: ");
        scanf("%d",&numero);

        imprimirFibonacci(numero);

    return 0;
}

int imprimirFibonacci(int n){

        int ant = 1;
        int atual = 1;
        int prox = 0;

        for(int i = 0; i < n; i++){

            (i+1) == n ? printf("%d<- termo encontrado\n",ant) : printf("%d\n",ant);
            prox = ant + atual;
            ant = atual;
            atual = prox;



        }
}
