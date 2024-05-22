#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimirTodosDivisoresDeUmNumero(int numero);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero = 0 ;

    printf("Digite um número para saber todos os seus divisores: ");
        scanf("%d",&numero);

    imprimirTodosDivisoresDeUmNumero(numero);

    return 0;
}

void imprimirTodosDivisoresDeUmNumero(int numero){
    for(int i = 1; i <= numero; i++){
        if(numero%i==0){
            printf("[%d] ",i);
        }
    }
}
