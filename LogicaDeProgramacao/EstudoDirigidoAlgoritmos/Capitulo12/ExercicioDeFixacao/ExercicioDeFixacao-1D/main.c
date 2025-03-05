#include <stdio.h>
#include <locale.h>
#include <math.h>

int calcularPotencia(int vNumero, int VPotencia);

int main(){

    setlocale(LC_ALL,"");

    int numero = 0, potencia = 0;

    printf("Entre com um número: ");
        scanf("%d",&numero);
    printf("Entre com o valor da potência: ");
        scanf("%d",&potencia);

    printf("Resposta: %d",calcularPotencia(numero,potencia));

    return 0;
}

int calcularPotencia(int vNumero, int VPotencia){

    int resp = 0;

    return pow(vNumero,VPotencia);

}
