#include <stdio.h>
#include <locale.h>

void calcularPrestacaoAtaso(float valor , int taxa, int tempo, float *pret);

int main(){

    setlocale(LC_ALL,"");

    float prestacao = 0;
    int taxa = 0;
    int tempo = 0;
    float pret = 0;

    printf("Entre com o valor da prestação: ");
        scanf("%f",&prestacao);
    printf("Entre com o valor da taxa: ");
        scanf("%d",&taxa);
    printf("Entre com o tempo de atraso: ");
        scanf("%d",&tempo);

     calcularPrestacaoAtaso(prestacao,taxa,tempo,&pret);
     printf("O valor com as taxas é %.2f",pret);
    return 0;
}

void calcularPrestacaoAtaso(float valor , int taxa, int tempo, float *pret){
    *pret = 0;
    *pret = valor + (valor *(taxa/100.0)*tempo);
}
