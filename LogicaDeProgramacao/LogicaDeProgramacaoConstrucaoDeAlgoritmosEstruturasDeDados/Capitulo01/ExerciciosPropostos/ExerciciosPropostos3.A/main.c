#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int pneu = 1; // Pneu igual a ZERO o pneu não esta furado.

    if(pneu){
        printf("\nPegar pneu reserva.");
        printf("\nTrocar pneu do furado.");
        printf("\nColocar pneu furado na mala.");
    }

    return 0;
}
