#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL,"");

    int valorBase, valorIndice;
    float resultado;

    printf("\nEntre com o valor da Base:");
        scanf("%d",&valorBase);
    printf("\nEntre com o valor do índice: ");
        scanf("%d",&valorIndice);

    printf("\nResultado: %.f",pow(valorBase,valorIndice));

    return 0;
}
