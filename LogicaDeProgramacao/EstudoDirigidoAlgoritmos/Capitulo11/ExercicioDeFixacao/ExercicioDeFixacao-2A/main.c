#include <stdio.h>
#include <locale.h>

void calcularsomatoriaorial(int n);

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;

    printf("Entre com um número para a somatória de um numero: ");
        scanf("%d",&numero);
    calcularsomatoriaorial(numero);
    return 0;
}

void calcularsomatoriaorial(int n){

    int somatoria = 0;

    for(int i = 1; i <= n; i++){

    somatoria += i;

    }

    printf("Somatória : %d",somatoria);
}
