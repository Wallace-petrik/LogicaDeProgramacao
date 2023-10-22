#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int pneuE = 1,pneuR = 1; // Pneu igual a ZERO o pneu NÂO esta furado.

    if(pneuE){
        if(pneuR){
            printf("\nColocar triangulo na rua");
            printf("\nPegar pneu reserva.");
            printf("\nTrocar pneu do furado.");
            printf("\nColocar pneu furado na mala.");
        }
    }

    return 0;
}
