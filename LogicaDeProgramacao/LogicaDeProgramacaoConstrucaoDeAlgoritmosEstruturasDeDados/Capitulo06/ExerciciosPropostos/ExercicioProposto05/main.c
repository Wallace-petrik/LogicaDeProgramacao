#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int numero = 0;

    printf("Digite um número inteiro qualquer: ");
        scanf("%d",&numero);

    verificarNumero(numero);
    return 0;
}

void verificarNumero(int numero){

    if(numero%6==0){
        printf("O número %d é divisível por 6\n",numero);
    }else{
        printf("O número %d não é divisívedel por 6\n",numero);
    }

}
