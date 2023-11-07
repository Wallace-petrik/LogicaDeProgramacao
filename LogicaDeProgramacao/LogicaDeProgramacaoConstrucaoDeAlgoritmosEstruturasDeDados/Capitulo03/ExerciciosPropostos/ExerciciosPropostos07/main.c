#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int mes;

    printf("\nEntre com o número do mês: ");
        scanf("%d",&mes);

    switch(mes){
        case 1:
        printf("\nJaneiro");
        break;
        case 2:
        printf("\nFevereiro");
        break;
        case 3:
        printf("\nMarço");
        break;
        case 4:
        printf("\nAbril");
        break;
        case 5:
        printf("\nMaio");
        break;
        case 6:
        printf("\Junho");
        break;
        case 7:
        printf("\nJulho");
        break;
        case 8:
        printf("\nAgosto");
        break;
        case 9:
        printf("\nSetembro");
        break;
        case 10:
        printf("\nOutubro");
        break;
        case 11:
        printf("\nNovembro");
        break;
        case 12:
        printf("\Dezembro");
        break;
        default :
        printf("\nMês inválido");
        break;

    }
        printf("\n\n");
    return 0;
}
