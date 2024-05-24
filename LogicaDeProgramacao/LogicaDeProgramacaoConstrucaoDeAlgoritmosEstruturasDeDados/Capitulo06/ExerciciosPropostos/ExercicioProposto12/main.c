#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularFatorial(int numero);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero;
    int fatorial;

    printf("Calcular fatorial\nDigite um número qualquer: ");
        scanf("%d",&numero);

    fatorial = calcularFatorial(numero);

    printf("Fatorial de %d = %d",numero,fatorial);
    return 0;
}

int calcularFatorial(int numero){
    int fatorial = numero;
    if(numero == 0 || numero == 1){
        return 1;
    }else{
         for(int i = numero-1; i >= 1; i--){
            fatorial *=i;
         }
         return fatorial;
    }
}
