#include <stdio.h>
#include <locale.h>
#define tam 5
int main(){

    setlocale(LC_ALL,"");

    int vetA[tam] = {1,2,3,4,5} ;
    int vetB[tam];
    int opc = 0, numero = 0;
    int local = 0, acho = 0;
    for(int i = 0; i < tam; i++){
        vetB[i] = vetA[i] * 5;
    }

    do{
        printf("Digite um número que deseja buscar no vetor: ");
            scanf("%d",&numero);
        acho = 0;
        for(int i = 0; i < tam; i++){
            if(numero==vetB[i]){
                acho = 1;
                local = i;
                break;
            }else{
                acho = 0;
            }
        }
        if(acho==1){
            printf("O valor foi localizado na posoção %d\nO valor é igual á %d\n",local,vetB[local]);
        }else{
            printf("Valor não foi encontrado\n");
        }
        printf("Deseja fazer outra busca: (1 P/sim 0 P/não )\n: ");
            scanf("%d",&opc);

    }while(opc != 0);

    return 0;
}
