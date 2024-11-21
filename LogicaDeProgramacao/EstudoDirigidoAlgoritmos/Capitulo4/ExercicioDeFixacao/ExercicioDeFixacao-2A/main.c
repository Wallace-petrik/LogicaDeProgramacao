#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int valorA, valorB, valorC, temp;

    printf("Digite três valores: ");
        scanf("%d%d%d",&valorA,&valorB,&valorC);

     if (valorA > valorB) {
        temp = valorA;
        valorA = valorB;
        valorB = temp;
    }
    if (valorA > valorC) {
        temp = valorA;
        valorA = valorC;
        valorC = temp;
    }
    if (valorB > valorC) {
        temp = valorB;
        valorB = valorC;
        valorC = temp;
    }

    printf("\nValores em ordem crescente: %d %d %d\n", valorA, valorB, valorC);

    return 0;
}
