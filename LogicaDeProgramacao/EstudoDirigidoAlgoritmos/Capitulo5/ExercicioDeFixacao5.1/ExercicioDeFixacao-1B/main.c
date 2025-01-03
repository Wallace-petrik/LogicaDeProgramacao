#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int number = 0,soma = 0;

    while(++number<=100){
        soma+=number;
    }
    printf("\nSoma dos cem primeiro números inteiros: %d\n",soma);
    // A soma dos cem primeiros números inteiros pode ser calculada usando a fórmula da soma de uma progressão aritmética,
    // pois os números inteiros seguem uma sequência com uma diferença constante de 1 entre eles.
    // Soma = (100/2)*(1+100)
    return 0;
}
