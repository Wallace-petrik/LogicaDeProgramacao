#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int codProduto;

    printf("\n----------------------------------");
    printf("\nCódigo                     Produto");
    printf("\n----------------------------------");
    printf("\n1                    Não-perecível");
    printf("\n2,3 ou 4                 Perecível");
    printf("\n5 ou 6                   Vestuário");
    printf("\n7                  Higiene pessoal");
    printf("\n8 até 15       Limpeza eUtensílios");
    printf("\n----------------------------------");

    printf("\n\nEntre com o código do produto: ");
        scanf("%d",&codProduto);

    switch(codProduto){
        case 1: printf("\nNão-perecível");
        break;
        case 2:
        case 3:
        case 4:
            printf("\nPerecível");
        break;
        case 5:
        case 6: printf("\nVestuário");
        break;
        case 7: printf("\nHigiene pessoal");
        break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:printf("\nLimpeza e utensílios");
        break;
        default: printf("\nInválido");
    }

    return 0;
}
