#include <stdio.h>
#include <locale.h>

int calcularSomatorio(int n);

int main(){

    setlocale(LC_ALL,"");

    int somatoria = 0;
    int numero = 0;

        printf("Entre com um número para calcular a somatório: ");
            scanf("%d",&numero);

        printf("O somatório é %d",calcularSomatorio(numero));

    return 0;
}

int calcularSomatorio(int n){

    int somatorio = 0;

    for(int i = 1; i <= n; i++){
        somatorio += i;
    }
    return somatorio;
}
