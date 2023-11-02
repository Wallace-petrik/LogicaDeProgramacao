#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float vproduto;
    int opcao;

    printf("\n--------------------------------------");
    printf("\nCódigo       |      Forma de pagamento");
    printf("\n--------------------------------------");
    printf("\n1        À vista dinheiro Desconto 10%");
    printf("\n2  À vista dinheiro cartão Desconto 5%");
    printf("\n3                         2x sem juros");
    printf("\n4                         3x de juros");
    printf("\n--------------------------------------");

    printf("\nEntre com o valor do produto: ");
        scanf("%f",&vproduto);
    printf("\nForma de pagamento: ");
        scanf("%d",&opcao);

    switch(opcao){
        case 1 :
            printf("\nTotal a ser pago = %.1f.",vproduto-(vproduto*0.1));
        break;
        case 2 :
            printf("\nTotal a ser pago = %.1f.",vproduto-(vproduto*0.05));
        break;
        case 3 :
            printf("\n2X de %.1f.",vproduto/2.0);
            printf("\nTotal a ser pago = %.1f.",vproduto);
        break;
        case 4 :
            printf("\n3x de %.1f.",(vproduto+(vproduto*0.1))/3.0);
            printf("\nTotal a ser pago = %.1f.",vproduto+(vproduto*0.1));
        break;
        default{
            printf("\nCódigo invalido.");
        }
    }
    return 0;
}
