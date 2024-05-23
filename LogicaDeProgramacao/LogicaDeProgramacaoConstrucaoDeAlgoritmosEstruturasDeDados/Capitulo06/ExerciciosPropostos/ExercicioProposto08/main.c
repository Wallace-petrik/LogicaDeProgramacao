#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularMmc(int numeroUm, int numeroDois);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numeroUm = 0;
    int numeroDois = 0;

    int mmc = 0;

    printf("Digite dois número inteiros para calcular o MMC: ");
        scanf("%d%d",&numeroUm, &numeroDois);

    if(numeroDois<numeroUm){
        mmc = calcularMmc(numeroDois,numeroUm);
    }else{
        mmc = calcularMmc(numeroUm,numeroDois);
    }

    printf("O MMC entre %d e %d é %d",numeroUm,numeroDois,mmc);
    return 0;
}

int calcularMmc(int numeroUm, int numeroDois){

    int numeroUmAux = numeroUm;
    int numeroDoisAux = numeroDois;

    while(numeroUmAux!=numeroDoisAux){
            while(numeroUmAux<numeroDoisAux){
                numeroUmAux += numeroUm;
            }
            if(numeroUmAux==numeroDoisAux){
                return numeroUmAux;
            }else{
                numeroDoisAux += numeroDois;
            }
    }
}
