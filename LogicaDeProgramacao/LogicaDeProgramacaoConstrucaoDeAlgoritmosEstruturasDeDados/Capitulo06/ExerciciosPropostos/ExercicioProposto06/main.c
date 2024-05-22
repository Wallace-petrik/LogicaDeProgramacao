#include <stdio.h>
#include <stdlib.h>
#include <locale.h>




int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero;

    printf("Digite um número para saber se é primo ou não: ");
        scanf("%d",&numero);

    verificarSeNumeroEPrimo(numero);

    return 0;
}

void verificarSeNumeroEPrimo(int numero){

    int contador;

    for(int i = 1; i <= numero; i++){
         if(numero%i==0){
            contador++;
         }
    }

    if(contador==2){
        printf("O número %d é primo",numero);
    }else{
        printf("O número %d não é primo",numero);

    }
}
