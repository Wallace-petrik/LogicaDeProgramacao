#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int E;
    int B;
    int P;
    int contador = 0;

    printf("\nEntre com o valor da base: ");
        scanf("%d",&B);
    printf("\nEntre com o valor do expoente: ");
        scanf("%d",&E);

        P = B;
    do{
        P *= B;
        contador++;
    }while(contador<E-1);
    printf("Resultado: %d",P);
    return 0;
}
