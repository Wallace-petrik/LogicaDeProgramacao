#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = -1;
    int contadorDois = 0;
    int resultado;

    while(contador++<15){
        resultado = 1;

        if(contador==0){
            printf("\n3^%d = %d",contador,1);
        }else if(contador==1){
            printf("\n3^%d = %d",contador,3);
        }else{

            while(contadorDois <= contador){
                resultado *= 3;
                contadorDois++;
            }
            printf("\n3^%d = %d",contador,resultado);
            contadorDois = 1;
        }

    }

    return 0;
}
