#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    const int qtd = 20;

    int a[qtd],b[qtd];
    float r[qtd];
    char operacao[qtd];
    int resp;

    do{
        for(int i = 0 ; i < qtd ; i++){

            printf("\nEntre com o %dº valores do VET A: ",i+1);
                scanf("%d",&a[i]);
            printf("\nEntre com a operação aritmética: : ");
                scanf(" %c",&operacao[i]);
            printf("\nEntre com o %dº valores do VET B: ",i+1);
                scanf("%d",&b[i]);

            switch(operacao[i]){
                case '+' : r[i]=(float)a[i]+b[i];
                break;
                case '-' : r[i]=(float)a[i]-b[i];
                break;
                case '*' : r[i]=(float)a[i]*b[i];
                break;
                case '/' : r[i]=(float)a[i]/b[i];
                break;
                default: printf("\nErro ao executar operação\n");
            }
        }

        for(int i = 0 ; i < qtd ; i++){

            printf("\nResp da %dª operação = %.1f.",i+1,r[i]);

        }
        do{
        printf("\n Quer continuar 1/SIM 2/NÂO ? ");
            scanf("%d",&resp);
        }while(resp!=2 || resp!=1);
    }while(resp!=2);
    return 0;
}
