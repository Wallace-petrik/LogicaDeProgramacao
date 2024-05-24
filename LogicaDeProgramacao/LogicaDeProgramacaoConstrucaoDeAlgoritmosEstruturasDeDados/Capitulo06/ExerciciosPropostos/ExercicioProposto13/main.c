#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Potuguese");

    int numeroUm, numeroDois, arranjo;

    printf("Calcular o Arranjo\nDigite dois numeros: ");
        scanf("%d%d",&numeroUm,&numeroDois);

    calcularArranjo(numeroUm,numeroDois);
    return 0;
}

void calcularArranjo(int numeroUm, int numeroDois){
    int arranjo = numeroUm;
    for( int i = numeroUm-1; i>=numeroDois; i--){
        arranjo *= i;
    }
    printf("Arranjo = %d",arranjo);
}
