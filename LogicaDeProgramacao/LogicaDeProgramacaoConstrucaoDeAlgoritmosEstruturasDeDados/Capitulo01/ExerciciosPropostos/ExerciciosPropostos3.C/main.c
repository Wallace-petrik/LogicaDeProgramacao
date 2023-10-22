#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int pneu[4] = {0,0,1,0},pneuR = 1; // Pneu igual a ZERO o pneu NÂO esta furado.

    printf("\nColocar triangulo na rua.");

    for(int i = 0 ; i <= 3 ; i++){
        if(pneu[i]){
            if(pneuR){
                printf("\nPegar pneu reserva.");
                printf("\nTrocar pneu furado.");
                printf("\nColocar pneu furado na mala.");
                break;
            }
        }
    }
    return 0;
}
