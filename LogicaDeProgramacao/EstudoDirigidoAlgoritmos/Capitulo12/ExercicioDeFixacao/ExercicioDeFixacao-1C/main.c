#include <stdio.h>
#include <locale.h>

float calcularValorPrestacaoAtraso(float valor, int taxa, int tempo);

int main(){

    setlocale(LC_ALL,"");

    float valorPrestacao = 0;
    float valorPrestacaoAtraso = 0;

    int tempo, taxa;

    printf("Entre com o valor da prestação: ");
        scanf("%f",&valorPrestacao);

    printf("Entre com o valor da taxa: ");
        scanf("%d",&taxa);

    printf("Entre com o tempo: ");
        scanf("%d",&tempo);

    printf("O valor corrigido é %.2f",calcularValorPrestacaoAtraso(valorPrestacao,taxa,tempo));
    return 0;
}

float calcularValorPrestacaoAtraso(float valor, int vTaxa, int VTempo){

    float prest  = 0;
    prest = valor + (valor * (vTaxa/100.1) * VTempo);
    return prest;

}
