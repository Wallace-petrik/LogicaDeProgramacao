#include <stdio.h>
#include <locale.h>
#include <math.h>

#define tam 5

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam];
    int aux,continua,achou = tam;

    for(int i = 0; i < tam; i++){
        printf("Digite o %dº do vetor: ",i+1);
            scanf("%d",&vetA[i]);
        vetB[i] = pow(vetA[i],3);
    }

    do{
        printf("\nDigite o valor que deseja buscar no vetor B: ");
            scanf("%d",&aux);
        for(int i = 0; i < tam; i++){
            if(aux==vetB[i]){
                achou = i;
                break;
            }
        }
        if(achou >= 0 && achou <tam){
            printf("\nValor encontrado Posição [%d], valor = %d.\n\n",achou,vetB[achou]);
        }else printf("Valor não encontrado.");

        printf("Deseja fazer outra busca:\n 1/Sim 0/Não: ");
            scanf("%d",&continua);
            achou = tam;
    }while(continua != 0);

    return 0;
}
