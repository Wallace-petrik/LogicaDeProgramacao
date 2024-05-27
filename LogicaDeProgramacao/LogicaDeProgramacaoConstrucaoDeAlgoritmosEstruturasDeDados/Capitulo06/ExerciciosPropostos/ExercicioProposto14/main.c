#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularFatorial(int numero);
void calcularCombinacaoSimples(int elementos, int subconjuntos);

int main(){
    setlocale(LC_ALL,"Portuguese");

    int elementos;
    int subconjuntos;

    printf("\nCombinação Simples");
    printf("\nEntre com a quantidade de elementos: ");
        scanf("%d",&elementos);
    printf("Entre com a quantidade de subconjuntos: ");
       scanf("%d",&subconjuntos);

    calcularCombinacaoSimples(elementos,subconjuntos);

    return 0;
}

void calcularCombinacaoSimples(int elementos, int subconjuntos){
    int combinacoes = 0;

    combinacoes = calcularFatorial(elementos)/(calcularFatorial(subconjuntos)*calcularFatorial(elementos-subconjuntos));

    printf("\nExistem %d combinações.\n",combinacoes);
}

int calcularFatorial(int numero){

    int resp = numero;

    if(numero == 0 || numero == 1){
        return 1;
    }else{
        for(int i = numero - 1; i > 0; i--){
            resp *= i;
        }
        return resp;
    }
}
