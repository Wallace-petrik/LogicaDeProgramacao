#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int divisor;
    int dividendo;
    int quociente;
    printf("Entre com o dividendo: ");
        scanf("%d",&dividendo);
    printf("Entre com o divisor: ");
        scanf("%d",&divisor);
    quociente = calcularQuociente(dividendo,divisor);
    printf("Quociente entre esses dois números é %d",quociente);
    return 0;
}

int calcularQuociente(int dividendo, int divisor){
    int quociente = 0;

    if(dividendo<divisor){
        quociente = 0;
        return quociente;
    }

     while(dividendo>=divisor){

        quociente++;
        dividendo-=divisor;
     }

    return quociente;
}
