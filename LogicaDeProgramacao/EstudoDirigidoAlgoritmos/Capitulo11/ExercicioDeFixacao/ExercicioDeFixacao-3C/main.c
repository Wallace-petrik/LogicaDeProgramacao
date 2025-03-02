#include <stdio.h>
#include <locale.h>

void calcularPotencia(int b, int e, int *p);

int main(){

    setlocale(LC_ALL,"");

    int base, expoente, potencia = 0;

    printf("Entre com a base: ");
        scanf("%d",&base);
    printf("Entre com o expoente: ");
        scanf("%d",&expoente);
    calcularPotencia(base,expoente,&potencia);
    printf("Potência: %d",potencia);
    return 0;
}

void calcularPotencia(int b, int e, int *p){
    *p = b;
    for(int i = 1; i < e; i++){
        *p *= b;
    }

}
